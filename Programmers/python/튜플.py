import re
from collections import Counter

def solution(s):
    p = re.compile('[0-9]+') # 111처럼 숫자의 길이가 1이 아닐 수 있다.ㅜ
    c = Counter(p.findall(s)).most_common() # most_common() : count 횟수가 높은 순으로 정렬해준다.
    answer = [ int(t[0]) for t in c ]
    
    return answer