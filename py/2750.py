class Solution:
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        last_1_pos = None
        ret = 0

        for i in range(0, len(nums)):
            if nums[i] != 1:
                continue

            if last_1_pos is None:
                last_1_pos = i
                ret = 1
                continue

            not1_count_p1 = i - last_1_pos
            last_1_pos = i
            if not1_count_p1 > 1:
                ret = (ret * not1_count_p1) % 1000000007
                pass
            pass
        return ret

        
