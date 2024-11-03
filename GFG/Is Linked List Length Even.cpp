struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        Node *temp = *head;
        int l=0;
        while(temp != NULL){
            l++;
            temp = temp->next;
        }
        
        if(l%2 == 0){
            return true;
        }
        
        return false;
    }
};
