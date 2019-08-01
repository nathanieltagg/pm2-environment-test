#include <iostream>
#include <nan.h>


int lib_func(void); // declaration
int builtin_func(void){
	return 99;
}

NAN_METHOD(cfunc) {
	std::cout << "Calling builtin function. Result:" << builtin_func()  << std::endl;
	std::cout << "Calling library function. Result:" << lib_func()  << std::endl;
    info.GetReturnValue().Set(Nan::True());
}

NAN_MODULE_INIT(Initialize) {
    NAN_EXPORT(target, cfunc);
}

NODE_MODULE(addon, Initialize);



