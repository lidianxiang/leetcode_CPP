/*

中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2

*/


#include<iostream>
using namespace std;
#include<vector>


class MedianFinder{   // sort排序
private:
    vector<double> store;
public:
    MedianFinder(){

    }

    void addNum(int num){
        store.push_back(num);
    }

    double findMedian(){
        sort(store.begin(), store.end());
        int n = store.size();
        return (n & 1 ? store[n/2-1]: (store[n/2-1] + store[n/2]) * 0.5);
    }
};


class MedianFinder{    // 插入排序
    vector<double> store;
public:
    MedianFinder(){

    }

    void addNum(int num){
        if (store.empty())
            store.push_back(num);
        else    
            store.insert(lower_bound(store.begin(), store.end(), num), num);
    }

    double findMedian(){
        int n = store.size();
        return (n & 1 ? store[n/2]: (store[n/2 - 1] + store[n/2]) * 0.5);
    }

}