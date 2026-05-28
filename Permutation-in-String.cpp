1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n = s1.length(), m = s2.length();
5        sort(s1.begin(),s1.end());
6
7        map<char,int> mp;
8
9        for(auto &s:s1){
10            mp[s]++;
11        }
12
13        for(int i=0;i<m-n+1;i++){
14            string s = s2.substr(i,n);
15            map<char,int> mp2;
16
17            for(auto &j:s){
18                mp2[j]++;
19            }
20            
21            if(mp == mp2){
22                return true;
23            }
24        }
25        return false;
26    }
27};