//  P2698 Flowerpot
#include<bits/stdc++.h>
using namespace std;
// 类似于https://www.lanqiao.cn/problems/2147/learning/

// W变大，D=maxy-miny肯定变大
int main(){
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> drop(n);
    for(int i=0;i<n;i++){
        cin>>drop[i].first>>drop[i].second;
    }
    // pair默认对第一个元素排序
    sort(drop.begin(),drop.end());
    // 对第二个元素从小到大排序
    // sort(drop.begin(),drop.end(),[](const pair<int,int> &a,const pair<int,int> &b){
    //     return a.second<b.second;
    // });
    deque<int> inc_q,dec_q;
    int ans = INT_MAX;
    for(int l=0,r=0;l<n;){
        while(r<n&&(inc_q.empty()||dec_q.empty()||
		drop[dec_q.front()].second - drop[inc_q.front()].second<d)){
            while(!inc_q.empty()&&drop[inc_q.back()].second>=drop[r].second)
            	inc_q.pop_back();
        	inc_q.push_back(r);
        	while(!dec_q.empty()&&drop[dec_q.back()].second<=drop[r].second)
            	dec_q.pop_back();
        	dec_q.push_back(r);
        	r++;
        }
        if(!inc_q.empty()&&!dec_q.empty()&&
		drop[dec_q.front()].second - drop[inc_q.front()].second>=d){
        	if(r>0) ans = min(ans,drop[r-1].first-drop[l].first);
		}
		l++;
        while(inc_q.front()<l&&l<n) inc_q.pop_front();
        while(dec_q.front()<l&&l<n) dec_q.pop_front();
        
    }
    if(ans == INT_MAX) ans = -1;
    cout<<ans<<endl;

}
