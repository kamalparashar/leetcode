1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        vector<int> ans;
5        deque<int> q;
6        int n = nums.size();
7
8        for(int i=0;i<k;i++){
9            while(!q.empty() && q.back() < nums[i]){
10                q.pop_back();
11            }
12            q.push_back(nums[i]);
13        }
14        ans.push_back(q.front());
15
16        for(int i=k;i<n;i++){
17            if(!q.empty() && q.front()==nums[i-k]){
18                q.pop_front();
19            }
20            while(!q.empty() && q.back() < nums[i]){
21                q.pop_back();
22            }
23            q.push_back(nums[i]);
24            ans.push_back(q.front());
25        }
26        return ans;
27    }
28};