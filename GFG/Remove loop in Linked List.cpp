class Solution {
  public:
    void removeLoop(Node* head) {
        unordered_set<Node*>st;
        Node* trv = head;
        Node* prv = nullptr;
        while (trv != nullptr){
            if (st.find(trv) != st.end()){
                prv->next = nullptr;
                break;
            }
            st.insert(trv);
            prv = trv;
            trv = trv->next;
        }
    }
};
