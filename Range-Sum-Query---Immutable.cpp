1class NumArray {
2public:
3    vector<int> ans;
4    NumArray(vector<int>& nums) {
5        ans.resize(nums.size());
6        ans[0] = nums[0];
7        for(int i=1;i<nums.size();i++){
8            ans[i] = ans[i-1]+nums[i];
9        }
10    }
11    
12    int sumRange(int left, int right) {
13        if(left == 0){
14            return ans[right];
15        }
16        return ans[right]-ans[left-1];
17    }
18};
19
20/**
21 * Your NumArray object will be instantiated and called as such:
22 * NumArray* obj = new NumArray(nums);
23 * int param_1 = obj->sumRange(left,right);
24 */