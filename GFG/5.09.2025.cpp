class Solution {
  public:
    Node* segregate(Node* head) {
        int count0=0;
        int count1=0;
        int count2=0;
        Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->data==0)
            {
                count0++;
            }
            if(temp->data==1)
            {
                count1++;
            }
            if(temp->data==2)
            {
                count2++;
            }
            temp=temp->next;
        }
        Node* tempo = head;
        for(int i = 1;i<=count0;i++)
        {
          tempo->data=0;  
          tempo=tempo->next;
        }
        for(int i=1;i<=count1;i++)
        {
            tempo->data=1;
            tempo=tempo->next;
        }
        for(int i=1;i<=count2;i++)
        {
            tempo->data=2;
            tempo=tempo->next;
        }
        return head;
    }
};
