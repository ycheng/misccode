# python:
#   create new reference for immutable value
#   use reference for mutable value (object)
def foo(a):
  print (id(a))
  a.append(1) # or a = 1
  print (id(a))
a = [0]
print (id(a))
foo(a)
print (a)
