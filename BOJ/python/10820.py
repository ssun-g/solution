def str_analyze(string) -> list:
    lower_cnt = 0
    upper_cnt = 0
    num_cnt = 0
    blank_cnt = 0

    for s in string:
        if "a" <= s <= "z":
            lower_cnt += 1
        elif "A" <= s <= "Z":
            upper_cnt += 1
        elif "0" <= s <= "9":
            num_cnt += 1
        else:
            blank_cnt += 1

    return [lower_cnt, upper_cnt, num_cnt, blank_cnt]


def main() -> None:
    while True:
        try:
            string = input().rstrip('\n')
            print(*str_analyze(string))

        except EOFError:
            break


if __name__ == "__main__":
    main()
