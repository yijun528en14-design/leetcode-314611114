using namespace std;

/**
 * Definition for singly-linked list.
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKthNode(groupPrev, k);
            if (kth == nullptr) break;

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }

private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};