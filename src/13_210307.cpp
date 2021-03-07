/*
  Palindrome Number
https://leetcode.com/problems/palindrome-number/
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
 * 문제 : 로마 숫자 변환기
 * 로마숫자 -> int로 바꾼다.
 * 범위는
 * I, V, X, L, C, D, M 까지
 * 
 * I    1
 * II   2
 * III  3
 * IV   4   5-1
 * V    5
 * VI   6
 * VII  7
 * VIII  8
 * IX   9   10-1
 * X    10
 * XI   11
 * XII  12
 * XIII 13
 * XLIX 49 50-10+10-1 
 * L    50
 * LI   51
 * LII  52
 * XCIX 99  100-10+10-1
 * C    100
 * CI   101
 * D    500
 * CM   900
 * M    1000
 * 
 * 
 * ex)
 * 3999
 * MMMCMXCIX
 */

class Solution {
public:
    int romanToInt(string s) {
        int no = 0;
        int rightNo = 0;

        stack<int> st;

        for(int i = 0; i < s.size(); i++){
            switch (s[i]) {
            case 'M':
                st.push(1000);
                break;
            case 'D':
                st.push(500);
                break;
            case 'C':
                st.push(100);
                break;
            case 'L':
                st.push(50);
                break;
            case 'X':
                st.push(10);
                break;
            case 'V':
                st.push(5);
                break;
            case 'I':
                st.push(1);
                break;
            }
        }

        // s를 왼쪽부터 오른쪽으로 stack에 담았다.
        // 이제 오른쪽부터 왼쪽순으로 숫자를 조립해 나간다.
        while(!st.empty()) {
            if(st.top() < rightNo) { // IV 인 경우 현재 숫자에서 I만큼 뺀다.
                no -= st.top();
                st.pop();
            } else { // 일반적인 경우 rightNo에 임시 저장만 하고 넘어간다.
                no += st.top();
                rightNo = st.top();
                st.pop();
            }
        }
        return no;
    }
};

// 후기 : 작년 취준 때 생각나는구만..ㅋㅋ 그떄 기억으로 스택을 썼는데, 제출하고 풀이를 보니 이렇게 푼 사람 없다. 그래도 성능은 잘 나와서 굳이 고칠 필요는 없는듯.

// Driver code 
int main() {
	Solution sol;
	string x = "MMMCMXCIX";
    sol.romanToInt(x);
	return 0;
}