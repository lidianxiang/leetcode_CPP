/*

在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到或超过 100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？

你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。

示例：

输入：
maxChoosableInteger = 10
desiredTotal = 11

输出：
false

解释：
无论第一个玩家选择哪个整数，他都会失败。
第一个玩家可以选择从 1 到 10 的整数。
如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。

*/


#include<iostream>
using namespace std;
#include <vector>


class Solution{  //  动态规划
public:
    int maxChoosableInteger, desiredTotal;
    map<pair<int, int>, int> mp;

    bool dfs(int state, int sum){
        // 递归边界
        if (sum >= desiredTotal)
            return true;
        // 记忆化
        if (mp.find({state, sum}) != mp.end())
            return mp[{state, sum}];

        int ret = true;
        for(int i=1; i<=maxChoosableInteger; i++){
            if ((state & (1 << i)) == 0){
                // 枚举
                if (dfs(state | (1 << i), sum+i)){
                    ret = false;
                    break;
                }
            }
        }
        return mp[{state, sum}] = ret;
    }

    bool canIWin(int a, int b){
        maxChoosableInteger = a, desiredTotal = b;
        // 如果所有可选的数字想加仍然小于desiredTotal, 则返回false
        if ((a + 1) * a / 2 < b)
            return false;
        for(int i=1; i<=a; i++){
            if (dfs(1 << i, i))
                return true;
        }
        return false;
    }
};