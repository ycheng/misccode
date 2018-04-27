
import bisect

def line(str):
    print("=" * 20, str, "=" * 20)

line("if code")

a = 10
b = "yes" if a % 2 == 0 else "no"
print(b, "mod 2 is zero")
c = "yes" if a % 3 == 0 else "no"
print(c, "mod 3 is zero")

line("tuple code")

a = 1, 2, 3, 4
b, c, *d = a
print(b) # 1
print(c) # 2
print(d) # 3, 4

line("array sort, bisect")
a = [4, 1, 5]
b = sorted(a) # return a new list
a.sort()
print(a, b)

b = ['aaaa', 'b', 'ccccc']
b.sort()
print(b)
b.sort(key=len)
print(b)

line("bisect")
a = [10, 20, 30, 40]
bisect.insort(a, 25)
print(a)

line("enumerate")
a = [10, 20, 30, 40]
for idx, value in enumerate(a):
    print(idx, value)

line("dict")

a = {1: "one", 2: "two"}
print(a.keys())
print(list(a.keys()))
print(a.values())
print(list(a.values()))

print(hash("12344")) # hash avaialbe means it can be key of dict
try:
    print(hash([12,344])) # hash avaialbe means it can be key of dict
except TypeError as err:
    print("Error:", err)

line("set, dict")
line("zip, reversed")
line("global var: specify var as global var")
line("generator")
line("itertools")

