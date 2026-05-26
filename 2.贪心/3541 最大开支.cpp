// https://www.lanqiao.cn/problems/3541/learning
#include<bits/stdc++.h>
using namespace std;

struct kb{
    long long delta;
    int k;
    int b;
    int num;
    // 构造函数，用于 emplace 直接构造
    kb(long long d, int k_, int b_, int n_)
        : delta(d), k(k_), b(b_), num(n_) {}

    bool operator<(const kb& other) const{
        return delta < other.delta;//大顶堆
    }
};


int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<kb> pq;
    while(m--){
        int k,b;
        cin>>k>>b;
        // pq.push(make_tuple(b + k, k, b, 1));
        pq.emplace(k+b,k,b,1);
    }
    long long ans = 0;
// 比如 n=4（4 个人）：
// 第 1 次循环：给增量最大的项目分配 1 个人
// 第 2 次循环：给当前增量最大的项目分配第 2 个人
// 第 3 次循环：分配第 3 个人
// 第 4 次循环：分配第 4 个人
    while(n--){
        kb s = pq.top();
        int x = s.num;
        int k2 = s.k;
        int b2 = s.b;
        if(s.delta<=0) break;
        ans += s.delta;
        pq.pop();
        long long d = 1ll*(k2*(x+1)+b2)*(x+1) - 1ll*(k2*x+b2)*x;
        pq.emplace(d,k2,b2,(x+1));
    }
    cout<<ans;
}