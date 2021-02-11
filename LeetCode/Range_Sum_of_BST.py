# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        def dfs(node):
            if not node: return # 노드가 존재하지 않으면 탈출
            if low <= node.val and node.val <= high: # 현재 노드가 low, high 사이의 값이면 결과값에 더해 준다.
                self.ret += node.val
            if node.val > low: # 현재 노드가 low보다 크면 왼쪽 자식 노드를 탐색한다.
                dfs(node.left)
            if node.val < high: # 현재 노드가 high보다 작다면 오른쪽 자식 노드를 탐색한다.
                dfs(node.right)
            
        self.ret = 0
        dfs(root)
        
        return self.ret