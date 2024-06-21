#include "iostream"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode *merge_two_list(ListNode *l1, ListNode *l2) {
            ListNode *dummy = new ListNode(0);
            ListNode *cur = dummy;
            while(l1 != nullptr && l2 != nullptr){
                if(l1->val < l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                }else{
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            if(l1 != nullptr){
                cur->next = l1;
            }
            if(l2 != nullptr){
                cur->next = l2;
            }
            return dummy->next;
        }
};

int main(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode *result = s.merge_two_list(l1, l2);
    while(result != nullptr){
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
