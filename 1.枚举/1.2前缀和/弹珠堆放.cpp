#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> pre(1000000);
    pre[0]=0;
    pre[1]=1,pre[2]=4,pre[3]=10,pre[4]=20;
    vector<int> a(1000000);
    a[0]=0,a[1]=1,a[2]=3,a[3]=6,a[4]=10;
    int dis=5,i=5;
    while(1){
        a[i]=a[i-1]+dis;
        dis++;
        pre[i]=pre[i-1]+a[i];
        if(pre[i]>=20230610) break;
        i++;
    }
    cout<<i-1;
    return 0;
}
