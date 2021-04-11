/*
  Valid Palindrome
https://leetcode.com/problems/valid-palindrome/
*/

#include <iostream>
#include <string>

using namespace std;

/*
 * 문제 : 앞뒤가 똑같은 문자열. 단 대소문자 구분없으며, 특수문자 무시. 문제엔 안쓰여 있는데 숫자도 고려해야된다..
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int leftIdx = 0;
        int rightIdx = s.size() - 1;

        while(leftIdx < rightIdx) {
            char leftChar = tolower(s[leftIdx]);
            char rightChar = tolower(s[rightIdx]);

            if(!((leftChar >= 97 && leftChar <= 122)||(leftChar >= 48 && leftChar <= 57))) { // 왼쪽이 소문자도 숫자도 아니면
                leftIdx++; // 패스
            } else if(!((rightChar >= 97 && rightChar <= 122)||((rightChar >= 48 && rightChar <= 57)))) { // 오른쪽이 소문자도 숫자도 아니면
                rightIdx--; // 패스
            } else { // 양쪽이 소문자거나 숫자면
                if(leftChar != rightChar) { // 다르면 바로 실패
                    return false;
                }
                leftIdx++;
                rightIdx--;
            }
        }
        return true;
    }
};

// Driver code 
int main() {
	Solution sol;
	string s = "A man, a plan, a canal: Panama";
    sol.isPalindrome(s);
	return 0;
}