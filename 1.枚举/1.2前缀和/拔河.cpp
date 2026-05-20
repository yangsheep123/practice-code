// l1<=r1<l2<=r2
// 枚举多个值时，最好枚举中间的，比如r
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> a(N);
typedef long long ll;
vector<ll> pre(N);

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        pre[i] = pre[i-1]+a[i];
    ll ans = LLONG_MAX;
    set<ll> s; //set：红黑树，按照从小到大的顺序排列
    for(int r = n-1; r >=1;r--){
        for(int x = r+1;x <= n;x++){
            // 计算[r+1,x]的区间和
            // 将r从大往小枚举，则只需要往s里面加，不需要减了，
            // 因为s里面的区间都在[l,r]右边
            s.insert(pre[x]-pre[r]);
        }
        for(int l = 1;l <= r;l++){
            ll target = pre[r] - pre[l-1];
            // 在s中找出最小的比target大的数
            set<ll>:: iterator iter = s.lower_bound(target);
            if(iter != s.end()){ //找到了
                ans = min(ans,*iter-target);
            }
            if(iter!=s.begin()){ //找到最大的比target小的数
                --iter;
                ans = min(ans,target - *iter);
            }
        }
    }
    cout<<ans;
}