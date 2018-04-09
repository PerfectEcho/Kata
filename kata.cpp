#include <iostream>
#include <string>
#include <sstream>
#include "catch.hpp"
using std::string;
using std::istringstream;


int add (string dogo)
{
  for (auto i = 0; i<dogo.size(); i++)
  {
    if (dogo[i]==',')
    {
      if ((dogo[i+1]) == '\n')
      {
        return -1;
      }
      dogo[i]=' ';
    }

  }

  istringstream ss(dogo);
  int number = 0;
  int total = 0;

  while(ss>>number)
  {
    total+=number;
  }

  return total;
}



TEST_CASE("Test empty string")
{
   REQUIRE( add ("") == 0 );

}

TEST_CASE("Test single numbers")
{
   REQUIRE( add ("1") == 1 );
   REQUIRE( add ("13") == 13);
   REQUIRE( add ("100") == 100);

}
TEST_CASE("Test case with commas")
{
  REQUIRE( add ("1,2,3") == 6);
  REQUIRE( add ("1,2\n,3") == 6);
  REQUIRE( add ("1,\n") == -1);
  REQUIRE( add ("//;\n1;2") == 3)
}
