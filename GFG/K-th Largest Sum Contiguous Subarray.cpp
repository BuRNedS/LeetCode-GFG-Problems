  int n=arr.size();
               priority_queue<int>pq;
              for(int i=0;i<n;i++){
                  
                    int sum=0;
                    
                    for(int j=i;j<n;j++){
                         
                         sum+=arr[j];
                         pq.push(sum);
                    }
                      
                  
              }
              
              
              
              while (k>1){
                   pq.pop();
                   k--;
              }
              
              return pq.top();
