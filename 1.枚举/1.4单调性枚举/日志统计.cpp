#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,d,k;
    cin>>n>>d>>k;
    vector<int> cnt(N);
    vector<pair<int,int>> logs(n);
    for(int i=0;i<n;i++){
        cin>>logs[i].first>>logs[i].second;
    }
    //对logs的第一个元素进行排序，递增
    sort(logs.begin(),logs.end());
    int r,l;
    set<int> ans;
    for(l=0,r=0;l<n,r<n;){
        while(logs[r].first - logs[l].first < d && r<n){
            cnt[logs[r++].second] ++;
            if(cnt[logs[r-1].second]==k){
                ans.insert(logs[r-1].second);
            }
        }
        cnt[logs[l++].second]--;
    }
    for(set<int>::iterator it = ans.begin();it!=ans.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}