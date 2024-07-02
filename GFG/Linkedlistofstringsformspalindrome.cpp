bool compute(Node* head) {
        // Your code goes here
        string s="";
        Node* node=head;
        while(node){
            s+=node->data;
            node=node->next;
        }
        int i=0, j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
