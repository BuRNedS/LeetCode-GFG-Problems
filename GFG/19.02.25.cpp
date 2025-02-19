class Solution {
  public:
    void putData(Node* r,vector<int> &v){
        if(!r)
            return;
        v.push_back(r->data);
        putData(r->next,v);
        return;
        
    }
    Node* convertAtoL(int i,int n,vector<int> &arr){
        if(i==n)      
            return NULL;
        Node* temp = new Node(arr[i]);
        temp->next = convertAtoL(i+1,n,arr);
        return temp;    
    }
  
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        vector<int> allData;
        int n=arr.size();
        for(int i=0;i<n;i++){
            putData(arr[i],allData);
        }
        
        sort(allData.begin(),allData.end());
        
        int nn=allData.size();
        return convertAtoL(0,nn,allData);
        
        
    }
};
