1class Solution {
2public:
3    int waysToSplitArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<long long int> prefix(n);
6
7        prefix[0] = nums[0];
8
9        for(int i=1;i<n;i++){
10            prefix[i] = prefix[i-1] + nums[i];
11        }
12
13        int count = 0;
14
15        for(int i=0;i<n-1;i++){
16            long long int left = prefix[i];
17            long long int right = prefix[n-1] - prefix[i];
18            if(left >= right){
19                count++;
20            }
21        }
22        return count;
23    }
24};