#include <iostream>
#include <memory>

class Foo {
public:
    Foo() {
        std::cout << "Ctor" << std::endl;
    }
    Foo(const Foo & other) = delete;
    Foo( Foo && other) {
        std::cout << "Ctor" << std::endl;
    }
    ~Foo() {
        std::cout << "Dtor" << std::endl;
    }

    void operator = (const Foo & other)=delete;
    void operator = (Foo && other) {}



    void bar() {
        std::cout << "bar" << std::endl;
    }
};
[[nodiscard]]
auto createFoo() -> std::unique_ptr<Foo> {
    auto result = std::make_unique<Foo>();
    return result;
}

auto sink(std::unique_ptr<Foo> f) {
    f->bar();
    return f;
}


int main() {

    /*
    //std::shared_ptr<Foo> myPtr = std::shared_ptr<Foo>(new Foo());
    auto myPtr = std::make_shared<Foo>();

    std::cout << myPtr.use_count() << std::endl;

    {
        std::shared_ptr<Foo> other = myPtr;

        std::cout << myPtr.use_count() << std::endl;
    }

    std::cout << myPtr.use_count() << std::endl;
    myPtr->bar();

*/
/*    auto myPtr = std::make_unique<Foo>();

    auto other = std::move(myPtr);

    other->bar();

    std::string s = "Hallo";
    std::string b = std::move(s);




    std::cout<< "s " << s << std::endl;
    std::cout<< "b " << b << std::endl;
    */

    std::unique_ptr<Foo>  myPtr = createFoo();

    myPtr = sink(std::move(myPtr));

    return 0;
}
