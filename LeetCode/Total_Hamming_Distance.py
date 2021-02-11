class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        ret = 0
        bits = 1
        for i in range(32):
            one = 0
            zero = 0
            for a in nums:
                if bits & a:
                    one += 1
                else:
                    zero += 1
            ret += one * zero
            bits = bits << 1
            
        return ret
    