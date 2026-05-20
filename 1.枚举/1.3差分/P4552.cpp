#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long ll;
vector<ll> a(N);


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=n-1;i>0;i--)
        a[i] = a[i] - a[i-1];
    ll pos=0,neg=0;
    for(int i=1;i<n;i++){
        if(a[i]>0) pos+=a[i];
        else if(a[i]<0) neg-=a[i];

    }
    ll ans1 = max(pos,neg);
    ll ans2 = abs(pos-neg)+1;
    cout<<ans1<<endl<<ans2<<endl;
}