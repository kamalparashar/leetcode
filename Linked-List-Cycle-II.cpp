1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    ListNode *detectCycle(ListNode *head) {
12        //Floyd’s Cycle-Finding Algorithm (Tortoise and the Hare)
13        if(!head){
14            return head;
15        }
16        ListNode *slow = head;
17        ListNode *fast = head;
18        //detecting whether cycle is present or not
19        while(fast && fast->next){
20            slow = slow->next;
21            fast = fast->next->next;
22            if(slow == fast){
23                break;
24            }
25        }
26        if(!fast || !fast->next){
27            return NULL;
28        }
29
30        // finding the node from which loop starts
31        slow = head;
32        while(slow != fast){
33            slow = slow->next;
34            fast = fast->next;
35        }
36        return slow;
37    }
38};