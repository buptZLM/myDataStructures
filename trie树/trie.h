//
// Created by lm on 19-2-28.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include <iostream>
#include <string>
#include <map>
using namespace std;
class trie{
private:
    class Node{
    public:
        bool isWorld;
        map<char,Node> next;
        Node(bool isWorld){
            this->isWorld=isWorld;
        }
        Node():isWorld(false),next(){}
    };
    Node* root;
    int size;
public:
    trie(){
        root=new Node();
        size = 0;
    }
    int getSize()const{return size;}
    void add(string world){
        Node * cur = root;
        for(int i=0;i<world.size();i++){
            char c = world.at(i);
            if(cur->next.find(c)==cur->next.end())
                cur->next.insert(pair<char,Node>(c,Node()));
            cur=&cur->next.find(c)->second;
        }
        if(!cur->isWorld){
            cur->isWorld=true;
            size++;
        }
    }
    bool contains(string world){
        Node* cur = root;
        for(int i=0;i<world.size();i++){
            char c=world.at(i);
            if(cur->next.find(c)==cur->next.end())
                return false;
            cur=&cur->next.find(c)->second;
        }
        return cur->isWorld;
    }
    //查询是否有以perfix为前缀的字符串
    bool isPerfix(string perfix){
        Node* cur=root;
        for(int i=0;i<perfix.size();i++){
            char c=perfix.at(i);
            if(cur->next.find(c)==cur->next.end())
                return false;
            cur=&cur->next.find(c)->second;
        }
        return true;
    }

};
#endif //TRIE_TRIE_H
