#include<bits/stdc++.h>
using namespace std;

//基于前缀和求解
//从左到右记录i点的最大高度
//从右往左记录j点的最大高度
//则i点可存储的雨水单位为min(right_max[i],left_max[i])-height[i]
int main(){
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=height.size();
    vector<int> left_max(n),right_max(n);
    int ans=0;
    for(int i=0;i<n;i++){
        if(i==0) left_max[i]=height[i];
        else left_max[i]=max(left_max[i-1],height[i]);
    }
    for(int j=n-1;j>=0;j--){
        if(j==0) right_max[j]=height[j];
        else right_max[j]=max(right_max[j+1],height[j]);
    }
    for(int row=0;row<n;row++){
        ans+=min(right_max[row],left_max[row])-height[row];
    }
    cout<<ans;
    return 0;
}