from typing import List


class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res = []
        words.sort(key=lambda i: len(i))
        # print(words)
        for k, w in enumerate(words):
            for i in range(k + 1, len(words)):
                if words[i].find(w) != -1:
                    res.append(w)
                    break
        # print(res)
        return res


if __name__ == "__main__":
    assert Solution().stringMatching(
        ["mass", "as", "hero", "superhero"]) == ["as", "hero"]
    assert Solution().stringMatching(
        ["leetcode", "et", "code"]) == ['et', 'code']
    assert Solution().stringMatching(["blue", "green", "bu"]) == []
    assert Solution().stringMatching(
        ["leetcoder", "leetcode", "od", "hamlet", "am"]) == ["leetcode", "od", "am"]
