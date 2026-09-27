/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         std::unordered_map<Node*,Node*>hmap;
        Node* root1 = head;
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while((root1) != NULL)
        {
            Node* temp = new Node(root1->val);
            //temp->val = root1->val;
            tail->next = temp;
            temp->next = NULL;
            hmap[root1] = temp;
            root1 = root1->next;
            tail = tail->next;
        }
        Node* root2 = dummy->next;
        root1 = head;
        while(root2 != NULL)
        {
            if(hmap.find(root1->random) != hmap.end())
            {
                root2->random = hmap[root1->random];
            }
            else
            {
                root2->random = NULL;
            }
            root2=root2->next;
            root1=root1->next;
        }
        root2 = dummy->next;
        return root2;
        
    }
};
