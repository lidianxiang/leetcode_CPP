/*

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。 

示例：

s = "leetcode"
返回 0

s = "loveleetcode"
返回 2

*/


#include<iostream>
using namespace std;
#include<unordered_map>
#include<queue>


class Solution
{
public:
    int firstUniqChar(string s)    // 哈希表
    {

        unordered_map<char, int> frequency;
        // int frequency[129] = {0};
        for (char ch : s)
        {
            frequency[ch]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (frequency[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};


class Solution2{
public:
    int firstUniqueChar(string s){
        unordered_map<char, int> position;
        queue<pair<char, int>> q;
        for (int i = 0; i < s.size(); i++)
        {
            if (!position.count(s[i]))
            {
                position[s[i]] = i;
                q.emplace(s[i], i);
            }
            else
            {
                position[s[i]] = -1;
                while (!q.empty() && position[q.front().first] == -1)
                {
                    q.pop();
                }
            }
        }
        return q.empty() ? -1 : q.front().second;
    }
};