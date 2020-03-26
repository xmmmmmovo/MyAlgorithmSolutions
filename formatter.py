import os

dirs = ['HDU OJ', 'LeetCode', 'PTA', 'SophomoreAlgorithm']

def main():
    for d in dirs:
        for f in os.listdir(d):
            if os.path.isdir(f'{d}/{f}'):
                for ff in os.listdir(f'{d}/{f}'):
                    if os.path.isdir(f'{d}/{f}/{ff}'):
                        for fff in os.listdir(f'{d}/{f}/{ff}'):
                            print(f"[{os.path.splitext(fff)[0]}]({d.replace(' ', '%20')}/{f.replace(' ', '%20')}/{ff.replace(' ', '%20')}/{fff.replace(' ', '%20')})")
                    else:
                        print(f"[{os.path.splitext(ff)[0]}]({d.replace(' ', '%20')}/{f.replace(' ', '%20')}/{ff.replace(' ', '%20')})")
            else:
                print(f"[{os.path.splitext(f)[0]}]({d.replace(' ', '%20')}/{f.replace(' ', '%20')})")
    pass

main()