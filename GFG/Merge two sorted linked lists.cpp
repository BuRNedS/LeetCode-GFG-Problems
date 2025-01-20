Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* ptr =NULL;
        Node* ans = NULL;
        if(head1->data <= head2->data){
            ptr = head1;
            ans = head1;
            head1 = head1->next;
        }
        else {
            ptr = head2;
            ans = head2;
            head2 = head2->next;
        }
        
        while(head1 && head2){
            if(head1->data <= head2->data){
                ptr->next = head1;
                ptr = ptr->next;
                head1 = head1->next;
            }
            else{
                ptr->next = head2;
                ptr = ptr->next;
                head2 = head2->next;
            }
        }
        while(head1){
            ptr->next = head1;
            ptr = ptr->next;
            head1 = head1->next;
        }
        while(head2){
            ptr->next = head2;
            ptr = ptr->next;
            head2 = head2->next;
        }
        return ans;
    }
