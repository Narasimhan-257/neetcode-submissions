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
    void reverse(ListNode* &head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* last = head->next;

        ListNode* temp = nullptr;





        while(last != nullptr)
        {
            temp = last->next;
            last->next = curr;
            curr->next = prev;
            prev = curr;
            curr = last;
            last = temp;
        }

        head = curr;


    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        dummy->next = head;

        ListNode* temp = head;
        ListNode* temp_head = head;

        int count = 0;
        ListNode* pre_head = nullptr;
        ListNode* res = nullptr;
        if(k > 1)
        {
            while(temp != nullptr)
            {
                temp = temp->next;
                //if(temp->next)
                //{
                    count++;
                    if(((count % (k-1)) == 0)&&(temp != nullptr))
                    {
                        res = temp->next;
                        //if(res != nullptr)
                        //{
                           temp->next = nullptr;
                           pre_head = temp_head;
                           reverse(temp_head);
                           tail->next = temp_head;
                           tail = pre_head;
                           temp_head = res;
                           count = 0;
                           temp = res;
                        //}
                        
                    }
    
    
                    // else if((temp == nullptr))
                    // {
                        
                    // }
    
                //}
    
            }
    
            if((count > 0) && (count <= k-1) && (temp == nullptr))
            {
                std::cout<<"Inside if at last:"<<"\n";
                tail->next = temp_head;
            }
        }

       ListNode* result = dummy->next;
       delete dummy;
       return result;
        
    }
};
