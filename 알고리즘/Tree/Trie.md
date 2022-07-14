```py
class Trie:
    def __init__(self):
        self.trie = dict()
        
    def insert(self, word: str) -> None:
        cur = self.trie
        for ch in word:
            if ch not in cur.keys():
                cur[ch] = dict()
            cur = cur[ch]
        cur['*'] = True

    def search(self, word: str) -> bool:
        cur = self.trie
        for ch in word:
            if ch not in cur.keys():
                return False
            cur = cur[ch]
        if '*' in cur.keys():
            return True
        else:
            return False

    def startsWith(self, prefix: str) -> bool:
        cur = self.trie
        for ch in prefix:
            if ch not in cur.keys():
                return False
            cur = cur[ch]
        return True


```