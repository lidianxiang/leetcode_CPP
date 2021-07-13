/*

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3

*/


#include<iostream
using namespace std;
#include<vector>


class Solution{    // 深度优先遍历dfs
private:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
        if (r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
        if (c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
        if (c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
    }

public:
    int numIslands(vector<vector<char>>& grid){
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for(int r=0; r<nr; r++){
            for(int c=0; c<nc; c++){
                if (grid[r][c] == '1'){
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }
        return num_islands;
    }
};



class Solution2{     // 广度优先遍历bfs
public:
    int numIslands(vector<vector<char>>& grid){
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for(int r=0; r<nr; r++){
            for(int c=0; c<nc; c++){
                if (grid[r][c] == '1'){
                    ++num_islands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while(!neighbors.empty()){
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col=rc.second;
                        if (row-1 >=0 && grid[row-1][col] == '1'){
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row+1 < nr && grid[row+1][col] == '1'){
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col-1 >=0 && grid[row][col-1] == '1'){
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col+1 < nc && grid[row][col+1] == '1'){
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};