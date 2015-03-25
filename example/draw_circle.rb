# sleep(0.5)
# Mouse.move_to(50,50)
# sleep(1)
# Mouse.double_click

offset = 500
radius = 250
360.times do |i|
  x = radius * Math.cos(i / 180 * Math::PI) + offset
  y = radius * Math.sin(i / 180 * Math::PI) + offset

  Mouse.move_to(x,y)
  sleep(0.01)
end
