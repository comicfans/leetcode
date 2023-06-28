import sys


class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        best = sys.maxsize
        current_start = {}

        for idx, number in enumerate(cards):
            if number not in current_start:
                current_start[number] = idx
                continue

            number_steps = idx - current_start[number] + 1
            if number_steps == 2:
                return 2

            best = min(best, number_steps)
            current_start[number] = idx

        return -1 if best == sys.maxsize else best
