import sys

input = sys.stdin.readline

month = [-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
x, y = map(int, input().rstrip("\n").split(" "))
total = 0
for i in range(1, x):  # x월 까지 며칠이 걸리는지 더해준다.
    total += month[i]

if total == 0:  # x가 1월일 경우 '일'만 고려하면 된다.
    print(day[(y - 1) % 7])
else:  # x가 1월이 아닐 경우 total에 y일까지 며칠이 걸리는지 더해준다.
    total += y - 1
    print(day[total % 7])
