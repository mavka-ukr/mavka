$IT = 10000000
$a = 0

def pos
  $a - $a
end

def x
  def f(value)
    x = [2]
    return x[pos()] + value * 2
  end

  l = $a + $a

  f(l)
end

while $a <= $IT
  x()
  $a += 1
end
