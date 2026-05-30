// https://www.luogu.com.cn/problem/P2249
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    int x;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    while(m--){
        cin>>x;
        int low = 0,high = n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(arr[mid]>=x)
                high = mid - 1;
            else low = mid+1;
        }
        // int low = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        if(low ==n || arr[low]!=x) cout<<-1<<' ';
        else cout<<low+1<<' ';
    }
}
