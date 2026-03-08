#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    vector<int> a(2e6+1);//存储坐标为正的矿洞
    vector<int> b(2e6+1);//存储坐标为负的矿洞
    int flag=0;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==0) flag++;
        //如果坐标i处有矿洞，则记为1，否则记为0
        else if(x>0) a[x]++;
        else b[-x]++;
    }
    //计算前缀和，记录从原点到矿洞i一共可以采集多少矿石
    for(i=1;i<1e6+1;i++){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    int ans=0;
    int step;
    for(step=0;step<=m;step++){
        //先向右走，再往左走
        if(m>=step*2){
            ans=max(ans,a[step]+b[m-step*2]);
        }
        else ans=max(ans,a[step]);   
            
    }

    for(step=0;step<=m;step++){
        //先向左走，再往右走
        if(m>=step*2){
            ans=max(ans,b[step]+a[m-step*2]);
        }
        else ans=max(ans,b[step]);
    }
    ans+=flag; 
    cout<<ans;
    return 0;
}