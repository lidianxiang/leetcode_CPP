/*

给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:

输入: "abab"

输出: True

解释: 可由子字符串 "ab" 重复两次构成。
示例 2:

输入: "aba"

输出: False
示例 3:

输入: "abcabcabcabc"

输出: True

解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)

*/


#include<iostream>
using namespace std;


class Solution{       // 字符串匹配
public:
    bool repeatedSubstringPattern(string s){
        /*
            我们可以把字符串s写成： s's'......s's‘的形式，总计n/n'个s'.
            如果移除前n'个字符（即一个完整的s'）,再将这些字符保持顺序添加到剩余字符串的末尾，那么得到的字符串仍是s。
            所以，如果将两个s连在一起，并移除掉第一个和最后一个字符，那么得到的字符串一定包含s，即s是它的一个字串。
        */
        return (s+s).find(s, 1) != s.size();
    }
};