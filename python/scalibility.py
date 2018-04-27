
def line(str):
    print("=" * 20, str, "=" * 20)

from collections import deque

line("collections.deque: a double-ended queue")

# dqueue: a double-ended queue, thread-safe, memory efficient appends
# and pops from either side of the deque with approximately
# the same O(1) performance in either direction.

a = deque()
a.append(1)
a.appendleft(0)
print(a)

line('')
