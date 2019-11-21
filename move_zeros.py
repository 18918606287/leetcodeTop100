class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pt0 = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[pt0], nums[i] = nums[i], nums[pt0]
                pt0 += 1