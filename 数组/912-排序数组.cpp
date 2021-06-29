/*

给你一个整数数组 nums，请你将该数组升序排列。

示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]

示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {    // 快速排序
public:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[right];
        int i = left - 1;
        for(int j=left; j<=right-1; j++){
            if (nums[j] <= pivot){
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[right]);
        return i+1;
    }

    int randomized_partition(vector<int>& nums, int left, int right){
        int i = rand() % (right - left + 1) + left;
        swap(nums[right], nums[i]);
        return partition(nums, left, right);
    }

    void randomized_quicksort(vector<int>& nums, int left, int right){
        if (left < right){
            int pos = randomized_partition(nums, left, right);
            randomized_quicksort(nums, left, pos - 1);
            randomized_quicksort(nums, pos + 1, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};


class Solution2{    // 堆排序
private:
    void maxHeapify(vector<int>& nums, int i, int len){
        for(; (i << 1) + 1 <= len;){
            int lson = (i << 1) + 1;
            int rson = (i << 1) + 2;
            int large;
            if (lson <= len && nums[lson] > nums[i]){
                large = lson;
            }else{
                large = i;
            }
            if (rson <= len && nums[rson] > nums[large]){
                large = rson;
            }
            if (large != i){
                swap(nums[i], nums[large]);
                i = large;
            }else{
                break;
            }
        }
    }

    void buildMaxHeap(vector<int>& nums, int len){
        for(int i=len/2; i>= 0; --i){
            maxHeapify(nums, i, len);
        }
    }

    void heapSort(vector<int>& nums){
        int len = (int) nums.size()-1;
        buildMaxHeap(nums, len);
        for(int i=len; i>=1; --i){
            swap(nums[i], nums[0]);
            len -= 1;
            maxHeapify(nums, 0, len);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums){
        heapSort(nums);
        return nums;
    }
};


class Solution{    // 归并排序
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int left, int right){
        if (left >= right) return;
        int mid = (left + right) >> 1;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        int i = left, j = mid + 1;
        int cnt = 0;
        while(i <= mid && j <= right){
            if (nums[i] <= nums[j]){
                tmp[cnt++] = nums[i++];
            }else{
                tmp[cnt++] = nums[j++];
            }
        }
        while( i<= mid){
            tmp[cnt++] = nums[i++];
        }
        while(j <= right){
            tmp[cnt++] = nums[j++];
        }
        for(int i=0; i<right-left+1; i++){
            nums[i+left] = tmp[i];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums){
        tmp.resize((int)nums.size(), 0);
        mergeSort(nums, 0, (int)nums.size()-1);
        return nums;
    }
};