class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        d = [['a', a], ['b', b], ['c', c]]

        res = ''
        i = 0
        lc = max(d, key=lambda i: i[1])[0]
        # print(a + b + c)
        for j in range(a + b + c):
            d.sort(key=lambda i: i[1], reverse=True)
            if i != 2 and lc == d[0][0]:
                res += d[0][0]
                d[0][1] -= 1
                i += 1
            elif lc != d[0][0]:
                i = 1
                res += d[0][0]
                d[0][1] -= 1
                lc = d[0][0]
            elif i == 2:
                if d[1][1] != 0:
                    res += d[1][0]
                    d[1][1] -= 1
                    i = 1                
                    lc = d[1][0]
                else:
                    return res
            
            # print(d)
            # print(f'res = {res} i = {i}')

        return res


if __name__ == "__main__":
    print(Solution().longestDiverseString(a=1, b=1, c=7))
    print(Solution().longestDiverseString(a=2, b=2, c=1))
    print(Solution().longestDiverseString(a=7, b=1, c=0))
