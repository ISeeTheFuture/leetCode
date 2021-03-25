/*
  Remove Duplicates from Sorted List
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

#include <iostream>

using namespace std;

/*
 * 문제 : 받은 배열에서 중복을 제거한다. 해당 배열은 오름차순으로 이미 정렬되어 있다.
 * 
 * linked list문제
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode* currNode = head;
		ListNode* nextNode;

		if(currNode == NULL) {
			return head;
		}

		while(currNode->next != NULL) {
			if(currNode->val == currNode->next->val) { // 현재노드 == 다음 노드라면,
				nextNode = currNode->next->next; // 다음 노드를 다다음으로 연결한다.
				currNode->next = nextNode;
			} else {
				currNode = currNode->next; // 아니라면, 그냥 다음으로 넘어간다.
			}
		}

		return head;
    }
};

// Driver code 
int main() {
	Solution sol;
	ListNode head[] = {1,1,2,3,3};

    sol.deleteDuplicates(head);
	return 0;
}