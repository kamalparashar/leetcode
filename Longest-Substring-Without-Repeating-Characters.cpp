1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        if(s.length()<= 1){
5            return s.length(); 
6        }
7        int i=0,j=0, n=s.length(), ans = INT_MIN, count = 0;
8        unordered_map<char, pair<int,int>> v;
9        while(j<n){
10            if(v.find(s[j]) != v.end()){
11                count = j-i;
12                for(int k=i;k<v[s[j]].first;k++){
13         v.erase(s[k]);
14                }
15                i=v[s[j]].first+1;
16                v[s[j]].first = j;
17                ans = max(ans, count);
18            }
19            else{
20                v.insert({s[j], {j,1}});
21            }            
22            j++;
23        }
24        count = j-i;
25        ans = max(ans,count);
26        return ans;
27    }
28};