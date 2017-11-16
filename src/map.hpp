#ifndef MAP_HPP
#define MAP_HPP
#include<string>
class Map{
/*
Student Name: Craig Albertson
Program Name: Large Map
Creation Date: January 23 2017
Last Modified Date: February 14 2017
CSCI Course: Data Structures
Grade Received: 50
Comments Regarding Design: The reason for receiving this grade is becuase of the run time, since linked list is O(n) it took a great of time when calling the function get.


*/
public:

 struct nodeMap{
    std::string name;
    int id;
    nodeMap *next;

   };
struct nodeMap *newNode;
struct nodeMap *nodeHead=NULL;
struct nodeMap *nodeTail;
struct nodeMap *currentNode;

int length;

  Map();
  Map(std::string pointing,int size);
  bool add(const char *key,int val);
  bool get(const char *key, int &ret);
  int size();
  bool remove(const char *key);
  int howMany(const char *prefix);
  ~Map();


private:

  std::string paraString;
  int numberId;
  char *copyKey;




};


#endif
