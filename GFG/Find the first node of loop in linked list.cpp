Node* findFirstNode(Node* head) {
        // your code here
        Node * slow = head , * fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (slow != fast) return NULL;
        slow = head ;
        while (slow != fast){
            slow = slow -> next;
            fast = fast -> next ;
        }
        return fast;

}
