/**
 * 문제. 여행 경로 찾기
 * 주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.
 * 항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
 * 
 * 함수의 정의
 * vector<string> solution(vector<vector<string>> tickets) {
 * ...
 * }
 * 
 * 
 * 제약조건
 * 모든 공항은 알파벳 대문자 3글자로 이루어집니다.
 * 주어진 공항 수는 3개 이상 10,000개 이하입니다.
 * tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
 * 주어진 항공권은 모두 사용해야 합니다.
 * 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
 * 모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
 * 
 * 입력 : [["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]] => 출력 : ["ICN", "JFK", "HND", "IAD"]
 * 입력 : [["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]] => 출력 : ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class Solution {

private:
    std::vector<std::string> ret_list; // 모든 답안 후보
    bool* visit;
    std::string route;

    void dfs(const std::vector<std::vector<std::string> > tickets, const std::string to_airport, const int cnt) {
        route += to_airport + ",";

        if(cnt == tickets.size()) { // 만약 cnt와 size의 길이가 같다면, 끝까지 도달했다는 의미.
            ret_list.push_back(route);
            return;
        }

        for(int i = 0; i < tickets.size(); i++) {
            std::string tmp_from_airport = tickets[i][0];
            std::string target_airport = tickets[i][1];

            if(tmp_from_airport == to_airport && !visit[i]) {
                visit[i] = true;
                dfs(tickets, target_airport, cnt + 1);
                visit[i] = false;
                route = route.substr(0, route.length()-4); // 마지막 지우고 다시 돈다.
            }
        }
    }

    std::vector<std::string> split(const std::string str, const char delimiter) {
        std::vector<std::string> ret;
        std::stringstream ss(str);
        std::string tmp_str;

        while(getline(ss, tmp_str, delimiter)) {
            ret.push_back(tmp_str);
        }

        return ret;
    }
public:

    std::vector<std::string> solution(std::vector<std::vector<std::string> > tickets) {
        for(int i = 0; i < tickets.size(); i++) {
            visit = (bool*)malloc(tickets.size());
            std::string from_airport = tickets[i][0];
            std::string to_airport = tickets[i][1];

            if(from_airport == "ICN") {
                route = from_airport + ",";
                visit[i] = true;
                dfs(tickets, to_airport, 1);
            }
        }
        sort(ret_list.begin(), ret_list.end()); // 어차피 알파벳 순이니 문장 통째로 정렬.
        std::vector<std::string> ret = split(ret_list.at(0), ',');
        free(visit);
        return ret;
    }
};

// Driver code 
int main() {
    Solution sol;
    // std::vector<std::vector<std::string> > tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    // std::vector<std::vector<std::string> > tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
    // std::vector<std::vector<std::string> > tickets = {{"ICN", "SFO"}, {"SFO", "ICN"}, {"SFO", "ATL"}, {"ICN", "SFO"}};
    std::vector<std::vector<std::string> > tickets = {{"ICN", "ATL"}, {"ICN", "HND"}, {"HND", "SFO"}, {"SFO", "HND"}, {"ATL", "SFO"}, {"SFO", "ICN"}, {"HND", "ATL"}};
    std::vector<std::string> ret = sol.solution(tickets);

    for(size_t i = 0; i < ret.size(); i++) {
        std::cout << ret[i] << ", ";
    }

    return 0;
}
