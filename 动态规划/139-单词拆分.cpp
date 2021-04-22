/*

给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。

示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

*/


#include<iostream>
using namespace std;
#include<unordered_set>


class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict){
        auto wordDictSet = unordered_set<string> ();
        for(auto word: wordDict){
            wordDictSet.insert(word);   // 去重
        }
        auto dp = vector<bool> (s.size()+1);
        dp[0] = true;

        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                if (dp[j] && wordDict.find(s.substr(j,i-j)) != wordDictSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};


class Solution2{    // 动态规划 + 遍历优化（减少无用遍历）
public:
    bool wordBreak(string s, vector<string> wordDict){
        unordered_set<string> wordDictSet;
        int minSize = INT_MAX, maxSize = 0;
        for(auto word: wordDict){
            wordDictSet.insert(word);
            if (word.size() < minSize)  minSize = word.size();
            if (word.size() > maxSize)  maxSize = word.size();
        }

        vector<bool> dp(s.size()+1);
        dp[0] = true;
        for(int i=1; i<=s.size(); i++){
            for(int j=max(i-maxSize, 0); i-j>=minSize; j++){
                if (dp[j] && wordDictSet.find(s.substr(j, i-j)) != wordDictSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};