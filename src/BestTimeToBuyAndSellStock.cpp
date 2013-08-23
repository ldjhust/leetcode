class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == prices.size())
        {
            return 0;
        }
        
        // 动态规划：maxProfit[i] = max{maxProfit[i-1], prices[i] - min{prices[0], ..., prices[i-1]}}}
        
        int min = prices[0];
        int maxProfit = 0;
        
        for (vector<int>::size_type i = 1; i < prices.size(); ++i)
        {
            if ((prices[i] - min) > maxProfit)
            {
                maxProfit = prices[i] - min;
            }
            
            if (prices[i] < min)
            {
                min = prices[i];
            }
        }
        
        return maxProfit;
    }
};
