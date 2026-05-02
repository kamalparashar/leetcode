1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        vector<vector<int>> ans;
5
6        sort(intervals.begin(), intervals.end());
7        
8        int start = intervals[0][0];
9        int end = intervals[0][1];
10
11        for(int i=1;i<intervals.size();i++){
12            if(end >= intervals[i][0]){
13                if(end <= intervals[i][1]){
14                    end = intervals[i][1];
15                }
16            }
17            else{
18                ans.push_back({start,end});
19                start = intervals[i][0];
20                end = intervals[i][1];
21            }
22        }
23        ans.push_back({start, end});
24        return ans;
25    }
26};