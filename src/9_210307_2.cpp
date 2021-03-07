/*
  Palindrome Number
https://leetcode.com/problems/palindrome-number/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 문제 : 앞뒤가 똑같은 번호면 true
 * palindrome 이란 "회문"이란 뜻.
 * 
 * 
 * 풀이 : 이번엔 string 없이 진행. 그냥 x를 뒤집어 버리고 다시 x와 비교한다.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {// 일단 음수면 false
            return false;
        }

        int tmpX = x;
        long mem, revX = 0;

        while(tmpX != 0){ // 숫자 뒤집기
            mem = tmpX%10; // 잠깐 한자리 저장
            revX = revX*10 + mem; // 뒤집은 숫자 저장.

            tmpX /= 10;
        }

        if(x == revX){
            return true;
        }
        return false;
    }
};
// 후기 : 좀 낫네

// Driver code 
int main() {
	Solution sol;
	int x = 121;
    sol.isPalindrome(x);
	return 0;
}