#ifndef MAP_HPP
#define MAP_HPP
#include<string>
class Map{

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
