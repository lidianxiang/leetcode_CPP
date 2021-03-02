/*

给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ）空就是没有下一个结点了。

示例 1：
输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3

示例 2：
输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

示例 3：
输入：graph = [[1],[]]
输出：[[0,1]]

示例 4：
输入：graph = [[1,2,3],[2],[3],[]]
输出：[[0,1,2,3],[0,2,3],[0,3]]

示例 5：
输入：graph = [[1,3],[2],[3],[]]
输出：[[0,1,2,3],[0,3]]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {    // 回溯
public:
    void dfs(vector<vector<int>>& graph, vector<int> path, vector<vector<int>>& res, int p){
        for(int i=0; i<graph[p].size(); i++){
            if (graph[p][i] == graph.size()-1){
                path.push_back(graph.size()-1);
                res.push_back(path);
                path.pop_back();
                continue;
            }
            path.push_back(graph[p][i]);
            dfs(graph, path, res, graph[p][i]);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path={0};
        dfs(graph, path, res, 0);
        return res;
    }
};