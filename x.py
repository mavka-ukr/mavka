a = 0

def x():
  def f(value):
    x = [2]
    return x[0] + value * 2

  l = a + a

  f(l)

while a <= 10000000:
    x()
    a = a + 1