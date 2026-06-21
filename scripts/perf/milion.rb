def f(a, b, c, d)
  a + b + c + d
end

class C
  attr_accessor :x

  def initialize(x)
    @x = x
  end
end

x = 0
c = C.new(x)
m = 1000000

while x < m
  f(1, 2, 3, 4)
  c = C.new(x)
  x += 1
end

puts c
puts x