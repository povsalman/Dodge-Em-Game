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
#include <iostream>
using namespace std;
using namespace sf;

////////////////////////////////////////////////////////////// PLAYER CLASS //////////////////////////////////////////////////////////////
class player {
public:
	
	Sprite Player;
	Texture pl_car;

	Font font;
	Text scoreText, livesText;

	int direction;
	float t, b, l, r;
	int path;
	int score = 0;
	float peed = 0.25;
	int lives = 400;


	
public:
	player() :direction(1) {
		pl_car.loadFromFile("img/playercar.png");
		Player.setTexture(pl_car);
		Player.rotate(90);
		Player.setPosition(270, 300);
		Player.setScale(0.1, 0.1);
		path = 4;
		t = 300;
		b = 490;
		l = 270;
		r = 510;

		if (!font.loadFromFile("fonts/Game Of Squids.ttf")) {
			cerr << "Error loading font!" << endl;
		}

		score = 0;
		scoreText.setFont(font);
		scoreText.setCharacterSize(30);
		scoreText.setFillColor(sf::Color::White);
		scoreText.setOutlineColor(sf::Color::Magenta);
		scoreText.setOutlineThickness(2);
		scoreText.setPosition(800, 292); 
		
		livesText.setFont(font);
		livesText.setCharacterSize(30);
		livesText.setFillColor(sf::Color::White);
		livesText.setOutlineColor(sf::Color::Magenta);
		livesText.setOutlineThickness(2);
		livesText.setPosition(800, 312);

	}

	void updateScore(int newScore) {
		score = newScore;
	}

	void renderScore(sf::RenderWindow& window) {
		scoreText.setString("Score: " + to_string(score));
		window.draw(scoreText);
	}

	string getScoreAsString() const {
		return to_string(score);
	}
	
	void updateLives(int newlives) {
		lives = newlives;
	}

	void renderLives(sf::RenderWindow& window) {
		livesText.setString("Lives: " + to_string(lives));
		window.draw(livesText);
	}

	string getLivesAsString() const {
		return to_string(lives);
	}

	void move(float x, float y) {
		Player.move(x, y);
	}

	void increasespeed() {
		peed *= 1.25;
	} 

	void updatelife() {
		lives--;
	}
	
	void setspeed(float tspeed) {
		peed = tspeed;
	}
	
	int getlife() {
		return lives;
	}
	
	

};
