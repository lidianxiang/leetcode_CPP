/*

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1：

输入："hello"
输出："holle"
示例 2：

输入："leetcode"
输出："leotcede"

*/

#include<iostream>
using namespace std;

class Solution   // 双指针法
{
public:  
    string reverseVowels(string s)
    {
        if (s.empty())
        {
            return s;
        }

        unordered_set vowelDict = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !vowelDict.count(s[left]))
            {
                ++left;
            }
            while (left < right && !vowelDict.count(s[right]))
            {
                --right;
            }
            if (s[left] != s[right])
            {
                swap(s[left], s[right]);
            }
            --right;
            ++left;
        }
        return s;
    }
};