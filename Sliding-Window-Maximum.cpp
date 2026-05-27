1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        // read cp handbook sliding window
5        
6        vector<int> ans;
7        deque<int> q;
8        int n = nums.size();
9
10        for(int i=0;i<k;i++){
11            while(!q.empty() && q.back() < nums[i]){
12                q.pop_back();
13            }
14            q.push_back(nums[i]);
15        }
16        ans.push_back(q.front());
17
18        for(int i=k;i<n;i++){
19            if(!q.empty() && q.front()==nums[i-k]){
20                q.pop_front();
21            }
22            while(!q.empty() && q.back() < nums[i]){
23                q.pop_back();
24            }
25            q.push_back(nums[i]);
26            ans.push_back(q.front());
27        }
28        return ans;
29    }
30};