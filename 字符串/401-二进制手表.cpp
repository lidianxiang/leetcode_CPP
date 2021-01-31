/*

二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。

每个 LED 代表一个 0 或 1，最低位在右侧。

例如，上面的二进制手表读取 “3:25”。

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

示例：

输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

*/


#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:
     vector<string> readBinaryWatch(int num) {
        vector<string> res;
        // 直接遍历 0:00 -> 12:00
        for(int i=0; i<12; i++){  // i表示小时
            for(int j=0; j<60; j++){   // j表示分钟
                if (countl(i) + countl(j) == num){
                    res.push_back(to_string(i) + ":" + (j< 10? "0"+to_string(j): to_string(j)));
                }
            }
        }
        return res;
    }
    // 计算将n转为二进制后，其中1的个数
    int countl(int n){
        int res = 0;
        while(n != 0){
            n = n & (n-1);  // 计算二进制中1的个数
            res++;
        }
        return res;
    }
};