#include<bits/stdc++.h>
using namespace std;


// h[l],h[r] min(h[l],h[r])*(r-l)
// r变小时,r-l变小，但是min(h[l],h[r])不能确定,所以不符合单调性
//(0,1) (0,2) (0,3) (0,4)
//                  (1,4)
//                  (2,4)
//                  (3,4)
//                  (4,4)
//如果h[0]<h[4]，h[0]*(4-0)
//当r变小的时候，min(h[0],h[r]) * (r-0)
// (r-0)变小，min(h[0],h[r])也一定会变小，所以r不能变小，需要l变大
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l,r;
        int ans = 0;
        for(l=0,r=n-1;r>0;){
            ans = max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]&&l<n){
                l++;
            }
            else r--;
        }
        return ans;
    }
};