/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        if(head != nullptr)
        {
          ListNode* last = head->next;
          while(curr != nullptr)
          {
            last = curr->next;
            curr->next = prev;
            prev = curr;
            curr = last;
          }
        }
        return prev;
    }
    void reorderList(ListNode* head) 
    {
        if(head->next == nullptr)
        {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = (fast->next)->next;
            slow = slow->next;
        }
        ListNode* mid = slow;
        ListNode* head2 = mid->next;
        mid->next = nullptr;
        head2 = reverse(head2);

        ListNode* temp = head;
        ListNode*temp1 = nullptr;
        temp1 = temp->next;
        while(head2 != nullptr)
        {
            temp1 = temp->next;
            temp->next = head2;
            head2 = head2->next;
            (temp->next)->next = temp1;
            temp = temp1;

        }
        
    }
};
