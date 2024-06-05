//https://leetcode.com/problems/add-two-numbers/
struct ListNode* applyAdditionOperation(struct ListNode* l1, struct ListNode* l2, int carry) {
    if (l1 == NULL && l2 == NULL && carry == 0) return NULL;
    
    //Sum numbers
    int sum = carry;
    sum += (l1 == NULL) ? 0 : l1->val;
    sum += (l2 == NULL) ? 0 : l2->val;

    //Find next nodes
    struct ListNode* l1Next = (l1 == NULL) ? NULL : l1->next;
    struct ListNode* l2Next = (l2 == NULL) ? NULL : l2->next;
    
    //Initialize current node
    struct ListNode* root = malloc(sizeof(struct ListNode));
    root->val = sum % 10;
    root->next = applyAdditionOperation(l1Next, l2Next, sum / 10);
    return root;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return applyAdditionOperation(l1, l2, 0);
}
