void nearlySorted(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k + 1);
    int j = 0;
    for (int i = k + 1; i < arr.size(); i++)
    {
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        arr[j++] = pq.top();
        pq.pop();
    }
}
