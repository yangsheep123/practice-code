//数字1 2 3 4 5
//位数5 4 3 2 1

#include<bits/stdc++.h>
using namespace std;

//x%10:取x的最低位，x/10：去掉x的最低位

bool is_good(int x){
    int p=1; //p表示当前位数，从最低位开始
    while(x){
        int t = x % 10;
        if((t % 2 ) == (p % 2)){
            p++;
            x /= 10;
            continue;
        }
        else return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(is_good(i)){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}