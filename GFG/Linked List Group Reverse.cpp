Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* dummy=new Node(-1);
        Node* temp=head;
        Node* dummy1=dummy;
        while(temp!=NULL){
            Node* it=temp,*prev=NULL,*nxt=NULL;
            int cnt=1;
            while(cnt<=k && it!=nullptr){
                nxt=it->next;
                it->next=prev;
                prev=it;
                it=nxt;
                cnt++;
            }
            dummy->next=prev;
            dummy=temp;
            temp=it;
        }
        return dummy1->next;
    }

