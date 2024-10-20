class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        DLLNode *temp=head;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(temp && k--){
            pq.push(temp->data);
            temp=temp->next;
        }
        
        DLLNode *curr=head;
        while(curr){
            if(temp){
                pq.push(temp->data);
                temp=temp->next;
            }
            
            curr->data = pq.top();
            pq.pop();
            curr=curr->next;
        }
        
        return head;
    }
};
