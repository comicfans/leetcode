class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        ret = 0

        for begin_idx in range(0, len(nums)-1):
            for end_idx in range(begin_idx+1, len(nums)):

                begin_number = int(str(nums[begin_idx])[0])
                end_number = int(str(nums[end_idx])[-1])
                try_gcd = min(begin_number, end_number)
        

                while try_gcd != 1:
                    reminder = max(begin_number, end_number) % try_gcd

                    if reminder == 0:
                        break

                    begin_number = min(begin_number, end_number)
                    end_number = try_gcd
                    try_gcd = reminder

                ret += 1 if try_gcd == 1 else 0
                pass
            pass
        return ret



