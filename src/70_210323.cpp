/*
  Climbing Stairs
https://leetcode.com/problems/climbing-stairs/
*/

#include <iostream>

using namespace std;

/*
 * 문제 : 1, 2를 조합해서 n을 만들 수 있는 경우의 수는?
 * 
 * 
 * 오랜만에 DP다.
 * 기억을 되살려보자.
 * 
 * 
 * 	1	1 = 1
 * 	2	2 = 1,1 / 2
 * 	3	3 = 1,1,1 / 2,1 / 1,2
 * 	5	4 = 1,1,1,1 / 2,1,1 / 1,2,1 / 1,1,2 / 2,2
 * 	8	5 = 1,1,1,1,1 / 2,1,1,1 / 1,2,1,1 / 1,1,2,1 / 2,2,1 / 1,1,1,2 / 2,1,2 / 1,2,2
 * 1 = 1이다
 * 2는 1의 결과에서 1을 더하거나 2이다. 여기까지는 DP로 풀 수 없는 정해진 영역이다.
 * 3은 2의 결과에서 1을 더하고, 1의 결과에서 2를 더했다.
 * 4는 3의 결과에서 1을 더하고, 2의 결과에서 2를 더했다.
 * 5는 4의 결과에서 1을 더하고, 3의 결과에서 2를 더했다.
 * ....
 * 즉 n은 = (n-1)과 (n-2)를 더한 값이다.
 * 
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) { // 3까지는 답이 1,2,3 이므로..
			return n;
		}
		int ret = 0; // return 값
		int m = 2; // n - 2
		int l = 3; // n - 1

		for(int i = 4; i <= n; i++) {
			ret = m + l;

			// m과 l을 각기 다음 n-2, n-1으로 업데이트한다.
			m = l;
			l = ret;
		}

		return ret; // l을 넘겨줘도 되지만, 어차피 m,l을 수정할 때 임시 변수 하나는 무조건 필요하므로, 그냥 코드 보기 쉽게 ret 쓰자.
    }
};

// 후기 : DP가 제일 재밌어

// Driver code 
int main() {
	Solution sol;
	int n = 2;

    sol.climbStairs(n);
	return 0;
}