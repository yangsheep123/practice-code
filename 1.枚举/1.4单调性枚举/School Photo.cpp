//P10710 [NOISG 2024 Prelim] School Photo

#include<bits/stdc++.h>
using namespace std;

// n*s个同学 contain(n) max-min最小
// 1.max-min最小 2.contain(n) 二分搜索
// 1.contain(n) 2.max-min最小 单调递减，因为contain的越多，max-min越大
// 条件：contain(n)
// 求满足条件的最小值

int main(){
    int n,s;
    cin>>n>>s;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        for(int j=0;j<s;j++){
            int h;
            cin>>h;
            a.push_back({h,i});
        }
    }
    int ans = INT_MAX;
    vector<int> cnt(n);
    int classCnt = 0;
    //按照身高升序排列
    sort(a.begin(),a.end());
    for(int l=0,r=0;l<n*s;){
        while(classCnt<n&&r<n*s){
            if(cnt[a[r].second]==0) classCnt++;
            cnt[a[r++].second]++;
        }if(classCnt==n){
            //[l,r-1]
            ans = min(ans,a[r-1].first-a[l].first);
        }
        cnt[a[l].second]--;
        if(cnt[a[l++].second]==0) classCnt--;
    }
    cout<<ans;
}
