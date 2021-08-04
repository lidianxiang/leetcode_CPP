/*

给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。

示例 1：
输入：s = "aaabb", k = 3
输出：3
解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。

示例 2：
输入：s = "ababbc", k = 2
输出：5
解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {  
            /*
                分治： 对于字符串s，如果存在某个字符ch，它的出现次数大于0且小于k，则任何包含ch的子串都不可能满足要求
                      也就是说，可以将字符串s按照ch分为若干段，则满足要求的最长子串一定出现在某个被切分的段内，
                      而不能跨越一个或多个。因此可以考虑使用分治的方式来求解此题。
            */
public:

    int dfs(const string s, int left, int right, int k){
        vector<int> cnt(26, 0);
        for(int i=left; i<=right; i++){
            cnt[s[i] - 'a']++;
        }

        char split = 0;
        for(int i=0; i<26; i++){
            if (cnt[i] > 0 && cnt[i] < k){
                split = i + 'a';
                break;
            }
        }

        if (split == 0){
            return right - left + 1;
        }

        int i = left;
        int ret = 0;
        while(i <= right){
            while (i <= right && s[i] == split){
                i++;
            }
            if (i > right){
                break;
            }
            int start = i;
            while (i <= right && s[i] != split){
                i++;
            }
            int length = dfs(s, start, i-1, k);
            ret = max(ret, length);
        }
        return ret;
    }

    int longestSubstring(string s, int k) {
        int n = s.length();
        return dfs(s, 0, n-1, k);
    }
};