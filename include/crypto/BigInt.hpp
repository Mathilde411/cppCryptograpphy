//
// Created by mathilde on 28/04/24.
//

#ifndef CRYPTO_BIGINT_HPP
#define CRYPTO_BIGINT_HPP

#include <cstdint>
#include <memory>

namespace Crypto {

    class BigInt {
    private:
        bool negative;
        uint32_t* data;

    public:
        BigInt();
    };

} // crypto

#endif //CRYPTO_BIGINT_HPP
