/*

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        // 从后往前遍历vector
        for (int i=digits.size() - 1; i >= 0; i--){
            ++digits[i];  // 当前位位加一
            if (digits[i] != 10){  // 当当前位加一后仍然不为10的情况
                return digits;    // 直接返回
            }
            else{   // 若当前位加一后等于10的情况
                digits[i] = 0;  // 当前为的值为设置为0
            }
        }
        digits.insert(digits.begin(), 1);  // 如果首位也为0，则在最前面加一
        return digits;
    }
};