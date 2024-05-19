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
using namespace std;

//polymorphism via abstract class
class Food {
public:

    Texture* texture;
    Sprite sprite;

    virtual void render(sf::RenderWindow& window) const = 0;
    virtual int getScore() const = 0;
    virtual void applyPowerUp(bool&) const = 0;
    bool active = 1;
};

//White Food(makes enemy disappear for 10 seconds)
class Pizza : public Food {
public:
   
    Pizza() {}

    Pizza(float x, float y) {
        texture = new Texture;
        (*texture).loadFromFile("img/pizzafood.png");
        sprite.setTexture(*texture);
        sprite.setPosition(x, y);
        sprite.setScale(0.25, 0.25);
    }

    void render(sf::RenderWindow& window) const override {
        window.draw(sprite);
    }

    int getScore() const override {
        return 5;
    }

    void applyPowerUp(bool& disabled) const override {
        disabled = 1;
    }
};

//Green Food (+life and +20 points)
class Donut : public Food {

public:
    Donut(){}

    Donut(float x, float y) {
        texture = new Texture;
        (*texture).loadFromFile("img/donutfood.png");
        sprite.setTexture(*texture);
        sprite.setPosition(x, y);
        sprite.setScale(0.10, 0.10);
    }

    void render(sf::RenderWindow& window) const override {
        window.draw(sprite);
    }

    int getScore() const override {
        return 20;
    }

    void applyPowerUp(bool& addslife) const override {
        //addslife = 1;
        // adds 1 life
    }
};

//Red food (+10)
class Meat : public Food {

public:
    Meat() {}
    Meat(float x, float y) {
        texture = new Texture;
        (*texture).loadFromFile("img/meatfood.png");
        sprite.setTexture(*texture);
        sprite.setPosition(x, y);
        sprite.setScale(0.3, 0.3);
    }

    void render(sf::RenderWindow& window) const override {
        window.draw(sprite);
    }

    int getScore() const override {
        return 10;
    }

    void applyPowerUp(bool&) const override {
    }
};

//Orange Food(+10 and 1.5x boost for next 10 seconds)
class Sandwich : public Food {


public:
    Sandwich() {}
    Sandwich(float x, float y) {
        texture = new Texture;
        (*texture).loadFromFile("img/sandwichfood.png");
        sprite.setTexture(*texture);
        sprite.setPosition(x, y);
        sprite.setScale(0.25, 0.25);
    }

    void render(sf::RenderWindow& window) const override {
        window.draw(sprite);
    }

    int getScore() const override {
        return 10;
    }

    void applyPowerUp(bool& speed) const override {
        //speed = 1;
    }
};


