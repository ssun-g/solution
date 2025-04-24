import sys

input = sys.stdin.readline


def find(n):
    global p

    if p[n] < 0:
        return n
    p[n] = find(p[n])
    return p[n]


def union(a, b):
    a = find(a)
    b = find(b)
    if a == b:
        return
    p[b] = a


def main() -> None:
    global p

    n, m = map(int, input().rstrip('\n').split(' '))
    p = [-1] * (n + 1)

    for _ in range(m):
        cmd, a, b = map(int, input().rstrip('\n').split(' '))
        if cmd == 0:  # 합집합(union)
            union(a, b)
        elif cmd == 1:  # 확인(find)
            if find(a) == find(b):
                print("YES")
            else:
                print("NO")


if __name__ == "__main__":
    main()
