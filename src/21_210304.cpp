/*
  Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*
 * 문제 : l1과 l2를 오름차순으로 병합하라.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
		ListNode* retNext = ret;
		while(l1!=NULL||l2!=NULL){
			if(l1!=NULL&&l2==NULL){
				retNext->next = l1;
				l1 = l1->next;
			} else if(l1==NULL&&l2!=NULL){
				retNext->next = l2;
				l2 = l2->next;
			} else if(l1->val >= l2->val) {
				retNext->next = l2;
				l2 = l2->next;
			} else if(l1->val < l2->val){
				retNext->next = l1;
				l1 = l1->next;
			}
			retNext = retNext->next;
		}
		return ret->next;
    }
};

// 후기 : 어렵지는 않은데.. 포인터를 적재적소에 사용하는 것은 아직도 헷갈린다.

// Driver code 
int main() {
	Solution sol;
  	ListNode *l1;
	ListNode *l2;
	
	sol.mergeTwoLists(l1, l2);
	
	return 0;
}