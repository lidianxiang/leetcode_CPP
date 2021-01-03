/*

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

*/

#include<iostream>
using namespace std;
#include<algorithm>


class Solution{    // 双指针法
public:
    bool isPalindrome(string s){   
        string s1;
        for(char ch : s){
            if(isalnum(ch)){   // 去掉标点，仅保留字母和数字
                s1 += tolower(ch);
            }
        }

        int n = s1.size();
        int left = 0, right = n - 1;
        while(left < right){   // 双指针
            if (s1[left] != s1[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};