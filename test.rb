#!/usr/bin/env ruby
# encoding: utf-8
require_relative './dziwne/Dziwne'

class Dziwne
attr_reader :a

def initialize
 @a = 7
end

end

t = Dziwne.new
p t.ustaw(nil)
p t.ustaw(t.a)
p t.cosik

y = Dziwne.test
p y.ustaw nil
p t
p y

#Is possible to check this? I found to compare free function of my object
# to free function of parameter (pointer) and check id. But I dont know what
# to do this.

#p t.ustaw y
