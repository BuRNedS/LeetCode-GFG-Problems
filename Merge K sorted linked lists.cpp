class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& it : arr){
            Node* curr = it;
            while (curr){
                pq.push(curr->data);
                curr = curr->next;
            }
        }
        Node* head = new Node(-1000);
        Node* curr = head;
        while (!pq.empty()){
            int val = pq.top();
            pq.pop();
            Node* node = new Node(val);
            curr->next = node;
            curr = node;
        }
        return head->next;
    }
};

