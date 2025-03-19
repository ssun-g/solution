"""
주어진 수열에서 최대값 N을 찾는 것에 유의할 것(Line 42)
"""
import sys

sys.setrecursionlimit(10**7)

input = sys.stdin.readline


def restore_sequence(seq: str, init: int, result):
    global N, check

    # 수열을 복구 완료한 경우
    if len(seq) <= init:
        print(" ".join(map(str, result)))
        return True

    # 길이가 1인 경우 탐색
    num = int(seq[init : init + 1])
    if (num <= N) and (not check[num]):
        check[num] = 1
        if restore_sequence(seq, init + 1, result + [num]):
            return True
        check[num] = 0

    # 길이가 2인 경우 탐색
    num = int(seq[init : init + 2])
    if (num <= N) and (not check[num]):
        check[num] = 1
        if restore_sequence(seq, init + 2, result + [num]):
            return True
        check[num] = 0

    return False


def main() -> None:
    global N, check

    seq = input().rstrip("\n")
    N = len(seq) if len(seq) < 10 else ((len(seq) - 9) // 2) + 9  # 수열 범위 구하기(최대 N)
    check = [0 for _ in range(N + 1)]

    restore_sequence(seq, 0, [])


if __name__ == "__main__":
    main()
