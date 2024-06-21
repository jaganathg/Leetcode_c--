
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }

    ListNode* Leetcode_Solution(ListNode* head, int val) {
    ListNode* begin = head;
    ListNode* prev = nullptr;
    ListNode* next= nullptr;
    while (head != nullptr)
    {
        if (head->val == val)
        {
            if (begin == head)
                begin = head->next;
            next = head->next;
            if(prev!=nullptr)
                prev->next = next;
        }
        else
        {
            prev = head;
        }
        head = head->next;
    }
        return begin;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    Solution solution;
    ListNode* res = solution.removeElements(head, 6);
    while (res) {
        std::cout << res->val << " ";
        res = res->next;
    }
    return 0;
}