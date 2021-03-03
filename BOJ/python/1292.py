import sys

input = sys.stdin.readline

# 문제에서 주어진 수열을 만든다.
def Init(arr: list) -> list:
    for i in range(1, 1001):
        for j in range(1, i + 1):
            if len(arr) > 1000:  # 최대 길이가 1000이므로 길이가 1000을 넘으면 함수를 종료한다.
                return arr
            arr.append(i)


answer = 0
arr = Init([0])
A, B = map(int, input().rstrip("\n").split(" "))

# A ~ B번째 숫자들의 합
for i in range(A, B + 1):
    answer += arr[i]

print(answer)
