// 문제 : https://www.synapsoft.co.kr/recruit-developer

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define SN3OK 1
#define ERROR_YOU_FAIL 0

class Solution {


private:
    void rightDown(const int I, const int J, const int N, const int S, const int *arr, vector<string>& routes_list) {
        string storedRoute = "";
        int iSum = 0;
        for(int i = I; i < N; i++) {
            string route = "";
            int tmpNo1 = *(arr+(i+N*J));
            iSum += tmpNo1;
            storedRoute += to_string(tmpNo1) + " ";
            route += storedRoute;
            int sum = iSum;
            if(sum > S) {
                route.clear();
                sum = 0;
                continue;
            } else if(sum == S) {
                routes_list.push_back(route);
                route.clear();
                sum = 0;
                continue;
            }
            if(J+1 >= N) continue;
            for(int j = J + 1; j < N; j++) {
                int tmpNo2 = *(arr+(i+N*j));
                sum += tmpNo2;
                route += to_string(tmpNo2) + " ";
                if(sum > S) {
                    route.clear();
                    sum = 0;
                    break;
                } else if(sum == S) {
                    routes_list.push_back(route);
                    route.clear();
                    sum = 0;
                    break;
                }
            }
        }
    }
    void downRight(const int I, const int J, const int N, const int S, const int *arr, vector<string>& routes_list) {
        string storedRoute = "";
        int iSum = 0;
        for(int j = J; j < N; j++) {
            string route = "";
            int tmpNo1 = *(arr+(I+N*j));
            iSum += tmpNo1;
            storedRoute += to_string(tmpNo1) + " ";
            route += storedRoute;
            int sum = iSum;
            if(sum > S) {
                route.clear();
                sum = 0;
                continue;
            } else if(sum == S) {
                routes_list.push_back(route);
                route.clear();
                sum = 0;
                continue;
            }
            if(I+1 >= N) continue;
            for(int i = I + 1; i < N; i++) {
                int tmpNo2 = *(arr+(i+N*j));
                sum += tmpNo2;
                route += to_string(tmpNo2) + " ";
                if(sum > S) {
                    route.clear();
                    sum = 0;
                    break;
                } else if(sum == S) {
                    routes_list.push_back(route);
                    route.clear();
                    sum = 0;
                    break;
                }
            }
        }
    }
    void printRoute(vector<string> routes_list) {
        for(auto it = routes_list.begin(); it != routes_list.end(); it++) {
            cout << *it << endl;
            // printf("%s \n", (*it).c_str());
        }
    }

public:

    int findRoute(const int N, const int S, const int* arr) {
        vector<string> routes_list;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                rightDown(i, j, N, S, arr, routes_list);
                downRight(i, j, N, S, arr, routes_list);
            }
        }

        if(!routes_list.empty()) {
            printRoute(routes_list);
        }

        return SN3OK;
    }

};

// Driver code 
int main() {
    Solution sol;

    const int N = 4; // N X N
    const int S = 11; // 경로의 총 합 한계
    const int arr[N][N] = {{2,4,2,6}, {6,6,4,2}, {2,2,1,2}, {4,4,5,3}};
    const int* pArr = *arr;

    int ret = sol.findRoute(N, S, pArr);
    if(ret != SN3OK) {
        return ERROR_YOU_FAIL;
    }

    return SN3OK;
}