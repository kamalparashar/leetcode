1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int n = nums.size(), num = 0;
5        for(int i=0;i<n;i++){
6            num ^= nums[i]^(i+1);
7        }
8        return num;
9        
10    }
11};