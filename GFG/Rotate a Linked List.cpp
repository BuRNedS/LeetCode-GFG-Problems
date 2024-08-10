class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node*temp=head;
        Node*ptr=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        while(k!=0)
        {
            head=head->next;
            ptr->next=NULL;
            temp->next=ptr;
            temp=ptr;
            ptr=head;
            k--;
        }
        return head;
        
    }
};
