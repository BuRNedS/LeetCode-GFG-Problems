int intersectPoint(Node* head1, Node* head2) {
        unordered_map<Node*,bool>mp;
        int ans=-1;
        while(head1!=NULL){
            mp[head1]=true;
            head1=head1->next;
        }
        while(head2!=NULL){
            if(mp[head2]==true) {
                ans=head2->data;
                return ans;
            }
            head2=head2->next;
        }
        return ans;
    }
