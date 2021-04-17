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
        ListNode* redHead = head;
        do {
            if(head == NULL || redHead == NULL || redHead->next == NULL) { // redHead->next->next 할때 redHead->next가 NULL이면 죽어버린다.
                return false;
            }
            head = head->next;
            redHead = redHead->next->next; // 빨간색은 세 ㅂ...아니 두 배 빠르다!
        } while(redHead != head); // 만날때까지 돌린다. 못만나면? 둘은 운명이 아닌거겠지....?ㅠㅠ
        return true;
    }
};

// 이해하기는 이게 더 쉬운데, 같은 원리지만 효율 더 잘나오는걸로 한 번더 풀자

// Driver code 
int main() {
	Solution sol;
	ListNode head[] = {3,2,0,-4};
    int pos = 1;

    sol.hasCycle(head);
	return 0;
}