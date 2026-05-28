1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n = s1.length(), m = s2.length();
5        vector<int> freq1(26,0);
6        vector<int> freq2(26,0);
7        
8        for(auto &s:s1){
9            freq1[s-'a']++;
10        }
11
12        int i=0, j=0;
13        while(i<m && j<m){
14            freq2[s2[j]-'a']++;
15
16            while(j-i+1 > n){
17                freq2[s2[i]-'a']--;
18                i++;
19            }
20            if(j-i+1 == n){
21                bool b = true;
22                for(int k=0;k<26;k++){
23                    if(freq1[k]!=freq2[k]){
24                        b = false;
25                        break;
26                    }
27                }
28                if(b){
29                    return true;
30                }
31            }
32            j++;
33        }
34        return false;
35    }
36};