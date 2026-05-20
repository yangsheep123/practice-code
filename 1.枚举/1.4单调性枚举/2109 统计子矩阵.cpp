#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int> > maze(505,vector<int>(505));
// 复杂度O(N^3)，N最大500，刚好

//[x1,y1]:左上角，[x2,y2]:右下角
ll getSum(int x1,int y1,int x2,int y2){
    return maze[x2][y2]-maze[x2][y1-1]-maze[x1-1][y2]+maze[x1-1][y1-1];
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    ll k;
    cin>>n>>m>>k;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>maze[i][j];
    //计算前缀和
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            maze[i][j] += maze[i-1][j]+maze[i][j-1] -maze[i-1][j-1];
    // cout<<"maze:";
    // for(int i=1;i<=n;i++){
    // 	for(int j=1;j<=m;j++)
    // 		cout<<maze[i][j]<<' ';
    // 	cout<<endl;
	// }
	// cout<<endl;
    ll ans=0;
    // i,j表示行
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            //将二维的单调性枚举转换成一维的
            // r,l表示列
            int r=1,l=1;
            while(l<=r&&l<=m&&r<=m){
                while(l<=r&&l<=m&&getSum(i,l,j,r)>k) l++;
                if(l<=r&&l<=m) ans += r-l+1;
                r++;
            }
        }
    }
    cout<<ans;
}
