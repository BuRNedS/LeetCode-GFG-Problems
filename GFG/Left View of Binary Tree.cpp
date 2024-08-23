vector<int> leftView(Node *root)
{
   // Your code here
   
   // vector to store the answer
   vector<int> ans;
   
   // queue to store and perform level order traversal
   queue<Node*> q;
   
   // push root node to queue
   q.push(root);
   
   // performing level-order traversal
   while(!q.empty()){
       
       int sz=q.size();
       
       // iterate over elements on a particular level
       for (int i=0;i<sz;i++){
          
           Node* curr=q.front();
           q.pop();
           
           // i=0 means first left element in that particular level so store it in answer vector
           if(i==0){ 
               ans.emplace_back(curr->data);
           }
       
           // curr node has left push it into queue 
           if(curr->left) {
               q.push(curr->left);
           }
       
           // curr node has right push it into queue
           if(curr->right){
               q.push(curr->right);
           }
       }
   }
   
   // return answer vector
   return ans;
}

