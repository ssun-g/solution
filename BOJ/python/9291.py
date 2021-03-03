import sys

input = sys.stdin.readline


def isCorrect(check: list) -> bool:
    """
    주어진 스도쿠가 규칙에 맞는지 확인.

    Args:
        check (list): 1~9까지 한 번씩만 등장했는지 check하기 위한 list

    Returns:
        bool: 규칙에 맞다면 True, 어긋나면 False 반환
    """
    for i in range(1, 10):
        if check[i] != 1:
            return False
    return True


def sudokuCheck(sudoku: list, check: list) -> str:
    # 가로줄 체크
    for y in range(9):
        check = [0 for _ in range(10)]
        for x in range(9):
            check[sudoku[y][x]] += 1
        if not isCorrect(check):
            return "INCORRECT"

    # 세로줄 체크
    for x in range(9):
        check = [0 for _ in range(10)]
        for y in range(9):
            check[sudoku[y][x]] += 1
        if not isCorrect(check):
            return "INCORRECT"

    # 3x3 크기의 작은 사각형 체크
    for dy in range(3):
        for dx in range(3):
            check = [0 for _ in range(10)]
            for y in range(3):
                for x in range(3):
                    check[sudoku[y + (dy * 3)][x + (dx * 3)]] += 1
            if not isCorrect(check):
                return "INCORRECT"
    return "CORRECT"


tc = int(input())
for i in range(1, tc + 1):
    sudoku = []
    sudoku = [list(map(int, input().rstrip("\n").split(" "))) for y in range(9)]
    check = [0 for _ in range(10)]
    print(f"Case {i}: {sudokuCheck(sudoku, check)}")
    input()  # test case마다 개행문자로 구분 되어 있으므로 input을 한번해준다.
