int getCount(struct Node* head) {
        int ans=0;
        while(head!=NULL)
        {
            head=head->next;
            ans++;
        }
        return ans;
    }
