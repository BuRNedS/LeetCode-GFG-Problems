class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> vals;
        function<void(Node*)> func = [&](Node *curr) -> void {
            if (!curr) {
                vals.push_back(0);
                return;
            }
            vals.push_back(curr->data);
            func(curr->left);
            func(curr->right);
            return;
        };
        func(root);
        return vals;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        Node *head=new Node(arr[0]);
        int idx=0;
        function<void(Node*)> func = [&](Node *curr) -> void {
            idx++;
            if(arr[idx]){
                curr->left = new Node(arr[idx]);
                func(curr->left);
            }
            idx++;
            if(arr[idx]){
                curr->right = new Node(arr[idx]);
                func(curr->right);
            }
        };
        func(head);
        return head;
    }
};
