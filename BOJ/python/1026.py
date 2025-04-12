"""
(B의 가장 큰 원소 x A의 가장 작은 원소)를 만족 하도록 A를 재배열 한다.
S = A[0]*B[0] + ... + A[N-1]*B[N-1]을 만족하는 S만 출력하면 되므로 A, B 둘다 정렬해서 곱한다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    A = list(map(int, input().rstrip('\n').split(' ')))
    B = list(map(int, input().rstrip('\n').split(' ')))

    A.sort()  # 오름차순 정렬
    B.sort(reverse=True)  # 내림차순 정렬

    S = 0
    for a, b in zip(A, B):  # 각 원소를 곱한다
        S += a * b

    print(S)


if __name__ == "__main__":
    main()
