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
    void QuickSort(vector<Interval> &v, const int first, const int last)
    {
        if (first >= last)
        {
            return;
        }
        
        int i = first;
        int j = last;
        Interval tmp = v[first];
        
        while (i < j)
        {
            while ((i < j) && (v[j].start > tmp.start))
            {
                --j;
            }
            
            if (i < j)
            {
                v[i] = v[j];
                ++i;
            }
            
            while ((i < j) && (v[i].start <= tmp.start))
            {
                ++i;
            }
            
            if (i < j)
            {
                v[j] = v[i];
                --j;
            }
        }
        
        v[i] = tmp;
        
        QuickSort(v, first, i - 1);
        QuickSort(v, i + 1, last);
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size() <= 1)
        {
            return intervals;
        }
        
        QuickSort(intervals, 0, intervals.size() - 1);
        
        vector<Interval>::iterator it1 = intervals.begin();
        vector<Interval>::iterator it2 = it1 + 1;
        
        while (it2 != intervals.end())
        {
            if ((*it1).end >= (*it2).start)
            {
                if ((*it2).end > (*it1).end)
                {
                    (*it1).end = (*it2).end;
                }
                
                intervals.erase(it2);
                
                it2 = it1 + 1;
            }
            else
            {
                it1 = it2;
                ++it2;
            }
        }
        
        return intervals;
    }
};