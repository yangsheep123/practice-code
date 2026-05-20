// P1886 【模板】单调队列 / 滑动窗口
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> ans_min(n-k+1);
    vector<int> ans_max(n-k+1);
    for(int i=0;i<n;i++) cin>>a[i];
    // inc_q从小到大排列
    // dec_q从大到小排列
    deque<int> inc_q,dec_q;
    for(int i=0;i<n;i++){
        while(!inc_q.empty()&&a[inc_q.back()]>=a[i]){
            inc_q.pop_back();
        }
        inc_q.push_back(i);
        while(!dec_q.empty()&&a[dec_q.back()]<=a[i])
            dec_q.pop_back();
        dec_q.push_back(i);
        while(!inc_q.empty()&&inc_q.front() < i-k+1)
            inc_q.pop_front();
        while(!dec_q.empty()&&dec_q.front() < i-k+1)
            dec_q.pop_front();
        if(i>=k-1){//形成了滑动窗口
            // i - k + 1 表示当前窗口是第几个窗口（从0开始计数）
            ans_min[i-k+1]=a[inc_q.front()];
            ans_max[i-k+1]=a[dec_q.front()];
        }
    }
    for (auto x : ans_min) cout << x << ' ';
    cout << endl;
    for (auto x : ans_max) cout << x << ' ';
    cout << endl;
}