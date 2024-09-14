class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        queue<int> pos;
    queue<int> neg;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0) {
            pos.push(arr[i]);
        } else {
            neg.push(arr[i]);
        }
    }

    int index = 0;
    while (!pos.empty() && !neg.empty()) {
        arr[index++] = pos.front();
        pos.pop();
        arr[index++] = neg.front();
        neg.pop();
    }
    while (!pos.empty()) {
        arr[index++] = pos.front();
        pos.pop();
    }

    while (!neg.empty()) {
        arr[index++] = neg.front();
        neg.pop();
    }
    }
};
