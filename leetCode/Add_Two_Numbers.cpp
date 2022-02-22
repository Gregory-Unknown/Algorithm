#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* tmp1 = l1, *tmp2 = l2;
    int flag = 0;
    for (; tmp1 && tmp2; tmp1 = tmp1->next, tmp2 = tmp2->next) {
        if (flag) {
            tmp1->val += 1;
            
            flag = 0;
        }
        if (tmp1->val + tmp2->val > 9) {
            tmp1->val = tmp2->val = (tmp1->val + tmp2->val) % 10;
            flag = 1;
        }
        else
            tmp1->val = tmp2->val = tmp1->val + tmp2->val;
    }
    if (tmp1) {
        for (; tmp1; tmp1 = tmp1->next) {
            if (flag) {
                tmp1->val += 1;
                flag = 0;
            }
            if (tmp1->val > 9) {
                tmp1->val = tmp1->val % 10;
                flag = 1;
            }
        }
    }
    if (tmp2) {
        for (; tmp2; tmp2 = tmp2->next) {
            if (flag) {
                tmp2->val += 1;
                flag = 0;
            }
            if (tmp2->val > 9) {
                tmp2->val = tmp2->val % 10;
                flag = 1;
            }
        }
        if (flag) {
            tmp2 = l2;
            for(; tmp2->next; tmp2 = tmp2->next) ;
            if (!tmp2->next)
                tmp2->next = new(ListNode);
            tmp2->next->val = 1;
        }
        return (l2);
    }
    if (flag) {
        tmp1 = l1;
        for(; tmp1->next; tmp1 = tmp1->next) ;
        if (!tmp1->next)
            tmp1->next = new(ListNode);
        tmp1->next->val = 1;
    } 
    return (l1);
}

int main()
{
    ListNode l11(3);
    ListNode l12(4, &l11);
    ListNode l13(2, &l12);

    ListNode l21(4);
    ListNode l22(6, &l21);
    ListNode l23(5, &l22);

    ListNode *res = addTwoNumbers(&l13, &l23);
    std::cout << "Res : " << std::endl;
    for (ListNode *tmp = res; tmp != nullptr; tmp = tmp->next) {
        std::cout << tmp->val << " " << std::endl;
    }

}