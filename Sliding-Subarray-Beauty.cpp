1class Solution {
2public:
3    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
4        int n = nums.size();
5        vector<int> ans;
6        map<int, int> mp;
7
8        for (int i = 0; i < k; i++) {
9            mp[nums[i]]++;
10        }
11        int count = 0;
12        for (auto m : mp) {
13            if(m.first < 0){
14                count += m.second;
15            }
16            if (count >= x) {
17                ans.push_back(m.first);
18                break;
19            }
20        }
21        if(count < x){
22            ans.push_back(0);
23        }
24
25        for (int i = k; i < n; i++) {
26            mp[nums[i - k]]--;
27            if (mp.count(nums[i - k]) == 0) {
28                mp.erase(nums[i - k]);
29            }
30            mp[nums[i]]++;
31            int count = 0;
32            for (auto m : mp) {
33                if(m.first < 0){
34                    count += m.second;
35                }
36                if (count >= x) {
37                    ans.push_back(m.first);
38                    break;
39                }
40            }
41            if(count < x){
42                ans.push_back(0);
43            }
44        }
45        return ans;
46    }
47};