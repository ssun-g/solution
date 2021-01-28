"""

입력 s가 string type이기 때문에 정규 표현식을 사용했다.
s를 탐색하면서 길이가 1이상인 모든 숫자를 찾고
Counter를 사용해 c에 {"숫자":"등장횟수"} 형태로 넣어 주고
most_common()를 사용해 등장 횟수 순으로 내림차순 정렬하여 list형태로 반환해주었다.

등장 횟수 순으로 정렬한 이유는 문제에서 주어진 튜플의 성질에 따른다.
(a1, a2, a3, ... ,an)이라는 튜플이 있을 때,
n-튜플은 다음과 같다. {{a1}, {a1, a2}, {a1, a2, a3}, ... , {a1, a2, a3, ... , an}}
이를 살펴 보면 등장 횟수가 a1 > a2 > ... > an 순이다.

그렇기 때문에 등장 횟수 순으로 Counter를 통해 넣어 주었다.
그 후, c라는 list를 탐색하면서 [0]번째 인덱스의 값.
즉, 가장 많이 등장한 숫자 순으로 answer에 담아 주었다.

"""
import re
from collections import Counter

def solution(s):
    p = re.compile('[0-9]+') # 111처럼 숫자의 길이가 1이 아닐 수 있다.ㅜ
    c = Counter(p.findall(s)).most_common() # most_common() : count 횟수가 높은 순으로 정렬해준다.
    answer = [ int(t[0]) for t in c ] # 등장 횟수가 높은 숫자 순으로 answer에 넣어준다.

    return answer