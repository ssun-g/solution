"""

check 배열을 nums의 길이만큼 0으로 초기화 해준다.
nums를 돌면서 등장한 숫자들을 체크해준다 (1로 변경)
마지막으로 check를 돌면서 체크되지 않은 숫자들을 List로 반환 해준다.

"""
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        check = [ 0 for i in range(len(nums)) ]
        for i in nums:
            check[i-1] = 1
        
        return [ i+1 for i in range(len(check)) if check[i] == 0 ]
