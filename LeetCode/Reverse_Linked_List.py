# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        temp_list = []
        ret = ListNode()
        cur_node = ret
        while head:  # convert Linked List to List
            temp_list.append(head.val)
            head = head.next

        for i in range(-1, -(len(temp_list) + 1), -1):  # reverse Linked List
            cur_node.next = ListNode(temp_list[i])
            cur_node = cur_node.next

        return ret.next
