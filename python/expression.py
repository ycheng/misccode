
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
