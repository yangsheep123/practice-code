#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r,l;
        int n = s.size();
        int ans = 0;
        // ASC码共有128个，字符在计算机眼里就是ASC码数字，可以直接当作数组下标
        vector<int> cnt(128);
        for(int l=0,r=0;l<n,r<n;){
            cnt[s[r]]++;
            while(cnt[s[r]]>1){
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};