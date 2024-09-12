class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int count(Node* head){
        int c=0;
        Node* temp=head;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        return c;
        
    }
    int getMiddle(Node* head) {
        // code here
        int n=count(head);
        Node* temp=head;
        int m=n/2;
        while(m){
            temp=temp->next;
            m--;
        }
        return temp->data;
    }
};

