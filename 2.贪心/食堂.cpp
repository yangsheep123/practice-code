// https://www.lanqiao.cn/problems/19724/learning/

#include<bits/stdc++.h>
using namespace std;
// 1.3+3=6    4+2=6   2+2+2=6
// 2.2+3=5
// 3.4 2+2=4
// 4.3
// 5.2
// 按照1-5顺序遍历，肯定如果可以选更多的人数就优先选


int main(){
    int q;
    cin>>q;
    while(q--){
        int a2,a3,a4,b4,b6;
        cin>>a2>>a3>>a4>>b4>>b6;
        vector<tuple<int,int,int,int>> patterns={
            {0,2,0,6},{1,0,1,6},{3,0,0,6},
            {1,1,0,5},
            {0,0,1,4},{2,0,0,4},
            {0,1,0,3},
            {1,0,0,2}
        };
        vector<int> tables(b6,6);
        // 在 tables 的 末尾（end() 位置）插入新元素,插入的内容是从 b4 指向的位置开始的 4 个元素
        // 相当于把 b4 后面 4 个元素拼接到 tables 末尾
        tables.insert(tables.end(),b4,4);
        int ans = 0;
        for(auto& b:tables){
            for(tuple<int,int,int,int>& pat:patterns){
                int c2 = get<0>(pat);
                int c3 = get<1>(pat);
                int c4 = get<2>(pat);
                int sum = get<3>(pat);
                if(a2>=c2&&a3>=c3&&a4>=c4&&b>=sum){
                    ans += sum;
                    a2-=c2,a3-=c3,a4-=c4;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}