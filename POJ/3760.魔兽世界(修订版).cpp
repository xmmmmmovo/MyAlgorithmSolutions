/**
 * author: xmmmmmovo
 * generation time: 2021/01/20
 * filename: 3760.魔兽世界(修订版).cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int groups;
int m, n, t;
// dragon、ninja、iceman、lion、wolf生命值
vector<int> health(5, 0);
// dragon、ninja、iceman、lion、wolf攻击力
vector<int> attack(5, 0);
// 武士名字
array<string, 5> warrior_name = {"dragon", "ninja", "iceman", "lion", "wolf"};

typedef struct {
    int id = 0;
    int type;
    int health;
    int times = 0;
    int step  = 0;
} warrior;

typedef struct {
    int     health_meta = 0;
    int     flag        = 0; // 0 无旗子 1 红 2 蓝
    int     cnt         = 0;
    warrior rw          = {.id = -1};
    warrior bw          = {.id = -1};
} city;

typedef struct {
    string        name;
    int           hel_remain = 0;
    array<int, 5> sequence;
    int           widx    = 0;
    int           enemies = 0;
    warrior       w       = {.id = -1};
} station;

void print_time(int hours, int mins) {
    cout << setw(3) << setfill('0') << hours << ":";
    cout << setw(2) << setfill('0') << mins << " ";
}

void gen_warrior(station &s, int h, int m) {
    warrior wt = warrior{.id = s.widx + 1, .type = s.sequence[s.widx % 5]};
    wt.health  = health[wt.type];
    if (s.hel_remain < wt.health) {
        s.w = {.id = -1}; // 说明没办法生产
        return;
    }
    print_time(h, m);
    s.widx++;
    s.w = wt;
    s.hel_remain -= wt.health;
    cout << s.name << " " << warrior_name[s.w.type] << " " << s.w.id << " bron"
         << endl;
}

int warrior_step(vector<city> &cl, station &rs, station &bs, int h, int m) {
    int     fin = 0;
    warrior rwt = rs.w, bwt = bs.w;
    for (int i = cl.size() - 1, j = 0; i >= 0 && j < cl.size(); i--, j++) {
        swap(cl[j].rw, rwt);
        swap(cl[i].bw, bwt);
    }

    for (int i = 0; i < cl.size(); i++) {
        city &ct = cl[i];
        // cout << "debug step:" << ct.rw.id << " " << ct.bw.id << endl;
        if (ct.rw.id != -1) {
            if (ct.rw.type == 2 && (++ct.rw.step) % 2 == 0) {
                ct.rw.health = (ct.rw.health <= 9) ? 1 : ct.rw.health - 9;
            }

            print_time(h, m);
            cout << "red " << warrior_name[ct.rw.type] << " " << ct.rw.id
                 << " marched to city " << i + 1 << " with " << ct.rw.health
                 << " elements and force " << attack[ct.rw.type] << endl;
        }
        if (ct.bw.id != -1) {
            if (ct.bw.type == 2 && ++ct.bw.step == 2) {
                ct.bw.health = (ct.bw.health <= 9) ? 1 : ct.bw.health - 9;
            }

            print_time(h, m);
            cout << "blue " << warrior_name[ct.bw.type] << " " << ct.bw.id
                 << " marched to city " << i + 1 << " with " << ct.bw.health
                 << " elements and force " << attack[ct.bw.type] << endl;
        }
    }

    // cout << "debug step:" << rwt.id << " " << bwt.id << endl;

    if (bwt.id != -1) {
        print_time(h, m);
        cout << "blue " << warrior_name[bwt.type] << " " << bwt.id
             << " reached red headquarter with " << bwt.health
             << " elements and force " << attack[bwt.type] << endl;
        rs.enemies++;
    }
    if (rs.enemies == 2) {
        print_time(h, m);
        cout << "red headquarter was taken" << endl;
        fin = 1;
    }
    if (rwt.id != -1) {
        print_time(h, m);
        cout << "red " << warrior_name[rwt.type] << " " << rwt.id
             << " reached blue headquarter with " << rwt.health
             << " elements and force " << attack[rwt.type] << endl;
        bs.enemies++;
    }
    if (bs.enemies == 2) {
        print_time(h, m);
        cout << "blue headquarter was taken" << endl;
        fin = 1;
    }

    return fin;
}

void product_health_meta(vector<city> &cl) {
    for (auto &c : cl) {
        c.health_meta += 10;
    }
}

void fetch_health_meta(vector<city> &cl, station &rs, station &bs, int h,
                       int m) {
    for (auto &c : cl) {
        if (c.rw.id != -1 && c.bw.id == -1) {
            rs.hel_remain += c.health_meta;
            print_time(h, m);
            cout << "red " << warrior_name[c.rw.type] << " " << c.rw.id
                 << " earned " << c.health_meta
                 << " elements for his headquarter" << endl;
            c.health_meta = 0;
        } else if (c.rw.id == -1 && c.bw.id != -1) {
            bs.hel_remain += c.health_meta;
            print_time(h, m);
            cout << "blue " << warrior_name[c.bw.type] << " " << c.bw.id
                 << " earned " << c.health_meta
                 << " elements for his headquarter" << endl;
            c.health_meta = 0;
        }
    }
}

// attack_warrior suffered_warrior
int attack_to_opponent(warrior &atw, warrior &sfw, int at, int cnum, int h,
                       int m) {
    print_time(h, m);
    cout << (at ? "red " : "blue ") << warrior_name[atw.type] << " " << atw.id
         << " attacked " << (at ? "blue " : "red ") << warrior_name[sfw.type]
         << " " << sfw.id << " in city " << cnum << " with " << atw.health
         << " elements and force " << attack[atw.type] << endl;
    if (sfw.health - attack[atw.type] * ((atw.times / 2) + 1) <= 0) {
        print_time(h, m);
        cout << (at ? "blue " : "red ") << warrior_name[sfw.type] << " "
             << sfw.id << " was killed in city " << cnum << endl;
        sfw.id = -1;
        if (atw.type == 4 && (++atw.times) % 2 == 0) {
            atw.health *= 2;
        }
        if (sfw.type == 3) {
            atw.health += sfw.health;
        }
        return 1;
    }
    sfw.health -= attack[atw.type] * ((atw.times / 2) + 1);
    return 0;
}

int attack_against(warrior &agw, warrior &sfw, int at, int cnum, int h, int m) {
    // cout << "debug fought:" << warrior_name[sfw.type] << " " << sfw.id <<
    // endl;
    print_time(h, m);
    cout << (at ? "blue " : "red ") << warrior_name[agw.type] << " " << agw.id
         << " fought back against " << (at ? "red " : "blue ")
         << warrior_name[sfw.type] << " " << sfw.id << " in city " << cnum
         << endl;
    if (sfw.health - ((attack[agw.type] * ((agw.times / 2) + 1)) / 2) <= 0) {
        print_time(h, m);
        cout << (at ? "red " : "blue ") << warrior_name[sfw.type] << " "
             << sfw.id << " was killed in city " << cnum << endl;
        sfw.id = -1;
        return 1;
    }
    sfw.health -= ((attack[agw.type] * ((agw.times / 2) + 1)) / 2);
    return 0;
}

void warrior_battle(vector<city> &cl, station &rs, station &bs, int h, int m) {
    vector<int> slayed(n, 0), collect(n, 0);
    for (int i = 0; i < cl.size(); i++) {
        city &c  = cl[i];
        int   at = 1; // 表示红色方先攻击
        if (c.rw.id != -1 && c.bw.id != -1) {
            switch (c.flag) {
            case 0:
                if ((i + 1) % 2 == 0)
                    at = 0;
                break;
            case 2:
                at = 0;
                break;
            }
            warrior *atw = &c.rw, *sfw = &c.bw;
            if (!at) {
                atw = &c.bw, sfw = &c.rw;
            }
            int f = 0;
            if (attack_to_opponent(*atw, *sfw, at, i + 1, h, m)) {
                slayed[i]  = at ? 1 : 2;
                collect[i] = c.health_meta;
                print_time(h, m);
                cout << (at ? "red " : "blue ") << warrior_name[atw->type]
                     << " " << atw->id << " earned " << c.health_meta
                     << " elements for his headquarter" << endl;
                c.health_meta = 0;
                c.cnt += at ? 1 : -1;
                if (c.flag == 0) {
                    if (c.cnt == 2)
                        f = 1;
                    if (c.cnt == -2)
                        f = 2;
                } else {
                    f = at ? 1 : 2;
                }
                if (f != 0) {
                    c.flag = f;
                    print_time(h, m);
                    cout << (at ? "red " : "blue ") << "flag raised in city "
                         << i + 1 << endl;
                }
            } else if (sfw->type != 1 &&
                       attack_against(*sfw, *atw, at, i + 1, h, m)) {
                slayed[i]  = at ? 2 : 1;
                collect[i] = c.health_meta;
                print_time(h, m);
                cout << (at ? "blue " : "red ") << warrior_name[sfw->type]
                     << " " << sfw->id << " earned " << c.health_meta
                     << " elements for his headquarter" << endl;
                c.health_meta = 0;
                c.cnt += at ? -1 : 1;
                if (c.flag == 0) {
                    if (c.cnt == 2)
                        f = 1;
                    if (c.cnt == -2)
                        f = 2;
                } else {
                    f = at ? 2 : 1;
                }
                if (f != 0) {
                    c.flag = f;
                    print_time(h, m);
                    cout << (at ? "blue " : "red ") << "flag raised in city "
                         << i + 1 << endl;
                }
            }
            if (atw->type == 0 && atw->id != -1) {
                print_time(h, m);
                cout << (at ? "red " : "blue ") << "dragon " << atw->id
                     << " yelled in city " << i + 1 << endl;
            }
        }
    }

    // 蓝方奖励
    for (int i = 0; i < slayed.size(); i++) {
        if (slayed[i] == 2 && bs.hel_remain >= 8) {
            bs.hel_remain -= 8;
            cl[i].bw.health += 8;
        }
    }

    // 红方奖励
    for (int i = slayed.size() - 1; i >= 0; i--) {
        if (slayed[i] == 1 && rs.hel_remain >= 8) {
            rs.hel_remain -= 8;
            cl[i].rw.health += 8;
        }
    }

    for (int i = 0; i < collect.size(); i++) {
        if (slayed[i] == 1)
            rs.hel_remain += collect[i];
        if (slayed[i] == 2)
            bs.hel_remain += collect[i];
    }
}

void report_health_meta(int h, int m, station &s) {
    print_time(h, m);
    cout << s.hel_remain << " elements in " << s.name << " headquarter" << endl;
}

void game_main(int m, int n, int t) {
    int          hours = 0, mins = 0;
    int          edh = t / 60, edm = t % 60;
    vector<city> cities(n, city{});
    station red_s{.name = "red", .hel_remain = m, .sequence = {2, 3, 4, 1, 0}},
        blue_s{.name = "blue", .hel_remain = m, .sequence = {3, 0, 1, 2, 4}};

    while (true) {
        // cout << "==debug==" << endl;
        // for (auto &c : cities)
        //     cout << c.health_meta << " " << c.rw.id << " " << c.bw.id << endl;
        // cout << "==debug==" << endl;

        switch (mins) {
        case 0:
            gen_warrior(red_s, hours, mins);
            gen_warrior(blue_s, hours, mins);
            break;
        case 10:
            if (warrior_step(cities, red_s, blue_s, hours, mins)) {
                return;
            }
            break;
        case 20:
            product_health_meta(cities);
            break;
        case 30:
            fetch_health_meta(cities, red_s, blue_s, hours, mins);
            break;
        case 40:
            warrior_battle(cities, red_s, blue_s, hours, mins);
            break;
        case 50:
            report_health_meta(hours, mins, red_s);
            report_health_meta(hours, mins, blue_s);
            break;
        }
        if (hours == edh && mins == edm)
            break;
        mins += 10;
        hours += mins / 60;
        mins %= 60;
    }
}

/**
 * 红方 iceman、lion、wolf、ninja、dragon
 * 蓝方 lion、dragon、ninja、iceman、wolf
 * 生命值m 生命元-m
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt","r",stdin);  //输入将被重定向到文件
    freopen("ouput.txt","w",stdout);  //输入将被重定向到文件

    cin >> groups;
    for (int g = 1; g <= groups; g++) {
        cin >> m >> n >> t;
        for (int i = 0; i < 5; i++)
            cin >> health[i];
        for (int i = 0; i < 5; i++)
            cin >> attack[i];
        cout << "Case:" << g << endl;
        game_main(m, n, t);
    }

    return 0;
}