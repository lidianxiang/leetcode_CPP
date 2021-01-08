/*

给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

提示：

num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式

*/


#include<iostream>
using namespace std;
#include<algorithm>



class Solution{    // 模拟法
public:
    string addStrings(string num1, string num2){
        int i = num1.length();
        int j = num2.length();
        int add = 0;   // 进位标志
        string ans = "";

        while(i>=0 || j>=0 || add !=0){
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};