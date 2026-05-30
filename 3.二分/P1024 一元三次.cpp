// https://www.luogu.com.cn/problem/P1024

#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
double a,b,c,d;
double f(double x){
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
}

int main(){
    cin>>a>>b>>c>>d;
    vector<double> ans;
    // 整数情况
    for(int x = -100;x<=100;x++){
        if(abs(f(x))<eps) ans.push_back(x);
    }
    // 浮点数情况
    for(int x=-100;x<=99;x++){
        double low = x,high = x+1;
        double f1 = f(x),f2 = f(x+1);
        // 相乘是很小的负数也当作等于0，所以写-eps
        if(f1*f2 > -eps) continue;
        while(high - low >= eps){
            double mid = (high+low)/2;
            if(f(mid)*f1 >0) 
                low = mid;
            else high = mid;
        }
        ans.push_back(low);
    }
    sort(ans.begin(),ans.end());
    cout<<fixed<<setprecision(2);
    for(auto x:ans)
        cout<<x<<' ';
}