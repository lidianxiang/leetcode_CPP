/*

爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：

选出任一 x，满足 0 < x < N 且 N % x == 0 。
用 N - x 替换黑板上的数字 N 。
如果玩家无法执行这些操作，就会输掉游戏。

只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 False。假设两个玩家都以最佳状态参与游戏。

示例 1：

输入：2
输出：true
解释：爱丽丝选择 1，鲍勃无法进行操作。
示例 2：

输入：3
输出：false
解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{    // 数学归纳总结
public:
    bool divisionGame(int N){
        return N % 2 == 0;
    }
};


class Solution2{    // 动态规划
public:
    bool divisionGame(int N){
        vector<int> f(N+5, false);

        f[1] = false;
        f[2] = true;
        for(int i=3; i<=N; i++){
            for(int j=1; j<i; j++){
                if (i % j == 0 && !f[i-j]){
                    f[i] = true;
                    break;
                }
            }
        }
        return f[N];
    }
};