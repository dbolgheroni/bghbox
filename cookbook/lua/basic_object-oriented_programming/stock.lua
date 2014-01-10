-- Stock class

-- instance values
Stock = { ey = 0, roc = 0 }

-- constructor
function Stock:new(o) -- the same as function Stock.new(self, o)
    o = o or {}
    setmetatable(o, self)
    print(self) -- self is a table
    self.__index = self
    return o
end
