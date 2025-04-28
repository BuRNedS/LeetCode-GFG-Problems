class Solution {
  public:
    void getMaxUtil(Node *root, int *withRoot, int *withoutRoot)
    {
        if(root == NULL)
        {
            *withRoot = 0;
            *withoutRoot = 0;
            return;
        }
        // Tree-DP
        // Node can be part of answer or not
        int leftWithChild = 0, leftWithoutChild = 0;
        int rightWithChild = 0, rightWithoutChild = 0;
        getMaxUtil(root->left, &leftWithChild, &leftWithoutChild);
        getMaxUtil(root->right, &rightWithChild, &rightWithoutChild);
        *withRoot = root->data + leftWithoutChild + rightWithoutChild;
        *withoutRoot = max(leftWithChild, leftWithoutChild) + 
                    max(rightWithChild, rightWithoutChild);
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // code here
        int withRoot =0, withoutRoot =0;
        getMaxUtil(root, &withRoot, &withoutRoot);
        return max(withRoot, withoutRoot);
        
    }
};
