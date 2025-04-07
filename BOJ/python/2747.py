import sys

input = sys.stdin.readline


def main() -> None:
    n = int(input().rstrip('\n'))
    prev = 0
    cur = 1
    for _ in range(n - 1):
        answer = cur + prev
        prev = cur
        cur = answer

    if n <= 1:
        print(n)
    else:
        print(answer)


if __name__ == "__main__":
    main()
