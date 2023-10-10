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
/* 两两交换链表节点，dummyHead指向头节点 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        auto dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* fir = head;
        ListNode* sec = head->next;
        while(fir != nullptr && sec != nullptr){
            ListNode* next = sec->next;
            pre->next = sec;
            sec->next = fir;
            fir->next = next;
            pre = fir;
            fir = fir->next;
            if(fir == nullptr) break;
            sec = fir->next;
        }
        return dummyHead->next;
    }
};