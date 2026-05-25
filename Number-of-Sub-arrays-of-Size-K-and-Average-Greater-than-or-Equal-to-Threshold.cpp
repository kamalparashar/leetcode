1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
4        int count = 0, n = arr.size();
5        int sum = 0;
6        for(int i=0;i<k;i++){
7            sum += arr[i];
8        }
9        if(sum >= threshold*k){
10            count++;
11        }
12        for(int i=k;i<n;i++){
13            sum += (arr[i]-arr[i-k]);
14            if(sum >= threshold*k){
15                count++;
16            }
17        }
18        return count;
19    }
20};