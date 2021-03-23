import sys
import re

input = sys.stdin.readline

while True:
    eng = list(map(str, input().rstrip("\n").split(" ")))
    if eng[0] == "#":
        break

    p = re.compile(eng[0])
    answer = 0
    for i in range(1, len(eng)):
        answer += len(p.findall(eng[i].lower())) # 모두 소문자로 바꾼 뒤 문자를 찾는다.

    print(eng[0], answer)
