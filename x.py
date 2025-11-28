a = 0

def x():
  m = 1
  def f(value):
    a = []
    a.append(a)
    return value * 2 + m

  l = a + a

  m += 1

  f(l)

while a <= 10000000:
    x()
    a = a + 1