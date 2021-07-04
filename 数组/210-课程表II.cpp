/*

现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

示例 1:
输入: 2, [[1,0]] 
输出: [0,1]
解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。

示例 2:
输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{     // dfs深度优先搜索 + 栈
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态： 0表示未搜索，1表示搜索中，2表示已完成
    vector<int> visited;
    // 用数组来模拟栈，下标0为栈底，下标n-1为栈顶
    vector<int> result;
    // 判断有向图是否有环
    bool visited = true;

public:
    void dfs(int u){
        // 将节点标记为搜索中
        visited[u] = 1;
        // 搜索其相邻节点
        // 只要发现有环，立刻停止搜索
        for(int v: edges[u]){
            // 如果未搜索，那么搜索相邻节点
            if (visited[v] == 0){
                dfs(v);
                if (!valid){
                    return;
                }
            }
            // 如果搜索中说明找到了环
            else if (visited[v] == 1){
                valid = false;
                return;
            }
        }
        // 将节点标记为已完成
        visited[u] = 2;
        // 将节点入栈
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info: prerequisites){
            edges[info[1]].push_back(info[0]);
        }
        // 每次挑选一个未搜索的节点，开始进行深度优先搜索
        for(int i=0; i<numCourses && valid; i++){
            if (!visited[i]){
                dfs(i);
            }
        }
        if (!valid){
            return {};
        }
        // 如果没有环，那么就有拓扑排序
        // 注意下标0为栈底，因此需要将数组反序输出
        reverse(result.begin(), result.end());
        return result;
    }
};