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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {

        using NodePair = std::pair<int,ListNode*>;
        std::priority_queue<NodePair,std::vector<NodePair>,std::greater<NodePair>>minheap;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != nullptr)
            {
               minheap.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = nullptr;
        ListNode* tail = dummy;
        ListNode* new_head = nullptr;
        while(!minheap.empty())
        {
            NodePair p1 = minheap.top();
            minheap.pop();
            ListNode* temp = p1.second;
            if(new_head == nullptr)
            {
                new_head = temp;
            }
            tail->next = temp;
            tail = tail->next;
            if(temp->next)
            {
                int val = (temp->next)->val;
                minheap.push({val,temp->next});
            }
        }
         
        return new_head;

    }
};
