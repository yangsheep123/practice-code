#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
vector<vector<int> > board(N,vector<int>(N,0));
vector<vector<int> > a(N,vector<int>(N,0));

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int x1,y1,x2,y2;
    while(m--){
        cin>>x1>>y1>>x2>>y2;
        board[x1][y1]++;
        board[x2+1][y1]--;
        board[x1][y2+1]--;
        board[x2+1][y2+1]++;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] = board[i][j] + a[i][j-1] + a[i-1][j] - a[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(a[i][j]%2);
        }
        cout<<endl;
    }
}