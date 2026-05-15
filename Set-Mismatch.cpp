1class Solution {
2public:
3    vector<int> findErrorNums(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> temp(n+1), ans(2);
6        for(auto &i: nums){
7            temp[i]++;
8        }
9        for(int i=1;i<n+1;i++){
10            if(temp[i]>1){
11                ans[0] = i;
12            }
13            else if(temp[i] == 0){
14                ans[1] = i;
15            }
16        }
17        return ans;
18    }
19};