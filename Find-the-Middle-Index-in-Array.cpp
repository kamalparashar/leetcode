1class Solution {
2public:
3    int findMiddleIndex(vector<int>& nums) {
4        int n = nums.size(), total_sum = 0;
5        vector<int> prefix(n+1,0);
6
7        for(int i:nums){
8            total_sum += i;
9        }
10
11        for(int i=0;i<n;i++){
12            prefix[i+1] = prefix[i] + nums[i];
13        }
14
15        for(int i=0;i<n;i++){
16            int leftmost = prefix[i];
17            int rightmost = total_sum - leftmost - nums[i];
18            // cout<<i<<" "<<leftmost<<" "<<rightmost<<"\n";
19            if(leftmost == rightmost){
20                return i;
21            }
22        }
23        return -1;
24
25    }
26};