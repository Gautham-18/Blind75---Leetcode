#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Step 1: Store all unique numbers in a hash set.
        // This handles duplicates in 'nums' efficiently, ensuring each number is present only once.
        unordered_set<int> numSet;
        for (int num : nums) {
            numSet.insert(num); // Average O(1) insertion
        }

        int longestStreak = 0;

        // Step 2: Iterate through each UNIQUE number present in the set.
        // This avoids redundant calculations if the original 'nums' had duplicates.
        for (int num : numSet) {
            // Check if 'num' is the potential start of a consecutive sequence.
            // A number 'num' is a sequence start if 'num - 1' is NOT in the set.
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Step 3: Count the length of the current consecutive sequence.
                // Keep checking for currentNum + 1, currentNum + 2, etc.
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update the overall longest streak found.
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

int main(){
    Solution solver;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = solver.longestConsecutive(nums);
    cout << "Input: {100, 4, 200, 1, 3, 2}" << endl;
    cout << "Longest Consecutive Sequence: " << result << endl;
    return 0;

}