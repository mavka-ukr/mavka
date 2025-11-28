a = 0

function x()
  l = a + a
end

while a <= 10000000 do
  x()
  a = a + 1
end
