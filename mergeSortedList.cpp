/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        if(pHead1 == nullptr) return pHead2;
        if(pHead2 == nullptr) return pHead1;

        auto dummy = new ListNode(0);
        ListNode* pre = dummy;

        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                pre->next = pHead1;
                pHead1 = pHead1->next;
                pre = pre->next;
            }
            else{
                pre->next= pHead2;
                pHead2 = pHead2->next;
                pre = pre->next;
            }
        }
        if(pHead1) pre->next = pHead1;
        if(pHead2) pre->next = pHead2;

        return dummy->next;
    }
};