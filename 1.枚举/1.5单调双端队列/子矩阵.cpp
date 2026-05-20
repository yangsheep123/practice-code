#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
// 先求每一列的最大值/最小值，再求每一行的最大值/最小值
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<vector<int>> maze(n,vector<int>(m));
    vector<vector<int>> mmin(n,vector<int>(m));
    vector<vector<int>> mmax(n,vector<int>(m));
    vector<vector<int>> mmin_d(n,vector<int>(m));
    vector<vector<int>> mmax_d(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>maze[i][j];
    for(int j=0;j<m;j++){
        deque<int> inc_q;
        deque<int> dec_q;
        for(int i=0;i<n;i++){
            while(!inc_q.empty()&&maze[inc_q.back()][j]>=maze[i][j])
                inc_q.pop_back();
            while(!dec_q.empty()&&maze[dec_q.back()][j]<=maze[i][j])
                dec_q.pop_back();
            while(!inc_q.empty()&&inc_q.front()<i-a+1)
                inc_q.pop_front();
            while(!dec_q.empty()&&dec_q.front()<i-a+1)
                dec_q.pop_front();
            inc_q.push_back(i);
            dec_q.push_back(i);
            if(i>=a-1){
                mmin[i][j] = maze[inc_q.front()][j];
                mmax[i][j] = maze[dec_q.front()][j];
            }
        }
    }
//    cout<<"mmin:"<<endl;
//    for(int i=0;i<n;i++){
//    	for(int j=0;j<m;j++){
//    		cout<<mmin[i][j]<<' ';
   		
// 		}
// 		cout<<endl;
// 	}
// 	cout<<"mmax:"<<endl;
// 	for(int i=0;i<n;i++){
//    	for(int j=0;j<m;j++){
//    		cout<<mmax[i][j]<<' ';
// 		}
// 		cout<<endl;
// 	}
	
	
    for(int i=a-1;i<n;i++){
        deque<int> inc_q,dec_q;
        for(int j=0;j<m;j++){
            while(!inc_q.empty()&&mmin[i][inc_q.back()]>=mmin[i][j])
                inc_q.pop_back();
            inc_q.push_back(j);
            while(!dec_q.empty()&&mmax[i][dec_q.back()]<=mmax[i][j])
                dec_q.pop_back();
            dec_q.push_back(j);
            while(!inc_q.empty()&&inc_q.front()<j-b+1)
                inc_q.pop_front();
            while(!dec_q.empty()&&dec_q.front()<j-b+1)
                dec_q.pop_front();
            if(j>=b-1){
                mmin_d[i][j] = mmin[i][inc_q.front()];
                mmax_d[i][j] = mmax[i][dec_q.front()];
            }
        }
    }

//        cout<<"mmin_d:"<<endl;
//    for(int i=0;i<n;i++){
//    	for(int j=0;j<m;j++){
//    		cout<<mmin_d[i][j]<<' ';
   		
// 		}
// 		cout<<endl;
// 	}
// 	cout<<"mmax_d:"<<endl;
// 	for(int i=0;i<n;i++){
//    	for(int j=0;j<m;j++){
//    		cout<<mmax_d[i][j]<<' ';
// 		}
// 		cout<<endl;
// 	}

    ll ans = 0;
    for(int i=a-1;i<n;i++){
        for(int j=b-1;j<m;j++){
            ans += (mmin_d[i][j]*mmax_d[i][j]);
        }
        cout<<endl;
    }
    
    ans %= mod;
    cout<<ans;
}
