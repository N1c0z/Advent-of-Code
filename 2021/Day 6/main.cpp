#include <iostream>
#include <inttypes.h>
#include <vector>
#include <iostream>
#include <string>
#include <inttypes.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> split(std::string str, char delimiter);


class Fish{
public:
    int currentInternalTimer;
};
    
std::vector<Fish> Fishes;
bool DoStuff(Fish *fish);

int main(int argc, const char * argv[]) {
    std::ifstream ifs;

    ifs.open("./../Inputs/06.txt", std::ifstream::in);
    std::string str ( (std::istreambuf_iterator<char>(ifs) ),(std::istreambuf_iterator<char>()));
    std::vector<std::string> FishTime = split(str, ',');
    
    for(std::string a : FishTime){
        Fish fish;
        fish.currentInternalTimer = stoi(a);
        Fishes.push_back(fish);
    }
    int amountOfDays = 80;
    uint64_t sizeOfFishes = 0;

    for (size_t i =0; i<amountOfDays; i++) {
        sizeOfFishes = Fishes.size();
        for (size_t k = 0; k<sizeOfFishes; k++) {
            if(DoStuff(&Fishes.at(k))){
                Fish newFish;
                newFish.currentInternalTimer = 8;
                Fishes.push_back(newFish);
            }
        }
    }
    for(auto& a : Fishes){
        std::cout << a.currentInternalTimer << std::endl;
    }
    std::cout << Fishes.size() << std::endl;
    return 0;
}

std::vector<std::string> split(std::string str, char delimiter) {
    std::vector<std::string> internal;
    std::stringstream ss(str);
    std::string tok;
    
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    
    return internal;
}
bool DoStuff(Fish *fish){
    if(fish->currentInternalTimer == 0){
        
        fish->currentInternalTimer = 6;
        return true;
    }
    fish->currentInternalTimer -= 1;
    return false;
}
