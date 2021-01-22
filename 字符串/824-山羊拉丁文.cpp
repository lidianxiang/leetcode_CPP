/*

给定一个由空格分割单词的句子 S。每个单词只包含大写或小写字母。

我们要将句子转换为 “Goat Latin”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。

山羊拉丁文的规则如下：

如果单词以元音开头（a, e, i, o, u），在单词后添加"ma"。
例如，单词"apple"变为"applema"。

如果单词以辅音字母开头（即非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
例如，单词"goat"变为"oatgma"。

根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从1开始。
例如，在第一个单词后添加"a"，在第二个单词后添加"aa"，以此类推。
返回将 S 转换为山羊拉丁文后的句子。

示例 1:

输入: "I speak Goat Latin"
输出: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
示例 2:

输入: "The quick brown fox jumped over the lazy dog"
输出: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

*/


#include<iostream>
using namespace std;

class Solution
{
public:
    string toGoatLatin(string S)
    {
        string res = "";             //存储返回值
        string vowel = "aeiouAEIOU"; // 用来判断首字母是否是vowel，直接使用string自带的find函数。
        int count_a = 1;
        for (int i = 0; i < S.size(); i++)
        {
            string str = "";
            while (isalnum(S[i]))
                str += S[i++]; //使用isalnum分割单词
            count_a++;
            if (find(vowel.begin(), vowel.end(), str[0]) == vowel.end()){   // 如果首字母不是aeiou                           
                str += str[0];          //str末尾添加首位字母
                str.erase(str.begin()); //删除首位字母
            }
            res += str + "ma"; //不管首字母是什么都加ma

            for (int j = 1; j < count_a; j++)
                res += "a"; //每个单词count_a++,加在末尾

            if (i < S.size())
                res += " "; //不是最后一个单词就要在单词之间加上空格符
        }
        return res;
    }
};