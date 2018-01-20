#!/usr/bin/env ruby
# encoding: utf-8
require_relative './dziwne/Dziwne'

class Dziwne

def testo
 a = Dziwne.new
 a.ustaw 1
 return a
end

end


t = Dziwne.new
p t.ustaw(nil)
p t.ustaw(7)
y = Dziwne.new
p t
p y

#this working
a = y.testo
p a.ustaw nil
#this not working
p y.test

#Is possible to check this? I found to compare free function of my object
# to free function of parameter (pointer) and check id. But I dont know what
# to do this.
#p t.ustaw y
