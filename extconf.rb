require 'mkmf'
$LDFLAGS += " -lstdc++ -std=c++17"
create_makefile("Hello")