1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> pref(n,0), suff(n,0), ans(n,0);
6
7        pref[0] = 1;
8        suff[n-1] = 1;
9        
10        for(int i=1;i<n;i++){
11            pref[i] = pref[i-1]*nums[i-1];
12        }
13        for(int i=n-2;i>=0;i--){
14            suff[i] = suff[i+1]*nums[i+1];
15        }
16        for(int i=0;i<n;i++){
17            ans[i] = (pref[i]*suff[i]);
18        }
19        return ans;
20    }
21};