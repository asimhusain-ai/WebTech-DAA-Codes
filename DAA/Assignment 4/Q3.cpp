#include <iostream>
#include <vector>
using namespace std;
void findSubsets(vector<int>& nums, vector<int>& subset, int index) {
    cout << "{ ";
    for (int num : subset)
        cout << num << " ";
    cout << "}\n";
    for (int i = index; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        findSubsets(nums, subset, i + 1);
        subset.pop_back(); // Backtrack
    }
}
void generateSubsets(vector<int>& nums) {
    vector<int> subset;
    findSubsets(nums, subset, 0);
}
int main() {
    vector<int> nums = {1, 2, 3}; // Input set
    generateSubsets(nums);
    return 0;
}