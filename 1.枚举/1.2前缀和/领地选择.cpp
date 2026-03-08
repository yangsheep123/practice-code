#include<bits/stdc++.h>
using namespace std;

//对于矩阵的前缀和，先让每一行算前缀和，再让每一列算前缀和，
//则点（i，j）上的值就是从左上角到该点包含的矩阵的和

// int main(){
//     int n,m,c;
//     cin>>n>>m>>c;
//     int a[n][m];
//     int pre[n][m];
//     int i,j;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>a[i][j];
//         }
//     }

//     //先算每一行的前缀和
//     for( i=0;i<n;i++){
//         for( j=0;j<m;j++){
//             if(j==0) pre[i][j]=a[i][j];    
//             else pre[i][j]=pre[i][j-1]+a[i][j];
//         }
//     }
    
//     //再算每一列的前缀和
//     for( j=0;j<m;j++){
//         for( i=0;i<n;i++){
//             if(i==0) pre[i][j]=pre[i][j];
//             else pre[i][j]=pre[i-1][j]+pre[i][j];
//         }
//     }
//     // for( i=0;i<n;i++){
//     //     for( j=0;j<m;j++)
//     //         cout<<pre[i][j]<<" ";
//     //     cout<<"\n";
//     // }
//     int max=INT_MIN;
//     int now=0;
//     int max_i=0,max_j=0;
//     //枚举每个地块的左上角
//     for( i=0;i<n;i++){
//         for( j=0;j<m;j++){
//             if(i+c>n||j+c>m) continue;
//             // if(i==j==0) now=pre[i+c-1][j+c-1];
//             //这个写法不对！！！
//             //i==j==0 会先执行 i==j，得到布尔值（0 或 1），再用这个值和 0 比较；
//             if(i==0&&j==0) now=pre[i+c-1][j+c-1];
//             else{
//                 if(i>=1&&j>=1) 
//                     now=pre[i+c-1][j+c-1]-pre[i-1][j+c-1]-pre[i+c-1][j-1]+pre[i-1][j-1];
//                 else if(i==0)
//                     now=pre[i+c-1][j+c-1]-pre[i+c-1][j-1];
//                 else
//                     now=pre[i+c-1][j+c-1]-pre[i-1][j+c-1];
//             }
//             if(now>max) max=now,max_i=i,max_j=j;

//         }
//     }
//     cout<<max_i+1<<" "<<max_j+1;
//     return 0;
// }


//标答写法
int main(){
    //竞赛中大量数据读写，如何提速？
    cin.tie(0)->sync_with_stdio(false);//// 关闭cin与stdio的同步，加速输入输出
    int m,n,c;
    cin>>n>>m>>c;
    //使用vector定义，所有的元素都默认为0
    vector<vector<int> > land(n+1,vector<int>(m+1));
    int i=1,j=1;
    //i和j初始值为1，可以有效避免数据越界
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>land[i][j];
            land[i][j]+=land[i-1][j]+land[i][j-1]-land[i-1][j-1];
        }
    }
    long long max=LLONG_MIN;//long long数据类型的最小值
    long long sum=0;
    int max_i=0,max_j=0;
    //枚举每个c*c的矩阵，右小角的坐标是(i,j)
    for(i=c;i<=n;i++){
        for(j=c;j<=n;j++){
            sum=land[i][j]-land[i-c][j]-land[i][j-c]+land[i-c][j-c];
            if(sum>max){
                max=sum;
                max_i=i-c+1;
                max_j=j-c+1;
            }
        }
    }
    cout<<max_i<<" "<<max_j;
    return 0;
}