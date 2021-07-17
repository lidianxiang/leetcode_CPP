/*

你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

示例 1：
输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。

示例 2：
输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
输出：false
解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {    // dfs
private:
    vector<vector<int>> edges;
    // 0表示未搜索，1表示搜索中，2表示已完成搜索
    vector<int> visited;
    bool valid = true;
public:

    void dfs(int u){
        visited[u] = 1;
        for(int v: edges[u]){
            if (visited[v] == 0){
                dfs(v);
                if (!valid){
                    return;
                }
            }
            else if (visited[v] == 1){
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info: prerequisites){
            edges[info[1]].push_back(info[0]);
        }
        for(int i=0; i<numCourses && valid; ++i){
            if (!visited[i]){
                dfs(i);
            }
        }
        return valid;
    }
};



class Solution2{     // bfs
private:
    vector<vector<int>> edges;
    vector<int> indeg;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(const auto& info: prerequisites){
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if (indeg[i] == 0){
                q.push(i);
            }
        }

        int visited = 0;
        while(!q.empty()){
            ++visited;
            int u = q.front();
            q.pop();
            for(int v: edges[u]){
                --indeg[v];
                if (indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};