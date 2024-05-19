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
#include "player.h"
#include "highscore.h"
#include "food.h"
#include "player.h"
#include "enemy.h"

const char title[] = "Best Atari Game";
using namespace sf;
using namespace std;

class Game
{

private:
    Food** foods;           //polymorphism via abstract class

public:

    Sprite gameover_sprite, background_sprite, pause_sprite, main_sprite, instruct_sprite, highscore_sprite, exit_sprite, previousbutton_sprite, musicbutton_sprite;
    Texture gameover_text, background_text,pause_text, main_text, instruct_text, highscore_text, exit_text, previousbutton_text, musicbutton_text;

    Font font;
    Text isname, highscoreText, scoredisplay, livesdisplay;

    Music Theme;

    int direction = 1; // Variable to store the direction of movement
    bool gameover = 0;  //1 for highscore 

    bool instructions = 0, start = 1, exit = 0, highscorebool = 0, paused = 0;
    int music = 0;

    highscore* h = new highscore;
    string userName;

    ///
    Sprite background; // Game background sprite
    Texture bg_texture;
    Enemy *PolsCar;
    player Slayer;
    int Ydirect = 0;
    ///////////////////////////////////ADD FOLLOWING FOR PLAYER MOVEMENT /////////////////////////
    bool isKeyPressed_Up = false;
    bool isKeyPressed_Down = false;
    bool isKeyPressed_Right = false;
    bool isKeyPressed_Left = false;

    int path = 1;

    const int DirectionLeft = 1;
    const int DirectionDown = 2;
    const int DirectionRight = 3;
    const int DirectionUp = 4;
    ///

    int numofenemies = 1;
    int level = 1;


    Game()
    {

        foods = new Food * [120];
        const int MAX_FOOD_ITEMS = 30;

        PolsCar = new Enemy;


        /*Theme.openFromFile("music/Snail's World.ogg");
        Theme.play();
        Theme.setLoop(true);*/

        background_text.loadFromFile("img/mapempty.png");
        background_sprite.setTexture(background_text);
        background_sprite.setScale(1, 1.75);
        background_sprite.setPosition(0, -295);

        gameover_text.loadFromFile("img/gameovermenu.jpg");
        gameover_sprite.setTexture(gameover_text);
        gameover_sprite.setPosition(0, -20);

        main_text.loadFromFile("img/mainmenu.jpg");
        main_sprite.setTexture(main_text);
        main_sprite.setPosition(0, -20);

        instruct_text.loadFromFile("img/instructionsmenu.jpg");
        instruct_sprite.setTexture(instruct_text);
        instruct_sprite.setPosition(0, -20);

        highscore_text.loadFromFile("img/highscoresmenu.jpg");
        highscore_sprite.setTexture(highscore_text);
        highscore_sprite.setPosition(0, -20);

        exit_text.loadFromFile("img/endmenu.jpg");
        exit_sprite.setTexture(exit_text);
        exit_sprite.setPosition(0, -20);

        pause_text.loadFromFile("img/pausemenu.jpg");
        pause_sprite.setTexture(pause_text);
        pause_sprite.setPosition(0, -20);

        previousbutton_text.loadFromFile("img/previousbutton.png");
        previousbutton_sprite.setTexture(previousbutton_text);
        previousbutton_sprite.setPosition(20, 15);
        previousbutton_sprite.setScale(0.10, 0.10);

        musicbutton_text.loadFromFile("img/musicbutton.png");
        musicbutton_sprite.setTexture(musicbutton_text);
        musicbutton_sprite.setPosition(685, -5);
        musicbutton_sprite.setScale(0.3, 0.3);

        font.loadFromFile("fonts/Game Of Squids.ttf");  
        isname.setFont(font);  
        isname.setCharacterSize(30);  
        isname.setPosition(245, 220);  
        isname.setFillColor(sf::Color::White);  
        isname.setOutlineColor(sf::Color::Magenta);  
        isname.setOutlineThickness(2);  

        highscoreText.setFont(font);
        highscoreText.setCharacterSize(30);
        highscoreText.setPosition(216, 292);
        highscoreText.setFillColor(sf::Color::White);
        highscoreText.setOutlineColor(sf::Color::Magenta);
        highscoreText.setOutlineThickness(2);

        FoodGenerate();

    }
   
    void loadHighscores() {

        ifstream highscoreFile("high.txt");
        string line;

        highscoreText.setString(""); // Clear previous highscores

        while (getline(highscoreFile, line)) {
            highscoreText.setString(highscoreText.getString() + line + "\n");
        }

        highscoreFile.close();
    }

    void start_game(string name)
    {
        srand(time(0));
        RenderWindow window(VideoMode(1080, 780), title);
        Clock clock;
        float timer = 0;

        int xbutton = 0;
        int ybutton = 0;
        int mouseclicked;

        userName = name;

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game 

                else if (e.type == Event::MouseButtonPressed) {

                    if (e.mouseButton.button == sf::Mouse::Left)
                    {
                        xbutton = e.mouseButton.x;						//to get x y coordinates of cursor
                        ybutton = e.mouseButton.y;
                        cout << "Now\n x is: " << xbutton << endl << " y is: " << ybutton << endl << endl;
                        cout << music << endl;
                        mouseclicked = 1;

                        if (xbutton >= 34 && xbutton <= 81 && ybutton >= 36 && ybutton <= 79) {                  //is previous button
                            start = 1;
                            instructions = 0;
                            highscorebool = 0;
                            exit = 0;
                        }

                        if (xbutton >= 693 && xbutton <= 739 && ybutton >= 25 && ybutton <= 76 && mouseclicked == 1) {                  //is music button
                            if (music <= 2) {
                                music++;
                            }
                            else
                                music = 0;

                            switch (music) {
                            case 0:
                                Theme.openFromFile("music/Rasputin.ogg");
                                Theme.play();
                                Theme.setLoop(true);
                                break;
                            case 1:
                                Theme.openFromFile("music/Snail's World.ogg");
                                Theme.play();
                                Theme.setLoop(true);
                                break;
                            case 2:
                                Theme.openFromFile("music/Tokyo drift.ogg");
                                Theme.play();
                                Theme.setLoop(true);
                                break;
                            case 3:
                                Theme.openFromFile("music/Max Verstappen Song.ogg");
                                Theme.play();
                                Theme.setLoop(true);
                                break;
                            }
                            mouseclicked = 0;
                            xbutton = 0;
                            ybutton = 0;

                        }
                    }
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::P)) // If down key is pressed
            {
                highscorebool = 0;
                instructions = 0;
                start = 0;
                exit = 0;
                paused = 1;
            }
            if (Keyboard::isKeyPressed(Keyboard::G)) // If down key is pressed
            {
                gameover = 1;
            }

            if (start) {
                //Making a selection based on the reading
                if (xbutton >= 230 && xbutton <= 551 && ybutton >= 307 && ybutton <= 386) {                  //is start
                    start = 1;
                    instructions = 0;
                    highscorebool = 0;
                    exit = 0;
                }

                if (xbutton >= 230 && xbutton <= 551 && ybutton >= 426 && ybutton <= 505) {                  //is highscore
                    highscorebool = 1;
                    instructions = 0;
                    start = 0;
                    exit = 0;
                }


                if (xbutton >= 230 && xbutton <= 551 && ybutton >= 547 && ybutton <= 626) {                  //is help
                    instructions = 1;
                    highscorebool = 0;
                    start = 0;
                    exit = 0;
                }


                if (xbutton >= 230 && xbutton <= 551 && ybutton >= 664 && ybutton <= 738) {         //is exit
                    if (timer > 2.0f) {  // Adjust the delay time as needed
                        window.draw(exit_sprite);
                        window.draw(previousbutton_sprite);
                        window.draw(musicbutton_sprite);

                        // Display user name

                        isname.setPosition(200, 450);
                        isname.setCharacterSize(23);
                        isname.setString("I will miss you, " + userName + "!");
                        window.draw(isname);
                        window.display();
                        h->adding(userName, Slayer.getScoreAsString());
                        sf::sleep(sf::seconds(2.0f));  // Adjust the delay time as needed
                        window.close();
                    }
                }

            }

            
            if (PolsCar->disabled == true) {
                PolsCar->time += time;
                if (PolsCar->time >= 10) {
                    PolsCar->disabled = false;
                    PolsCar->time = 0;

                }
            }


            window.clear(Color::Black); //clears the screen

            foodsReceived();

            if (Slayer.getlife() <= 0) {
                paused = 1;
            }

            if (start) {
                window.draw(background_sprite);  // setting background
                window.draw(previousbutton_sprite);
                window.draw(musicbutton_sprite);
                Slayer.renderScore(window);
                Slayer.renderLives(window);

                renderFoods(window);
            }
            if(paused) {
                window.draw(pause_sprite);
                window.draw(previousbutton_sprite);
                window.draw(musicbutton_sprite);
            }
            if (instructions) {
                window.draw(instruct_sprite);
                window.draw(previousbutton_sprite);
                window.draw(musicbutton_sprite);
            }
            if (highscorebool) {
                loadHighscores(); // Load highscores from file
                window.draw(highscore_sprite);
                window.draw(previousbutton_sprite);
                window.draw(musicbutton_sprite);
                window.draw(highscoreText);
            }
           

            if (start) {

        ///////GamePlay//////
                
        /////////////////////////////////////////////ENEMY DIRECTION CHANGE ///////////////////////////
                switch (path) {
                case 1: {
                    if ((PolsCar->Ecar.getPosition().x <= 50) && (PolsCar->Ecar.getPosition().y == 80)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(60, 150);
                        direction = DirectionDown;
                    }
                    if ((PolsCar->Ecar.getPosition().x == 60) && (PolsCar->Ecar.getPosition().y >= 700)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(140, 690);
                        direction = DirectionRight;
                    }
                    if ((PolsCar->Ecar.getPosition().x >= 730) && (PolsCar->Ecar.getPosition().y == 690)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(730, 590);
                        direction = DirectionUp;
                    }
                    if ((PolsCar->Ecar.getPosition().x == 730) && (PolsCar->Ecar.getPosition().y <= 80)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(650, 80);
                        direction = DirectionLeft;
                    }
                    break;
                }
                case 2: {
                    ///////////////////////////////////////////// 2nd Path Direction /////////////////////////////////////
                    if ((PolsCar->Ecar.getPosition().x <= 110) && (PolsCar->Ecar.getPosition().y == 160)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(130, 250);
                        direction = DirectionDown;
                    }
                    if ((PolsCar->Ecar.getPosition().x == 130) && (PolsCar->Ecar.getPosition().y >= 650)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(210, 620);
                        direction = DirectionRight;
                    }
                    if ((PolsCar->Ecar.getPosition().x >= 670) && (PolsCar->Ecar.getPosition().y == 620)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(650, 530);
                        direction = DirectionUp;
                    }
                    if ((PolsCar->Ecar.getPosition().x == 650) && (PolsCar->Ecar.getPosition().y <= 160)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(570, 160);
                        direction = DirectionLeft;
                    }
                    break;
                }
                case 3: {
                    /////////////////////////////////////////////// 3rd Path Direction /////////////////////////////////////
                    if ((PolsCar->Ecar.getPosition().x <= 190) && (PolsCar->Ecar.getPosition().y == 230)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(200, 300);
                        direction = DirectionDown;
                    }
                    if ((PolsCar->Ecar.getPosition().x == 200) && (PolsCar->Ecar.getPosition().y >= 570)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(300, 550);
                        direction = DirectionRight;
                    }
                    if ((PolsCar->Ecar.getPosition().x >= 520) && (PolsCar->Ecar.getPosition().y == 550)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(580, 480);
                        direction = DirectionUp;
                    }
                    if ((PolsCar->Ecar.getPosition().x == 580) && (PolsCar->Ecar.getPosition().y <= 230)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(520, 230);
                        direction = DirectionLeft;
                    }
                    break;
                }
                case 4: {
                    /////////////////////////////////////////////// 4th Path Direction /////////////////////////////////////
                    if ((PolsCar->Ecar.getPosition().x <= 260) && (PolsCar->Ecar.getPosition().y == 300)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(270, 370);
                        direction = DirectionDown;
                    }
                    if ((PolsCar->Ecar.getPosition().x == 270) && (PolsCar->Ecar.getPosition().y >= 500)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(350, 480);
                        direction = DirectionRight;
                    }
                    if ((PolsCar->Ecar.getPosition().x >= 520) && (PolsCar->Ecar.getPosition().y == 480)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(510, 400);
                        direction = DirectionUp;
                    }
                    if ((PolsCar->Ecar.getPosition().x == 510) && (PolsCar->Ecar.getPosition().y <= 300)) {
                        PolsCar->Ecar.rotate(270);
                        PolsCar->Ecar.setPosition(440, 300);
                        direction = DirectionLeft;
                    }
                    break;
                }
                }
                //////////////////////////////////////////////////// ENEMY MOVEMENT //////////////////////////////////////////

                if (direction == DirectionLeft) {
                    PolsCar->move(-PolsCar->espeed, 0);
                }
                else if (direction == DirectionDown) {
                    PolsCar->move(0, PolsCar->espeed);
                }
                else if (direction == DirectionRight) {
                    PolsCar->move(PolsCar->espeed, 0);

                }
                else if (direction == DirectionUp) {
                    PolsCar->move(0, -PolsCar->espeed);
                }

                //************************************************************************


                //////////////////////////////////////////// PLAYER CHECKS ////////////////////////////////////////////////

                if ((Slayer.Player.getPosition().x != Slayer.r) && (Slayer.Player.getPosition().y == Slayer.t)) {
                    Slayer.move(Slayer.peed, 0);
                }
                if (Slayer.Player.getPosition().x == Slayer.r && Slayer.Player.getPosition().y == Slayer.t)
                    Slayer.Player.rotate(90);

                if ((Slayer.Player.getPosition().x == Slayer.r) && (Slayer.Player.getPosition().y != Slayer.b)) {
                    Slayer.move(0, Slayer.peed);
                }
                if (Slayer.Player.getPosition().x == Slayer.r && Slayer.Player.getPosition().y == Slayer.b)
                    Slayer.Player.rotate(90);

                if ((Slayer.Player.getPosition().x != Slayer.l) && (Slayer.Player.getPosition().y == Slayer.b)) {

                    Slayer.move(-Slayer.peed, 0);
                }
                if (Slayer.Player.getPosition().x == Slayer.l && Slayer.Player.getPosition().y == Slayer.b)
                    Slayer.Player.rotate(90);

                if ((Slayer.Player.getPosition().x == Slayer.l) && (Slayer.Player.getPosition().y != Slayer.t)) {

                    Slayer.move(0, -Slayer.peed);
                }

                if (Slayer.Player.getPosition().x == Slayer.l && Slayer.Player.getPosition().y == Slayer.t)
                    Slayer.Player.rotate(90);

                ///////////////////////////////////////// UPPER RANGE CHECK ////////////////////////////////////////////////
                if ((Slayer.Player.getPosition().x >= 400) && (Slayer.Player.getPosition().x <= 500) &&
                    (Slayer.Player.getPosition().y == Slayer.t)) {

                    if (Keyboard::isKeyPressed(Keyboard::Down) && !isKeyPressed_Down) {
                        isKeyPressed_Down = true;
                        isKeyPressed_Up = false;

                        // Your existing code for handling Down key press
                        if (Slayer.path != 4) {
                            Slayer.path += 1;
                            Slayer.t += 70;
                            Slayer.b -= 70;
                            Slayer.l += 70;
                            Slayer.r -= 70;
                            Slayer.Player.setPosition(450, Slayer.t);
                        }
                    }
                    else if (!Keyboard::isKeyPressed(Keyboard::Down)) {
                        isKeyPressed_Down = false;
                    }

                    if (Keyboard::isKeyPressed(Keyboard::Up) && !isKeyPressed_Up) {
                        isKeyPressed_Up = true;
                        isKeyPressed_Down = false;

                        // Your existing code for handling Up key press
                        if (Slayer.path != 1) {
                            Slayer.path -= 1;
                            Slayer.t -= 70;
                            Slayer.b += 70;
                            Slayer.l -= 70;
                            Slayer.r += 70;
                            Slayer.Player.setPosition(450, Slayer.t);
                        }
                    }
                    else if (!Keyboard::isKeyPressed(Keyboard::Up)) {
                        isKeyPressed_Up = false;
                    }
                }

                ////////////////////////////////////////////////// LEFT RANGE CHECK ////////////////////////////////////////////
                if ((Slayer.Player.getPosition().y >= 300) && (Slayer.Player.getPosition().y <= 400) &&
                    (Slayer.Player.getPosition().x == Slayer.l)) {

                    if (Keyboard::isKeyPressed(Keyboard::Right) && !isKeyPressed_Right) {
                        isKeyPressed_Right = true;
                        isKeyPressed_Left = false;

                        if (Slayer.path != 4) {
                            Slayer.path += 1;
                            Slayer.t += 70;
                            Slayer.b -= 70;
                            Slayer.l += 70;
                            Slayer.r -= 70;
                            Slayer.Player.setPosition(Slayer.l, 350);
                        }
                    }
                    else if (!Keyboard::isKeyPressed(Keyboard::Right)) {
                        isKeyPressed_Right = false;
                    }

                    if (Keyboard::isKeyPressed(Keyboard::Left) && !isKeyPressed_Left) {
                        isKeyPressed_Left = true;
                        isKeyPressed_Right = false;

                        if (Slayer.path != 1) {
                            Slayer.path -= 1;
                            Slayer.t -= 70;
                            Slayer.b += 70;
                            Slayer.l -= 70;
                            Slayer.r += 70;
                            Slayer.Player.setPosition(Slayer.l, 350);
                        }
                    }
                    else if (!Keyboard::isKeyPressed(Keyboard::Left)) {
                        isKeyPressed_Left = false;
                    }
                }

                ///////////////////////////////////////////////// RIGHT RANGE CHECK //////////////////////////////////////////
                if ((Slayer.Player.getPosition().y >= 400) && (Slayer.Player.getPosition().y <= 500) &&
                    (Slayer.Player.getPosition().x == Slayer.r)) {

                    if (Keyboard::isKeyPressed(Keyboard::Left) && !isKeyPressed_Right) {
                        isKeyPressed_Right = true;
                        isKeyPressed_Left = false;

                        if (Slayer.path != 4) {
                            Slayer.path += 1;
                            Slayer.t += 70;
                            Slayer.b -= 70;
                            Slayer.l += 70;
                            Slayer.r -= 70;
                            Slayer.Player.setPosition(Slayer.r, 450);
                        }
                    }
                    else if (!Keyboard::isKeyPressed(Keyboard::Left)) {
                        isKeyPressed_Right = false;
                    }

                    if (Keyboard::isKeyPressed(Keyboard::Right) && !isKeyPressed_Left) {
                        isKeyPressed_Left = true;
                        isKeyPressed_Right = false;

                        if (Slayer.path != 1) {
                            Slayer.path -= 1;
                            Slayer.t -= 70;
                            Slayer.b += 70;
                            Slayer.l -= 70;
                            Slayer.r += 70;
                            Slayer.Player.setPosition(Slayer.r, 450);
                        }
                    }
                    else if (!Keyboard::isKeyPressed(Keyboard::Right)) {
                        isKeyPressed_Left = false;
                    }
                }
                ///////////////////////////////////////////// LOWER RANGE CHECK/////////////////////////////////////////
                if ((Slayer.Player.getPosition().x >= 300) && (Slayer.Player.getPosition().x <= 400) &&
                    (Slayer.Player.getPosition().y == Slayer.b)) {

                    if (Keyboard::isKeyPressed(Keyboard::Down) && !isKeyPressed_Down) {
                        isKeyPressed_Down = true;
                        isKeyPressed_Up = false;

                        if (Slayer.path != 1) {
                            Slayer.path -= 1;
                            Slayer.t -= 70;
                            Slayer.b += 70;
                            Slayer.l -= 70;
                            Slayer.r += 70;
                            Slayer.Player.setPosition(350, Slayer.b);
                        }
                    }
                    else if (!Keyboard::isKeyPressed(Keyboard::Down)) {
                        isKeyPressed_Down = false;
                    }

                    if (Keyboard::isKeyPressed(Keyboard::Up) && !isKeyPressed_Up) {
                        isKeyPressed_Up = true;
                        isKeyPressed_Down = false;


                        if (Slayer.path != 4) {
                            Slayer.path += 1;
                            Slayer.t += 70;
                            Slayer.b -= 70;
                            Slayer.l += 70;
                            Slayer.r -= 70;
                            Slayer.Player.setPosition(350, Slayer.b);
                        }

                    }
                    else if (!Keyboard::isKeyPressed(Keyboard::Up)) {
                        isKeyPressed_Up = false;
                    }
                }


                //*************************************************************************
               
                
                if (!PolsCar->disabled ) {
                    window.draw(PolsCar->Ecar);
                        
                }
                window.draw(Slayer.Player);

                FloatRect globalBounds = PolsCar->Ecar.getGlobalBounds();
                if (globalBounds.intersects(Slayer.Player.getGlobalBounds())) {
                    PolsCar->collided = true;
                    
                }
                if (PolsCar->collided == true) {
                    Slayer.updatelife();
                    PolsCar->collided = false;
                }

                ///////GamePlay//////



            }

            window.display();  //Displying all the sprites

        }


    }

    void renderFoods(sf::RenderWindow& window) const {
        for (int i = 0; i < 120; i++) {
            if (foods[i]->active == 1) {
                foods[i]->render(window);
            }
        }

    }

    void foodsReceived() {
        for (int i = 0; i < 120; i++) {

            if (foods[i]->active) {
                if (Slayer.Player.getGlobalBounds().intersects(foods[i]->sprite.getGlobalBounds())) {
                    Slayer.score += foods[i]->getScore();
                    Slayer.updateScore(Slayer.score);
                    foods[i]->applyPowerUp(PolsCar->disabled);
                    foods[i]->active = 0;
                    if (allfoodsdisabled()) {
                        for (int i = 0; i < 120; i++) {
                            delete foods[i];
                        }
                        FoodGenerate();     //for next level
                        level++;
                        cout << level << endl;
                        if (level == 2) {
                            (*PolsCar).increasespeed(0.5);
                        }
                        if (level == 3) {
                            (*PolsCar).increasespeed(1.5);
                        } 
                        if (level == 4) {
                            (*PolsCar).increasespeed(3.5);
                        }
                       
                    }
                    
                }
               
            }

        }
    }

    bool allfoodsdisabled() {
        
        for (int i = 0; i < 120; i++) {

            if (foods[i]->active == true) {
                return 0;
            }

        }
        
        return 1;
    }

    void FoodGenerate() {

        const int MAX_FOOD_ITEMS = 30;

        int indices[MAX_FOOD_ITEMS];
        for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
            indices[i] = i;
        }

        //// Shuffle indices manually
        //for (int i = MAX_FOOD_ITEMS - 1; i > 0; --i) {
        //    int j = rand() % (i + 1);

        //    // Manual swap
        //    int temp = indices[i];
        //    indices[i] = indices[j];
        //    indices[j] = temp;
        //}

        //pizza
        int index = 0;
        for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
            int side = indices[i] / 8; // Determine which side to spawn the food (0: top, 1: right, 2: bottom, 3: left)
            int x, y;

            switch (side) {
            case 0: // Top side
                x = 70 + 87 * (indices[i] % 8); // Equally spaced X along the top side
                y = 102;
                break;
            case 1: // Right side
                x = 692;
                y = 180 + 80 * (indices[i] % 6); // Equally spaced Y along the right side
                break;
            case 2: // Bottom side
                x = 82 + 87 * (indices[i] % 8); // Equally spaced X along the bottom side
                y = 660;
                break;
            case 3: // Left side
                x = 68;
                y = 180 + 80 * (indices[i] % 6); // Equally spaced Y along the left side
                break;
            }

            foods[index] = new Pizza(x, y);
            index++;
        }

        //donuts
        int smallerIndices[MAX_FOOD_ITEMS];
        for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
            smallerIndices[i] = i;
        }

        for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
            int side = smallerIndices[i] / 8; // Determine which side to spawn the food (0: top, 1: right, 2: bottom, 3: left)
            int x, y;

            switch (side) {
            case 0: // Top side
                x = 140 + 78 * (smallerIndices[i] % 7); // Equally spaced X along the top side
                y = 165;
                break;
            case 1: // Right side
                x = 613;
                y = 251 + 69 * (smallerIndices[i] % 5); // Equally spaced Y along the right side
                break;
            case 2: // Bottom side
                x = 140 + 78 * (smallerIndices[i] % 7); // Equally spaced X along the bottom side
                y = 585;
                break;
            case 3: // Left side
                x = 130;
                y = 251 + 69 * (smallerIndices[i] % 5); // Equally spaced Y along the left side
                break;
            }
            foods[index] = new Donut(x, y);
            index++;
        }

        //meats
        int smaller3Indices[MAX_FOOD_ITEMS];
        for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
            smaller3Indices[i] = i;
        }

        for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
            int side = indices[i] / 5; // Determine which side to spawn the food
            int x, y;

            switch (side) {
            case 0: // Top side
                x = 205 + 83 * (indices[i] % 5); // Equally spaced X along the top side
                y = 240;
                break;
            case 1: // Right side
                x = 540;
                y = 321 + 90 * (indices[i] % 2); // Equally spaced Y along the right side
                break;
            case 2: // Bottom side
                x = 205 + 83 * (indices[i] % 5); // Equally spaced X along the bottom side
                y = 510;
                break;
            case 3: // Left side
                x = 205;
                y = 321 + 90 * (indices[i] % 2); // Equally spaced Y along the left side
                break;
            }
            foods[index] = new Meat(x, y);
            index++;
        }

        //sandwiches
        for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
            int side = indices[i] / 4; // Determine which side to spawn the food
            int x, y;

            switch (side) {
            case 0: // Top side
                x = 289 + 90 * (indices[i] % 3); // Equally spaced X along the top side
                y = 305;
                break;
            case 1: // Right side
                x = 479;
                y = 380; // Equally spaced Y along the right side
                break;
            case 2: // Bottom side
                x = 289 + 90 * (indices[i] % 3); // Equally spaced X along the bottom side
                y = 450;
                break;
            case 3: // Left side
                x = 290;
                y = 380; // Equally spaced Y along the left side
                break;
            }
            foods[index] = new Sandwich(x, y);
            index++;

        }
        

    
    }


   
};

