class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.size() <= 1)
        {
            return 0;
        }
        
        int i = 0;
        int j = height.size() - 1;
        
        int maxArea = 0;
        int currArea = 0;
        
        while (i < j)
        {
            if (height[i] < height[j])
            {
                currArea = height[i] * (j - (i++));
            }
            else
            {
                currArea = height[j] * ((j--) - i);
            }
            
            if (currArea > maxArea)
            {
                maxArea = currArea;
            }
        }
        
        return maxArea;
    }
};
