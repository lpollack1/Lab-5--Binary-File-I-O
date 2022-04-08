//
// Created by Lance Pollack on 3/6/22.
//
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class extrafile{
private:
    string name;
    string type;
    short length;
    int shield;
    float warp;
    vector<string> weapons;
    vector<int> power;
    vector<float> consumption;


public:
    extrafile(string name, string type, short length, int shield, float warp, vector<string> weapons, vector<int> power, vector<float> consumption);
    string getName();
    string getType();
    short getLength();
    int getShield();
    float getWarp();
    vector<string> getWeapons();
    vector<int> getPower();
    vector<float> getConsumption();

};
