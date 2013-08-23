/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == intervals.size())
        {
            intervals.push_back(newInterval);
            
            return intervals;
        }
        
        int i = 0;
        int j = intervals.size() - 1;
        
        while (i <= j)
        {
            if (i == j)
            {
                if (intervals[i].start < newInterval.start)
                {
                    ++i;
                    break;
                }
            }
            
            int mid = i + ((j - i) >> 1);
            
            if (intervals[mid].start == newInterval.start)
            {
                i = mid;
                break;
            }
            else if (intervals[mid].start > newInterval.start)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        
        if (i == intervals.size())
        {
            intervals.push_back(newInterval);
            
            if (intervals[i-1].end >= intervals[i].start)
            {
                if (intervals[i-1].end < intervals[i].end)
                {
                    intervals[i-1].end = intervals[i].end;
                }
                
                intervals.erase(intervals.end() - 1);
            }
            
            return intervals;
        }
        
        vector<Interval>::iterator it = intervals.begin() + i;
        
        intervals.insert(it, newInterval);
        
        it = intervals.begin() + i;
        
        if (i > 0)
        {
            if ((*it).start <= intervals[i-1].end)
            {
                --it;
            }
        }
        
        vector<Interval>::iterator it2 = it + 1;
        
        while (it2 != intervals.end())
        {
            if ((*it).end < (*it2).start)
            {
                break;
            }
            
            if ((*it).end < (*it2).end)
            {
                (*it).end = (*it2).end;
            }
            
            intervals.erase(it2);
            
            it2 = it + 1;
        }
        
        return intervals;
    }
};
