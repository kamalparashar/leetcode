1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int low = 0, mid = 0, high = nums.size()-1;
5        while(mid<=high){
6            if(nums[mid] == 0){
7                swap(nums[low],nums[mid]);
8                low++;
9                mid++;
10            }
11            else if(nums[mid] == 2){
12                swap(nums[mid],nums[high]);
13                high--;
14            }
15            else{
16                mid++;
17            }
18        }
19    }
20};