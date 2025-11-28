a = 0

function x()
  function f(value)
    return value * 2
  end

  l = a + a

  f(l)
end

while a <= 10000000 do
  x()
  a = a + 1
end
