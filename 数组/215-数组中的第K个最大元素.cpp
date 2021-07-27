/*

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {     // 快速选择算法
public:
    int quickSelect(vector<int>& a, int l, int r, int index){
        int q = randomPartition(a, l, r);
        if (q == index){
            return a[q];
        }else{
            return q < index ? quickSelect(a, q+1, r ,index): quickSelect(a, l, q-1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r){
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r){
        int x = a[r], i = l - 1;
        for(int j=l; j < r; ++j){
            if (a[j] <= x){
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size()-1, nums.size() - k);
    }
};