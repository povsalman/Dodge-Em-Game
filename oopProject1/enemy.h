/*

Group: 2
Name: Salman Khan       22I-1285
      Arshiq Rehman     22I-1023

OOP Section - A

*/



#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <time.h>
#include "game.h"
#include <iostream>
using namespace sf;
using namespace std;
class Enemy
{
public:
    Sprite Ecar;
    Texture bol_texture;
    int direction; // Direction of movement for the box
    int Ydirect;
    bool disabled = 0;
    bool collided = 0;
    float espeed = 0.5;

    float time = 0.0;

    // Default constructor
    Enemy()
        : direction(0), Ydirect(1) // Set a default direction (you can adjust as needed)
    {
        bol_texture.loadFromFile("img/PolsCar2.png");
        Ecar.setTexture(bol_texture);
        Ecar.setPosition(500, 80);
        Ecar.setScale(0.1, 0.1);
    }

    

    void move(float x, float y) {
        Ecar.move(x, y);
    }

    void increasespeed(float speed) {
        espeed *= speed;
    }


};