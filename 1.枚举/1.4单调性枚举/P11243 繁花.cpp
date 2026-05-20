#include<bits/stdc++.h>
using namespace std;

// P11243 繁花
// <<<<<
// 条件：包含大于号 大于-1 小于 0 sum<0
// 找出不满足条件的区间个数 a
// 条件：包含小于号（i>j的情况） 大于 0 小于 -1 sum>0
// 找出不满足条件的区间个数 b
// 条件：包含大于小于号 大于 -1 小于 -1 sum<0
// 找出不符合条件的区间个数 c
// < = 多算1个
// > = 多算1个
// a+b-2*c
int main(){
    int t,n;
    cin>>t;
    string c;
    while(t--){
        cin>>n;
        cin>>c;
        auto func = [&](int less,int biger){
            vector<int> v(128);
            v['<'] = less;
            v['>'] = biger;
            int sum = 0;
            long long total=0;
            for(int i=0,j=0;i<n;){
                while(sum==0&&j<n){
                    sum += v[c[j++]];
                }
                total += j-2-i+1;
                sum -= v[c[i++]];
            }
            return total;
        };
        cout<<func(0,-1)+func(-1,0)-2*func(-1,-1)<<endl;
    }
}