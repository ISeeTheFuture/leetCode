/*
  Valid Parentheses
https://leetcode.com/problems/valid-parentheses/
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
 * 문제 : 괄호가 쌍이 맞는지 확인!
 * () : true
 * (){}[] : true
 * (] : false
 * ([)] : false
 * 
 */

class Solution {
public:
    bool isValid(string s) {
		int sLen = s.length();
		
		if(sLen%2 == 1) { // 괄호가 홀수개면 애초에 짝이 안맞다.
			return false;
		}
		
		stack<char> st;

    	for(int i = 0; i < sLen; i++) {
			char tmp = s[i];
			if(tmp == '(') {
				st.push(')');
			} else if(tmp == '{') {
				st.push('}');
			} else if(tmp == '[') {
				st.push(']');
			} else {
				if(st.empty() || tmp != st.top()) { // for문이 끝날때까지 st가 비는 경우가 있어서는 안된다. 빈다면 괄호를 열지도 않고 닫으려는 경우이므로 false. 두번째 경우는 괄호 짝이 안맞는 경우이므로 false
					return false;
				}
				st.pop();
			}
		}
		if(!st.empty()) { // st이 남아있는 경우 : 괄호를 열기만 하고 안닫은채 for문을 나왔다.
			return false;
		}
		return true;
	}	
};
// 후기 : 제출 후 풀이를 보니 알아보기 어렵게 풀어놨다. 오랜만에 다른 사람 코드보다 내 코드가 더 읽기 쉬운 것 같아 뿌듯하네.

// Driver code 
int main() {
	Solution sol;
	string strs = "()[]{}";
    sol.isValid(strs);
	return 0;
}