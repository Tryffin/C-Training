// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "test_matcher.hh"
#include "passgrid.hh"
#include "path.hh"
#include <fstream>


bool notEqualGrids (PassGrid& p0, PassGrid& p1)
{
  for (std::size_t i = 0 ; i < p0.getH(); i++ )
    for (std::size_t j = 0 ; j < p0.getW(); j++)
      if ((p0(i,j) != p1(i,j)))
        return true;
  return false;
}


TEST_CASE("1: Size of the grid","[grid]"){
  PassGrid p0(0,0);
  REQUIRE(p0.getW() == 0);
  REQUIRE(p0.getH() == 0);
  PassGrid p1(10,8);
  REQUIRE(p1.getW() == 10);
  REQUIRE(p1.getH() == 8);
}

TEST_CASE("1: copy same grid"){
  PassGrid p0(0,0);
  PassGrid p1(p0);
  REQUIRE(!notEqualGrids(p0,p1));
}

TEST_CASE("2: Grid contents","[grid]"){
  PassGrid p0(10,10);
  SECTION("All characters are printable character"){
    for (std::size_t i = 0 ; i < p0.getH(); i++ )
      for (std::size_t j = 0 ; j < p0.getW(); j++)
        CHECK_THAT(p0(i,j), IsBetween(33,94));
  }
  SECTION("Same grids are equals")
    {
      REQUIRE_FALSE(notEqualGrids(p0,p0));
    }
  SECTION("Two successively generated grid are different")
    {
      PassGrid p1(10,10);
      REQUIRE(notEqualGrids(p0,p1));
    }
  SECTION("reset make differences")
    {
      PassGrid p1(p0);
      p0.reset();
      REQUIRE(notEqualGrids(p0,p1));
    }
}

TEST_CASE("5: check save and load","[passgrid]")
{
    PassGrid p0(10,10);
    PassGrid p1(p0);
    std::fstream fs;
    fs.open ("grid.txt", std::fstream::out);
    p0.save(fs);
    fs.close();
    fs.open ("grid.txt", std::fstream::in);
    p0.load(fs);
    REQUIRE(!notEqualGrids(p0,p1));

}

TEST_CASE("3: check path start","[path]")
{
  Path p(4,4,5);
  REQUIRE_THAT( p.getStartX(),IsBetween(0,4));
  REQUIRE_THAT( p.getStartY(),IsBetween(0,5));
}

TEST_CASE("7: Path Created correctly")
{
  Path p(4,9,8);
  SECTION("Correct size")
    {
      REQUIRE(p.getSize() == 4);
    }
  SECTION(" starting point whithin bounds")
    {
      REQUIRE_THAT(p.getStartX(), IsBetween(0,9));
      REQUIRE_THAT(p.getStartY(), IsBetween(0,8));
    }
}
