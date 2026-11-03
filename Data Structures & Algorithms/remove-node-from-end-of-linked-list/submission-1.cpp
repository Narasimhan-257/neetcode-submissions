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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {

        int f_count = 0;
        int s_count = 1;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != nullptr)
        {
            if(fast != nullptr)
            {
                fast = fast->next;
                f_count++;
            }
            else if(fast == nullptr)
            {
                if(n == f_count)
                {
                    ListNode* newHead = head->next;
                    delete head;
                    return newHead;
                }
                if(f_count-s_count == n)
                {
                    if(slow->next)
                    {
                        ListNode* temp = (slow->next)->next;
                        // if(slow == head)
                        // {
                        //     head = slow->next;
                        // }
                        //free(slow->next);
                        delete(slow->next);
                        slow->next = temp;
                        break;
                    }
                    else
                    {
                        cout<<"Inside else!";
                        slow = nullptr;
                        head = slow;
                    }

                }
                else
                {
                    slow = slow->next;
                    s_count++;
                }
            }
        }

        return head;
        
    }
};
