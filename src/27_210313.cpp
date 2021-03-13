/*
  Remove Element
https://leetcode.com/problems/remove-element/
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 문제 : 벡터 nums에서 val의 값과 같은 숫자를 제거하라.
 * 
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator iter = nums.begin();
		while(iter != nums.end()) {
			if(*iter == val) {
				nums.erase(iter);
			} else {
                iter++;    
            }
		}
		return nums.size();
    }
};

// iterator를 써서 모르고 넘어갈뻔. vector는 포인터 구조인것 같다. nums[i] = nums[j] 로 nums[i]를 nums[j] 자리로 보내버릴 수 있다.

// Driver code 
int main() {
	Solution sol;
	vector<int> nums;
	int val;

    sol.removeElement(nums, val);
	return 0;
}