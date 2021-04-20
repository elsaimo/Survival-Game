#ifndef LANDS_H
#define LANDS_H

#include <string>
#include <stdlib.h>
#include "player.h"

using namespace std;

enum LandTypes {LAKE, FOREST, DESERT, 
                OCEAN,JUNGLE,CITY,MILITARYBASE,WARZONE,
                MAX_NUM_LANDS};

class Land {
    public:
    virtual string getShortDescription() = 0;
    virtual string getLongDescription() = 0;
    virtual string visit(Player &p) = 0;
    
    private:
};

class Lake : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class Forest : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class Desert : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

//start my code 
class Ocean : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class Jungle  : public Land{
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
}; 

class City  : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class MilitaryBase : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
}; 


class WarZone : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
    
};

// ended my code 

Land* getRandomLand(void);


#endif

