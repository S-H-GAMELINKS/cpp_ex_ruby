require 'mkmf'
$LDFLAGS += "-lstdc++"
create_makefile("Hello")