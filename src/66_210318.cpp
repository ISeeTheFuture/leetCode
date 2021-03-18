/*
  Plus One
https://leetcode.com/problems/plus-one/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 문제 : 양수의 십진수 배열에 1을 더한다. 배열은 그 자체로 숫자를 의미한다. 각 요소는 한 자리 수이다.
 * 
 * 예) {9,9,9}를 넣으면 {1,0,0,0}이 답이다.
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size()-1;

		while(idx>=0) {
			if(idx==0&&digits[idx]==9) {
				digits[idx] = 0;
				digits.insert(digits.begin(),1);
				break;
			}
			if(digits[idx]!=9) {
				digits[idx] += 1;
				break;
			}
			digits[idx] = 0;
			idx--;
		}
		return digits;
    }
};

// 후기 : 후기랄게 없다. 왜 이게 답인지 모를 정도로 허술하게 풀리고 모범답안도 다를 바가 없어서.. 문제 의도를 모르겠네. 뭘 공부하란 의도지?

// Driver code 
int main() {
	Solution sol;
	vector<int> digits = {1,2,3};

    sol.plusOne(digits);
	return 0;
}