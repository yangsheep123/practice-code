#include<bits/stdc++.h>
using namespace std;

// min(leftMax,rightMax)-h[i]
// [0,l]  leftMax     [r,n-1]  rightMax
// 在l处   leftMax,rightMax:[l,n-1]
// l变大,leftMax一定变大;r变小,rightMax也一定变大
// 是单调递增模型
// if(leftMax<rightMax) leftMax-h[l]
// if(leftMax>rightMax) rightMax-h[r]


class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int leftMax = h[0];
        int rightMax = h[n-1];
        int sum = 0;
        for(int l=1,r=n-2;l<n-1&&r>0&&l<=r;){
            leftMax = max(leftMax,h[l]);
            rightMax = max(rightMax,h[r]);
            if(leftMax<rightMax) 
                sum += leftMax-h[l++];
            else sum += rightMax-h[r--];
        }
        return sum;
    }
};