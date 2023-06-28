class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        ret = '0' * (len(number)-1)

        for idx,c in enumerate(number):
            if c != digit:
                continue
            changed = number[:idx] + number[idx+ 1:]
            ret = max(ret, changed)
        return ret

        

