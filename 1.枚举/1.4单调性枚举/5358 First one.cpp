#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// for(i=1;i<n;i++)
//   for(int j=i;j<n;j++)
//       (lg+1)*(i+j)
//   for(int j=i;j<n;j++) (i+j)可以简化为：
//   i*(n-i+1) + (i+n)*(n-i+1)/2
//   for(int i=0;i<n;i++)
//       i*(R-L+1)+(L+R)*(R-L+1)/2
//       R表示j的最大值，L表示j的最小值   a[L]<=j<=a[R]
//条件：sum>=lg    
//找到不满足条件的最大值  得到R[i]
//条件：sum>=lg-1
//找到不满足条件的最大值  得到R[i-1]
//那么区间就是[R[i-1]+1,R[i]]



int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll total = 0;
        vector<long long> a(n+2);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            total += a[i];
        }
        // last[i]表示：上一轮的右端点的最小值
        vector<int> last(n+1);
        for(int i=1;i<=n;i++) last[i]=i;
        ll ans = 0;
        //外层循环:O(logn)
        for(int lg=1,limit = 2; ;limit*=2,lg++){
            ll sum = 0;
            for(int i=1,j=1;i<=n;){
                // lg是原始的log^s+1,limit就等于s
                while(sum<limit && j<=n){
                    sum+=a[j++];
                }
                int l = last[i];
                if(sum>=limit){//
                    //右端点k区间：[l,j-1]
                    //区间[i,k]中，log^s+1都等于lg
                    ans += lg*i*(j-l) + lg*(j-1+l)*(j-l)/2;
                    last[l] = j;
                }
                else{//全都<limit，那么[i,k]中，log^s+1都等于lg-1
                    // 右端点k：[l,j-1]
                    ans += (lg-1)*i*(j-l)+(lg-1)*(j-1+l)*(j-l)/2;
                    last[l] = j;
                }
                sum -= a[i++];
            }
            if(limit>total) break;
        }
        cout<<ans<<endl;
    }
    
}
