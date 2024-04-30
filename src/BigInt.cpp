//
// Created by mathilde on 28/04/24.
//

#include "crypto/BigInt.hpp"
#include <cstring>

namespace Crypto {

    BigInt::BigInt(int64_t value) {
        negative = false;
        dataSize = 0;
        data = nullptr;

        uint64_t num;
        if(value < 0) {
            negative = true;
            num = -value;
        } else {
            num = value;
        }

        uint32_t right = 0;
        uint32_t left = 0;

        if(num > 0) {
            right = 0xffffffff & num;
            dataSize++;
        }

        if(num > 0xffffffff) {
            left = num >> 32;
            dataSize++;
        }

        if(dataSize > 0) {
            data = new uint32_t[dataSize];
            data[0] = right;
            if(dataSize > 1) {
                data[1] = left;
            }
        }
    }

    BigInt::BigInt() : negative(false), data(nullptr), dataSize(0) {
    }

    BigInt::~BigInt() {
        delete[] data;
    }

    BigInt::BigInt(const BigInt& other) : dataSize(other.dataSize), negative(other.negative),
                                          data(new uint32_t[dataSize]) {
        memcpy(data, other.data, dataSize);
    }

    BigInt& BigInt::operator=(const BigInt& other) {
        if (this != &other) {
            delete[] data;
            dataSize = other.dataSize;
            negative = other.negative;
            if(dataSize > 0) {
                data = new uint32_t[dataSize];
                memcpy(data, other.data, dataSize);
            } else {
                data = nullptr;
            }

        }
        return *this;
    }

    BigInt::BigInt(BigInt&& other) noexcept: dataSize(other.dataSize), negative(other.negative), data(other.data) {
        other.data = nullptr;
        other.dataSize = 0;
    }

    BigInt& BigInt::operator=(BigInt&& other) noexcept {
        if (this != &other) {
            delete[] data;
            dataSize = other.dataSize;
            negative = other.negative;
            data = other.data;
            other.data = nullptr;
            other.dataSize = 0;
        }
        return *this;
    }


    std::string BigInt::toString() {
        std::string res;

        if(data == nullptr || dataSize == 0) {
            res += '0';
            return res;
        }

        if(negative) {
            res += '-';
        }

        bool started = false;
        for(size_t i = 1; i <= dataSize; i++) {
            uint32_t num = data[dataSize - i];
            uint32_t mask = 0xf0000000;
            for(int nibble = 7; nibble >= 0; nibble--) {
                switch((num & mask) >> nibble*4) {
                    case 0:
                        if(started)
                            res += '0';
                        break;
                    case 1:
                        res += '1';
                        started = true;
                        break;
                    case 2:
                        res += '2';
                        started = true;
                        break;
                    case 3:
                        res += '3';
                        started = true;
                        break;
                    case 4:
                        res += '4';
                        started = true;
                        break;
                    case 5:
                        res += '5';
                        started = true;
                        break;
                    case 6:
                        res += '6';
                        started = true;
                        break;
                    case 7:
                        res += '7';
                        started = true;
                        break;
                    case 8:
                        res += '8';
                        started = true;
                        break;
                    case 9:
                        res += '9';
                        started = true;
                        break;
                    case 10:
                        res += 'a';
                        started = true;
                        break;
                    case 11:
                        res += 'b';
                        started = true;
                        break;
                    case 12:
                        res += 'c';
                        started = true;
                        break;
                    case 13:
                        res += 'd';
                        started = true;
                        break;
                    case 14:
                        res += 'e';
                        started = true;
                        break;
                    case 15:
                        res += 'f';
                        started = true;
                        break;
                }
                mask = mask >> 4;
            }
        }

        return res;
    }


} // Crypto