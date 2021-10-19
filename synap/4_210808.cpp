#include <iostream>
#include <stdlib.h>
#include <cstring>

//https://www.thepoorcoder.com/hackerrank-equal-solution/
// https://torbjorn.tistory.com/310

class Solution {

private:
    char* readline() {
        size_t alloc_length = 1024;
        size_t data_length = 0;

        char* data = malloc(alloc_length);

        while (true) {
            char* cursor = data + data_length;
            char* line = fgets(cursor, alloc_length - data_length, stdin);

            if (!line) {
                break;
            }

            data_length += strlen(cursor);

            if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
                break;
            }

            alloc_length <<= 1;

            data = realloc(data, alloc_length);

            if (!data) {
                data = '\0';

                break;
            }
        }

        if (data[data_length - 1] == '\n') {
            data[data_length - 1] = '\0';

            data = realloc(data, data_length);

            if (!data) {
                data = '\0';
            }
        } else {
            data = realloc(data, data_length + 1);

            if (!data) {
                data = '\0';
            } else {
                data[data_length] = '\0';
            }
        }

        return data;
    }

    char* ltrim(char* str) {
        if (!str) {
            return '\0';
        }

        if (!*str) {
            return str;
        }

        while (*str != '\0' && isspace(*str)) {
            str++;
        }

        return str;
    }

    char* rtrim(char* str) {
        if (!str) {
            return '\0';
        }

        if (!*str) {
            return str;
        }

        char* end = str + strlen(str) - 1;

        while (end >= str && isspace(*end)) {
            end--;
        }

        *(end + 1) = '\0';

        return str;
    }

    char** split_string(char* str) {
        char** splits = NULL;
        char* token = strtok(str, " ");

        int spaces = 0;

        while (token) {
            splits = realloc(splits, sizeof(char*) * ++spaces);

            if (!splits) {
                return splits;
            }

            splits[spaces - 1] = token;

            token = strtok(NULL, " ");
        }

        return splits;
    }

    int parse_int(char* str) {
        char* endptr;
        int value = strtol(str, &endptr, 10);

        if (endptr == str || *endptr != '\0') {
            exit(EXIT_FAILURE);
        }

        return value;
    }
public:
// 수식으로 풀기.
    // 아이디어
    // 한 명을 제외하고 모든 사람에게 1,2,5를 더한다 = (최대값)한 명에게서만 1,2,5를 뺀다.
    int equal(int arr_count, int* arr) {
        int arrMin = INT32_MAX;
        int ret = INT32_MAX;

        // 최소값 구하기
        for(int i = 0; i < arr_count; i++) {
            arrMin = arr[i] < arrMin ? arr[i] : arrMin;
        }

        // 0, 1, 2를 더하는 이유
        // 반례 : 1 4 4 처럼 숫자를 더해야만 결과가 제대로 나오는 경우가 있음.
            // 1 4 4
            // 2 4 5
            // 4 4 7
            // 6 6 7
            // 7 7 7
        // 2까지만 더하는 이유
            // n = 0 : 0 - 0
            // n = 1 : 1 - 1
            // n = 2 : 2 - 2
            // n = 3 : (3 + 2) - 5
            // n = 4 : (4 + 1) - 5
            // n = 5 : 5 - 5
            // n = 6 : 6 / 5 - 1
            // n = 7 : 7 / 5 - 2
            // n = 8 : (8 + 2) - 5 - 5
            // n = 9 : (9 + 1) - 5 - 5
            // ....
        for(int i = 0; i < 3; i++) {
            int sum = 0;
            for(int j = 0; j < arr_count; j++) {
                int tmp = arr[j] - arrMin + i;
                sum += tmp/5; // 5를 뺀 횟수
                sum += tmp%5/2; // 2를 뺀 횟수
                sum += tmp%5%2/1; // 1을 뺀 횟수
            }
            ret = ret > sum ? sum : ret; // 최소값
        }
        return ret;
    }
};

// Driver code 
int main() {
    Solution sol;
    int n = 3;
    int arr[3] = {10,7,12};
    int ret = sol.equal(n, arr);

    std::cout << ret << std::endl; 

    return 0;
}
