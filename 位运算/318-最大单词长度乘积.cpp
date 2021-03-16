/*

给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

示例 1:

输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16 
解释: 这两个单词为 "abcw", "xtfn"。
示例 2:

输入: ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4 
解释: 这两个单词为 "ab", "cd"。
示例 3:

输入: ["a","aa","aaa","aaaa"]
输出: 0 
解释: 不存在这样的两个单词。

*/


#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>


class Solution{
        /*
            1、为每一个字符串使用一个长度为26的二进制数字，每一个二进制数字表示
               当前字符串中是否出现了这个字母
            2、用一个哈希表来表示一个字符串二进制数字与其长度的对应关系
        */
public:
    int maxProduct(vector<string>& words){
        unordered_map<int, int> hash;
        int ans(0);
        for(const string& word: words){
            int mask = 0, size = word.size();
            for(const char& c: word){
                mask |= 1 << (c - 'a');
            }

            hash[mask] = max(hash[mask], size);
            for(const auto& [h_mask, h_len]: hash){
                if (!(mask & h_mask)){
                    ans = max(ans, size * h_len);
                }
            }
        }
        return ans;
    }
};