class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {"0": 0, "I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        ret = 0
        pre = 1000
        for c in s:
            ret += roman[c] # 일단 로마자에 해당하는 숫자를 다 더해준다.
            if pre < roman[c]: # 전에 등장했던 숫자가 현재 숫자(c)보다 작으면 전에 더했던 숫자를 두번 빼준다.
                ret -= 2*pre
            pre = roman[c] # 전에 등장한 숫자를 저장해주기 위한 변수를 설정해주었다.
        
        return ret
    