#include<bits/stdc++.h>
using namespace std;
const int M = 1000010;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int l,r,k;
    long long cnt = 0;
    vector<vector<int> > colors(4,vector<int>(n+2,0));
    while(m--){
        cin>>l>>r>>k;
        colors[k][l] ++;
        colors[k][r+1] --;
    }
    for(int i=1;i< 4;i++){
        for(int j=1;j<=n;j++){
            colors[i][j] += colors[i][j-1];
        }
    }
    for(int j = 1;j <= n;j++){
        if(colors[1][j]&&colors[2][j]&&!colors[3][j])
            cnt++;
    }
    cout<<cnt;
}