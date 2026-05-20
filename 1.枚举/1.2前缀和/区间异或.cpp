#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];

int main(){
    cin.tie(0)->sync_with_stdio(false);
    long long res = 0;
    int n;
    cin>>n;
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        //计算前缀异或
        pre[i] = pre[i-1] ^ a[i];
    unordered_map<int,int> cnt;
    // 使用引用可以避免拷贝大数据
    // 我一开始讲pre定义为大小为N的vector，
    // 导致auto x遍历到了没有用到的位置
    for(auto& x:pre){
        //统计前缀异或（pre）中有多少值相同的
        //当你通过 cnt[x]++ 访问一个不存在的键时，C++ 会自动插入这个键，
        //并将其值初始化为 0，然后再执行 ++ 操作，使其变成 1。
        cnt[x]++;
    }
    // 必须用 auto 来推导键值对类型
    for(auto &[_,c]:cnt){
        res += (long long)c*(c-1)/2;
    }
    cout<<res;
    
}