"""
가로, 세로, 높이 중 가장 큰 숫자를 기준으로 자르면 된다.
=> 가로, 세로, 높이가 최대한 균등한 숫자인 경우가 부피가 최대가 됨.

1. (가로 + 세로 + 높이 - 먹은 횟수)가 목표값이 된다.
2. 목표값을 기준으로 가로, 세로, 높이를 최대한 균등하도록 나눈다.
3. 나눌 때 원래 값보다 커질순 없음에 유의 한다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    T = int(input().rstrip('\n'))
    for _ in range(T):
        input().rstrip('\n')  # 빈 줄
        A, B, C, D = map(int, input().rstrip('\n').split(' '))

        arr = sorted([A, B, C])

        aim = A + B + C - D

        A = min(arr[0], aim // 3)  # 원래 값보다 커질 순 없음(가장 작은 수부터 판별 해야 함)
        B = min(arr[1], (aim - A) // 2)  # 원래 값보다 커질 순 없음
        C = aim - (A + B)

        print(A * B * C)


if __name__ == "__main__":
    main()
