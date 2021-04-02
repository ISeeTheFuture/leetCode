/*
  Pascal's Triangle II
https://leetcode.com/problems/pascals-triangle-ii/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 문제 : 118이랑 완전히 동일. 단, 전체가 아닌 특정 줄만 리턴
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
    vector<int> getRow(int rowIndex) {
		vector<int> prev = {{1}};
		if(rowIndex == 0) {
			return prev;
		}
		vector<int> ret(rowIndex+1);

		for(int i = 1; i <= rowIndex; i++) {
			ret[0] = 1;
			ret[i] = 1;
			for(int j = 1; j < i; j++) {
				ret[j] = prev[j-1]+prev[j];
			}
			prev = ret;
		}

		return ret;
    }
};

// 후기 : 풀이보니 재귀함수를 썼었네..생각도 못했다.

// Driver code 
int main() {
	Solution sol;
	int rowIndex = 3;
    sol.getRow(rowIndex);
	return 0;
}