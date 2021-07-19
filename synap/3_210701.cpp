#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits.h>

class Solution {

private:
    std::vector<std::vector<int> > horizonFlip(std::vector<std::vector<int> > input) {
        int tmp = 0;
        for(int i = 0; i < 3; i++) {
            tmp = input[0][i];
            input[0][i] = input[2][i];
            input[2][i] = tmp;
        }
        return input;
    }
    std::vector<std::vector<int> > verticalFlip(std::vector<std::vector<int> > input) {
        int tmp = 0;
        for(int i = 0; i < 3; i++) {
            tmp = input[i][0];
            input[i][0] = input[i][2];
            input[i][2] = tmp;
        }
        return input;
    }
    std::vector<std::vector<int> > rRotate(std::vector<std::vector<int> > input) {
        std::vector<std::vector<int> > ret = {{0,0,0},{0,0,0},{0,0,0}};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                ret[j][2-i] = input[i][j];
            }
        }
        return ret;
    }
    std::vector<std::vector<int> > lRotate(std::vector<std::vector<int> > input) {
        std::vector<std::vector<int> > ret = {{0,0,0},{0,0,0},{0,0,0}};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                ret[2-j][i] = input[i][j];
            }
        }
        return ret;
    }

    std::vector<std::vector<std::vector<int> > > makeTripeMagicSquare() {
        std::vector<std::vector<std::vector<int> > > ret;

        std::vector<std::vector<int> > tmp_ret = {{0,0,0},{0,0,0},{0,0,0}};
        const int SIZE = 3;
        for(int i = 0, j = 1, num = 1; num < 10; num++) {
            tmp_ret[i][j] = num;
            if(num%SIZE == 0) {
                i++;
            } else {
                i--;
                j++;
                if(i < 0) {
                    i = SIZE - 1;
                }
                if(j > SIZE - 1) {
                    j = 0;
                }
            }
        }

        ret.push_back(tmp_ret);
        ret.push_back(horizonFlip(tmp_ret));
        ret.push_back(verticalFlip(tmp_ret));
        ret.push_back(rRotate(tmp_ret));
        ret.push_back(lRotate(tmp_ret));

        std::vector<std::vector<int> > vertical_tmp_ret = verticalFlip(tmp_ret);
        ret.push_back(horizonFlip(vertical_tmp_ret));
        ret.push_back(rRotate(vertical_tmp_ret));
        ret.push_back(lRotate(vertical_tmp_ret));

        return ret;
    }
public:
    int formingMagicSquare(std::vector<std::vector<int> > input) {
        int ret = INT_MAX;
        // const std::vector<std::vector<std::vector<int> > > TripleMagicSquare =
        //     {{{8,1,6},{3,5,7},{4,9,2}}
        //     ,{{4,3,8},{9,5,1},{2,7,6}}
        //     ,{{2,9,4},{7,5,3},{6,1,8}}
        //     ,{{6,7,2},{1,5,9},{8,3,4}}
        //     ,{{6,1,8},{7,5,3},{2,9,4}}
        //     ,{{8,3,4},{1,5,9},{6,7,2}}
        //     ,{{4,9,2},{3,5,7},{8,1,6}}
        //     ,{{2,7,6},{9,5,1},{4,3,8}}};

        const std::vector<std::vector<std::vector<int> > > TripleMagicSquare = makeTripeMagicSquare();

        for(int i = 0; i < TripleMagicSquare.size(); i++) {
            int tmp_ret = 0;
            for(int j = 0; j < TripleMagicSquare.at(i).size(); j++) {
                for(int k = 0; k < TripleMagicSquare.at(i).at(j).size(); k++) {
                    tmp_ret += std::abs(TripleMagicSquare[i][j][k] - input.at(j).at(k));
                }
            }

            if(ret > tmp_ret) {
                ret = tmp_ret;
            }
        }

        return ret;
    }
};

// Driver code 
int main() {
    Solution sol;
    std::vector<std::vector<int> > input = {{5,3,4}, {1,5,8}, {6,4,2}};
    int ret = sol.formingMagicSquare(input);

    std::cout << ret << std::endl;

    return 0;
}
