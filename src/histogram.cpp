#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int maxArea(const vector<int> vec, const int start, const int end)
{
    if (start > end)
    {
        return 0;
    }
    
    if (start == end)
    {
        return vec[start];
    }
    
    int min = vec[start];
    int index = start;
    int i = start;    
    
    while (i <= end)
    {
        if (vec[i] < min)
        {
            min = vec[i];
            index = i;
        }
        
        ++i;
    }
    
    int minArea = min * (end - start + 1);
    
    int minLeft = maxArea(vec, start, index - 1);
    int minRight = maxArea(vec, index + 1, end);
    
    if (minArea < minLeft)
    {
        minArea = minLeft;
    }
    
    if (minArea < minRight)
    {
        minArea = minRight;
    }
    
    return minArea;
}

int largestRectangleArea(vector<int> &height) {
    //wirte your code hero
    
    if (0 == height.size())
    {
        return 0;
    }
    
    return maxArea(height, 0, height.size() - 1);
}



//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{   
    // 
    return 0;
} 
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。