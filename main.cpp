#include <any>
#include <iostream>
#include <memory>

#include "genany.h"

int main()
{
    using WrappedType = std::shared_ptr<int>;

    auto a = genAny();
    std::cout << "main:\tname=" << a.type().name() << "\thash_code=" << a.type().hash_code() << '\n';
    std::cout << "typeid matches:\t"<< (a.type() == typeid(WrappedType)) << '\n';

    auto p = std::any_cast<WrappedType>(a);
    std::cout << "wrapped ptr:\t" << p << '\n';
    std::cout << "wrapped value:\t"<< *p << '\n';
    return 0;
}
