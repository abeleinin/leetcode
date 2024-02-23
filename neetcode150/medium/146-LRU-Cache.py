class Node:
    def __init__(self, val, key):
        self.val = val
        self.key = key
        self.next = self.prev = None

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}

        self.head, self.tail = Node(0, 0), Node(0, 0)
        self.head.next, self.tail.prev = self.tail, self.head

    def insert(self, node):
        nxt, prev = self.head.next, self.head
        prev.next = nxt.prev = node
        node.next, node.prev = nxt, prev

    def remove(self, node: Node):
        nxt, prev = node.next, node.prev
        nxt.prev, prev.next = prev, nxt

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key] = Node(value, key)
        self.insert(self.cache[key])

        if len(self.cache) > self.cap:
            lru = self.tail.prev
            self.remove(lru)
            del self.cache[lru.key]

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)