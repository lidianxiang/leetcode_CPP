/*

请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：
输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]

示例 2：
输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]

*/


#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<deque>


class MaxQueue{
    int q[20000];
    int begin = 0, end = 0;
public:
    MaxQueue(){

    }

    int max_value(){
        int ans = -1;
        for(int i=begin; i != end; i++){
            ans = max(ans, q[i]);
        }
        return ans;
    }

    void push_back(int value){
        q[end++] = value;
    }

    int pop_front(){
        if (begin == end){
            return -1;
        }
        return q[begin++];
    }
}


class MaxQueue{    // 维护一个单调的双端队列
    queue<int> q;
    deque<int> d;
public:
    MaxQueue(){

    }
    int max_value(){
        if (d.empty())
            return -1;
        return d.front();
    }

    void push_back(int value){
        while( !d.empty() && d.back() < value){
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front(){
        if (q.empty()){
            return -1;
        }
        int ans = q.front();
        if (ans == d.front()){
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};