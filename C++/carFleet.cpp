#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <optional>
#include <cmath>

using namespace std;

struct car{
    int pos;
    double movesLeft;
};

class Solution {
public:
    //function from leetcode goes here
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (target<1 || position.empty() || position.size()<1)
            return 0;
        
        std::vector<car> cars(position.size());
        for (int i=0; i<position.size();i++){
            cars[i].pos = position[i];
            int positionsLeft = target - position[i];
            cars[i].movesLeft = static_cast<double>(positionsLeft) / speed[i];
        }
        std::sort(cars.begin(), cars.end(), [](const car& a, const car& b){
            return a.pos > b.pos;
        });
        
        int fleets = 0;
        double slowerFleet = 0;
        for (const car& c:cars){
            // cause if it's less or equal moves it'll catch it, if not it becomes a new fleet
            if (c.movesLeft>slowerFleet){
                slowerFleet = c.movesLeft;
                fleets++;
            }
        }
        return fleets;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    int target = 10;
    std::vector<int> positions{1,4};
    std::vector<int> speeds{3,2};

    Solution sol{};

    int target2 = 10;
    std::vector<int> positions2{4,1,0,7};
    std::vector<int> speeds2{2,2,1,1};

    int target3 = 12;
    std::vector<int> positions3{10,8,0,5,3};
    std::vector<int> speeds3{2,4,1,1,3};

    int target4 = 10;
    std::vector<int> positions4{3};
    std::vector<int> speeds4{3};

    int target5 = 100;
    std::vector<int> positions5{0,2,4};
    std::vector<int> speeds5{4,2,1};

    std::cout << "first example " << sol.carFleet(target, positions, speeds) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 1
    std::cout << "second example " << sol.carFleet(target2, positions2, speeds2) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 3
    std::cout << "third example " << sol.carFleet(target3, positions3, speeds3) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 3
    std::cout << "fourth example " << sol.carFleet(target4, positions4, speeds4) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 1
    std::cout << "fifth example " << sol.carFleet(target5, positions5, speeds5) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 1

    //output

}