"""
가능한 답 중 가장 큰 수가 len(citations)이다.
그러므로 반복문을 돌때 len(citations)부터 역순으로 반복 시켜주었다.
바깥 반복문에서는 h를 정해주고, 안쪽 반복문에서는 h번 이상 인용된 논문을 카운트 해주었다.
h번 이상 인용된 논문이 h편 이상이라면 answer에 저장 된 값과 비교해서 큰 값을 저장해주었다.
"""
def solution(citations):
    answer = 0
    for h in range(len(citations), -1, -1):
        cnt = 0
        for q in citations:
            if h <= q: # q : 인용횟수
                cnt += 1
        if h <= cnt: # h번 이상 인용된 논문이 h편 이상이라면
            answer = max(answer, h)
        
    return answer