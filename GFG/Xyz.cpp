
if(k==0)return head;
        int len=1;
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
            len++;
        }
        k=k%len;
        if(k==0)
        {
            return head;
        }
            temp->next=head;
            Node* nwt=head;
            for(int i=1;i<k;i++)
             nwt=nwt->next;
            Node *nwh=nwt->next;
            nwt->next=NULL;
            return nwh;
    }
