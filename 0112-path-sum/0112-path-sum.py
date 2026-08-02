from collections import deque

class Solution(object):
    def hasPathSum(self, root, targetSum):
        if not root:
            return False

        q = deque([(root, root.val)])

        while q:
            node, currsum = q.popleft()

            if node.left is None and node.right is None and currsum == targetSum:
                return True

            if node.left:
                q.append((node.left, currsum + node.left.val))

            if node.right:
                q.append((node.right, currsum + node.right.val))

        return False