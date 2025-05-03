bool isprime(int num){
   /// int i = 1;
   if (num <= 1) return false;
    for (int i=2; i<=sqrt(num) ; i++){
        if (num %i == 0){
            return false;
        }
    }
    return true;
}


int neigh(int num) {
    if (isprime(num)) return num; // If num is already prime
    
    int l = num - 1;
    int h = num + 1;

    while (true) {
        if (l >= 2 && isprime(l)) return l;
        if (isprime(h)) return h;
        l--;
        h++;
    }
}

class Solution {
  public:
    Node *primeList(Node *head) {
        // code here
        Node *ptr = head;
        while(ptr){
            if (!isprime(ptr->val) ){
                ptr->val = neigh(ptr->val);
            }
            ptr = ptr->next;
        }
        return head;
    }
};
