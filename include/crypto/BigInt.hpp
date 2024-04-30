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
        size_t dataSize;
        uint32_t* data;

    public:
        explicit BigInt(int64_t value);

        BigInt();

        ~BigInt();

        BigInt(const BigInt& other);

        BigInt& operator=(const BigInt& other);

        BigInt(BigInt&& other) noexcept;

        BigInt& operator=(BigInt&& other) noexcept;

        std::string toString();
    };

} // crypto

#endif //CRYPTO_BIGINT_HPP
