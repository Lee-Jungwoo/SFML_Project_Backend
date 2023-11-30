#ifndef PLANT_H
#define PLANT_H
#include <map>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "PlantResource.h"

#define PLANT_LEVEL 4



class Plant
{
private:
    int elapsedDay;
    int level;
    int waterPercentage;
    int soilPercentage;
    PlantSpecies species;
    int bloomingDay;
    sf::Texture plantTexture[PLANT_LEVEL];
    sf::Sprite sprite;

public:
    Plant(PlantSpecies);
    ~Plant();

    void fillWater();
    void fillEnergy();
    
    sf::Sprite getSprite();    

    bool isDead();
    bool isBlooming();
    void draw(sf::RenderTarget & target);

};



class PlantSlot
{
private:
    Plant *plant;
    bool isEmpty();
    sf::Sprite sprite;
public:
    PlantSlot();

    void pushPlant(Plant *p);
    void pullPlant();

    void draw(sf::RenderTarget &target);
};

#endif 