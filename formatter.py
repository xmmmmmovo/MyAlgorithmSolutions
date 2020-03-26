import os

dirs = ['HDU OJ', 'LeetCode', 'PTA', 'SophomoreAlgorithm']


def dfs(p, lf):
    if os.path.isdir(p):
        for f in os.listdir(p):
            dfs(f'{p}/{f}', f)
    else:
        print(f"[{os.path.splitext(lf)[0]}]({p.replace(' ', '%20')})")


def main():
    for d in dirs:
        dfs(d, None)


main()
