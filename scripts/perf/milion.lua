local function f(a, b, c, d)
  return a + b + c + d
end

-- Define the class/prototype
local C = {}
C.__index = C

function C.new(x)
  local self = setmetatable({}, C)
  self.x = x
  return self
end

local x = 0
local c = C.new(x)
local m = 1000000

while x < m do
  f(1, 2, 3, 4)
  c = C.new(x)
  x = x + 1
end

print(c)
print(x)