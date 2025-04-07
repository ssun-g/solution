import sys

input = sys.stdin.readline


def main() -> None:
    N, M = map(int, input().rstrip('\n').split(' '))
    pokemon_num = {i + 1: input().rstrip('\n') for i in range(N)}
    pokemon_name = {v: k for k, v in pokemon_num.items()}

    for _ in range(M):
        question = input().rstrip('\n')

        if question.isdigit():
            print(pokemon_num[int(question)])
        else:
            print(pokemon_name[question])


if __name__ == "__main__":
    main()
