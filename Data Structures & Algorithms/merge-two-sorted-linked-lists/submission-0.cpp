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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* new_head = nullptr;
        while((temp1 != nullptr) && (temp2 != nullptr))
        {
          ListNode * new_node = new ListNode();
          if(temp1->val < temp2->val)
          {
            new_node->val = temp1->val;
            temp1 = temp1->next;
          }
          else
          {
            new_node->val = temp2->val;
            temp2 = temp2->next;
          }
          new_node->next = nullptr;
          if(new_head == nullptr)
          {
            new_head = new_node;
          }
          tail->next = new_node;
          tail = tail->next;
        }

        while(temp1 != nullptr)
        {
          ListNode * new_node = new ListNode();
          new_node->val = temp1->val;

          new_node->next = nullptr;
          if(new_head == nullptr)
          {
            new_head = new_node;
          }
          tail->next = new_node;
          tail = tail->next;
          temp1 = temp1->next;
          
        }

        while(temp2 != nullptr)
        {
          ListNode * new_node = new ListNode();
          new_node->val = temp2->val;

          new_node->next = nullptr;
          if(new_head == nullptr)
          {
            new_head = new_node;
          }
          tail->next = new_node;
          tail = tail->next;
          temp2 = temp2->next;
          
        }

       return new_head; 
    }
};
