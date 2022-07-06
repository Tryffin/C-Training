// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
//include your classes here
using namespace ThreeVal;

TEST_CASE("1: Atoms toString")
{
  Atom a(U),b,d(F);
  Atom c(b);
  REQUIRE(a.toString() == "(a_0 = U)");
  REQUIRE(b.toString() == "(a_1 = U)");
  REQUIRE(c.toString() == "(a_3 = U)");
  REQUIRE(d.toString() == "(a_2 = F)");
}


TEST_CASE("2: Create Atoms and evaluate Atoms"){
  Atom a(U),b,c(T),d(F);
  REQUIRE(a.evaluate() == U);
  REQUIRE(b.evaluate() == U);
  REQUIRE(c.evaluate() == T);
  REQUIRE(d.evaluate() == F);
  Atom e(a);
  REQUIRE(e.evaluate() == U);
  REQUIRE((a.id() != e.id() && b.id() != a.id() && a.id() != c.id()));
}


TEST_CASE("3: Assign Atoms "){
  Atom a,b;
  a = T;
  REQUIRE(a.evaluate() == T);
  a = false;
  REQUIRE(a.evaluate() == F);
  a = b = T;
  REQUIRE((a.evaluate() == T && b.evaluate() == T));

}


TEST_CASE("4: Create and Evaluate NOT operator")
{
  Atom a(U),b,c(T),d(F);
  ExpNot not1(c);
  REQUIRE(not1.evaluate() == F);
  REQUIRE(not1.toString() == "!(a_13 = T)");
  REQUIRE(ExpNot(not1).evaluate() == T);
  REQUIRE(ExpNot(not1).toString() =="!!(a_13 = T)");
}

TEST_CASE("5: Create and Evaluate AND et OR operator")
{
  Atom a(T);
  Atom b;
  Atom c(F);
  ExpNot not1(a);
  ExpAnd and1(not1,b);
  ExpAnd and2(a,b);
  ExpOr or1(and1,and2);
  REQUIRE(and1.evaluate() == F);
  REQUIRE(and2.evaluate() == U);
  REQUIRE(or1.evaluate() == U);
}


TEST_CASE("6: Equal operation")
{
  Atom a(U),b(U),c(U);
  ExpNot nota(a);
  ExpAnd and1(a , b);
  ExpAnd and2(nota , c);
  ExpAnd and3(b , c);
  ExpOr or1(and1,and2);
  ExpOr or2(or1,and3);
  REQUIRE(or2 == U);
  a = T;
  b = T;
  REQUIRE(a == T);
  REQUIRE(or2 == T);
}
