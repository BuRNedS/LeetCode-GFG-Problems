class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node*tail=head;
        while(tail->next!=head) tail=tail->next;
        
        if(data<head->data){
            Node*node=new Node(data);
            node->next=head;
            tail->next=node;
            return node;
        }
        if(data>tail->data){
            Node*node=new Node(data);
            tail->next=node;
            node->next=head;
            return head;
        }
        
        Node*temp1=head;
        Node*temp2=NULL;
        while(temp1->data<data){
            temp2=temp1;
            temp1=temp1->next;
        }
        
        Node*node=new Node(data);
        
        temp2->next=node;
        node->next=temp1;
        
        return head;
    }
};

