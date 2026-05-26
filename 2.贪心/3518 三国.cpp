// https://www.lanqiao.cn/problems/3518/learning/
#include<bits/stdc++.h>
using namespace std;

// 如果x>y+z 则a0+a1+a2>(b0+b1+b2)+(c1+c2+c3)
// 则:(a0-b0-c0)+(a1-b1-c1)+(a2-b2-c2)>0
// 令d0=a0-b0-c0,d1=a1-b1-c1,d2=a2-b2-c2
// 让d数组从大到小排序，一直累加到小于等于0
struct xyz{
    int x;
    int y;
    int z;
};


int main(){
    int n;
    cin>>n;
    vector<xyz> nums(n);
    for(xyz& elem:nums) cin>>elem.x;
    for(xyz& elem:nums) cin>>elem.y;
    for(xyz& elem:nums) cin>>elem.z;
    long long ans = -1;
    // [&]:捕获匿名函数外面的参数
    auto cal = [&](){
        auto getV = [](xyz& a){
            return a.x-a.y-a.z;
        };
        // sort里面的匿名函数是排序逻辑
        sort(nums.begin(),nums.end(),[&](xyz& a,xyz& b){
            return getV(a) > getV(b);
        });
        long long v = 0;
        long long cnt = 0;
        for(int i=0;i<nums.size();i++){
            v += (getV(nums[i]));
            if(v>0) cnt++;
        }
        if(cnt == 0) return;
        ans = max(ans,cnt);
    };
    cal();
    for(xyz& a:nums) swap(a.x,a.y); //必须使用引用，交换才有效
    cal();
    for(xyz& a:nums) swap(a.x,a.z);
    cal();
    cout<<ans;
}