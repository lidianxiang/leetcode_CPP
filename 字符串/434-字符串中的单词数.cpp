/*

统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。

*/


#include<iostream>
using namespace std;


class Solution{
public:
    int countSegments(string s){
        int flag = 1;  // 标志符
        int count = 0;
        for(int i=0; i<s.length(); i++){
            if (s[i] != ' ' && flag){
                count++;
                flag = 0;
            }

            if (s[i] == ' '){
                flag = 1;
            }
        }
        return count;
    }
};