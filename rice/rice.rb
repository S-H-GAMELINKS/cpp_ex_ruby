require './test'

puts hoge = Test.new
puts hoge.hello
puts hoge.instance_variable_get(:@foo)