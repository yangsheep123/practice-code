#include<bits/stdc++.h>
using namespace std;

bool is_leap(int x){
    if((x%4==0&&x%100!=0)||(x%400==0))
        return true;
    return false;
}


int main(){
    int y=2000,m=1,d=1;
    int ans=1;
    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//days[0]不用
    while(y<2000000){
        if(is_leap(y)) days[2]=29;
        else days[2]=28;
        if(y%m==0&&y%d==0) ans++;
        d++;
        if(d>days[m]){
            m++;
            d=1;
        } 
        if(m>12) m=1,y++;
    }
    cout<<ans;
    return 0;
}