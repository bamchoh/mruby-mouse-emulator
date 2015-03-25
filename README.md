# mruby-mouse-emulator

This is the application that emulates mouse on windows.

## install by mrbgems
 - add conf.gem line to `build_config.rb`
```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'bamchoh/mruby-mouse-emulator'
    conf.gem :github => 'bamchoh/mruby-sleep', :branch => 'support-float-value'
end
```

## example

```ruby
offset = 500
radius = 250
360.times do |i|
  x = radius * Math.cos(i / 180 * Math::PI) + offset
  y = radius * Math.sin(i / 180 * Math::PI) + offset

  Mouse.move_to(x,y)
  sleep(0.01)
end
```

# License
under the MIT License:

* http://www.opensource.org/licenses/mit-license.php


