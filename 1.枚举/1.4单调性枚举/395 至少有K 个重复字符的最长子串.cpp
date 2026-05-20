#include<bits/stdc++.h>
using namespace std;


//[l,r] <每一个>字符 （出现次数都>=k）,不符合单调性
//[l,r] 出现x个字符 符合单调性，因为区间扩大时，x也会变大
//条件：[l,r]出现的字符数量>x
//求不满足条件的最大区间 （出现次数>=k）

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int x;
        int ans=0;
        // 26个英文字符
        for(x=1;x<=26;x++){
            vector<int> cnt(128);
            int typeCnt=0;//出现的字符种类个数
            int matchCnt=0;//符合条件的个数
            for(int r=0,l=0;l<n;){
                while(typeCnt<=x&&r<n){
                    char c = s[r++];
                    if(cnt[c] == 0) typeCnt++;
                    cnt[c]++;
                    if(cnt[c]==k) matchCnt++;
                }
                if(matchCnt==x){//判断出现次数>=k条件
                    if(typeCnt>x){
                        //[l,r-2]满足条件
                        ans = max(ans,r-2-l+1);
                    }
                    else{
                        // [l,r-1]满足条件
                        ans = max(ans,r-1-l+1);
                    }
                }
                char c = s[l++];
                if(cnt[c]==k) matchCnt--;
                cnt[c]--;
                if(cnt[c]==0) typeCnt--;
            }
        }
        return ans;
    }
};