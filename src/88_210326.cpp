/*
  Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 문제 : 정렬된 두 벡터 배열을 병합하라. 단, 정렬된 상태여야 한다
 * 
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if(m == 0) {
			nums1 = nums2;
		} else if(n > 0) {
			for(int i = m; i < m+n; i++){
				nums1[i] = nums2[i-m];
			}
			sort(nums1.begin(), nums1.end());
		}
    }
};
// 후기 : 너무 단순하게 생각해서 그런가 효율이 안나온다. 다시 풀자.


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