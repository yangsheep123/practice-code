// https://www.lanqiao.cn/problems/3532/learning/
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int>> score(n);
    vector<int> cnt(10);
//    for(auto& [a,b]:arr) {
//        cin>>a>>b;
//        cnt[a]++;
//        score[a].push_back(b);
//    }
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		cnt[a] ++;
		score[a].push_back(b);
	}
    for(auto& row:score){
        sort(row.begin(),row.end(),[](int a,int b){
            return a<b;
        });
    }
    long long ans = 0;
    n /= 10;
    for(int i=0;i<10;i++){
        int k = 0;
        while(cnt[i]>n){
            if(k<score[i].size())
                ans += score[i][k];
            k++;
            cnt[i]--;
        }
    }
    cout<<ans;

}
