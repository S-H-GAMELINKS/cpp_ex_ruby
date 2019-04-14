#include "ruby/ruby.h"
#include "hello.hpp"

void hello_wrapper() {
    hello();
}

extern "C" {
    void Init_Hello() {
        rb_define_global_function("hello", (VALUE(*)(...)hello_wrapper, 1));
    }
}