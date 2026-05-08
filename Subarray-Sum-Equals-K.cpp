1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int n = nums.size();
5        long long int psum = 0; //prefix_sum
6        int count = 0;
7        unordered_map<int,int> mp;
8        mp[0] = 1;  //k=3 and psum till now is also 3
9
10        for(int i=0;i<n;i++){
11            psum += nums[i];
12            if(mp.find(psum-k) !=mp.end()){
13                count += mp[psum-k];
14            }
15            mp[psum]++;
16        }
17
18        return count;
19    }
20};