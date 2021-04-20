#include "lands.h"

using namespace std;

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case OCEAN:
            return new Ocean;
            break;
        case JUNGLE:
            return new Jungle;
            break;
        case CITY: 
            return new City;
            break;
        case MILITARYBASE:
            return new MilitaryBase;
            break;
        case WARZONE:
            return new WarZone;
            break;
        default:
            return new Lake;
            break;
    }
    
}

string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}

string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    
    p.setThirst(p.getThirst() - 1);

    return description;
}

// My code start here 

string Ocean::getShortDescription(){
    
    return "Ocean";
}

string Ocean::getLongDescription(){
    return "You are in a deepest Ocean";
}

string Ocean::visit(Player& p){
    
    string description = "you have been swimming for long time, now you are sick and hungry";
    int chance = rand() % 100;
    
    if (chance > 50){
        description =  "you found a ship that can help you";
        p.setHealth(p.getHealth() + 1);
        p.setHunger(p.getHunger() + 1);
    }
    
    if (chance < 10 && chance > 5){
        description =  "you are under attack from pirates";
        p.setHealth(p.getHealth() - 1);
    }
    
    if (chance < 5){
        description =  "you are under shark's attack";
        int newhealth = (int)p.getHealth() - 2;
        newhealth = newhealth < 0 ? 0 : newhealth;
    }

    return description;
}

//////////////////
 string Jungle::getShortDescription(){
    
    return "Jungle";
}

string Jungle::getLongDescription(){
    return "You are in a Wild Jungle";
}

string Jungle::visit(Player& p){
    string description = "Noise in the jungle makes you scared";
    
    int chance = rand() % 100;
    
    if (chance > 50){
        description = "You found a cottage that help you to rest, eat, and drink";
        p.setHealth(p.getHealth() + 1);
        p.setHunger(p.getHunger() + 1);
        p.setThirst(p.getThirst() + 1);
    }
    
    if (chance < 10 && chance > 5 ){
        description = "You are under tiger's attack";
        p.setHealth(p.getHealth() - 1);
    }
    
    if (chance < 5){
        description = "You are under attack from a Dinosaur";
        int new_health = (int)p.getHealth() - 2;
        new_health = new_health < 0? 0: new_health;
    }

    return description;
}

////////////////////////////

 string City::getShortDescription(){
    
    return "City";
}

string City::getLongDescription(){
    return "You are in a crime city";
}

string City::visit(Player& p){
    string description = "The City is running crazy";
    int chance = rand() % 100;
    
    if (chance > 50){
        description = "Great you are at the house has a doctore and good food";
        p.setHealth(p.getHealth() + 1);
        p.setHunger(p.getHunger() + 1);
    }
    
    if (chance < 10 && chance > 5){
        description = "Bad people shooting at you";
        p.setHealth (p.getHealth()- 1);
    }
    
    if (chance < 5){
        description = "Mafia's sniper shooting you ";
        int newhealth = (int)p.getHealth() - 2;
        newhealth = newhealth < 0 ? 0 : newhealth;
    }

    return description;
}

////////////////////////////

 string MilitaryBase::getShortDescription(){
    
    return "MilitaryBase";
}

string MilitaryBase::getLongDescription(){
    return "You are in a dangerous MilitaryBase";
}

string MilitaryBase::visit(Player& p){
    string description = "you are in safe place, do not go out";
    int chance = rand() % 100;
    
    if (chance > 50){
        description = "Great, there is no attack on the base, you can eat, drink and have enough sleep";
        p.setHealth(p.getHealth() + 1);
        p.setHunger(p.getHunger() + 1);
        p.setThirst(p.getThirst() + 1);
    }
    
    if (chance < 10 && chance > 5){
        description = "enemy trying to attack the base";
        p.setHealth (p.getHealth() - 1);
    }
    
    if (chance < 5){
        description = "massive attack";
        int newhealth = (int)p.getHealth() - 2;
        newhealth = newhealth < 0 ? 0 : newhealth;
    }   
    return description;
}

////////////////////////////

 string WarZone::getShortDescription(){
    
    return "WarZone";
}

string WarZone::getLongDescription(){
    return "You are in a WarZone, be careful";
}

string WarZone::visit(Player& p){
    string description = "war is so bad here and there are a lot of died bodies everywhere";
    int chance = rand() % 100;
    
    if (chance > 50){
        description = "Great, war is temperary on hold";
        p.setHealth(p.getHealth() + 1);
        p.setHunger(p.getHunger() + 1);
        p.setThirst(p.getThirst() + 1);
    }
    
    if (chance < 10 && chance > 5){
        description = "war started again";
        p.setHealth (p.getHealth() - 1);
    }
    
    if (chance < 5){
        description = "Anti perosnnal mine everywhere";
        int newhealth = (int)p.getHealth() - 2;
        newhealth = newhealth < 0 ? 0 : newhealth;
    }      

    return description;
}

////////////////////////////
