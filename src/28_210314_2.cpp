/*
  Implement strStr()
https://leetcode.com/problems/implement-strstr/
*/

#include <iostream>
#include <string>

using namespace std;

/*
 * 문제 : haystack에 needle이 있으면 index 리턴, 없으면 -1리턴, needle이 비어있다면 0 리턴
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
		if(needle == "") {
			return 0;
		}
		return haystack.find(needle, 0); // needle이 없을 경우 사전 정의된 npos가 반환되는데, default는 -1인가 보다.
	}
};

// 후기 : 이게 답이라니...

// Driver code 
int main() {
	Solution sol;
	string haystack = "helloo";
	string needle = "ll";

    sol.strStr(haystack, needle);
	return 0;
}