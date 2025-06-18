import sys

input = sys.stdin.readline


class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.current = None

    def insert(self, key_log):
        for s in key_log:
            if s == '<':
                if self.current:
                    self.current = self.current.prev
            elif s == '>':
                if self.current and self.current.next:
                    self.current = self.current.next
                elif self.current is None and self.head:  # 커서가 맨 앞에 있을 경우
                    self.current = self.head
            elif s == '-':
                if self.current:
                    prev_node = self.current.prev

                    # 이전 노드가 존재 하는 경우
                    if self.current.prev:
                        self.current.prev.next = self.current.next
                    # 현재 노드가 head인 경우
                    else:
                        self.head = self.current.next

                    # 다음 노드가 존재하는 경우
                    if self.current.next:
                        self.current.next.prev = self.current.prev

                    self.current = prev_node  # 커서 위치 업데이트
            else:
                new_node = Node(s)
                # 새로운 노드 연결

                if self.current is None:  # 커서가 맨 앞
                    new_node.next = self.head
                    if self.head:
                        self.head.prev = new_node

                    self.head = new_node
                    self.current = new_node
                else:
                    new_node.prev = self.current
                    new_node.next = self.current.next

                    # 이전 노드 업데이트
                    if self.current.next:
                        self.current.next.prev = new_node
                    self.current.next = new_node
                    self.current = new_node  # 커서 위치 업데이트

    def display(self):
        cur = self.head
        while cur:
            print(cur.data, end='')
            cur = cur.next
        print()


def main() -> None:
    T = int(input().rstrip('\n'))
    for _ in range(T):
        key_log = input().rstrip('\n')
        ll = LinkedList()
        ll.insert(key_log)
        ll.display()


if __name__ == "__main__":
    main()
