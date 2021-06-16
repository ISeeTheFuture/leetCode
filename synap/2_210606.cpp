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

class Solution {

private:
public:

    std::vector<std::string> solution(std::vector<std::vector<std::string> > tickets) {
        const int FROM_AIRPORT = 0;
        const int TO_AIRPORT = 1;
        const int VISITED_NOWHERE = -1;

        std::vector<std::string> ret;
        std::string target_airport = "ICN";

        ret.push_back(target_airport); // 일단 출발지는 집어 넣는다.

        while(!tickets.empty()) {
            std::vector<std::vector<std::string> >::iterator tickets_iter = tickets.begin();
            int target_index = VISITED_NOWHERE;

            for(; tickets_iter < tickets.end(); tickets_iter++) {
                
                // 찾고 있는 공항을 발견했다면,
                if(tickets_iter->at(FROM_AIRPORT) == target_airport) {
                    const int CURRENT_INDEX = tickets_iter - tickets.begin();

                    if(target_index == VISITED_NOWHERE){
                        target_index = CURRENT_INDEX;
                        
                    } else {
                        std::string stock_airport = tickets.at(target_index).at(TO_AIRPORT);
                        std::string new_airport = tickets.at(CURRENT_INDEX).at(TO_AIRPORT);
                        target_index = stock_airport.compare(new_airport) == -1 ? target_index : CURRENT_INDEX; // 사전 순으로 더 앞쪽에 있는 것을 저장한다.
                    }
                }
            }
            
            ret.push_back(tickets.at(target_index).at(TO_AIRPORT));
            tickets.erase(tickets.begin() + target_index);
        }

        return ret;
    }

};

// Driver code 
int main() {
    Solution sol;
    std::vector<std::vector<std::string> > tickets;
    std::vector<std::string> ticket;
    ticket.push_back("ICN");
    ticket.push_back("JFK");
    tickets.push_back(ticket);
    ticket.clear();

    ticket.push_back("HND");
    ticket.push_back("IAD");
    tickets.push_back(ticket);
    ticket.clear();

    ticket.push_back("JFK");
    ticket.push_back("HND");
    tickets.push_back(ticket);
    ticket.clear();

    sol.solution(tickets);

    return 0;
}
