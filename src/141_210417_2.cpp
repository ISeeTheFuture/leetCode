/*
  Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 문제 : linked list가 순환하면 true 리턴. 중복값이 있을 수 있다는 것에 유의...
 * 
 * 만약 리스트가 순회한다면, head와 두배 빠른 redHead는 언젠가 만난다.
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) {
            return false;
        }
        ListNode* redHead = head;

        while(redHead->next && redHead->next->next) {
            redHead = redHead->next->next;
            head = head->next;
            if(head == redHead) {
                return true;
            }
        }
        return false;
    }
};

// 이전보다 검사를 덜하니 속도가 더 빠를 줄 알았는데, 똑같다. 별 보람 없구만.

// Driver code 
int main() {
	Solution sol;
	ListNode head[] = {3,2,0,-4};
    int pos = 1;

    sol.hasCycle(head);
	return 0;
}