#include "rice/Class.hpp"

Rice::Object test_initialize(Rice::Object self) {
    self.iv_set("@foo", 42);
}

Rice::Object test_hello(Rice::Object /* self */) {
    Rice::String str("Hello World");
    return str;
}

extern "C" {
    void Init_test() {
        Rice::Class rb_cTest = Rice::define_class("Test")
            .define_method("initialize", &test_initialize)
            .define_method("hello", &test_hello);
    }
}