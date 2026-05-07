1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        long long int prefix = 1;
5        long long int suffix = 1;
6        long long int ans = nums[0];
7        int n = nums.size();
8
9        for(int i=0;i<n;i++){
10            if(prefix == 0){
11                prefix = 1;
12            }
13            if(suffix == 0){
14                suffix = 1;
15            }
16
17            prefix *= nums[i];
18            suffix*= nums[n-1-i];
19
20            ans = max({ans, prefix,suffix});
21            
22        }
23        return (int)ans;
24    }
25};