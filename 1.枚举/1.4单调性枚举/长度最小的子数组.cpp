#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,target;
	
	cin>>n>>target;
    vector<int> nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int r,l,ans=INT_MAX;
    int sum = 0;
    for(r=0,l=0;l<n;){
        if(sum<target && r<n ){
            sum += nums[r++];
        }
        else{
            if(sum>=target){
                ans = min(ans,r-l);
            }
            sum -= nums[l++];
        }
    }
    if(ans==INT_MAX) ans=0;
    cout<<ans;
}
