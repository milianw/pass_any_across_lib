#include <any>
#include <iostream>

#if defined(USE_QT)
#include <QSharedPointer>
#else
#include <memory>
#endif

#include "genany.h"

int main()
{
#if defined(USE_QT)
    using WrappedType = QSharedPointer<int>;
#else
    using WrappedType = std::shared_ptr<int>;
#endif

    auto a = genAny();
    std::cout << "main:\tname=" << a.type().name() << "\thash_code=" << a.type().hash_code() << '\n';
    std::cout << "typeid matches:\t"<< (a.type() == typeid(WrappedType)) << '\n';

    auto p = std::any_cast<WrappedType>(a);
    std::cout << "wrapped ptr:\t" << p << '\n';
    std::cout << "wrapped value:\t"<< *p << '\n';
    return 0;
}
