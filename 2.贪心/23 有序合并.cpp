// 23 有序合并
// https://leetcode.cn/problems/merge-k-sorted-lists/

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using node = ListNode;
        //new node()初始化分配内存，加上初始化
        // 初始化val=0，dummy->next=null
        // dummy当作头节点
        node* dummy = new node();
        node* tail = dummy;
        // 优先级队列接受的是值，不能用&
        // 并且不能用const，因为pq.push(list)时，list只是普通的node*
        struct cmp{
            bool operator()(node* a,node* b){
                return a->val > b->val;
            } 
        };
        // 定义小顶堆
        priority_queue<node*,vector<node*>,cmp> pq;
        // 比如1->4->5,list就是节点1
        for(auto &list:lists) if(list) pq.push(list);
        while(!pq.empty()){
            node* s = pq.top();
            tail->next = s;
            tail = tail->next;
            pq.pop();
            if(s->next) pq.push(s->next);
        }
        return dummy->next;
    }
};