import sys

input = sys.stdin.readline

A, P = map(int, input().rstrip("\n").split(" "))

check = {}
Sum = 0
idx = 0
while True:
    # 이미 등장한 숫자이면 남은 수의 개수를 출력해준다.
    if A in check.keys():
        print(check[A])
        break

    # 등장하지 않은 숫자이면 수열을 계속 만든다.
    else:
        check[A] = idx  # 수열의 길이를 저장.
        idx += 1
        while A:
            tmp = A % 10
            Sum += tmp ** P
            A //= 10
        A = Sum
        Sum = 0
