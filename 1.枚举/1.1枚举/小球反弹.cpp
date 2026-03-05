#include<bits/stdc++.h>
using namespace std;
//使用镜像法
int main(){
    //核心作用：设置输出浮点数时的有效精度（默认是 “有效数字个数”）。
    //单独使用时（没有fixed）：precision(n) 表示输出n位有效数字（从第一个非 0 数字开始数）。
    cout.precision(2);

//cout.precision(2) 单独用是 “保留 2 位有效数字”，搭配fixed后变成 “小数点后保留 2 位”,并且四舍五入；
    cout<<fixed;
    int width = 343720*2,height = 233333*2;
    int dx=15,dy=17;
    for(long long t=1;;t++){
        if((t*dx%width==0)&&(t*dy%height==0)){
            cout<<hypot(t*dx,t*dy);
            break;
        }
    }
    
    return 0;
}