/*

给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

 

注意：

你可以假设两个字符串均只含有小写字母。

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/

#include<iostream>
using namespace std;



class Solution{     // 哈希表
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int record[26] = {0};
        for (int i = 0; i < magazine.length(); ++i)
        {
            record[magazine[i] - 'a']++;
        }

        for (int j = 0; j < ransomNote.length(); ++j)
        {
            record[ransomNote[j] - 'a']--;
            if (record[ransomNote[j] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};