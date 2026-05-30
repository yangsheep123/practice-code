// https://www.lanqiao.cn/problems/19705/learning/

#include<bits/stdc++.h>
using namespace std;
// 在前x个人里面选k个人，使得他们的方差<t
// 加上x符合条件，那么大于x的数里面也能满足（因为包含了前面的数）
// 现在要找到第一个符合条件的数
typedef long long ll;

int main(){
    int n,k,t;
    cin>>n>>k>>t;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    // 在x里面排序后，滑动窗口。不可能跳着选，因为那会让方差变大
    auto check = [&](int x){
        // 左闭右开 
        // 里面包含 a 中从 a.begin()到 a.begin() + x（也就是第 x 个元素，不含它本身）的所有元素。
        vector<int> b(a.begin(),a.begin()+x);
        sort(b.begin(),b.end());
        vector<ll> sum1(n+5);
        vector<ll> sum2(n+5);
        for(int i=1;i<=b.size();i++){
            sum1[i] = sum1[i-1] + b[i-1];
            sum2[i] = sum2[i-1] + (ll)b[i-1]*b[i-1];
        }
        for(int l=1,r=k;r<=x;){
            double avg = (double)(sum1[r] - sum1[l-1]) / k;
            double var = (sum2[r] - sum2[l-1] - 2*avg*(sum1[r]-sum1[l-1]) + k*avg*avg)/k;
            if(var<t) return true;
            l++;
            r++;
        }
        return false;
    };
    int low = 1,high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(mid)) high = mid-1;
        else low = mid+1;
    }
    if(low == n+1) cout<<-1<<endl;
    else cout<<low<<endl;
}