Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node* curr=head;
        while(curr){
            Node* temp=new Node(curr->data);
            temp->next=curr->next;
            curr->next=temp;
            curr=curr->next->next;
        }
        curr=head;
        while(curr){
            Node* temp=curr->next;
            if(curr->random) temp->random=curr->random->next;
            else temp->random=NULL;
            curr=curr->next->next;
        }
        curr=head;
        Node* newHead=curr->next;
        Node* prev=NULL;
        while(curr){
            Node* temp=curr->next;
            curr->next=temp->next;
            curr=curr->next;
            if(prev) prev->next=temp;
            prev=temp;
        }
        return newHead;
    }
