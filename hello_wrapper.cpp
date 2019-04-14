#include "ruby/ruby.h"
#include "hello.hpp"
#include <new>

void wrap_Hello_free(Hello* ptr) {
    ptr->~Hello();
    ruby_xfree(ptr);
}

VALUE wrap_Hello_allocate(VALUE self) {
    void* p = ruby_xmalloc(sizeof(Hello));
    return Data_Wrap_Struct(self, NULL, wrap_Hello_free, p);
}

VALUE wrap_Hello_initialize(VALUE self, VALUE val_var) {
    Hello* p;
    Data_Get_Struct(self, Hello, p);

    int var = FIX2INT(val_var);
    new (p) Hello(var);

    return Qnil;
}

VALUE wrap_Hello_sayHello(VALUE self) {
    Hello* p;
    Data_Get_Struct(self, Hello, p);
    p->sayHello();
    return Qnil;
}

extern "C" {
    void Init_Hello() {

        VALUE class_define = rb_define_class("Hello", rb_cObject);

        rb_define_alloc_func(class_define, wrap_Hello_allocate);
        rb_define_private_method(class_define, "initialize", (VALUE(*)(...))wrap_Hello_initialize, 1);

        rb_define_method(class_define, "sayHello", (VALUE(*)(...))wrap_Hello_sayHello, 0);
    }
}