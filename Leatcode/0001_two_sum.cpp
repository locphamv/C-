
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> seenNumbers;

        for (int i = 0; i < nums.size(); i++)
        {
            int currentNum = nums[i];
            int numberNeed = target - currentNum;

            if (seenNumbers.find(numberNeed) != seenNumbers.end())
            {

                return {seenNumbers[numberNeed], i};
            }

            seenNumbers[currentNum] = i;
        }

        return {};
    }
};

int main()
{

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;

    vector<int> result = sol.twoSum(nums, target);

    if (result.size() == 2)
    {
        cout << "Ket qua tim thay: [" << result[0] << ", " << result[1] << "]" << endl;
    }
    else
    {
        cout << "Khong tim thay cap so nao thoa man." << endl;
    }

    return 0;
}