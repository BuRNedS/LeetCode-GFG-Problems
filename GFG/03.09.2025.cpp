class Solution {
  public:
    Node* reverse(Node* head) {
        Node* temp = NULL;
        Node* curr = head;

        while (curr != NULL) {
            // Swap prev and next pointers
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Move to the next node in the original list
            curr = curr->prev;
        }

        // After the loop, temp will be pointing to the previous node of the last node
        if (temp != NULL) {
            head = temp->prev;
        }

        return head;
    }
};
