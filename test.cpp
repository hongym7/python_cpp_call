#include <iostream>
#include <stdlib.h>
#include <string.h>


typedef struct Result{
    unsigned long long ret_data;
    unsigned long ret_size;
} Result;

class Foo
{
    public:

        Foo(){
            std::cout << "init" << std::endl;
        }

        void test(){
            std::cout << "hello" << std::endl;
        }

        void getData(unsigned long long buf, unsigned long bufSize, Result *ret)
        {

            std::cout << "getData start " << buf <<"   " << bufSize << std::endl;

            ret->ret_data = buf+10;
            ret->ret_size = bufSize+10;

            std::cout << "getData end   " << ret->ret_data <<"   " << ret->ret_size << std::endl;
        }
};

extern "C" {
    Foo* Foo_new(){
        Foo* foo = new Foo();
        return foo;
    }

    void Foo_bar(Foo* foo){
        foo->test();
    }

    Result* Foo_Struct(){
        Result *ret = new Result();
        ret->ret_data = 777;
        ret->ret_size = 888;

        return ret;
    }

    void Foo_get(Foo* foo, long a, long b, Result* result){
        foo->getData(a, b, result);
    }
}
