#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *i = headA;
    ListNode *j = headB;
    while (i != j) {
        if (i) {
            i = i->next;
        }
        else {
            i = headB;
        }

        if (j) {
            j = j->next;
        }
        else {
            j = headA;
        }
    }
    return i;
}


int main() {
    ListNode *inter = new ListNode(8);
    inter->next = new ListNode(4);
    inter->next->next = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = inter;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = inter;

    ListNode *result = getIntersectionNode(headA, headB);
    if (result) {
        std::cout << result->val;
    }
    else {
        std::cout << "nullptr";
    }
    return 0;
}
