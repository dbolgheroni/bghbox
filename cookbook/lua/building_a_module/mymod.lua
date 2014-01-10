-- module() is deprecated in Lua 5.2

local M = {}

function M.answer()
    return 42
end

function M.print()
    print(M.answer())
end

return M
