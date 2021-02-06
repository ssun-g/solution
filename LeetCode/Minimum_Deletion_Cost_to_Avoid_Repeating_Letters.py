class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        answer = 0 # 제거한 문자들의 총 비용
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                answer += min(cost[i], cost[i-1]) # 연속 되는 문자가 존재한다면 cost가 작은 값을 제거 해준다.
                cost[i] = max(cost[i], cost[i-1]) 
                """ 
                제거 후 다음 문자도 제거한 문자와 같다면 cost[i]는 다음 cost와 비교 될 것이기 때문에
                cost[i]에  max(cost[i], cost[i-1])값을 저장해 준다.
                """

        return answer