/**
 * 문제. 진법과 배수의 성질을 이루는 수 구하기
 * (Question) 진법이 주어졌을때 특정 수의 성질을 만족하는 수를 구하시오.
 * 10진수에서 숫자 3과 숫자 9는 특별한 성질을 갖고 있습니다.
 * 3의 배수의 각 자릿수의 합은 다른 3의 배수가 되는 성질입니다. 예를 들어 118 X 3 = 354이고, 이때 구해진 354의 값을 자릿수 별로 더한값 3 + 5 + 4 = 12는 3의 배수가 됩니다.
 * 마찬가지로 9의 배수역시 각 자릿수의 합은 다른 9의 배수가됩니다. 예를 들면 75 X 9 = 674이고 6 + 7 + 5 = 18은 역시 9의 배수가 됩니다.
 * 10진법에서 3과 9가 아닌 다른 수는 어떨까요? 숫자 4를 예로 들어볼까요?
 * 13 X 4 = 52이고, 5 + 2 = 7이므로 4의 배수가 되지 않으므로 10진법에서 숫자 4는 위 성질을 만족하지 않는 수입니다.
 * 어떤 진법에서 이러한 성질은 갖는다고 다른 진법에서 이러한 성질을 가지지는 않습니다.
 * 예를 들어 10진수에서 3은 이러한 성질을 가지지만 5진수에서 3은 이러한 성질을 갖지 않지요.
 * 여기서 문제입니다.
 * base 진법이 주어졌을 때 이러한 성질을 가진 수를 오름차순으로 모두 리턴하세요(0과 1은 제외합니다.)
 * 어떤 수가 이러한 성질을 가지는지 알고자 모든 숫자의 곱을 고려할 필요는 없습니다.
 * 만약 4자리 미만의 곱으로 성립되면 더 큰 자리에서도 성립된다 할 수 있습니다. 예를 들어 10진수에서는 999보다 큰 숫자를 고려하지 않아도 됩니다. 마찬가지로 5진수에서는 444보다 큰 숫자를 고려하지 않아도 됩니다.
 * 
 * 
 * 함수의 정의
 * vector<int> get_digits(int base) {
 *  ...
 * }
 * 
 * 
 * 제약조건
 * base : 3 ~ 30의 정수
 * 
 * 입력     반환
 * 3    /   2
 * 9    /   2, 4, 8
 * 10   /   3, 9
 * 21   /   2, 4, 5, 10, 20
 * 26   /   5, 25
 * 30   /   29
 * 
 * 
 * 
 * 답은 아는데 풀이를 모르겠네...
 * 
 * 답은 "입력 - 1" 과 그 수의 약수이다. 왠지는 모르겠다..
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>

class Solution {

private:
    /**
     * 약수를 구한다
     * @param src 약수를 구할 수
     * @return 구한 약수를 vector로 리턴.
     */
    std::vector<int> get_divisor(const int src) {
        std::vector<int> ret;
        for(int i = 1; i*i <= src; i++) {
            if(src % i == 0) {
                ret.push_back(src/i);
                if(i == 1) { // 1은 생략
                    continue;
                }
                ret.push_back(i);
            }
        }
        std::sort(ret.begin(), ret.end()); // 보기쉽게 오름차순 정렬
        ret.erase(std::unique(ret.begin(), ret.end()), ret.end()); // 중복 요소 제거
        return ret;
    }
    /**
     * target과 multiple의 곱인 n의 각 자리수를 모두 더한다. 계산 과정은 base 진법으로 하나 더한 결과는 편의상 10진수이다.
     * @param target
     * @param multiple  곱할 배수
     * @param base      계산할 진법
     * @return 각 자리수의 합(10진수)
     */
    long sum_digitsByMultiple(const int target, const int multiple, const int base) {
        long n = (long)target * multiple;
        long ret = 0;
        while(n != 0) {
            ret = ret + n%base;
            n /= base;
        }
        return ret;
    }
    /**
     * 구한 답을 검산한다. 진법*100의 미만 자리수(4자리수 미만)까지 검증한다.
     * @param answer    구한 정답 vector
     * @param base      진법
     * @return 답이 맞다면 true, 틀리다면 false 리턴.
     */
    bool check_answer(std::vector<int> answer, const int base) {
        for(std::vector<int>::iterator i = answer.begin(); i != answer.end(); i++) {
            for(int j = 1; j < base*100; j++) {
                long sum = sum_digitsByMultiple(*i, j, base);
                if(sum < 0 || sum % *i != 0) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    /**
     * base진법에서 n의 배수의 각 자릿수의 합이 다시 n의 배수인 조건을 만족하는 n을 모두 구한다.
     * @param base  답을 구할 진법
     * @return 정답 vector
     */
    std::vector<int> get_digits(const int base) {
        std::vector<int> ret = get_divisor(base - 1);

        if(!check_answer(ret, base)) {
            ret.clear();
            std::cout << "something wrong."<< std::endl;
        }

        return ret;
    }

    /**
     * 정답을 화면에 출력한다.
     * @param src 출력할 정답 vector
     */
    void print_vector(const std::vector<int> src) {
        if(src.empty()) {
            std::cout << "there is nothing to print." << std::endl;
            return;
        }
        
        std::cout << "print : ";
        for(const auto &target : src) {
            std::cout << target << " ";
        }
        std::cout << std::endl;
    }
};

// Driver code 
int main() {
    while (true) {
	    Solution sol;
	    int base = 0;
        std::cout << "------------- start -------------" << std::endl;
        std::cout << "please do not put the too big number has 6 or more digits." << std::endl;
        std::cout << "input a number(3 ~ 4,634 (32bit)|| 3 ~ 30,370,004(64bit)) : " << std::endl;
        std::cin >> base;
        if(base <= 2) {
            break;
        }
        std::vector<int> ret = sol.get_digits(base);
        sol.print_vector(ret);
        std::cout << "-------------- end --------------" << std::endl;
    }
	return 0;
}
