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
    void calc_sum(ListNode* &temp1, ListNode* &temp2, int& sum, int& carry)
    {
        sum = (temp1->val) + (temp2->val) + carry;
        if(sum > 9)
        {
            carry = 1;
            sum = sum % 10;
        }
        else
        {
            carry = 0;

        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        int sum = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = nullptr;
        ListNode* tail = dummy;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* n_head = nullptr;

        while((temp1 != nullptr) && (temp2 != nullptr))
        {
            calc_sum(temp1,temp2,sum,carry);

            ListNode* temp = new ListNode(sum);
            if(n_head == nullptr)
            {
                //tail->next = temp;
                n_head = temp;
                //tail = tail->next;
            }
            //else
            //{
                tail->next = temp;
                tail = tail->next;
            //}

            temp1 = temp1->next;
            temp2 = temp2->next;
        
        }

        while(temp1 != nullptr)
        {
            
            sum = (temp1->val) + carry;
            if(sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            ListNode* temp = new ListNode(sum);
            if(n_head == nullptr)
            {
                //tail = temp;
                n_head = temp;
                //tail = tail->next;
            }
            //else
            //{
                tail->next = temp;
                tail = tail->next;
            //}

            temp1 = temp1->next;

        }

        while(temp2 != nullptr)
        {
            
            sum = (temp2->val) + carry;
            if(sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            ListNode* temp = new ListNode(sum);
            if(n_head == nullptr)
            {
                //tail = temp;
                n_head = temp;
                //tail = tail->next;
            }
            //else
            //{
                tail->next = temp;
                tail = tail->next;
            //}

            temp2 = temp2->next;

        }

        if(carry > 0)
        {
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
            tail = tail->next;
        }

        return n_head;

        
    }
};
