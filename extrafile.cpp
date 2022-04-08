//
// Created by Lance Pollack on 3/6/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "extrafile.h"
using namespace std;
extrafile::extrafile(string name, string type, short length, int shield, float warp, vector<string> weapons, vector<int> power, vector<float> consumption){
    this->name = name;
    this->type = type;
    this->length = length;
    this->shield = shield;
    this->warp = warp;
    this->weapons = weapons;
    this->power = power;
    this->consumption = consumption;
}
string extrafile::getName(){
    return name;
}
string extrafile::getType(){
    return type;
}
short extrafile::getLength(){
    return length;
}
int extrafile::getShield(){
    return shield;
}
float extrafile::getWarp(){
    return warp;
}

vector<string> extrafile::getWeapons(){
    return weapons;
}
vector<int> extrafile::getPower(){
    return power;
}
vector<float> extrafile::getConsumption(){
    return consumption;
}
