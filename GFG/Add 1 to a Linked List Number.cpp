Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        int carry=1;
        Node* temp=head;
        while(carry!=0 && temp!=NULL){
            int sum=temp->data+carry;
            temp->data=sum%10;
            carry=sum/10;
            if(temp->next!=NULL){
                 temp=temp->next;
            }
            else{
                break;
            }
        }
        if(carry>0){
            Node* newNode=new Node(carry);
            temp->next=newNode;
        }
        head=reverse(head);
        return head;
    }
