from typing import List

class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        """
        如果游戏存在获胜者（A 或 B）就返回该游戏的获胜者
        如果游戏以平局结束 则返回 "Draw"
        如果仍会有行动（游戏未结束） 则返回 "Pending"。
        """

        if len(moves) < 6:
            return 'Pending'


        for move in moves:
            pass

        pass



if __name__ == "__main__":
    s = Solution()

    print(s.tictactoe([[0,0],[2,0],[1,1],[2,1],[2,2]]))
    print(s.tictactoe([0,0],[1,1],[0,1],[0,2],[1,0],[2,0]))
    print(s.tictactoe([0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]))
    print(s.tictactoe([0,0],[1,1]))