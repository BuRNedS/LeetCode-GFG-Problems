 int maxDepth(Node* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    int travel(Node* root, int &ans, int &target){
        //if travel returns 0 this means target is not found in that part of the tree
        if(root == NULL){
            return 0;
        }
        
        // if the root is the target
        // we will calculate the maximum depth of the leaf node from the target on left and right side
        // This can be the potential answer
        // And return 1 as the target is in this half of the tree
        if(root->data == target){
            int lft = maxDepth(root->left);
            int rgt = maxDepth(root->right);
            ans = max(lft, rgt);
            return 1;
        }
        // If target was in the left subtree of the current node
        // lh will be returning some non-zero value
        // this will be ideally the distance of the current node with target node
        int lh = travel(root->left, ans, target);
        if(lh){
            // Now we will check for the right subtree depth of the current node
            // and compare its distance from target + right subtree depth with ans and update the ans 
            ans = max(ans, lh + maxDepth(root->right));
            // increment 1 as the current node will added to the distance, as we move upwards towards its parent
            return 1 + lh;
        }
        // If left subtree contains the target, this will be non-zero
        int rh = travel(root->right, ans, target);
        // And then we will compare ans variable with current distance + max depth of the left subtree of the current node
        if(rh){
            ans = max(ans, rh + maxDepth(root->left));
            // And we will add 1 to the current distance as for its parent node, the current node will also be part of the path
            return 1 + rh;
        }
        // if target is not found return 0
        return 0;
    }
    
    int minTime(Node* root, int target) {
        // This will be carry the time taken to burn the farthest node 
        int ans = 0;
        travel(root, ans, target);
        return ans;
    }
