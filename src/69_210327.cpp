/*
  Sqrt(x)
https://leetcode.com/problems/sqrtx/
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
 * 문제 : 제곱근을 구하라. 단 내림해서 정수만 반환하라.
 * 
 * 제곱근 구하는 것 자체는 쉽다.
 * 얼마나 효율적으로 풀 수 있는가 묻는 듯.
 * 
 * 일단 제곱근은 x의 절반보다 무조건 작거나 같다.
 * 이후 이분탐색하면 될듯.
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
		if(x < 2) {
			return x;
		}
		int left = 1;
		int right = x/2;

		while(left <= right) {
			int mid = (left + right)/2;

			if(mid == x/mid) {
				return mid;
			} else if(mid < x/mid) {
				left = mid + 1;
			} else if(mid > x/mid) {
				right = mid-1;
			}
		}
		return right;
    }
};

// Driver code 
int main() {
	Solution sol;
	int x = 255;

    cout << sol.mySqrt(x) << endl;
	return 0;
}