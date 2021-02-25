/*

给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {      // 双指针 + 回溯
private:
    vector<vector<string>> res;
    vector<string> path;

    void backtrack(const string&s, int startIndex){
        if (startIndex >= s.size()){
            res.push_back(path);
            return;
        }

        for(int i=startIndex; i<s.size(); i++){
            if (isPalindrome(s, startIndex, i)){
                string str = s.substr(startIndex, i-startIndex+1);
                path.push_back(str);
            }else continue;
            backtrack(s, i+1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string& s, int start, int end){
        for(int i=start, j= end; i<j; i++, j--){
            if (s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        backtrack(s, 0);
        return res;
    }
};