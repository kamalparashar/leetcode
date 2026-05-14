1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int ans=0,i=0,j=height.size()-1;
5        while(i<j){
6            ans = max(ans, (j-i)*min(height[i],height[j]));
7            if(height[i]<height[j]){
8                i++;
9            }
10            else{
11                j--;
12            }
13        }
14        return ans;
15
16    }
17};