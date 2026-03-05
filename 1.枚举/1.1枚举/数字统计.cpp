#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    cin>>l>>r;
    int ans=0;
    for(int i=l;i<=r;i++){
        int t=i;
        while(t){
            if(t%10==2)
                ans++;
            t/=10;
        }
    }
    cout<<ans;
    return 0;
}