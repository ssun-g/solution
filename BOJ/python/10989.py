import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip("\n"))

    # 카운팅
    count = [0] * 10001
    for _ in range(N):
        num = int(input().rstrip("\n"))
        count[num] += 1

    # 정렬
    for i, freq in enumerate(count):
        for _ in range(freq):
            print(i)


if __name__ == "__main__":
    main()
