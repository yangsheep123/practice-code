#include<bits/stdc++.h>
using namespace std;

const int N = 1e9+10;

void print(auto a){
    int n = a.size();
    cout<<"maze:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m,k,x,y;
    long long z;
    cin>>n>>m>>k;
    // 差分数组尽量多开几个，避免处理边界
    vector<vector<long long>> maze(n+5,vector<long long>(n+5));
    for(int i=0;i<m;i++){        
        cin>>x>>y>>z;
        maze[x][y] += z;
    }
    // print(maze);
    //求数组的差分数组
    for(int i=n;i>0;i--){
        for(int j=n;j>0;j--){
            maze[i][j] = maze[i-1][j-1] - maze[i][j-1] + maze[i][j] - maze[i-1][j];
        }
    }
    // print(maze);
    long long sum = 0;//最少操作数
    //从左上往右下遍历差分数组
    //(i,j) 是最后一个能影响 diff[i][j] 的位置
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //判断差分矩阵是否放的下一个n*n的矩阵，所以是>而不是>=
            // 并且差分矩阵确实比原矩阵要大
            if(maze[i][j]){
                if(i+k>n+1||j+k>n+1){
                    cout<<-1<<endl;
                    return 0;
                }
                sum += abs(maze[i][j]);
                maze[i+k][j] += maze[i][j];
                maze[i][j+k] += maze[i][j];
                maze[i+k][j+k] -= maze[i][j];
                maze[i][j] -= maze[i][j];
            }
        }
    }
    // print(maze);

    cout<<sum<<endl;
    return 0;
    
}
