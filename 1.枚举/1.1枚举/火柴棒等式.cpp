#include<bits/stdc++.h>
using namespace std;

int f(int x){
    int stick[10]={6,2,5,5,4,5,6,3,7,6};
    if(x==0) return 6;
    int p=0;
    while(x){
        p+=stick[x%10];
        x/=10;
    }
    return p;
}

int main(){
    int n;
    cin>>n;
    int ans=0;
    
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(f(i)+f(j)+f(i+j)+4==n) ans++;
        }
    }
    cout<<ans;
    return 0;
}