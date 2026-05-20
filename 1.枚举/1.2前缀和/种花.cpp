#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
typedef long long ll;
//sum_right[x][y]:往右边看，有多少个连续的0
//sum_up[x][y]:往上看，有多少sum_right的总和
//sum_down[x][y]:往下看，有多少个连续的0

void debug(vector<vector<int> >& x){
    int n = x.size(), m = x[0].size();
    for(int i = 0; i<n;i++){
        for(int j=0;j<m;j++)
            cout<<x[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}


int main(){
    int T,id;
    cin.tie(0)->sync_with_stdio(false);
    cin>>T>>id;
    int n,m,c,f;
    
    while(T--){
        cin>>n>>m>>c>>f;
        vector<string> maze(n);
        for(int i=0;i<n;i++)
            cin>>maze[i];
        // vector<int >(m,0):每个元素都是一个长度为m的vector，且初始化为0
        vector<vector<int> > sum_right(n,vector<int >(m+1,0));
        for(int i = 0; i < n ; i++){
            for(int j = m-1; j >=0 ; j--){
                if(maze[i][j] == '0')
                    sum_right[i][j] = sum_right[i][j+1] + 1;

            }
        }
        // debug(sum_right);
        vector<vector<int> > sum_up(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j]=='0'){
                    if(i) sum_up[i][j] = sum_up[i-1][j];
                    sum_up[i][j] +=  sum_right[i][j] - 1;
                }
            }
        }
        // debug(sum_up);

        vector<vector<int> > sum_down(n+1,vector<int>(m,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(maze[i][j] == '0')
                    sum_down[i][j] = sum_down[i+1][j] + 1; 
            }
        }
        // debug(sum_down);
        ll cntc = 0,cntf=0;
        for(int i = 2;i<n;i++){
            for(int j=0;j<m;j++){
                //不需要判断maze[i-2][j],因为sum_up[i-2][j]直接就是0
                if(maze[i][j]=='1'||maze[i-1][j]=='1') continue;
                //sum_right[i][j]和sum_down[i][j]还算了自己本身，所以要减掉
                cntc += sum_up[i-2][j] * (sum_right[i][j]-1);
                cntf += 1ll*sum_up[i-2][j] * (sum_right[i][j]-1) * (sum_down[i][j]-1);
            }
        }
        cntc*=c;
        cntf*=f;
        cntc %= mod;
        cntf %= mod;
        cout<<cntc <<' '<<cntf<<endl;

    }

}