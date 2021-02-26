/*
  Delete Node in a Linked List
https://leetcode.com/problems/delete-node-in-a-linked-list/
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*
 * 문제 : LinkedList에서 주어진 값을 삭제하라.
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};

	// 후기 : 아래처럼 풀어도 된다. 속도는 비슷하던데, 왜 똑같은지 모르겠다. 당연히 포인터가 빨라야 하지 않나?
    // node->val = node->next->val;
	// node->next = node->next->next;

// Driver code 
int main() {
	Solution sol;
  	ListNode *node;
	
	sol.deleteNode(node);
	
	return 0;
}