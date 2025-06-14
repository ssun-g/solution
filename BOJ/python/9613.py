import sys
import math

input = sys.stdin.readline


def get_gcd_sum(arr):
    total = 0
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            total += math.gcd(arr[i], arr[j])

    return total


def main() -> None:
    t = int(input().rstrip('\n'))
    for _ in range(t):
        arr = list(map(int, input().rstrip('\n').split(' ')))
        print(get_gcd_sum(arr[1:]))


if __name__ == "__main__":
    main()
