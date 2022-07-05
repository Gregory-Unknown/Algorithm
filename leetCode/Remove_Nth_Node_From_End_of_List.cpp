#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head)
        return nullptr;
    ListNode* tmp = head;
    int size = 0;
    while (tmp){
        ++size;
        tmp = tmp->next;
    }
    tmp = head;
    if (n == 1 && size == 1) return nullptr;
    int num = 0;
    if (n > size) return head;
    if (n < size) {
        num = size - n - 1;
        if (num < 0)
            return nullptr;
        while (num-- > 0)
            tmp = tmp->next;
    } else if (n == size)
        head = tmp->next;
    tmp->next = tmp->next->next;
    return head;
}

int main()
{
    ListNode l1(5);
    ListNode l2(4, &l1);
    ListNode l3(3, &l2);

    ListNode l4(2, &l3);
    ListNode l5(1, &l4);

    ListNode *res = removeNthFromEnd(&l5, 4);
    std::cout << "Res : " << std::endl;
    for (ListNode *tmp = res; tmp != nullptr; tmp = tmp->next) {
        std::cout << tmp->val << " " << std::endl;
    }

}