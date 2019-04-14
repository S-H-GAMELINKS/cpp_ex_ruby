#include "ruby/ruby.h"
#include "hello.hpp"

VALUE hello_wrapper(VALUE self, VALUE val_var) {
    int var, result;

    var = FIX2INT(val_var);
    result = hello(var);

    return INT2FIX(result);
}

extern "C" {
    void Init_Hello() {
        rb_define_global_function("hello", (VALUE(*)(...))hello_wrapper, 1);
    }
}