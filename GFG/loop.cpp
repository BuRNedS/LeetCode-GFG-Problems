class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        unordered_map<Node*, int> mp;
        Node* ptr = head;
        while(ptr){
            if(mp[ptr]) break;
            mp[ptr] = ptr->data;
            ptr = ptr -> next;
        }
        int len = 0;
        if(ptr){
            Node* ptr2 = ptr;
            while(ptr2){
                ptr2 = ptr2 -> next;
                len++;
                if(ptr2 == ptr) break;
            }
        }
        return len;
    }
};
