class SpecialQueue {
  private:
  queue<int> q;
  deque<int> mindq;
  deque<int> maxdq;
  
  public:
    void enqueue(int x) {
        q.push(x);
        while(!mindq.empty() and mindq.back()>x)mindq.pop_back();
        mindq.push_back(x);
        
        while(!maxdq.empty() and maxdq.back()<x)maxdq.pop_back();
        maxdq.push_back(x);
    }

    void dequeue() {
        if(mindq.front() == q.front())mindq.pop_front();
        if(maxdq.front() == q.front())maxdq.pop_front();
        q.pop(); 
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return mindq.front();
    }

    int getMax() {
        return maxdq.front();
    }
};
