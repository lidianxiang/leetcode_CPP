/*

你将得到一个字符串数组 A。

每次移动都可以交换 S 的任意两个偶数下标的字符或任意两个奇数下标的字符。

如果经过任意次数的移动，S == T，那么两个字符串 S 和 T 是 特殊等价 的。

例如，S = "zzxy" 和 T = "xyzz" 是一对特殊等价字符串，因为可以先交换 S[0] 和 S[2]，然后交换 S[1] 和 S[3]，使得 "zzxy" -> "xzzy" -> "xyzz" 。

现在规定，A 的 一组特殊等价字符串 就是 A 的一个同时满足下述条件的非空子集：

该组中的每一对字符串都是 特殊等价 的
该组字符串已经涵盖了该类别中的所有特殊等价字符串，容量达到理论上的最大值（也就是说，如果一个字符串不在该组中，那么这个字符串就 不会 与该组内任何字符串特殊等价）
返回 A 中特殊等价字符串组的数量。

示例 1：

输入：["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
输出：3
解释：
其中一组为 ["abcd", "cdab", "cbad"]，因为它们是成对的特殊等价字符串，且没有其他字符串与这些字符串特殊等价。
另外两组分别是 ["xyzz", "zzxy"] 和 ["zzyx"]。特别需要注意的是，"zzxy" 不与 "zzyx" 特殊等价。
示例 2：

输入：["abc","acb","bac","bca","cab","cba"]
输出：3
解释：3 组 ["abc","cba"]，["acb","bca"]，["bac","cab"]

*/

#include<iostream>
using namespace std;
#include<unordered_set>
#include<vector>
#include<algorithm>


class Solution{     // 集合
public:
    int numSpecialEquivGroups(vector<string>& A){
        unordered_set<string> set;
        for(const auto& str: A){
            string even, odd;
            // 只需要统计每个单词的奇数位的单词和偶数位的单词是否相同即可
            for(int i=0; i<str.size(); i++){
                if (i%2){
                    odd += str[i];
                }else{
                    even += str[i];
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            set.insert(odd+even);
        }
        return set.size();
    }
};