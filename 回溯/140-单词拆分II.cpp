/*

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。

示例 1：
输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]

示例 2：
输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。

示例 3：
输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]

*/

#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>


class Solution {    // 回溯，但代码会超时
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        backtrack(s, 0, dict, "", res);
        return res;
    }

    void backtrack(string& s, int start, unordered_set<string>& dict, string cur, vector<string>& res){
        if (start == s.size()){
            res.push_back(cur.substr(1));
            return;
        }

        for(int i=start; i<s.size(); i++){
            auto prefix = s.substr(start, i-start+1);
            if (dict.count(prefix)){
                backtrack(s, i+1, dict, cur + ' '+ prefix, res);
            }
        }
    }
};



class Solution2{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        return backtrack(s, 0, dict);
    }
private:
    unordered_map<int, vector<string>> memo;
    vector<string> backtrack(string& s, int start, unordered_set<string>& dict){
        if (start == s.size()){
            return {""};
        }

        if (memo.count(start)){
            return memo[start];
        }

        vector<string> res;
        for (int i=start; i<s.size(); i++){
            auto prefix = s.substr(start, i-start+1);
            if(dict.count(prefix)){
                auto suffixes = backtrack(s, i+1, dict);
                for(const auto& suffix: suffixes){
                    auto str = prefix;
                    if (!suffix.empty()){
                        str += ' ' + suffix;
                    }
                    res.push_back(str);
                }
            }
        }
        memo[start] = res;
        return memo[start];
    }
};
