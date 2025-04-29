Node* segregate(Node* h) {
        multiset<int> s;
        Node *p = h;
        
        while(p) s.insert(p->data), p = p->next;
        
        p = h;
        for(int i : s) p->data = i, p = p->next;
        
        return h;
}
