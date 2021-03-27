/*
  Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 문제 : 정렬된 두 벡터 배열을 병합하라. 단, 정렬된 상태여야 한다
 * 
 * 이번에는 정렬를 사용하지 않고, 병합 중에 정렬이 되도록 풀자
 * 뒤에서부터 다시 쓰면 되네..
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int nums1Idx = m - 1; // 뒤에서부터 시작
		int nums2Idx = n - 1;
		int retIdx = m + n - 1;
		
		while(nums1Idx >= 0 && nums2Idx >= 0) {
			if(nums1[nums1Idx] > nums2[nums2Idx]) {
				nums1[retIdx--] = nums1[nums1Idx--];
			} else {
				nums1[retIdx--] = nums2[nums2Idx--];
			}
		}
		while(nums2Idx >= 0) { // nums1 은 이미 정렬되어 있고 리턴값이니, nums2가 아직 남아있다면, nums2만 처리하면 된다.
			nums1[retIdx--] = nums2[nums2Idx--];
		}
    }
};

// Driver code 
int main() {
	Solution sol;
	vector<int> nums1 = {1,2,3,0,0,0};
	int m = 3;
	vector<int> nums2 = {2,5,6};
	int n = 3;
    sol.merge(nums1, m, nums2, n);
	return 0;
}