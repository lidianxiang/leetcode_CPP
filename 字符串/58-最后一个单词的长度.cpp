/*

给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

示例:

输入: "Hello World"
输出: 5

*/


#include<iostream>
using namespace std;


class Solution{   // 从尾到头遍历字符串
public:
    int lengthOfLastWord(string s){
        if (s.size() == 0){
            return 0;
        }

        int count = 0;   //  统计字符长度
        for(int i=s.size()-1; i>=0; i--){
            if (s[i] == ' '){  // 当出现空格
                if (count = 0){  // 判断是不是最后末尾的那个空格
                    continue;  // 是的话，跳过去
                }
                break;  // 否则的话，说明统计好了最后一个单词
            }
            count++;  // 没有出现空格的话，就count加一
        }
        return count;
    }
};