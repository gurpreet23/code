#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {3,2,4};
    std::vector <int> res;
    int target = 6;
    int n=nums.size();
    int start =0, end = n-1;
    std::sort(nums.begin(), nums.end());
    while(start<end) {
        if(nums[start] + nums[end] == target) {
            res.push_back(start);
            res.push_back(end);
        }
        else if(nums[start] + nums[end] < target) {
            start++;
        }
        else{
            end--;
        }
    }
    std::cout<<res[0]<<" "<<res[1];
    return 0;
}