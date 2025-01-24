bool detectLoop(Node* head) 
    {
        Node *slow=head;
        Node *fast=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }

