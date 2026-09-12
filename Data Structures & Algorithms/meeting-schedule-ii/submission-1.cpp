/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n  = intervals.size();
        if(n==0)return 0;
        vector<int>start,end;
        for(int i=0;i<n;i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        int room = 1,i=1,j=0,res =1;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        while(i<n && j<n){
            if(start[i] < end[j]){
                room++;
                i++;
            }else if(start[i] > end[j]){
                room--;
                j++;
            }else {
                i++;
                j++;
            }
            res = max(res,room);
        }
        return res;
    }
};
