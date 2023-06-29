class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:

        for try_number in range(1, 60+1):
            diff = num1 - num2 * try_number

            if diff < 1:
                return -1

            if diff < try_number:
                continue

            bin_1s = diff.bit_count()

            if bin_1s > try_number:
                continue

            return try_number


        
