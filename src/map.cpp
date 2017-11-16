#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include<stdio.h>
#include "map.hpp"

using namespace std;

struct nodeMap *nodeHead=NULL ,*nodeTail,*newNode;
//struct nodeMap *someNode;

Map::Map(){
  //nodeHead = nodeTail = NULL;

  struct nodeMap{
    std::string name;
    int id;
    nodeMap *next;
   };
  ifstream firstTextFile("firstnames.txt");
  ifstream secondTextFile("lastnames.txt");
  if(firstTextFile.is_open() && secondTextFile.is_open()){
    cout << "Its working" << endl;
  }

}

Map::Map(std::string pointing,int size){
  paraString = pointing;
  length=size;
  ifstream firstTextFile("firstnames.txt");
  ifstream secondTextFile("lastnames.txt");
}

bool Map::add(const char *key,int val){
  newNode  = new nodeMap;
  newNode -> name = key;
  newNode -> id = val;
  newNode -> next = NULL;

  if(nodeHead == NULL){
    nodeHead = newNode;
    nodeTail = newNode;
    //cout << "Node head is "<< nodeHead -> name << endl;
  }
  else{
    nodeTail -> next = newNode;
    nodeTail = newNode;
   //cout << " A node "<< nodeTail -> name << endl;
  }
 length++;
 //cout << nodeTail -> next << endl;

return true;
}

bool Map::get(const char *key,int &ret){
currentNode = nodeHead;

while(currentNode != NULL ){

  if(currentNode -> name == key){
    currentNode -> id = ret;
    return true;
  }
  currentNode = currentNode -> next;
}
return false;
}

int Map::size(){
  return  length;
}

bool Map::remove(const char *key){
  currentNode = nodeHead;
  nodeMap *deleteNode;
  while(currentNode != NULL ){

    if(currentNode -> name == key){
      deleteNode = currentNode -> next;
      currentNode -> next = deleteNode -> next;
      delete deleteNode;
      return true;
    }
    currentNode = currentNode -> next;
  }
  return false;
}
int Map::howMany(const char *prefix){
 int killCounter = -1;
 currentNode=nodeHead;

 while(currentNode != NULL ){
   string nodeString = currentNode -> name;
   string prefixString = prefix;

   if(nodeString.find(prefixString) != std::string::npos){
     killCounter++;
   }
   currentNode = currentNode -> next;
 }
 return killCounter;
}

Map::~Map(){
  nodeMap* currentNode =nodeHead;
  while(currentNode != NULL){
    nodeMap* toNextNode= currentNode -> next;
    delete currentNode;
    currentNode= toNextNode;
  }
nodeHead=NULL;
}
