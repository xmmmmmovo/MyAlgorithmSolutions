
class Solution2:
    def entityParser(self, text: str) -> str:
        return text.replace('&frasl;', '/')\
            .replace('&lt;', '<')\
            .replace('&gt;', '>')\
            .replace('&quot;', '\"')\
            .replace('&apos;', '\'')\
            .replace('&amp;', '&')


class Solution:
    def __init__(self):
        self.match = {
            "&quot;": "\"",
            "&apos;": "'",
            "&amp;": "&",
            "&gt;": ">",
            "&lt;": "<",
            "&frasl;": "/"
        }

    def entityParser(self, text: str) -> str:
        k, res = '', ''

        for c in text:
            if c == '&':
                if k != '':
                    res += k
                    k = ''
                k += c
            elif c == ';':
                k += c
                if k in self.match:
                    res += self.match[k]
                    k = ''
                else:
                    res += k
                    k = ''
            else:
                k += c
            # print(f'res={res} c={c} k={k}')

        res += k
        return res


if __name__ == "__main__":
    assert Solution().entityParser(
        text="&amp; is an HTML entity but &ambassador; is not.") == "& is an HTML entity but &ambassador; is not."
    assert Solution().entityParser(
        text="and I quote: &quot;...&quot;") == "and I quote: \"...\""
    assert Solution().entityParser(
        text="Stay home! Practice on Leetcode :)") == "Stay home! Practice on Leetcode :)"
    assert Solution().entityParser(
        text="x &gt; y &amp;&amp; x &lt; y is always false") == "x > y && x < y is always false"
    assert Solution().entityParser(
        text="leetcode.com&frasl;problemset&frasl;all") == "leetcode.com/problemset/all"
