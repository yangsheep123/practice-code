#include<bits/stdc++.h>
using namespace std;

int main(){
    //如果一个区间要框住某个线段，则这个线段的中点一定要包含在该区间里面
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    int L,R;
    cin>>n>>m;
    vector<vector<int> >b(2e6+2,vector<int>(2));
    //如果坐标i有一个中点，pre[i]就++一次
    vector<int> pre(2e6+2);
    int i,j;
    for(i=0;i<n;i++){
        cin>>L>>R;
        pre[L+R]++;//取中点（至少一半），为避免像1/2这样的小数，所以直接乘以2（ (l + r) / 2 * 2 ）
    }
    
    for(i=0;i<m;i++){
        for(j=0;j<2;j++){
            cin>>b[i][j];
        }
    }

    //计算前缀和pre：统计从原点到i，一共有多少个中点
    for(i=1;i<2e6+2;i++){
        pre[i]+=pre[i-1];
    }

    for(i=0;i<m;i++){
        cout<<pre[2*b[i][1]]-pre[2*b[i][0]-1]<<endl;
    }

    return 0;
}