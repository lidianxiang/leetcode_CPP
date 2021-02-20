/*

给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {   // 回溯：深度优先搜索
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string&s, int k){
        // 当前位的元素不等于字符串的第k位
        if (board[i][j] != s[k]){
            return false;
        // 当搜索到达最后位置
        }else if(k == s.length() -1 ){
            return true;
        }
        // visited数组表示是否在这之前访问过该位置的元素，初始值为true
        visited[i][j] = true;
        // 四个方向
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for(const auto& dir: directions){
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >=0 && newj <board[0].size()){
                if (!visited[newi][newj]){
                    bool flag = check(board, visited, newi, newj, s, k+1);
                    if (flag){
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                bool flag = check(board, visited, i, j, word, 0);
                if (flag){
                    return true;
                }
            }
        }
        return false;
    }
};