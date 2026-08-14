class MinStack 
{
public:
    struct node
    {
        int data;
        int curr_min;
        node* next;

        node()
        {
            data = INT_MIN;
            curr_min = INT_MAX;
            next = nullptr;
        }
    };

    node* head;

    MinStack() 
    {
        head = nullptr;
    }
    
    void push(int val) 
    {
        node* temp = new node();
        temp->data = val;
        temp->next = head;
        
        if(head != nullptr)
        {
            if(val < head->curr_min)
            {
                temp->curr_min = val;
                //std::cout<<temp->curr_min<<"\n";
            }
            else
            {
                //std::cout<<"Inside else:"<<"\n";
                temp->curr_min = head->curr_min;
                //std::cout<<temp->curr_min<<"\n";
            }
        }
        else
        {
            //first node case
            temp->curr_min = val;
        }
        head = temp;


    }
    
    void pop() 
    {
        node* temp = head;
        head = head->next;
        if(temp != nullptr)
        {
            delete temp;
        }
        temp = nullptr;
    }
    
    int top() 
    {
        int val = head->data;
        return val;
        
    }
    
    int getMin() 
    {
        int mini = head->curr_min;
        return mini;
    }
};
