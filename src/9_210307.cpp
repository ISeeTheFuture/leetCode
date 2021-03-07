/*
  Palindrome Number
https://leetcode.com/problems/palindrome-number/
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * 문제 : 앞뒤가 똑같은 번호면 true
 * palindrome 이란 "회문"이란 뜻.
 * 
 * 
 * 풀이 : string화 시켜서 앞에서 절반 뒤에서 절반 읽으면 되겠네.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int len = str.size();
        for(int i = 0; i < len/2; i++){
            if(str[i] != str[len-i-1]){
                return false;
            }
        }
        return true;
    }
};
// 후기 : 틀리지도 않고 효율도 나름 상위권. 근데 to_string 안쓰고 숫자로만 푸는게 더 효율적이다.


// Driver code 
int main() {
	Solution sol;
	int x = 121;
    sol.isPalindrome(x);
	return 0;
}