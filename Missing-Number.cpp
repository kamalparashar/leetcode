1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int n = nums.size();
5        vector<bool> v(n+1,0);
6        for(int i:nums){
7            v[i] = 1;
8        }
9        for(int i=0;i<=n;i++){
10            if(!v[i]){
11                return i;
12            }
13        }
14        return -1;
15        
16    }
17};