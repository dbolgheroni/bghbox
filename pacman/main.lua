-- LOVE 0.9.0 required

function love.load()
    blksz = 40
    pacblksz = 8

    player = { x, y }

    pac = {
        { 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 0 },
        { 1, 1, 1, 1, 0 },
        { 0, 1, 1, 1, 1 }
    }

    map = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    }

    -- initial position
    player.x = 2 * blksz
    player.y = 2 * blksz

    -- window size
    love.window.setMode(16 * blksz, 16 * blksz, { borderless=true })
end

function love.draw()
    drawpac()
    drawmap(map)
end

function love.keypressed(key)
    if key == "up" then
        if testpos(0, -1) then
            player.y = player.y - blksz
        end
    end

    if key == "down" then
        if testpos(0, 1) then
            player.y = player.y + blksz
        end
    end

    if key == "right" then
        if testpos(1, 0) then
            player.x = player.x + blksz
        end
    end

    if key == "left" then
        if testpos(-1, 0) then
            player.x = player.x - blksz
        end
    end
end

function testpos(x, y)
    if map[(player.y / blksz) + y][(player.x / blksz) + x] == 1 then
        return false
    end

    return true
end

function drawpac()
    blksize = 8
    pacman = love.graphics.newCanvas(5 * blksize, 5 * blksize)
    
    -- change canvas
    love.graphics.setCanvas(pacman)

    -- save old color and set new color
    r, g, b = love.graphics.getColor()
    love.graphics.setColor(255, 255, 0)

    -- draw pacman based on the map
    for y=1, #pac do
        for x=1, #pac[y] do
            if pac[y][x] == 1 then
                love.graphics.rectangle("fill",
                        (x-1)*blksize, (y-1)*blksize,
                        blksize, blksize)
            end
        end
    end

    -- restore canvas
    love.graphics.setCanvas()

    -- restore old color
    love.graphics.setColor(r, g, b)
    
    love.graphics.draw(pacman, player.x - blksz, player.y - blksz)
end

function drawmap(map)
    for y=1, #map do
        for x=1, #map[y] do
            if map[y][x] == 1 then
                -- luaisms, need to adjust to 0
                love.graphics.rectangle("fill", (x-1)*blksz, (y-1)*blksz, blksz, blksz)
            end
        end
    end
end
