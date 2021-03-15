"""

최대 활성화 가능한 아케인스톤 수는 k이다.
경험치를 가장 많이 얻기 위해서는 경험치가 적은 순으로 퀘스트를 수행하면서 아케인스톤을 빨리 활성화 하는 것이 중요하다.
따라서 경험치를 기준으로 오름차순으로 정렬한 후 퀘스트를 수행하며 k개까지 아케인스톤을 활성화 하고 경험치를 쌓아 주었다.

"""
import sys

input = sys.stdin.readline

n, k = map(int, input().rstrip("\n").split(" "))
stone = sorted(list(map(int, input().rstrip("\n").split(" "))))

answer = 0
activation = 0
for i in range(n):
    answer += activation * stone[i]  # 퀘스트를 깨고 활성화 되어 있는 아케인스톤에 경험치를 저장한다.
    if activation < k:  # 활성화 된 아케인스톤이 k개 보다 적다면 활성화 시켜준다.
        activation += 1
print(answer)
