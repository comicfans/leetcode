from typing import List, Iterable
import collections


class hash_list(list):
    def __init__(self, *args):
        if len(args) == 1 and isinstance(args[0], Iterable):
            args = args[0]
        super().__init__(args)

    def __hash__(self):
        return hash(e for e in self)

    def __eq__(self, other):
        return super().__eq__(other)


class Range:
    def __init__(self, nums, begin, end):
        self.nums = nums
        self.begin = begin
        self.end = end

    def __hash__(self):
        return hash(tuple(self.nums[self.begin:self.end]))

    def __eq__(self, other):
        if self.end - self.begin != other.end - other.begin:
            return False
        return self.nums[self.begin:self.end] == other.nums[other.begin:other.end]

    def __repr__(self) -> str:
        return f"{self.nums[self.begin:self.end]}"


class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        div_pos = {x for x in range(len(nums)) if nums[x] % p == 0}

        unique_sets = collections.defaultdict(lambda: [])

        for begin_idx in range(0, len(nums)):
            for end_idx in range(begin_idx+1, len(nums)+1):
                in_range_div = [x for x in div_pos if begin_idx <= x < end_idx]
                if len(in_range_div) > k:
                    break

                this_range = Range(nums, begin_idx, end_idx)
                this_hash = hash(this_range)
                existing = unique_sets[this_hash]
                if this_range in existing:
                    continue
                existing.append(this_range)

        return sum((len(value) for value in unique_sets.values()))


numsa = [2, 3, 3, 2, 2]

r1 = Range(numsa, 0, 1)
r2 = Range(numsa, 3, 4)

s = Solution()
print(s.countDistinct(numsa, 2, 2))

numsa = [1, 2, 3, 4]
print(s.countDistinct(numsa, 4, 1))
