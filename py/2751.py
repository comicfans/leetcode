from typing import List

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        infos = []
        for i in range(len(positions)):
            infos.append([i, healths[i], directions[i]])

        infos.sort(key=lambda x: positions[x[0]])

        last_survived_pos = 0

        current_pos = 1
        while current_pos < len(infos):

            if last_survived_pos < 0:
                last_survived_pos = current_pos
                current_pos += 1
                continue

            last_survived = infos[last_survived_pos]
            if last_survived[1] == 0:
                last_survived_pos -= 1 
                continue

            current = infos[current_pos]

            if current[2] == last_survived[2] or current[2] == 'R':
                last_survived_pos = current_pos
                current_pos += 1
                continue

            if current[1] < last_survived[1]:
                last_survived[1] -= 1
                current[1] = 0
                current_pos += 1
                continue
                
            if current[1] == last_survived[1]:
                current[1] = 0
                last_survived[1] = 0
                current_pos += 1
            else:
                last_survived[1] = 0
                current[1] -= 1

            last_survived_pos -= 1

        infos.sort(key = lambda x: x[0])
        ret = map(lambda x: x[1], filter(lambda x: x[1]>0, infos))
        return [*ret]

s = Solution()
res1 = s.survivedRobotsHealths([5,4,3,2,1], [2,17,9,15,10], "RRRRR") 
assert res1 == [2,17,9,15,10]

res2 = s.survivedRobotsHealths([3,5,2,6], [10,10,15,12], "RLRL")
assert res2 == [14]

res3 = s.survivedRobotsHealths([1,2,5,6], [10,10,11,11], "RLRL")
assert res3 == []
print ("ok")
