1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int i=0, j=numbers.size()-1;
5        while(i<j){
6            if(numbers[i]+numbers[j] == target){
7                return {i+1, j+1};
8            }
9            else if(numbers[i]+numbers[j] < target){
10                i++;
11            }
12            else{
13                j--;
14            }
15        }
16        return {};
17    }
18};