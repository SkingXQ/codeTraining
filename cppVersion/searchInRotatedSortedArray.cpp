/*
    Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
    Tips: we can begin with the three kinds of situation:
          s1: 1 2 3 4 5 6 7 
          s2: 2 3 4 5 6 7 1
          s3: 6 7 1 2 3 4 5
          when mid > begin, we turn into s1 and s2, then the left side of mid is sorted.
          when mid < begin, we turn into s1 and s3 , then the right side of mid is sorted.
          the sorted part is easy to check whether the target is sitting in the sorted part.
          we must think the several edge situation; 
          the size of vector is 2 and mid = begin (the same position), so nums[mid]>= nums[begin](no >)
          the target is in the end or begin postion, so nums[begin] <= target
/*
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1;
        int s = nums.size();
        int begin = 0;
        int end = s - 1;
        while(begin <= end) {
            int mid = begin + (end-begin) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[begin]) {
                if(nums[mid] > target && nums[begin] <= target)  end = mid-1;
                else begin = mid+1;
            }else {
                if(nums[mid] < target && nums[end] >= target) begin = mid+1;
                else end = mid-1;
            }
        }
        return -1;
    }
};

int main()  {
    Solution a;
    vector<int> t = {3,1};
    cout<<a.search(t, 1)<<endl;
    return 0;
}
