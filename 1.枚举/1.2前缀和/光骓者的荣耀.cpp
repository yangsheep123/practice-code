#include<bits/stdc++.h>
using namespace std;

// //int最大到2.1*10^9
// //由题目可知，dis和pre最坏情况会远超int的最大范围，因此要使用long long

// int main(){
//     int n,k;
//     cin>>n>>k;
//     long long a[n];
//     a[0]=0;
//     for(int i=1;i<n;i++)
//         cin>>a[i];
//     //先求出每一点的前缀和，再求得最大的k长度的前缀和，在这个区间传送
//     vector<long long> pre(1000000);
//     pre[0]=0;
//     for(int i=1;i<n;i++){
//         pre[i]=pre[i-1]+a[i];
//     }
//     long long max = 0;
//     int idx=-1;
//     long long now;
//     for(int i=k;i<n;i++){
//         now=pre[i]-pre[i-k];
//         if(now>max){
//             max=now;
//             idx=i-k;
//         }
//     }  
//     int j=0;
//     long long dis=0;
//     while(1){
//         if(j!=idx){
//             dis+=a[j+1];
//             j++;
//         }
//         else j+=k;
//         if(j==n-1) break;
//     }
//     cout<<dis;
//     return 0;
// }


//标答写法

//直接求最大的跨度为k的距离，然后再用总长度减去该长度
int main(){
    vector<long long> pre(1000000,0);
    long long sum=0;
    int n,k;
    cin>>n>>k;
    long long a[n];
    a[0]=0;
    for(int i=1;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    long long max_dis=0,dis=0;
    for(int i=k;i<n;i++){
        max_dis=max(max_dis,pre[i]-pre[i-k]);
    }
    dis=sum-max_dis;
    cout<<dis;
    return 0;
}
