#include "catch.hpp"
#include <cstdlib>
#include "Memory.h"

TEST_CASE( "test write with no delay works", "memory" ){
    Memory mem(5,0,0);
    mem.write(1,1,2);
    REQUIRE(mem.ready());
}

TEST_CASE( "test write delay of 2 works", "memory" ) {
    Memory mem(5,2,2);
    mem.write(1,1,2);
    REQUIRE(!mem.ready());
    REQUIRE(!mem.ready());
    REQUIRE(mem.ready());
}

TEST_CASE( "test read with no delay works", "memory" ){
    Memory mem(5,0,0);
    mem.write(1,1,2);
    REQUIRE(mem.ready());
}

TEST_CASE( "test read with delay of 2 works", "memory" ) {
    Memory mem(5,2,2);
    mem.write(1,1,2);
    REQUIRE(!mem.ready());
    REQUIRE(!mem.ready());
    REQUIRE(mem.ready());
}

TEST_CASE( "read 8 bits after write with no delay works", "memory" ) {
    Memory mem(5,0,0);
    mem.write(1,1,2);
    REQUIRE(mem.ready());
    mem.read(1,1);
    REQUIRE(mem.ready());
    REQUIRE(mem.read_valid() == 2);
}

TEST_CASE( "read 8 bitsafter write with delay of 2 works", "memory" ) {
    Memory mem(5,2,2);
    mem.write(1,1,2);
    REQUIRE(!mem.ready());
    REQUIRE(!mem.ready());
    REQUIRE(mem.ready());
    mem.read(1,1);
    REQUIRE(!mem.ready());
    REQUIRE(!mem.ready());
    REQUIRE(mem.ready());
    REQUIRE(mem.read_valid() == 2);
}

TEST_CASE( "read 16 bits after write with no delay works", "memory" ) {
    Memory mem(5,0,0);
    mem.write(1,2,478);
    REQUIRE(mem.ready());
    mem.read(1,2);
    REQUIRE(mem.ready());
    REQUIRE(mem.read_valid() == 478);
}

TEST_CASE( "read 16 bitsafter write with delay of 2 works", "memory" ) {
    Memory mem(5,2,2);
    mem.write(1,2,478);
    REQUIRE(!mem.ready());
    REQUIRE(!mem.ready());
    REQUIRE(mem.ready());
    mem.read(1,2);
    REQUIRE(!mem.ready());
    REQUIRE(!mem.ready());
    REQUIRE(mem.ready());
    REQUIRE(mem.read_valid() == 478);
}

