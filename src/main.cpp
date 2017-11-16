#include<iostream>
#include <string>
#include <fstream>
#include "map.hpp"

using namespace std;


int main(){
 ifstream testFileOne("firstnames.txt");
 ifstream testFileTwo("lastnames.txt");
 int counter=0;
 std::string strFirst;
 std::string strTwo;
 std::string combineString;
 int val=250;
 int valTwo=300;

 const char *testChar="heloo";
 Map testing("testArray",counter);
 while(getline(testFileOne,strFirst) && getline(testFileTwo,strTwo)){

  combineString= strFirst+" "+strTwo;
  const char *charString= combineString.c_str();
  testing.add(charString,counter);
  counter++;
 }


 //Test cases for adding function which returns true or false.


 //Test case for size funtion
 cout << testing.size()<<" is the testing size" << endl;



 cout << testing.get("Marion Agincourt",val) << "should be true"<<endl;
 cout <<  testing.get("Craig Albertson",valTwo) << " shoudld be false"<<endl;

 //cout << testing.remove("Marion Agincourt") <<endl;
 //const char *array[]={"Craig","cr","er","wert","crawe"};
 cout << testing.howMany("cr") << " should be 63"<< endl;
 cout << testing.howMany("alb") <<" should be 6" << endl;

 return 0;
}
