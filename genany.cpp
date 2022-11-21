#include "genany.h"

#include <iostream>

#if defined(USE_QT)
#include <QSharedPointer>
#else
#include <memory>
#endif

std::any genAny()
{
#if defined(USE_QT)
    auto ret = std::any(QSharedPointer<int>::create(42));
#else
    auto ret = std::any(std::make_shared<int>(42));
#endif
    std::cout << "genAny:\tname=" << ret.type().name() << "\thash_code=" << ret.type().hash_code() << '\n';
    return ret;
}
