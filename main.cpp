#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "extrafile.h"
using namespace std;
void getData(string fileName, vector<extrafile> &shipSet){
    // get count
    ifstream file(fileName, ios_base::binary);
    unsigned int count;
    file.read((char*)&count, 4);

    for (unsigned int i = 0; i < count; ++i) {

        // get name
        int length;
        file.read((char *) &length, 4);
        char *temp = new char[length];
        file.read(temp, length);
        string name = temp;
        delete[] temp;

        // get class type
        file.read((char *) &length, 4);
        temp = new char[length];
        file.read(temp, length);
        string type = temp;
        delete[] temp;

        // get ship length
        short shipLength;
        file.read((char *) &shipLength, 2);

        // get shield capacity
        int shield;
        file.read((char *) &shield, 4);

        // get max warp
        float warp;
        file.read((char *) &warp, 4);

        // get weapon count
        vector<string> weapons;
        vector<int> power;
        vector<float> consumption;
        int weaponCount;
        file.read((char*)&weaponCount, 4);

        for (int j = 0; j < weaponCount; ++j) {
            file.read((char *) &length, 4);
            char *temp = new char[length];
            file.read(temp, length);
            string str = temp;
            weapons.push_back(str);
            delete[] temp;

            int x;
            file.read((char *) &x, 4);
            power.push_back(x);

            float f;
            file.read((char*)&f, 4);
            consumption.push_back(f);

        }
        // add to ship set vector
        shipSet.push_back(extrafile(name, type, shipLength, shield, warp, weapons, power, consumption));
    }
}

void Display(vector<extrafile> set, int i) {
    cout << "Name: " << set.at(i).getName() << endl;
    cout << "Class: " << set.at(i).getType() << endl;
    cout << "Length: " << set.at(i).getLength() << endl;
    cout << "Shield capacity: " << set.at(i).getShield() << endl;
    cout << "Maximum Warp: " << set.at(i).getWarp() << endl;

    vector<string> w = set.at(i).getWeapons();
    vector<int> x = set.at(i).getPower();
    vector<float> f = set.at(i).getConsumption();
    int totalPower = 0;

    if (w.size() != 0) {
        cout << "Armaments: " << endl;
        for (unsigned int j = 0; j < w.size(); ++j) {
            cout << w.at(j) << ", " << x.at(j) << ", " << f.at(j) << endl;
            totalPower += x.at(j);
        }
        cout << "Total firepower: " << totalPower << endl;
    } else {
        cout << "Armaments: " << endl;
        cout << "Unarmed" << endl;
    }
    cout << endl;
}

int main() {
    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    vector<extrafile> set;

    if (option == 1) {
        const string fileName = "../friendlyships.shp";
        getData(fileName, set);
    } else if (option == 2) {
        const string fileName = "../enemyships.shp";
        getData(fileName, set);
    } else if (option == 3) {
        string fileName = "../friendlyships.shp";
        getData(fileName, set);
        fileName = "../enemyships.shp";
        getData(fileName, set);
    }
    /* Load files here */

    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;

    cin >> option;

    if (option == 1) {
        for (unsigned int i = 0; i < set.size(); ++i) {
            Display(set, i);
        }
    }
    else if (option == 2) {
        int maxPow = 0;
        int pos = 0;
        for (unsigned int i = 0; i < set.size(); ++i) {
            vector<int> p = set.at(i).getPower();

            for (unsigned int j = 0; j < p.size(); ++j) {
                if (p.at(j) > maxPow) {
                    maxPow = p.at(j);
                    pos = i;
                }
            }
        }
        Display(set, pos);
    }
    else if(option == 3){
        int maxPow = 0;
        int pos = 0;
        for (unsigned int i = 0; i < set.size(); ++i) {
            vector<int> p = set.at(i).getPower();
            int totalPow = 0;

            for (unsigned int j = 0; j < p.size(); ++j) {
                totalPow += p.at(j);
            }
            if (totalPow > maxPow) {
                maxPow = totalPow;
                pos = i;
            }
        }
        Display(set, pos);
    }
    else if(option == 4){
        int minPow = 100000;
        int pos = 0;
        for (unsigned int i = 0; i < set.size(); ++i) {
            vector<int> p = set.at(i).getPower();
            int totalPow = 0;

            if (p.size() != 0) {
                for (unsigned int j = 0; j < p.size(); ++j) {
                    totalPow += p.at(j);
                }
                if (totalPow < minPow) {
                    minPow = totalPow;
                    pos = i;
                }
            }
        }
        Display(set, pos);
    }
    else if(option == 5){
        for (unsigned int i = 0; i < set.size(); ++i) {
            vector<string> w = set.at(i).getWeapons();
            if(w.size() == 0){
                Display(set, i);
            }
        }
    }
    return 0;
}
