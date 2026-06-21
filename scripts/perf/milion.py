def f(a, b, c, d):
  return a + b + c + d

class C:
  def __init__(self, x):
    self.x = x

x = 0
c = C(x)
m = 1000000

while x < m:
  f(1, 2, 3, 4)
  c = C(x)
  x += 1

print(c)
print(x)