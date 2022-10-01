# Solution 1
class Solution:
    def buildAdjList(self, n, edgesList):
        adj = [[] for _ in range(n)]
        for c1, c2 in edgesList:
            adj[c2].append(c1)
        return adj
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        a = self.buildAdjList(numCourses, prerequisites)
        
        state = [0] * numCourses
        def hasCycle(n):
            
            if state[n] == 1:
                return False
            
            if state[n] == -1:
                return True
            
            state[n] = -1
            
            for i in a[n]:
                if hasCycle(i):
                    return True 
        
            state[n] = 1
            return False
            
        for v in range(numCourses):
            if hasCycle(v):
                return False
        return True