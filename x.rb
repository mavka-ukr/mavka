$a = 0

def x
  def f(value)
    x = [2]
    return x[0] + value * 2
  end

  l = $a + $a

  f(l)
end

while $a <= 10000000
  x()
  $a += 1
end
