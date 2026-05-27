1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n = s1.length(), m = s2.length();
5        sort(s1.begin(),s1.end());
6
7        for(int i=0;i<m-n+1;i++){
8            string s = s2.substr(i,n);
9            sort(s.begin(),s.end());
10            if(s1 == s){
11                return true;
12            }
13        }
14        return false;
15    }
16};