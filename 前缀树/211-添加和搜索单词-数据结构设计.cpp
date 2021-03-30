/*

211. 添加与搜索单词 - 数据结构设计
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
 

示例：

输入：
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
输出：
[null,null,null,null,false,true,true,true]

解释：
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

*/

#include<iostream>
using namespace std;


class WordDictionary 
{
private:
    bool isEnd;
    WordDictionary* next[26];
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void addWord(string word) {
        WordDictionary* p = this;
        for(auto c: word){
            if (p->next[c-'a'] == nullptr){
                p->next[c-'a'] = new WordDictionary();
            }
            p = p->next[c-'a'];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        return searchWord(this, word);
    }

    bool searchWord(WordDictionary* node, string word)
    {
        if(word.size()==1) {  //边界
            if(isalpha(word[0])) {
                if(node->next[word[0]-'a'] && node->next[word[0]-'a']->isEnd)
                    return true;
                return false;
            }
            else {
                for(int i=0; i<26; i++)
                    if(node->next[i] && node->next[i]->isEnd)
                        return true;
                return false;
            }
        }
        else {
            if(isalpha(word[0])) {
                if(node->next[word[0]-'a'])
                    return searchWord(node->next[word[0]-'a'], word.substr(1, word.size()-1));
                else
                    return false;
            }
            else {
                bool b;
                for(int i=0; i<26; i++) {      
                    if(node->next[i]){
                        b = searchWord(node->next[i], word.substr(1, word.size()-1));
                        if(b)   return true;
                    }
                }
                return false;
            }
        }
    }
};
