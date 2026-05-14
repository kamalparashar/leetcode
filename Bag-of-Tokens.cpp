1class Solution {
2public:
3    int bagOfTokensScore(vector<int>& tokens, int power) {
4        sort(tokens.begin(), tokens.end());
5        int i=0, j = tokens.size()-1, score = 0;
6
7        while(i<=j){
8            if(score==0 && power<tokens[i] && power<tokens[j]){
9                return 0;
10            }
11            if(power >= tokens[i]){
12                score++;
13                power -= tokens[i];
14                i++;
15            }
16            else if(power >= tokens[j]){
17                score++;
18                power -= tokens[j];
19                j--;
20            }
21            else if(score > 0 && i!=j){
22                if(tokens[i] > tokens[j]){
23                    power += tokens[i];
24                    i++;
25                }
26                else{
27                    power += tokens[j];
28                    j--;
29                }
30                    score--;
31            }
32            else{
33                i++;
34                j--;
35            }
36
37        }
38        return score;
39    }
40};