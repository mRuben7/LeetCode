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

class Solution {
public:
    //function from leetcode goes here
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (target<1 || position.empty() || position.size()<1)
            return 0;

        std::vector<pair<int, int>> cars{}; //position, speed
        cars.reserve(position.size());

        for (int i=0;i<position.size();i++){
            cars.emplace_back(position[i], speed[i]);
        }
        sort(cars.begin(), cars.end());
        std::vector<std::vector<pair<int, int>>> fleets{};
        fleets.reserve(cars.size());
        for (const auto& car:cars){
            fleets.push_back({car});
        }
        std::vector<std::vector<pair<int, int>>> finalStack{};
        while (!fleets.empty()){
            std::vector<pair<int, int>> prevFleet{};
            bool isFirstElem = true;
            for (int i=0; i<fleets.size();i++){
                if (prevFleet.empty()){
                    prevFleet = fleets[i];
                    if (fleets.size()>1){
                        isFirstElem = false;
                        continue;
                    }
                }
                int nextPosOfPrevFleet = prevFleet.back().first + prevFleet.back().second;
                int nextPostOfCurrentFleet = fleets[i][0].first + fleets[i][0].second;
                int nextPostOfLastCurrentFleet = fleets[i].back().first + fleets[i].back().second;
                if (nextPosOfPrevFleet>=nextPostOfCurrentFleet){
                    // pop fleet from prev and add to current, also hold the pos to prev one
                    int fleetSpeed = fleets[i][0].second;
                    int pos = fleets[i][0].first;
                    for (int j=0; j<prevFleet.size();j++){
                        // fleets[i].emplace_back(pos - j, fleetSpeed); //? should this be added on top instead?
                        fleets[i].insert(fleets[i].begin(), {pos - j, fleetSpeed});
                    }
                    fleets.erase(fleets.begin()+i);
                }else if (nextPostOfLastCurrentFleet>=target){ // target reached
                    // add fleet to final stack and pop it from fleets
                    finalStack.push_back(fleets[i]);
                    // fleets.pop_back(); // IDK if pop_back is correct or should be fleets[i]
                    fleets.erase(fleets.begin()+i);
                }else{
                    for (auto& car:fleets[i]){
                        car.first += car.second;
                    }
                }
                prevFleet.clear();
                prevFleet = fleets[i];
            }
        }
        return finalStack.size();
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