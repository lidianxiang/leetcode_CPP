/*

一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：

'A' -> 1
'B' -> 2
...
'Z' -> 26
要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"111" 可以将 "1" 中的每个 "1" 映射为 "A" ，从而得到 "AAA" ，或者可以将 "11" 和 "1"（分别为 "K" 和 "A" ）映射为 "KA" 。注意，"06" 不能映射为 "F" ，因为 "6" 和 "06" 不同。

给你一个只含数字的 非空 字符串 num ，请计算并返回 解码 方法的 总数 。

题目数据保证答案肯定是一个 32 位 的整数。

示例 1：
输入：s = "12"
输出：2
解释：它可以解码为 "AB"（1 2）或者 "L"（12）。

示例 2：
输入：s = "226"
输出：3
解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

示例 3：
输入：s = "0"
输出：0
解释：没有字符映射到以 0 开头的数字。含有 0 的有效映射是 'J' -> "10" 和 'T'-> "20" 。由于没有字符，因此没有有效的方法对此进行解码，因为所有数字都需要映射。

示例 4：
输入：s = "06"
输出：0
解释："06" 不能映射到 "F" ，因为字符串开头的 0 无法指向一个有效的字符。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{   // 动态规划
public:
    int numDecodings(string s){
        if (s[0] == '0')
            return 0;
        vector<int> dp(s.size()+1, 1);
        for(int i=1; i<s.size(); i++){
            if (s[i] == '0'){
                if (s[i-1] != '1' && s[i-1] != '2')
                    return 0;
                else
                    dp[i+1] = dp[i-1];
                    continue;
            }
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')){
                dp[i+1] = dp[i] + dp[i-1];
            }
            else{
                dp[i+1] = dp[i];
            }
        }
        return dp[s.size()];
    }
}


class Solution2 {   // 动态规划（dp[i]仅可能与前两项有关，可以使用单变量代替数组）
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        int pre = 1, curr = 1;
        for(int i=1; i<s.size(); i++){
            // tmp临时保存
            int tmp = curr;
            // 当当前位置为0时
            if (s[i] == '0'){
                // 若前一位是1或2时
                if (s[i-1] == '1' || s[i-1] == '2'){
                    curr = pre;
                }else{
                    return 0;
                }
            // 当当前位不为0时，且前一位为1或是前一位为2当前位大于等于1小于等于6时
            }else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')){
                curr = curr + pre;
            }
            // pre更新
            pre = tmp;
        }
        return curr;
    }
};