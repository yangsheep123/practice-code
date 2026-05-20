#include<bits/stdc++.h>
using namespace std;
//n=N-k+1
// p1 p2 p3 ... pn
// q1 q2 q3 ... qn
// (p1-q1)+(p1-q2)+(p1-q3)+... = n*p1-(q1+q2+..+qn)
// n*(p1+p2+p3...+pn) - n*(q1+q2+..+qn)



int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> p(n-k+1);
    vector<int> q(n-k+1);
    int j=0;
    deque<int> inc_q,dec_q;
    for(int i=0;i<n;i++){
        while(!inc_q.empty()&&a[inc_q.back()]>=a[i])
            inc_q.pop_back();
        inc_q.push_back(i);
        while(!dec_q.empty()&&a[dec_q.back()]<=a[i])
            dec_q.pop_back();
        dec_q.push_back(i);
        while(inc_q.front()<i-k+1)
            inc_q.pop_front();
        while(dec_q.front()<i-k+1)
            dec_q.pop_front();
        if(i>=k-1){
            p[j] = a[dec_q.front()];
            q[j++] = a[inc_q.front()];
        }
        
    }
    int s = 0;
    long long sp = 0;
    long long sq = 0;
    for(int i=0;i<p.size();i++){
        sp += p[i];
    }
    for(int i=0;i<q.size();i++){
        sq += q[i];
    }

    // for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
    // cout<<endl;
    double sum = 0;
    sum = sp - sq;
    sum /= (n-k+1);
    printf("%.2lf",sum);
}
