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
    ListNode* reverseSingleGroup(ListNode* target, int k){
        ListNode* cur = target->next;
        ListNode* pre = target;
        for(int i=0; i<k-1; i++){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1) return head;
        int curK = 0;
        // 当前指针
        ListNode* cur = head;
        // k个一组反转的开始节点
        ListNode* curHead = head;
        ListNode* dummyHead = new ListNode(0);
        // 上一组的结尾节点
        ListNode* lastNode = dummyHead;
        dummyHead->next = head;
        while(cur != nullptr){
            ++curK;
            if(curK == k){
                // 保存下一个节点
                ListNode* nextHead = cur->next;
                // 上一组最后一个节点指向这一组反转后的头节点
                lastNode->next = reverseSingleGroup(curHead, k);
                // 更新成这组最后一个节点，原本的头节点变最尾节点
                lastNode = curHead;
                // 更新cur和curHead
                cur = nextHead;
                curHead = nextHead;
                // 重置k
                curK = 0;
            }
            else{
                cur = cur->next;
            }
        }
        // 不加这句会导致循环链表
        lastNode->next = curHead;
        return dummyHead->next;
    }
};