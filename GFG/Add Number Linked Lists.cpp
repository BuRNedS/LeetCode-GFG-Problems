Node* reverse(Node* head){
        if(!head || !head->next) return head;
        
        Node* anshead=reverse(head->next);
        Node* front=head->next;
        head->next=NULL;
        front->next=head;
        return anshead;
    }
  
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        int carry=0;
        Node* temp1=reverse(num1),*temp2=reverse(num2);
        
        Node* ans=new Node(-1);
        Node* dummy=ans;
        
        while(temp1 || temp2){
            int sum=carry;
            if(temp1){
                sum+=temp1->data;
                temp1=temp1->next;
            } 
            if(temp2){
                sum+=temp2->data;
                temp2=temp2->next;
            }
            
            dummy->next=new Node(sum%10);
            carry=sum/10;
            dummy=dummy->next;
        }
        
        if(carry){
            dummy->next=new Node(carry);
            dummy=dummy->next;
        }
        
        ans=ans->next;
        Node* updatedans=reverse(ans);
        while(updatedans && updatedans->data==0){
            updatedans=updatedans->next;
        }
        
        return updatedans;
    }
