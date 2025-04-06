"""
누적 합 배열이 psum이고 여기서 두 개의 인덱스 i, j를 골랐을 때,
- 구간 합: psum[j] - psum[i-1]

나누어 떨어지는 개수를 구해야 하므로 (psum[j] - psum[i-1]) % m = 0
(psum[j] % m) == (psum[i-1] % m) 인 i, j를 찾으면 됨. (M으로 나눈 나머지가 같은 i, j)
"""
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

    answer = remainder[0]  # 원래 나누어 떨어지는 경우
    for i in range(M):
        # 나머지가 같은 애들을 찾는다. (combination(n, 2))
        answer += (remainder[i] * (remainder[i] - 1)) // 2

    print(answer)


if __name__ == "__main__":
    main()
