#include<bits/stdc++.h>
using namespace std;

bool is_luck(int x){
    int p = 0;//p表示位数
    int tmp=x;
    while(tmp){
        tmp /= 10;
        p++;
    }
    if(p%2!=0) return false;
    int now=0;
    for(int i=0;i<p/2;i++){
        now+=x%10;
        x /= 10;
    }
    for(int i=0;i<p/2;i++){
        now-=x%10;
        x/=10;
    }
    if(now==0) return true;
    return false;
}

int main(){
    int ans = 0;
    for(int i=1;i<=100000000;i++){
        if(is_luck(i))
            ans++;
    }
    cout<<ans;
}