IT = 10000000

a = 0

def pos():
  return a - a

def x():
  def f(value):
    x = [2]
    return x[pos()] + value * 2

  l = a + a

  f(l)

while a <= IT:
    x()
    a = a + 1