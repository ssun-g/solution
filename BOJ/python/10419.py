"""

수업 시간 : d
교수님의 지각 시간 : t
수업을 일찍 마쳐주는 시간 : s

t+s <= d를 만족하는 최대 t를 찾으면 되는 간단한 문제

"""
import sys

input = sys.stdin.readline

tc = int(input().rstrip("\n"))
for _ in range(tc):
    d = int(input().rstrip("\n"))
    for t in range(d + 1):
        if t + (t ** 2) > d:  # 지각시간이 t일 때 t + t**2가 총 수업시간을 넘는다면 t-1이 지각할 수 있는 최대 시간이 된다.
            print(t - 1)
            break
