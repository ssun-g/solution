import sys

input = sys.stdin.readline


def preorder(tree: dict, node: str) -> None:
    if node == '.':
        return

    l_child, r_child = tree[node]

    print(node, end='')
    preorder(tree, l_child)
    preorder(tree, r_child)


def inorder(tree: dict, node: str) -> None:
    if node == '.':
        return

    l_child, r_child = tree[node]

    inorder(tree, l_child)
    print(node, end='')
    inorder(tree, r_child)


def postorder(tree: dict, node: str) -> None:
    if node == '.':
        return

    l_child, r_child = tree[node]

    postorder(tree, l_child)
    postorder(tree, r_child)
    print(node, end='')


def main() -> None:
    N = int(input().rstrip('\n'))

    # 트리 구현
    tree = {}
    for _ in range(N):
        root, l_child, r_child = input().rstrip('\n').split(' ')
        tree[root] = [l_child, r_child]

    preorder(tree, 'A')  # 전위 순회
    print()
    inorder(tree, 'A')  # 중위 순회
    print()
    postorder(tree, 'A')  # 후위 순회


if __name__ == "__main__":
    main()
