def foo(a):
  print (id(a))
  a += 1 # or a = 1
  print (id(a))
a = 0
print (id(a))
foo(a)
print (a)
