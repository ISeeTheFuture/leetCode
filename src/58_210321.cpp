/*
  Length of Last Word
https://leetcode.com/problems/length-of-last-word/
*/

#include <iostream>
#include <string>

using namespace std;

/*
 * 문제 : 마지막 단어 하나의 길이를 구하라
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int sLen = s.size() - 1;
		int ret = 0;
		bool start = false; // 맨 뒤에 ' ' 가 있을 경우도 고려해야 한다.

		for(int i = sLen; i >= 0; i--) {
			if(s[i] != ' ') { // 공백이 아닌 경우
				start = true; // 이제부터 셈 시작.
				ret++;
			} else if (s[i] == ' ' && start == true) { // 다시 공백을 만난 경우
				return ret;
			}
		}
		return ret;
    }
};

// Driver code 
int main() {
	Solution sol;
	string s = "Hello World";

    sol.lengthOfLastWord(s);
	return 0;
}