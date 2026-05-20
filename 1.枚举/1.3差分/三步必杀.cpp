#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<long long> a(N);


int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    int l,r,s,e;
    int d;
    while(m--){
        scanf("%d%d%d%d",&l,&r,&s,&e);
        d = (e-s)/(r-l);
        a[l] += s;
        a[l+1] += d-s;
        a[r+1] -= (e+d);
        a[r+2] += e;
    }
    // cout<<a.size()<<endl;
    for(int i = 1;i<=n;i++){
        a[i] += a[i-1];
    }
    for(int i = 1;i<=n;i++){
        a[i] += a[i-1];
    }
    long long ans = 0;
    for(int i=1;i<=n;i++){
        ans ^= a[i];
    }
    long long maxx = 0;
    for(int i=1;i<=n;i++){
        if(a[i]>maxx) maxx=a[i];
    }
    cout<<ans<<' '<<maxx<<endl;
}