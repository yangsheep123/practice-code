// P10266
#include<bits/stdc++.h>
using namespace std;
const int N = 3010;
const int offset = 1005;
int n,m;
typedef long long ll;
vector<vector<ll> > maze(N,vector<ll>(N,0));
vector<vector<ll> > dialog(N,vector<ll>(N));
vector<vector<ll> > back_dialog(N,vector<ll>(N));
vector<vector<ll> > total(N,vector<ll>(N,0));

void add_dialog(auto& dialog){
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            dialog[i][j] += dialog[i-1][j-1];
        }
    }
}

void add_back_dialog(auto& back_dialog){
    for(int i=1;i<N;i++){
        for(int j=N-2;j>=0;j--){
            back_dialog[i][j] += back_dialog[i-1][j+1];
        }
    }
}



int main(){
    cin.tie(0)->sync_with_stdio(false);
    int k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>maze[i][j];
    }
    int x,y,p;
    while(k--){
        cin>>x>>y>>p;
        x += offset;
        y += offset;
        dialog[x-p+1][y-p+1] += 1;
        dialog[x-p+2][y-p+2] += 1;
        dialog[x+1][y+1] -= 2;
        dialog[x+2][y+2] -= 2;
        dialog[x+p+1][y+p+1] += 1;
        dialog[x+p+2][y+p+2] += 1;
        back_dialog[x+1][y] +=2;
        back_dialog[x+2][y-1] +=2;
        back_dialog[x+1+p][y-p] -=1;
        back_dialog[x+2+p][y-p-1] -=1;
        back_dialog[x-p+1][y+p] -= 1;
        back_dialog[x-p+2][y+p-1] -= 1;
    }

    add_dialog(dialog);
    add_dialog(dialog);
    add_back_dialog(back_dialog);
    add_back_dialog(back_dialog);


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            total[i][j] = dialog[i][j] + back_dialog[i][j];
        }
    }

    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            total[i][j] = total[i][j] + total[i-1][j] + total[i][j-1] - total[i-1][j-1];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maze[i][j] -= total[i+offset+1][j+offset+1];
            if(maze[i][j]<0) maze[i][j]=0;
            cout<<maze[i][j]<<' ';
        }
        cout<<endl;
    }

}