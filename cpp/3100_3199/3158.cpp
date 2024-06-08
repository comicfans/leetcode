class Solution {
public:
  int duplicateNumbersXOR(vector<int> &nums) {
    int ret = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size();) {
      if (i == nums.size() - 1) {
        break;
      }
      if (nums[i] == nums[i + 1]) {
        ret = ret xor nums[i];
        i += 2;
        continue;
      } else {
        ++i;
      }
    }
    return ret;
  }
};
