#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i,j;
        vector<int> ans(2);
        for(i=0,j=n-1;i<n-1,j>0;){
            if(numbers[i]+numbers[j]<target){
                i++;
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
            }
            else{
                ans[0]=i+1;
                ans[1]=j+1;
                break;
            }
        }
        return ans;
    }
};