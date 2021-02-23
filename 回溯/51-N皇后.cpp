/*

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例 1：
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。

示例 2：
输入：n = 1
输出：[["Q"]]

*/


#include <iostream>
using namespace std;
#include<vector>


class Solution {   // 回溯算法
private:
    vector<vector<string>> res;
public:

    void backtrack(vector<string> board, int rows){   // 一个棋盘， 一个行数
        if (rows == board.size()){   // 摆到第N行了，棋盘满了
            res.push_back(board);  // 得到了一个答案，加入到res中
            return;   // 返回空，进行下一种尝试
        }
        int size = board.size();
        for(int cols=0; cols<size; cols++){  // 尝试第rows行的N个列， 就是N个可选择的位置
            if(!isValid(board, rows, cols))  // 看看这个位置和之前的皇后是否冲突
                continue;   // 不合法就尝试下一个位置
            board[rows][cols] = 'Q';  // 合法，就在该位置上写下Q
            backtrack(board, rows+1);  // 递归到下一行，进行下一步尝试
            board[rows][cols] = '.';   // 尝试这一行的选择
        }
    }
    // 判断在对角线、反对角线、列上是否有冲突
    bool isValid(vector<string> board, int rows, int cols){
        for(int i=0; i<rows; i++){  // 当前列是否有皇后
            if (board[i][cols] == 'Q')
                return false;
        }
        for(int R=rows-1, C=cols-1; R>=0 && C>=0; R--, C--){  // 左上角是否有皇后
            if (board[R][C] == 'Q')
                return false;

        }
        int size = board.size();
        for(int R=rows-1, C=cols+1; R>=0 && C<size; R--,C++){  // 右上角是否有皇后
            if (board[R][C] == 'Q')
                return false;
        }
        return true;   // 如果都不冲突，则返回true
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string (n, '.'));
        backtrack(board, 0);
        return res;

    }
};