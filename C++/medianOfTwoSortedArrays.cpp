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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = (nums1.size() - 1) + (nums2.size() - 1);
        int half = floor(total/2);
        int l1 = 0;
        int r1 = nums1.size()-1;
        while (l1 <= r1){
            int mid1 = floor(((r1 - l1) / 2)+l1);
            int mid2 = floor(half - mid1);

            if (nums1[mid1]>nums2[mid2+1]){
                l1 = mid1 + 1;
                continue;
            }
            if(nums1[mid1+1]<nums2[mid2]){
                r1 = mid1 - 1;
                continue;
            }

            if (total%2==0){
                double max = std::max(nums1[mid1], nums2[mid2]);
                double min = std::min(nums1[mid1+1], nums2[mid2+1]);
                return (max + min) / 2;
            }else{
                return std::min(nums1[mid1+1], nums2[mid2+1]);
            }
        }
        return 0;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    // std::vector<int> nums1{1,3,8,9};
    // std::vector<int> nums2{2,4,5,6};
    std::vector<int> nums1{1,3};
    std::vector<int> nums2{2,4};

    Solution sol{};

    sol.findMedianSortedArrays(nums1, nums2);
    std::cout << sol.findMedianSortedArrays(nums1, nums2) << std::endl;

    //output
    
}