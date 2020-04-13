
class Solution:
    def entityParser(self, text: str) -> str:
        return text.replace('&frasl;', '/')\
            .replace('&lt;', '<')\
            .replace('&gt;', '>')\
            .replace('&quot;', '\"')\
            .replace('&apos;', '\'')\
            .replace('&amp;', '&')


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
