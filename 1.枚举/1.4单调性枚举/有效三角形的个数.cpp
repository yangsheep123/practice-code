#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     int k,j;
//     int ans=0;
//         // 先对数组进行排序，遍历两条较短的边，使得两边之和小于第三条边
//     sort(nums.begin(),nums.end());
//         // 找到最大的k，使得nums[k]<nums[i]+nums[j]
//         // 则从[j+1]到[k]的位置，都可以组合成三角形的三条边
//     for(int i=0;i<n-2;i++){
//         k = i+2;
//         for(j = i+1;j<n-1;j++){
//             while(k<n&&nums[k]<nums[i]+nums[j])
//                 k++;
//             // 因为j在初始赋值的时候可能会比k大
//             ans += max(k-j-1,0);
//         }
//     }
//     cout<<ans;
// }


//枚举最大边
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i,j,k,ans=0;
        for(k=n-1;k>=2;k--){
            i = 0,j = k-1;
            while(i<j){
                if(nums[k]<nums[i]+nums[j]){
                    // 如果当前i可以满足，那么i往右走就更加满足
                    // 因此i可以取[i,j-1]的位置
                    ans += j-i;
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};