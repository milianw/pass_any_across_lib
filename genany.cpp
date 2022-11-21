#include "genany.h"

#include <memory>
#include <iostream>

std::any genAny()
{
    auto ret = std::any(std::make_shared<int>(42));
    std::cout << "genAny:\tname=" << ret.type().name() << "\thash_code=" << ret.type().hash_code() << '\n';
    return ret;
}
