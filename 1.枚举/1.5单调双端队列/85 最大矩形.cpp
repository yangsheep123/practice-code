#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& maze) {
        int n = maze.size(),m = maze[0].size();
        vector<vector<int>> h(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j] == '0') continue;
                h[i][j] = 1;
                if(i==0) continue;
                h[i][j] += h[i-1][j];
            }
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++)
        		cout<<h[i][j]<<' ';
        	cout<<endl;
		}
        stack<int> s;
        vector<vector<int>> pre_g(n,vector<int>(m));
        vector<vector<int>> next_g(n,vector<int>(m));
        for(int i=0;i<n;i++){
        	while(!s.empty()) s.pop();
            for(int j=0;j<m;j++){
                while(!s.empty()&&h[i][s.top()]>=h[i][j])
                    s.pop();
                if(s.empty()) pre_g[i][j] = -1;
                else pre_g[i][j] = s.top();
                s.push(j);
            }
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
        	while(!s.empty()) s.pop();
            for(int j=m-1;j>=0;j--){
                while(!s.empty()&&h[i][s.top()]>=h[i][j])
                    s.pop();
                if(s.empty()) next_g[i][j] = m;
                else next_g[i][j] = s.top();
                s.push(j);
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int l = pre_g[i][j],r=next_g[i][j];
                ans = max(ans,(r-l-1)*h[i][j]);
            }
        }
        return ans;
    }
};


// int main(){
//     vector<vector<char>> maze(4,vector<char>(5));
//     for(int i=0;i<4;i++)
//         for(int j=0;j<5;j++)
//             cin>>maze[i][j];
//     int ans = maximalRectangle(maze);

// }

//int main() {
//    Solution sol;
//    // 题目示例输入
//    vector<vector<char>> matrix = {
//        {'1','0','1','0','0'},
//        {'1','0','1','1','1'},
//        {'1','1','1','1','1'},
//        {'1','0','0','1','0'}
//    };
//    int res = sol.maximalRectangle(matrix);
//    // 输出 6，和题目答案一致
//    printf("%d\n", res);
//    return 0;
//}
