#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=height.size();
    int ans=0,j;
    for(int i=0;i<n;i++){
        j=i+1;
        while(height[i]>height[j]){
            ans+=height[i]-height[j];
            j++;
        }
    }
    cout<<ans;

    return 0;
}