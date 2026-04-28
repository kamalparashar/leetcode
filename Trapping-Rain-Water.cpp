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
18        int total_water, block_in_between, actual_trap_water;
19
20        //left->right
21        while(i<j && j<n){
22            if(height[j]>=height[i]){
23                total_water = (height[i]*(j-i-1));
24                block_in_between = (pref[j]-pref[i]-height[j]);
25                actual_trap_water = total_water - block_in_between;
26                ans += actual_trap_water;
27                i=j;
28                j++;
29            }
30            else{
31                j++;
32            }
33        }
34
35        //right->left
36        j=n-1;
37        i=n-2;
38        while(i<j && i>=0){
39            if(height[i] > height[j]){                  // did not implemented >= because we will we counting it double 
40                total_water = (height[j]*(j-i-1));  // if pillars length is same e.g., [2,0,2]
41                block_in_between = (pref[j]-pref[i]-height[j]);
42                actual_trap_water = total_water - block_in_between;
43                ans += actual_trap_water;
44                j=i;
45                i--;
46            }
47            else{
48                i--;
49            }
50        }
51        return ans;
52    }
53};
54
55