class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        cnt = {}
        for i,num in enumerate(nums):
            if target - num in cnt:
                return [cnt[target-num], i]
            cnt[num] = i
        return []
            