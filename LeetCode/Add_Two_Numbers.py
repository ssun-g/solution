# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ret = ListNode()
        carry = 0  # 처음 올림 값을 0으로 설정 해준다.
        cur_node = ret
        while l1 or l2:  # 길이가 긴 ListNode의 길이만큼 돌면서 덧셈해준다. index를 벗어나면 0값으로 초기화
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0

            sum = a + b + carry  # 올림 값이 존재할 경우 이를 포함한 a, b의 덧셈
            carry = sum // 10  # 더해서 10이 넘는다면 올림 값을 설정 해준다.
            cur_node.next = ListNode(sum % 10)  # 결과 값의 next에 a+b의 올림 값을 제외한 일의 자리 숫자를 하나씩 저장한다.
            cur_node = cur_node.next  # 다음 위치를 가리키게 해준다.

            if l1:  # l1이 존재하면 다음 위치를 가리킨다.
                l1 = l1.next
            if l2:  # l2가 존재하면 다음 위치를 가리킨다.
                l2 = l2.next

        if carry:
            cur_node.next = ListNode(carry)

        return ret.next
