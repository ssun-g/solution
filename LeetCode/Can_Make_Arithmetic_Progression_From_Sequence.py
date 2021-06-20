class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr = sorted(arr)
        
        prev = 0
        for i in range(1, len(arr)):
            if (i!=1) and (prev != arr[i]-arr[i-1]):
                return False
            prev=arr[i]-arr[i-1]
            
        return True
        