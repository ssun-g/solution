"""
주어진 citations를 내림차순으로 정렬 한다.
정렬 된 list를 반복문으로 돌면서 [ '인용횟수' <= index ]를 찾는다.
[ '인용횟수' <= index ]를 만족하는 index가 최대의 H-Index 이다.
만족하는 값이 없으면 citations의 길이가 H-index가 된다.
"""

def solution(citations):
    answer = len(citations)
    sorted_citations = sorted(citations, reverse=True)
    for i in range(len(sorted_citations)):
        if sorted_citations[i] <= i:
            answer = i
            break
        
    return answer