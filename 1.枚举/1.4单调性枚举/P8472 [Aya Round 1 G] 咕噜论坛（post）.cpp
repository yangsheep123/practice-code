//P8472 [Aya Round 1 G] 咕噜论坛（post）

#include<bits/stdc++.h>
using namespace std;

// 如果改G为B，则B：0，G：1，P：K+1
// BBGB  0010
// GBBB  1000
// PGPP  K1KK
// 求和小于等于k的最大子矩阵
// G B:0 G:1 P:K+1
// B B:1 G:0 P:K+1
// P B:K+1 G:K+1 P:0

int ans = 0;
tuple<char,int,int,int,int> res;
int n,m,k;


void add(int B,int G,int P,vector<string>& maze){
    vector<int> v(128);
    char c = 'P';
    v['B'] = B;
    v['G'] = G;
    v['P'] = P;
    for(int x1 = 0;x1<n;x1++){
        vector<int> sum(m);
        for(int x2=x1;x2<n;x2++){
            for(int i=0;i<m;i++){
                sum[i] += v[maze[x2][i]];
            }
            int total = 0;
            for(int l=0,r=0;l<m;){
                while(total<=k&&r<m){
                    total += sum[r++];
                }
                if(total>k){
                    int t = (x2-x1+1)*(r-l-1);
                    if(ans>=t);
                    else{
                        ans = t;
                        if(B==0) c= 'B';
                        else if(B==1) c = 'G';
                        res = {c,x1,l,x2,r-2};
                    }
                }else{
                    int t = (x2-x1+1)*(r-l);
                    if(ans>=t);
                    else{
                        ans = t;
                        if(B==0) c= 'B';
                        else if(B==1) c = 'G';
                        res = {c,x1,l,x2,r-1};
                    }
                }
                total -= sum[l++];
            }
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m>>k;
    vector<string> maze(n);
    for(int i=0;i<n;i++)
        cin>>maze[i];
    add(0,1,k+1,maze);
    add(1,0,k+1,maze);
    add(k+1,k+1,0,maze);
    cout<<ans<<endl;
    int x1,x2,l,r;
    char c = get<0>(res);
    x1 = get<1>(res);
    l = get<2>(res);
    x2 = get<3>(res);
    r = get<4>(res);
    if(c!='P')
        for(int i=x1;i<=x2;i++){
            for(int j=l;j<=r;j++)
                maze[i][j] = c;
        }
    for(int i=0;i<n;i++){
        cout<<maze[i];
        cout<<endl;
    }
}
