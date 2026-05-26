#include<bits/stdc++.h>
using namespace std;

// 相当于：从区间中选择最多了不重叠的区间个数是多少
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size();
        // x 和 y 代表二维数组中的每一行
        // 根据右端点排序
        sort(a.begin(),a.end(),[](const vector<int> &x,const vector<int> &y){
            return x[1]<y[1];
        });
        int right = -5e4;
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int> interval = a[i];
            if(interval[0]>=right){
                right = interval[1];
                ans++;
            }
        }
        return a.size() - ans;     
    }
};