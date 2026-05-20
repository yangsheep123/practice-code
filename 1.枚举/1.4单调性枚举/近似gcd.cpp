#include<bits/stdc++.h>
using namespace std;

// a[i]是g的公倍数，记为0，不是g的公倍数，记为1
// 1 3 6 4 10 g=3
// 1 0 0 1 1
// 变成区间内的和<2
// 单调性

int main(){
    int n,g;
    cin>>n>>g;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%g==0) a[i]=0;
        else a[i]=1;
    }
    int sum =0;
    long long ans=0;
    for(int l=0,r=0;l<n;){
        while(sum<2&&r<n){
            sum+=a[r++];
        }
        if(sum>=2){
            //(l,r-2]
            if(r-2==l) ans += 0;
            else ans += r-2-l;
        }else{//[l,r-1]
            if(l==r-1) ans +=0 ;
            else ans += r-l-1;
        }
        sum-=a[l++];
    }
    cout<<ans<<endl;
    
}