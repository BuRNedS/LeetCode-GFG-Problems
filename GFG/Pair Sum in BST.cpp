class Solution {
  public:
  
    unordered_map<int,int> map;
    
    bool preorder(Node* root, int target) {
        
        if(root == nullptr){
            return false;
        }
        if(map.find(target - root->data) != map.end()){
            return true;
        }
        map[root->data] = 1;
        if(preorder(root->left,target)) return true;;
        if(preorder(root->right,target)) return true;
        
        return false;
    }
    
    bool findTarget(Node *root, int target) {
        // your code here.
        if(preorder(root,target)){
            return true;
        }
        return false;
    }
