import sys

input = sys.stdin.readline


def main() -> None:
    M, N = map(int, input().rstrip('\n').split(' '))

    # 소수 구하기
    is_prime = [True] * (N + 1)  # 문제 조건에서 M <= N
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(N ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, N + 1, i):
                is_prime[j] = False

    # 출력
    for i in range(M, N + 1):
        if is_prime[i]:
            print(i)


if __name__ == "__main__":
    main()
