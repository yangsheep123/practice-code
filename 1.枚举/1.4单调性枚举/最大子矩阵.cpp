#include<bits/stdc++.h>
using namespace std;

int main(){
    // [max-min],面积变大，max变大，min变小，max-min变大
    //面积变小，max变小，min变大，max-min变小
    // 说明符合单调性
    cin.tie(0)->sync_with_stdio(false);
    int m,n,limit;
    cin>>n>>m;
    vector<vector<int> >maze(n+5,vector<int>(m+5));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>maze[i][j];
    cin>>limit;
    int ans = 0;
    // multiser和set的区别是：前者可以有重复元素，后者不能有
    // 枚举行[x1,x2]
    for(int x1=1;x1<=n;x1++){
        vector<int> mmin(m+1,INT_MAX);
        vector<int> mmax(m+1,-1);
        for(int x2=x1;x2<=n;x2++){
            //mmin[r]：第r列在[x1,x2]间的最小的元素
            for(int r=1;r<=m;r++){
                mmin[r] = min(mmin[r],maze[x2][r]);
                mmax[r] = max(mmax[r],maze[x2][r]);
            }
            multiset<int> s;
            for(int r=1,l=1;r<=m,l<=m;){
                while(r<=m && (s.empty()||*s.rbegin()-*s.begin()<=limit)){
                    s.insert(mmin[r]);
                    s.insert(mmax[r++]);
                }
                if(!s.empty()&&*s.rbegin()-*s.begin()>limit){
                    // [l,r-2]
                    //因为while里面*s.rbegin()-*s.begin()天然比r的增加慢一步
                    ans = max(ans,(x2-x1+1)*(r-l-1));
                }
                else{// r==m,说明[l,r-1]都可以
                    ans = max(ans,(x2-x1+1)*(r-l));
                }
                // 用s.find(mmin[l])可以只删除一个元素
                s.erase(s.find(mmin[l]));
                s.erase(s.find(mmax[l++]));
            }
        }
    }
    cout<<ans;
}