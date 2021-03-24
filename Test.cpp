#include "doctest.h"
#include "Board.hpp"
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Empty string"){
    Board b;
    CHECK(b.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(b.read(0, 0, Direction::Vertical, 1) == string("_"));
    b.post(0, 0, Direction::Horizontal, "");
    CHECK(b.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(b.read(0, 0, Direction::Vertical, 1) == string("_"));
    b.post(0, 0, Direction::Vertical, "");
    CHECK(b.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(b.read(0, 0, Direction::Vertical, 1) == string("_"));
}

TEST_CASE("Vertical string"){
    Board b;
    b.post(1,1,Direction::Vertical,"Vertical");
    CHECK(b.read(0, 1, Direction::Horizontal, 2) == string("_V"));
    CHECK(b.read(1, 1, Direction::Horizontal, 2) == string("V_"));
    CHECK(b.read(1, 1, Direction::Horizontal, 1) == string("V"));
    CHECK(b.read(0, 2, Direction::Horizontal, 2) == string("_e"));
    CHECK(b.read(1, 2, Direction::Horizontal, 2) == string("e_"));
    CHECK(b.read(1, 2, Direction::Horizontal, 1) == string("e"));
    CHECK(b.read(0, 3, Direction::Horizontal, 2) == string("_r"));
    CHECK(b.read(1, 3, Direction::Horizontal, 2) == string("r_"));
    CHECK(b.read(1, 3, Direction::Horizontal, 1) == string("r"));
    CHECK(b.read(0, 4, Direction::Horizontal, 2) == string("_t"));
    CHECK(b.read(1, 4, Direction::Horizontal, 2) == string("t_"));
    CHECK(b.read(1, 4, Direction::Horizontal, 1) == string("t"));
    CHECK(b.read(0, 5, Direction::Horizontal, 2) == string("_i"));
    CHECK(b.read(1, 5, Direction::Horizontal, 2) == string("i_"));
    CHECK(b.read(1, 5, Direction::Horizontal, 1) == string("i"));
    CHECK(b.read(0, 6, Direction::Horizontal, 2) == string("_c"));
    CHECK(b.read(1, 6, Direction::Horizontal, 2) == string("c_"));
    CHECK(b.read(1, 6, Direction::Horizontal, 1) == string("c"));
    CHECK(b.read(0, 7, Direction::Horizontal, 2) == string("_a"));
    CHECK(b.read(1, 7, Direction::Horizontal, 2) == string("a_"));
    CHECK(b.read(1, 7, Direction::Horizontal, 1) == string("a"));
    CHECK(b.read(0, 8, Direction::Horizontal, 2) == string("_l"));
    CHECK(b.read(1, 8, Direction::Horizontal, 2) == string("l_"));
    CHECK(b.read(1, 8, Direction::Horizontal, 1) == string("l"));
}



TEST_CASE("Vertical string"){
    Board b;
    b.post(1,1,Direction::Horizontal,"Horizontal");
    CHECK(b.read(1, 0, Direction::Vertical, 2) == string("_H"));
    CHECK(b.read(1, 1, Direction::Vertical, 2) == string("H_"));
    CHECK(b.read(1, 1, Direction::Vertical, 1) == string("H"));
    CHECK(b.read(2, 0, Direction::Vertical, 2) == string("_o"));
    CHECK(b.read(2, 1, Direction::Vertical, 2) == string("o_"));
    CHECK(b.read(2, 1, Direction::Vertical, 1) == string("o"));
    CHECK(b.read(3, 0, Direction::Vertical, 2) == string("_r"));
    CHECK(b.read(3, 1, Direction::Vertical, 2) == string("r_"));
    CHECK(b.read(3, 1, Direction::Vertical, 1) == string("r"));
    CHECK(b.read(4, 0, Direction::Vertical, 2) == string("_i"));
    CHECK(b.read(4, 1, Direction::Vertical, 2) == string("i_"));
    CHECK(b.read(4, 1, Direction::Vertical, 1) == string("i"));
    CHECK(b.read(5, 0, Direction::Vertical, 2) == string("_z"));
    CHECK(b.read(5, 1, Direction::Vertical, 2) == string("z_"));
    CHECK(b.read(5, 1, Direction::Vertical, 1) == string("z"));
    CHECK(b.read(6, 0, Direction::Vertical, 2) == string("_o"));
    CHECK(b.read(6, 1, Direction::Vertical, 2) == string("o_"));
    CHECK(b.read(6, 1, Direction::Vertical, 1) == string("o"));
    CHECK(b.read(7, 0, Direction::Vertical, 2) == string("_n"));
    CHECK(b.read(7, 1, Direction::Vertical, 2) == string("n_"));
    CHECK(b.read(7, 1, Direction::Vertical, 1) == string("n"));
    CHECK(b.read(8, 0, Direction::Vertical, 2) == string("_t"));
    CHECK(b.read(8, 1, Direction::Vertical, 2) == string("t_"));
    CHECK(b.read(8, 1, Direction::Vertical, 1) == string("t"));
    CHECK(b.read(9, 0, Direction::Vertical, 2) == string("_a"));
    CHECK(b.read(9, 1, Direction::Vertical, 2) == string("a_"));
    CHECK(b.read(9, 1, Direction::Vertical, 1) == string("a"));
    CHECK(b.read(10, 0, Direction::Vertical, 2) == string("_l"));
    CHECK(b.read(10, 1, Direction::Vertical, 2) == string("l_"));
    CHECK(b.read(10, 1, Direction::Vertical, 1) == string("l"));
}

TEST_CASE("one on another"){
    Board b;
    b.post(1,1,Direction::Horizontal,"cpp");
    b.post(2,1,Direction::Horizontal,"is the");
    b.post(3,1,Direction::Horizontal,"best");
    b.post(3,1,Direction::Vertical,"bap");
    b.post(1,2,Direction::Vertical,"bip");
    b.post(2,3,Direction::Vertical,"bup");
    CHECK(b.read(1,1,Direction::Horizontal,3) == string("cbp"));
    CHECK(b.read(2,1,Direction::Horizontal,6) == string("iibthe"));
    CHECK(b.read(3,1,Direction::Horizontal,4) == string("bput"));
    CHECK(b.read(1,1,Direction::Vertical,5) == string("cibap"));
    CHECK(b.read(1,2,Direction::Vertical,3) == string("bip"));
    CHECK(b.read(1,3,Direction::Vertical,4) == string("pbup"));
}