
from functools import partial

def add_numbers(x, y):
  return x+y

add_five_v1 = lambda y: add_numbers(5, y)
print(add_five_v1(8))

add_five_v2 = partial(add_numbers, 5)
print(add_five_v2(8))
