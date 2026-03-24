#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */

class Solution {
public:
    // 合併兩條排序 linked list
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // 剩下哪一條沒接完，直接接上去
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
    }

    // 分治合併 lists[left...right]
    ListNode* mergeRange(vector<ListNode*>& lists, int left, int right) {
        if (left > right) return nullptr;
        if (left == right) return lists[left];

        int mid = left + (right - left) / 2;

        ListNode* l1 = mergeRange(lists, left, mid);
        ListNode* l2 = mergeRange(lists, mid + 1, right);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeRange(lists, 0, (int)lists.size() - 1);
    }
};