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

class MinStack {
public:
    //function from leetcode goes here
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if(minStack.empty()){
            minStack.push_back(val);
        }else{
            if(val<=minStack.back()){
                minStack.push_back(val);
            }
        }
    }
    
    void pop() {
        if(stack.back()==minStack.back()){
            minStack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }

private:
    std::vector<int> stack{};
    std::vector<int> minStack{};
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    MinStack minStack = MinStack();
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    std::cout << "get min: " << minStack.getMin() << std::endl;//return 0
    minStack.pop();
    std::cout << "get top: " << minStack.top() << std::endl;//return 2
    std::cout << "get min: " << minStack.getMin() << std::endl;//return 1

}