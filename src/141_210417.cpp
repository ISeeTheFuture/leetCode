/*
  Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 문제 : linked list가 순환하면 true 리턴
 * 
 * 
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* redHead = head;
        do {
            if(head == NULL || redHead == NULL || redHead->next == NULL) {
                return false;
            }
            head = head->next;
            redHead = redHead->next->next;
        } while(redHead != head);
        return true;
    }
};

// Driver code 
int main() {
	Solution sol;
	ListNode head[] = {3,2,0,-4};
    int pos = 1;

    sol.hasCycle(head);
	return 0;
}