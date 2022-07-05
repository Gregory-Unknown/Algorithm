#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head) return NULL;
    if (head->next == NULL) return head;
    ListNode* tmp = head;
    ListNode* tmpNode = new(ListNode);
    int flag = 0;
    while (tmp->next) {
        if (!flag) {
            tmpNode->val = tmp->val;
            tmp->val = tmp->next->val;
            tmp->next->val = tmpNode->val;
            flag = 1;
        } else
            flag = 0;
        tmp = tmp->next;
    }
    delete tmpNode;
    return head;
}

int main() {
    ListNode l1(5);
    ListNode l2(4, &l1);
    ListNode l3(3, &l2);

    ListNode l4(2, &l3);
    ListNode l5(1, &l4);

    ListNode *res = swapPairs(&l5);
    std::cout << "Res : " << std::endl;
    for (ListNode *tmp = res; tmp != nullptr; tmp = tmp->next) {
        std::cout << tmp->val << " " << std::endl;
    }
}