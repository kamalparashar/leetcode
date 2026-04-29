1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int n = nums.size(), ans=0;
5        vector<int> pref(n);
6        pref[0] = nums[0];
7        for(int i=1;i<n;i++){
8            pref[i] = pref[i-1] + nums[i];
9        }
10        unordered_map<int,int> mp;
11        for(int i=0;i<n;i++){
12            if(pref[i] == k){
13                ans++;
14            }
15            if(mp.find(pref[i]-k) != mp.end()){
16                ans += mp[pref[i]-k];
17            }
18            mp[pref[i]]++;
19        }
20        return ans;
21    }
22};