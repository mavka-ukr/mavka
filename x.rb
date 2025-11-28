$a = 0

def x
  def f(value)
    value * 2
  end

  l = $a + $a

  f(l)
end

while $a <= 10000000
  x()
  $a += 1
end
