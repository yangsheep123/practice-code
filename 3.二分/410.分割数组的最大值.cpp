/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

bool match(vector<int>& nums, int k,int x){
    int sum = 0;
    int cnt = 1;
    for(auto& num:nums){
        if(sum+num>x){
            cnt++;
            sum = num;
            if(cnt>k) return false;
        }else{
            sum += num;
        }
    }
    return true;
}


class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0,high = INT_MAX;
        for(auto& num:nums)
            low = max(low,num);
        while(low<=high){
            int mid = low + (high - low)/2;
            if(match(nums,k,mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
// @lc code=end

