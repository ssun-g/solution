import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip("\n"))
    members = []
    for i in range(N):
        age, name = map(str, input().rstrip("\n").split(" "))
        members.append([int(age), name, i])

    members.sort(key=lambda x: (x[0], x[2]))
    for age, name, _ in members:
        print(age, name)


if __name__ == "__main__":
    main()
