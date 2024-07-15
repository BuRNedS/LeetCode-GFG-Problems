class Solution {
  public:
    string smallestNumber(int s, int d) {
    int num = 0, place = 1;
    
    for (int i=d; i>1; i--) {
        int n = min(s-1, 9);
        num = n * place + num;
        
        s -= n;
        place *= 10;
    }
    
    if (s/10 != 0) return to_string(-1);
    
    return to_string(place * max(1, s) + num);
}
};
