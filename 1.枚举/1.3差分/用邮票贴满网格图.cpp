#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<long long>> pre(n+10,vector<long long>(m+10));
        vector<vector<long long>> diff(n+10,vector<long long>(m+10));
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]=grid[i-1][j-1]+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
            }
        }
        //枚举矩阵左上角点的坐标
        for(int i=0;i+h<=n;i++){
            for(int j=0;j+w<=m;j++){
                // 计算邮票占据的矩阵里的前缀和
                int v = pre[i+h][j+w] - pre[i+h][j] - pre[i][j+w] + pre[i][j];
                if(v==0){//如果邮票所在矩阵和为0，说明这个矩阵全为0
                    diff[i+1][j+1]++;
                    diff[i+h+1][j+1]--;
                    diff[i+1][j+w+1]--;
                    diff[i+h+1][j+w+1]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //计算差分矩阵的前缀和矩阵
                // 含义是：[i,j]位置贴了几次邮票
                diff[i][j]+=diff[i][j-1]+diff[i-1][j]-diff[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0&&diff[i+1][j+1]==0) return false;
            }
        }
        return true;
    }
};