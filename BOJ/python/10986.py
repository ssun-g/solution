import sys

input = sys.stdin.readline


def main() -> None:
    N, M = map(int, input().rstrip('\n').split(' '))
    arr = list(map(int, input().rstrip('\n').split(' ')))

    remainder = [0] * M  # 나머지
    psum = 0
    for i in range(N):
        psum += arr[i]
        remainder[psum % M] += 1

    # 나머지가 0인 개수 세기
    answer = remainder[0]
    for i in range(M):
        answer += (remainder[i] * (remainder[i] - 1)) // 2

    print(answer)


if __name__ == "__main__":
    main()
