/*

给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

示例 1:

输入: "USA"
输出: True
示例 2:

输入: "FlaG"
输出: False

*/


#include<iostream>
using namespace std;


class Solution{
public:
    detectCapitalUse(string word){
        int uc = 0;  // 记录大写字母的个数
        for(int i=0; i<word.size(); i++){
            // 当遍历时，大写字母的个数小于正在遍历的下标时，说明不符合题意，即AaAa的形式
            if (isupper(word[i]) && uc++ < i){
                return false;
            }
        }
        return uc == word.size() || uc <= 1;
    }
};