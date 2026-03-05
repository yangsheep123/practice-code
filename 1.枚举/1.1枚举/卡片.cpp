#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt[10];
    for(int i=0;i<10;i++)
        cnt[i]=2021;
    bool flag=true;
    int num;
    for(num=1; ; num++){
        int x=num;
        while(x){
            cnt[x%10]--;
            if(cnt[x%10]<0){
                flag=false;
                break;
            }
            x /= 10; 
        }
        if(flag==false) break;
    }
    cout<< num-1 <<endl;
    return 0;
}
