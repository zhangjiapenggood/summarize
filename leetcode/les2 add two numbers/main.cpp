#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    static int carry = 0;
    if(l1 == nullptr && l2 ==nullptr && carry == 0){
        return nullptr;
    }
    ListNode *ret = new ListNode();
    if (l1 == nullptr){
        l1 = new ListNode();
    }
    if(l2 == nullptr){
        l2 = new ListNode();
    }
    int tmp = 0;
    tmp = l1->val + l2->val + carry;
    if (tmp >= 10){
        ret->val = tmp%10;
        carry = 1;
    }
    else{
        ret->val = tmp;
        carry = 0;
    }
    ret->next = addTwoNumbers(l1->next,l2->next);
    return ret;
}

int main()
{
    ListNode tmp1;
    tmp1.val = 1;
    tmp1.next = new ListNode(2);
    ListNode tmp2;
    tmp2.val =3;

    ListNode *ret = addTwoNumbers(&tmp1,&tmp2);
    while(ret != nullptr){
        cout << ret->val <<endl;
        ret = ret->next;
    }
    return 0;
}
