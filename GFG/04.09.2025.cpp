class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(k<2) return head;
        Node* curr = head;
        Node* prev=nullptr;
        Node* left = nullptr;
        Node* leftO = nullptr;
        Node* newHead = nullptr;
        int n=0;
        while(curr!=nullptr){
            n++;
            if(n==k) newHead = curr;
            if(n%k==1){
                leftO = left;
                left = curr;
                Node* next = curr->next;
                curr->next = nullptr;
                prev = curr;
                curr = next;
            }
            else{
                Node* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(n%k==0&&leftO){
                leftO->next = prev;
                leftO = nullptr;
            }
        }
        if(leftO)leftO->next = prev;
        return newHead;
    }
};
