// https://www.lanqiao.cn/problems/19715/learning

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> diff(n/2);
    for(auto& x:a) cin>>x;
    for(int i=0;i<n/2;i++){
        diff[i] = a[i] - a[n-i-1];
    }
    n /= 2;
    long long ans = 0;
    for(int i=0;i<n;i++){
        if(i+1<n){
            // 如果相邻两个数同号
            if(1ll*diff[i]*diff[i+1]>=0){
                int mmin = min(abs(diff[i]),abs(diff[i+1]));
                ans += mmin;
                if(diff[i]>0){
                    diff[i] -= mmin;
                    diff[i+1] -= mmin;
                }else{
                    diff[i] += mmin;
                    diff[i+1] += mmin;
                }
            }
        }
        // 如果diff[i]与diff[i+1]同号，且diff[i]>diff[i+1]，则单独对diff[i]操作
        // 如果diff[i]与diff[i+1]异号，单独对diff[i]操作
        ans += abs(diff[i]);
    }
    cout<<ans;
}
