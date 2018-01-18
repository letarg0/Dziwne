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
