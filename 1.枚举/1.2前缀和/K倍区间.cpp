#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<long long>a(1e5+1);
    //相当于哈希桶
    vector<long long> st(200000);
    int i;
    for(i=1;i<=n;i++) {
        cin>>a[i];
    }
    //求前缀和
    for(i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    long long ans=0;
    // for(i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         if((a[j]-a[i-1])%k==0)
    //             ans++;    
    //     }
    // }

    //优化1：
    //使用同余定理进行优化:如果(a-b)%m得到一个整数，则有a%m==b%m;
    //要特别注意这里i是从0开始的，否则会漏掉从第一个元素开始的区间
    // for(i=0;i<=n;i++){
    //     ans+=st[a[i]%k];
    //     st[a[i]%k]++;
    // }

    //优化2：映射到哈希桶以后，直接用组合数求解即可
    for(i=0;i<=n;i++){
        st[a[i]%k]++;
    }
    for(i=0;i<=n;i++){
        ans+=(st[i]*(st[i]-1))/2;
    }
    cout<<ans;
    return 0;
}