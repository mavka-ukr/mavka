IT = 10000000

a = 0

function pos()
  return (a - a) + 1
end

function x()
  function f(value)
    local x = {2}
    return x[pos()] + value * 2
  end

  l = a + a

  f(l)
end

while a <= IT do
  x()
  a = a + 1
end
