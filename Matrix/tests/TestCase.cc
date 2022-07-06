// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "tableau2d.hpp"
#include "matrix.hpp"
#include <iostream>
#include <string>

TEST_CASE("1: Tableau2D with float")
{
  Tableau2D<float> tab(10,10);
  tab(2,2) = 42.0;
  REQUIRE(tab(2,2)== 42);
  Tableau2D<float> tab2 = tab;
  REQUIRE(tab2 == tab);
  tab2(1,1) = 1.5;
  REQUIRE_FALSE(tab2 == tab);
  std::cout << " ---------- Tableau float ---------------" << std::endl;
  std::cout << tab2 << std::endl;
}

TEST_CASE("2: Tableau2D with string")
{
  Tableau2D<std::string> tab(4,4);
  tab(1,3) = "ABC";
  REQUIRE(tab(1,3)== "ABC");
  REQUIRE(tab(3,3)== "");
  std::cout << " ----------- Tableau string --------------" << std::endl;
  std::cout << tab << std::endl;

}

TEST_CASE("3: Matrix operation avec un réel")
{
  Matrix<int> mat(5,5);
  mat(0,1) = 2;
  mat(1,0) = 3;

  mat =  5 * mat;
  REQUIRE(mat(0,1) == 10);
  REQUIRE(mat(1,0) == 15);

  mat =  mat * 2 ;
  REQUIRE(mat(0,1) == 20);
  REQUIRE(mat(1,0) == 30);

  mat =  mat / 2 ;
  REQUIRE(mat(0,1) == 10);
  REQUIRE(mat(1,0) == 15);

  std::cout << " -------- Matrix int -----------------" << std::endl;
  std::cout << mat << std::endl;

}

TEST_CASE("5: Matrix operation between matix")
{
  Matrix<float> a1(5, 5, 0);
  Matrix<float> a2(5, 5, 1);
  Matrix<float> a3 = a2;
  Matrix<float> a4 = 2 * (a1 + a2 + a3);
  for(size_t i = 0; i < 5; i++)
    for(size_t j = 0; j < 5; j++)
      CHECK(a4(i,j) == 4);

}
TEST_CASE("4: Matrix init")
{
  Matrix<float> a1(5, 5, Matrix<float>::identity);
  for(size_t i = 0; i < 5; i++)
    for(size_t j = 0; j < 5; j++)
      if(i==j)
        CHECK(a1(i,j) == 1);
      else
        CHECK(a1(i,j) == 0);

  std::cout << " ----------Matrix id ---------------" << std::endl;
  std::cout << a1 << std::endl;
  Matrix<float> a2(5, 5, 2);
  for(size_t i = 0; i < 5; i++)
    for(size_t j = 0; j < 5; j++)
        CHECK(a2(i,j) == 2);
  std::cout << " ---------matrix with init----------------" << std::endl;
  std::cout << a2 << std::endl;

}
