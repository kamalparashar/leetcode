1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        //{TC, SC}
5        //1. using map if it frequency occures twice , that's the duplicate {O(n), O(n)}
6        // use array of size : n+1 traverse nums, insert each num freq,if freq is already one that's the duplicate {O(n), O(n)}
7
8        // 2. works only for +ve numbers but modifies the array(sign flipping)  {O(N) O(1)}
9        // traverse array, for each element x(say), make nums[x] = -nums[x] (flipping the element)
10        // if it is already visited i.e., nums[x] is already -ve, then return x as the answer.
11
12
13        // 3. using the bove approach and fast & slow pointer, No need to modify the array  {O(N) O(1)}
14
15        int slow = nums[0];
16        int fast = nums[0];
17
18        //using do-while as both have same value now
19        do{
20            slow = nums[slow];
21            fast = nums[nums[fast]];
22        }while(slow != fast);
23
24        slow = nums[0];
25
26        while(slow != fast){
27            slow = nums[slow];
28            fast = nums[fast];
29        }
30
31        return slow;
32    }
33};