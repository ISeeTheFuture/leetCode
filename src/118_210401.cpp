/*
  Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 문제 : 설명 힘듬. 그냥 링크 가서 볼 것.
 * 
 * 1
 * 1 1
 * 1 n0+n1 1
 * 1 n0+n1 n1+n2 1
 * 1 n0+n1 n1+n2 n2+n3 1
 * 
 */
class Solution {
public:
    vector< vector<int> > generate(int numRows) {
		vector< vector<int> > ret = {{1}};
        if(numRows == 1) {
			return ret;
		}
		vector<int> tmp1 = {1,1};
		ret.push_back(tmp1);
		if(numRows == 2) {
			return ret;
		}

		for(int i = 2; i < numRows; i++) {
			vector<int> tmp2(i+1);
			tmp2[0] = 1;
			tmp2[i] = 1;
			for(int j = 1; j < i; j++) {
				tmp2[j] = ret[i-1][j-1]+ret[i-1][j];
			}
			ret.push_back(tmp2);
		}

		return ret;
    }
};
// 후기 : 후기랄게 있나


// Driver code 
int main() {
	Solution sol;
	int numRows = 5;
    sol.generate(numRows);
	return 0;
}