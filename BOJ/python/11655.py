import sys

input = sys.stdin.readline


def main() -> None:
    S = input().rstrip('\n')

    result = ""
    for s in S:
        if 'A' <= s <= 'Z':
            c = ord(s) + 13
            if c > ord('Z'):
                c -= 26
            result += chr(c)
        elif 'a' <= s <= 'z':
            c = ord(s) + 13
            if c > ord('z'):
                c -= 26
            result += chr(c)
        else:
            result += s

    print(result)


if __name__ == "__main__":
    main()
