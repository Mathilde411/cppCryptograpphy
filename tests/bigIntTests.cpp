#include <catch2/catch_all.hpp>
#include "crypto/BigInt.hpp"

TEST_CASE("testZeroValue", "[testZeroValue]") {
    Crypto::BigInt test;
    REQUIRE(test.toString() == "0");
}

TEST_CASE("testAssignedZeroValue", "[testAssignedZeroValue]") {
    Crypto::BigInt test(0);
    REQUIRE(test.toString() == "0");
}

TEST_CASE("testOneValue", "[testOneValue]") {
    Crypto::BigInt test(1);
    REQUIRE(test.toString() == "1");
}

TEST_CASE("testMax32BitsValue", "[testMax32BitsValue]") {
    Crypto::BigInt test(0xffffffff);
    REQUIRE(test.toString() == "ffffffff");
}

TEST_CASE("testMax64BitsValue", "[testMax64BitsValue]") {
    Crypto::BigInt test(0xfffffffffffffff);
    REQUIRE(test.toString() == "fffffffffffffff");
}

TEST_CASE("testRandomValue1", "[testRandomValue1]") {
    Crypto::BigInt test(0x20ac6972e8983340);
    REQUIRE(test.toString() == "20ac6972e8983340");
}

TEST_CASE("testRandomValue2", "[testRandomValue2]") {
    Crypto::BigInt test(0x72bd336e3dfc6469);
    REQUIRE(test.toString() == "72bd336e3dfc6469");
}

TEST_CASE("testRandomValue3", "[testRandomValue3]") {
    Crypto::BigInt test(0x5f10f0191e3871cc);
    REQUIRE(test.toString() == "5f10f0191e3871cc");
}

TEST_CASE("testMinus1", "[testMinus1]") {
    Crypto::BigInt test(-1);
    REQUIRE(test.toString() == "-1");
}

TEST_CASE("testRandomNegativeValue1", "[testRandomNegativeValue1]") {
    Crypto::BigInt test(-1092426813041596461);
    REQUIRE(test.toString() == "-f2914660674d82d");
}

TEST_CASE("testRandomNegativeValue2", "[testRandomNegativeValue2]") {
    Crypto::BigInt test(-1831382650231189024);
    REQUIRE(test.toString() == "-196a60d13ad7ee20");
}