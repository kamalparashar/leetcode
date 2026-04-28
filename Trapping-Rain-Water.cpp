1class Solution {
2public:
3    int trap(vector<int>& height) {
4
5    // Approach: prefix_sum(for blocks in between) and two-pointer to calc actual trap water
6    // once from l->r and then from r->l
7
8        int i=0, j=1;
9        int ans = 0, n = height.size();
10
11        //for blocks volume 
12        vector<int> pref(n);
13        pref[0] = height[0];
14        for(int k=1;k<n;k++){
15            pref[k] = pref[k-1]+height[k];
16        }
17
18        //left->right
19        while(i<j && j<n){
20            if(height[j]>=height[i]){
21                int total_water = (height[i]*(j-i-1));
22                int block_in_between = (pref[j]-pref[i]-height[j]);
23                int actual_trap_water = total_water - block_in_between;
24                ans += actual_trap_water;
25                i=j;
26                j++;
27            }
28            else{
29                j++;
30            }
31        }
32
33        //right->left
34        j=n-1;
35        i=n-2;
36        while(i<j && i>=0){
37            if(height[i] > height[j]){                  // did not implemented >= because we will we counting it double 
38                int total_water = (height[j]*(j-i-1));  // if pillars length is same e.g., [2,0,2]
39                int block_in_between = (pref[j]-pref[i]-height[j]);
40                int actual_trap_water = total_water - block_in_between;
41                ans += actual_trap_water;
42                j=i;
43                i--;
44            }
45            else{
46                i--;
47            }
48        }
49        return ans;
50    }
51};
52
53