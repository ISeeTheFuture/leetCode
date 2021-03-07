/*
  Two Sum
https://leetcode.com/problems/two-sum/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 문제 : 합이 tartget이 되도록 주어진 nums 벡터 배열에서 두 개의 수를 추출.
 * 조건 : 답은 한 가지가 아닐 수 있지만, 한 가지 경우만 구하면 된다.
 * 
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums.at(i)+nums.at(j) == target){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};
// 후기 : 쉽긴 한데, 더 효율적인 방법이 있지 않았었나?

// Driver code 
int main() {
	Solution sol;
    vector<int> nums = {2,11,15,7};
	int target = 9;
    sol.twoSum(nums, target);
	return 0;
}