/*

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{     // 位运算
        /*
        
        对每一个元素x：
                第一次出现时，once为0，twice为0，导致once被更新为x，twice依旧是0
                第二次出现时，once被更新为0，twice被更新为0
                第三次出现时，once保持为0，twice更新为0
        所以所有出现三次的元素都不会改变once和twice的值，而仅出现一次的值会使得once被更新为x，而twice不受影响。
        
        */
public:
    int singleNumber(vector<int>& nums){
        int once = 0, twice = 0;
        for(auto num: nums){
            once = (once ^ num) & (~twice);
            twice = (twice ^ num) & (~once);
        }
        return once;
    }
};