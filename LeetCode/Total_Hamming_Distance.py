class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        """
        hamming distance란 두 이진수를 기준으로 서로 다른 값을 갖는 자리 수의 개수 이다.
        따라서 여러 개의 숫자가 List로 주어 졌을 때, 모든 숫자의 자리 수마다 
        0의 개수와 1의 개수를 구해서 이를 곱해 주면 모든 숫자들 간의 hamming distance를 알 수 있다.
        
        예를 들어, 1(2^0)의 자리에서 0의 개수가 n개이고 1의 개수가 m개라면
        List에 속하는 모든 쌍의 1의 자리 hamming distance를 구하면
        nC1 * mC1 이 된다.(XOR연산과 같기 때문)

        따라서 1의 자리부터 2^30 bit까지 모든 자리 수에 대해 
        hamming distance를 더한 것이 결과 값이 된다.

        Args:
            nums (List[int]): the given numbers

        Returns:
            int: Total hamming distance between all pairs of the given numbers.
        """
        ret = 0
        bits = 1
        for i in range(31): # element의 범위가 10^9 (2^30보다 작다)
            one = 0
            zero = 0
            for a in nums: # XOR 연산은 경우의 수와 같다고 생각할 수 있다.
                if bits & a:
                    one += 1
                else:
                    zero += 1
            ret += one * zero
            bits = bits << 1
            
        return ret
    