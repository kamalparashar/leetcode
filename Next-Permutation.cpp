1class Solution {
2public:
3    void nextPermutation(vector<int>& nums) {
4        //approach 1: 
5        // 1.generate all permutation(in (inc.) order)
6        // 2.linear search the given permutaion
7        // 3.return the next permutation to it
8
9        //approach 2:
10        // 1.use stl function:= next_permutation(arr.begin(), arr.end())
11        // it will return the next permutation
12
13        //approach3:(optimal)(how stl function work)
14        // 1. find dip in arr from end(ind)
15        // 2. find element greater than  at ind, but smallest (just greater) & swap them
16        // 3. reverse the remaining arr (ind+1, n)
17
18        int ind = -1, n=nums.size();
19        for(int i=n-2;i>=0;i--){
20            if(nums[i]<nums[i+1]){
21                ind = i;
22                break;
23            }
24        }
25        if(ind == -1){
26            reverse(nums.begin(), nums.end());
27        }
28        else{
29
30        for(int i=n-1;i>ind;i--){
31            if(nums[i] > nums[ind]){
32                swap(nums[i], nums[ind]);
33                break;
34            }
35        }
36        reverse(nums.begin()+ind+1, nums.end());
37        }
38    }
39};