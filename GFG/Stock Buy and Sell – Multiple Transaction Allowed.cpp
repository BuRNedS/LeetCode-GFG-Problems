class Solution {
public:
    int stockBuyAndSell(int n, int price[]) {
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (price[i] > price[i - 1])
                profit += price[i] - price[i - 1];
        }
        return profit;
    }
};
