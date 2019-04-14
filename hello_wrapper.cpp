#include "ruby/ruby.h"
#include "hello.hpp"

void hello_wrapper() {
    hello();
}