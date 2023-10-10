/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/* 哈希表记录原链表和新链表节点 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* newHead = new Node(head->val);
        unordered_map<Node*, Node*> mp;
        mp[head] = newHead;
        Node* pre = newHead;
        Node* old = head;
        old = old->next;
        while(old != nullptr){
            Node* node = new Node(old->val);
            pre->next = node;
            pre = node;
            mp[old] = node;
            old = old->next;
        }

        Node* h1 = newHead;
        Node* h2 = head;
        while(h2 != nullptr){
            h1->random = mp[h2->random];
            h2 = h2->next;
            h1 = h1->next;
        }

        return newHead;
    }
};