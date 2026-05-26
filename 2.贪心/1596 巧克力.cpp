// https://www.lanqiao.cn/problems/1596/learning

#include<bits/stdc++.h>
using namespace std;
// 将巧克力按照保质期从小到大排列，然后逆序遍历，、
// 每次选择在保质期内的价格最低的巧克力


int main(){
    int x,n;
    cin>>x>>n;
    // deadline,price,cnt
    vector<tuple<int,int,int>> chos(n);
    // for(int i=0;i<n;i++){
    //     int a,b,c;
    //     cin>>a>>b>>c;
    //     cho[i] = make_tuple(a,b,c);
    // }
    //for(auto& [d,p,c]:chos) cin>>p>>d>>c;
    for (auto& t : chos) {
    int p, d, c;
    cin >> p >> d >> c;
    get<0>(t) = d;
    get<1>(t) = p;
    get<2>(t) = c;
	}
    // 将巧克力按照保质期从小到大排列
    sort(chos.begin(),chos.end());
    using pii = pair<int,int>;
    // pq里面存储pii,并且是小顶堆，从小到大排列
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int index = n-1;
    long long ans = 0;
    for(;x>0;x--){
        while(index>=0){
//            auto [d,p,c] = chos[index];
			int d = get<0>(chos[index]);
			int p = get<1>(chos[index]);
			int c = get<2>(chos[index]);
            if(d>=x){
			index--;
			pq.emplace(p,c);
			}
            else break; //当前的保质期比它前面的都要长，如果当前保质期都过期，那么就直接break
        }
        if(pq.empty()) break;
//        auto [p,c] = pq.top();
		int price = pq.top().first;
		int cnt = pq.top().second; 
        ans += price;
        pq.pop();
        if(cnt>1) pq.emplace(price,cnt-1);
    }
    cout<<(x==0?ans:-1)<<endl;
}
