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
class Menu {

public:
    Sprite main_sprite, instruct_sprite, highscore_sprite, exit_sprite, previousbutton_sprite, musicbutton_sprite; 
    Texture main_text,instruct_text, highscore_text, exit_text, previousbutton_text, musicbutton_text;

    Font font;
    Text name,highscoreText;

    Music Theme;

    bool instructions = 0, start = 1, exit = 0, highscore = 0;
    int music = 0;

    string userName = ""; // Variable to store user input

    //add menu attributes here
    Menu()
    {
        /*Theme.openFromFile("music/Rasputin.ogg");
        Theme.play();
        Theme.setLoop(true);*/

        //constructors body
  
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
        
        previousbutton_text.loadFromFile("img/previousbutton.png");
        previousbutton_sprite.setTexture(previousbutton_text);
        previousbutton_sprite.setPosition(20, 20);
        previousbutton_sprite.setScale(0.15, 0.15);
        
        musicbutton_text.loadFromFile("img/musicbutton.png");
        musicbutton_sprite.setTexture(musicbutton_text);
        musicbutton_sprite.setPosition(650, -10);
        musicbutton_sprite.setScale(0.5, 0.5);

        //

        font.loadFromFile("fonts/Game Of Squids.ttf");  
        name.setFont(font);  
        name.setCharacterSize(30); 
        name.setPosition(245, 220);  
        name.setFillColor(sf::Color::White);  
        name.setOutlineColor(sf::Color::Magenta);  
        name.setOutlineThickness(2);  

        highscoreText.setFont(font);
        highscoreText.setCharacterSize(30);
        highscoreText.setPosition(216,292);
        highscoreText.setFillColor(sf::Color::White);  
        highscoreText.setOutlineColor(sf::Color::Magenta); 
        highscoreText.setOutlineThickness(2);  

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

    char* get_name() {
        Texture backgrd, tex;
        Text enter;
        Font newfont;
        newfont.loadFromFile("fonts/Hey Comic.ttf");
        enter.setFont(newfont);
        enter.setCharacterSize(30);
        enter.setFillColor(Color::Black);
        enter.setString("Enter Name:");
        enter.setPosition(260, 280);
        backgrd.loadFromFile("img/carback4.jpeg");
        Sprite spr;
        spr.setTexture(backgrd);
        tex.loadFromFile("img/buttonBlue.png");
        Sprite input;
        input.setTexture(tex);
        input.setPosition(220, 350);
        input.setScale(1.25, 1.5);
        Text name_input;
        name_input.setFont(font);
        name_input.setCharacterSize(25);
        name_input.setFillColor(Color::Black);
        name_input.setPosition(input.getPosition());
        name_input.move(10, 7);

        srand(time(0));
        Clock clock;
        float timer = 0.0;
        RenderWindow window(VideoMode(780, 780), "Enter Name");
        char* the_name = new char[13];
        for (int i = 0; i < 13; i++)
            the_name[i] = '\0';
        int i = 0;
        while (window.isOpen()) {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            name_input.setString(the_name);
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::KeyPressed)
                {
                    if (i < 12)
                    {
                        if (e.key.code == Keyboard::A) the_name[i++] = 'A';
                        else if (e.key.code == Keyboard::B) the_name[i++] = 'B';
                        else if (e.key.code == Keyboard::C) the_name[i++] = 'C';
                        else if (e.key.code == Keyboard::D) the_name[i++] = 'D';
                        else if (e.key.code == Keyboard::E) the_name[i++] = 'E';
                        else if (e.key.code == Keyboard::F) the_name[i++] = 'F';
                        else if (e.key.code == Keyboard::G) the_name[i++] = 'G';
                        else if (e.key.code == Keyboard::H) the_name[i++] = 'H';
                        else if (e.key.code == Keyboard::I) the_name[i++] = 'I';
                        else if (e.key.code == Keyboard::J) the_name[i++] = 'J';
                        else if (e.key.code == Keyboard::K) the_name[i++] = 'K';
                        else if (e.key.code == Keyboard::L) the_name[i++] = 'L';
                        else if (e.key.code == Keyboard::M) the_name[i++] = 'M';
                        else if (e.key.code == Keyboard::N) the_name[i++] = 'N';
                        else if (e.key.code == Keyboard::O) the_name[i++] = 'O';
                        else if (e.key.code == Keyboard::P) the_name[i++] = 'P';
                        else if (e.key.code == Keyboard::Q) the_name[i++] = 'Q';
                        else if (e.key.code == Keyboard::R) the_name[i++] = 'R';
                        else if (e.key.code == Keyboard::S) the_name[i++] = 'S';
                        else if (e.key.code == Keyboard::T) the_name[i++] = 'T';
                        else if (e.key.code == Keyboard::U) the_name[i++] = 'U';
                        else if (e.key.code == Keyboard::V) the_name[i++] = 'V';
                        else if (e.key.code == Keyboard::W) the_name[i++] = 'W';
                        else if (e.key.code == Keyboard::X) the_name[i++] = 'X';
                        else if (e.key.code == Keyboard::Y) the_name[i++] = 'Y';
                        else if (e.key.code == Keyboard::Z) the_name[i++] = 'Z';
                        else if (e.key.code == Keyboard::Space) the_name[i++] = ' ';
                    }
                    if (e.key.code == Keyboard::BackSpace && i > 0) the_name[--i] = '\0';
                    if (e.key.code == Keyboard::Enter)
                    {
                        window.close();
                        return the_name;

                    }
                }
            }
            window.clear(Color::Black);
            window.draw(spr);
            window.draw(input);
            window.draw(enter);
            window.draw(name_input);
            window.display();
        }
        return NULL;
    }

    void display_menu()

    {

        Game g;
        //display menu screen here

        // add functionality of all the menu options here

        //if Start game option is chosen 

        srand(time(0));
        RenderWindow menuwindow(VideoMode(780, 780), "Menu Screen");
        Clock clock;
        float timer = 0;

        int xbutton = 0;
        int ybutton = 0;

        bool mouseclicked = 0;


        // user to input their name before entering the menu loop
        userName = get_name();


        while (menuwindow.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            Event e;
            while (menuwindow.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    menuwindow.close(); //close the game         
                else if (e.type == Event::TextEntered) {
                    // Handle text input
                    if (e.text.unicode < 128)
                        userName += static_cast<char>(e.text.unicode);
                }
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
                            highscore = 0;
                            exit = 0;
                        }

                        if (xbutton >= 693 && xbutton <= 739 && ybutton >= 25 && ybutton <= 76 && mouseclicked == 1) {                  //is music button
                            if (music <= 3) {
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
                            case 4:
                                Theme.stop();
                                break;
                            }
                            mouseclicked = 0;
                            xbutton = 0;
                            ybutton = 0;

                        }
                    }
                }
            }


            if(start){
                //Making a selection based on the reading
                if (xbutton >= 230 && xbutton <= 551 && ybutton >= 307 && ybutton <= 386) {                  //is start
                    start = 1;
                    instructions = 0;
                    highscore = 0;
                    exit = 0;
                    menuwindow.close();
                    g.start_game(userName);
                }

                if (xbutton >= 230 && xbutton <= 551 && ybutton >= 426 && ybutton <= 505) {                  //is highscore
                    highscore = 1;
                    instructions = 0;
                    start = 0;
                    exit = 0;
                }


                if (xbutton >= 230 && xbutton <= 551 && ybutton >= 547 && ybutton <= 626) {                  //is help
                    instructions = 1;
                    highscore = 0;
                    start = 0;
                    exit = 0;
                }


                if (xbutton >= 230 && xbutton <= 551 && ybutton >= 664 && ybutton <= 738) {
                    if (timer > 2.0f) {  // Adjust the delay time as needed
                        menuwindow.draw(exit_sprite);
                        menuwindow.draw(previousbutton_sprite);
                        menuwindow.draw(musicbutton_sprite);

                        // Display user name
                        
                        name.setPosition(200, 450);
                        name.setCharacterSize(23);
                        name.setString("I will miss you, " + userName + "!");
                        menuwindow.draw(name);
                        menuwindow.display();
                        sf::sleep(sf::seconds(2.0f));  // Adjust the delay time as needed
                        menuwindow.close();
                    }
                }

            }

            


            ////////////////////////////////////////////////
            /////  Call your functions here            ////
            //////////////////////////////////////////////

                
            
            menuwindow.clear(Color::Black); //clears the screen

            if (start) {
                menuwindow.draw(main_sprite);  // setting background
                menuwindow.draw(previousbutton_sprite);
                menuwindow.draw(musicbutton_sprite);
                name.setString("Hello, " + userName + "!");
                menuwindow.draw(name);
            }
            else if(instructions) {
                menuwindow.draw(instruct_sprite);
                menuwindow.draw(previousbutton_sprite);
                menuwindow.draw(musicbutton_sprite);
            }
            else if(highscore) {
                loadHighscores(); // Load highscores from file
                menuwindow.draw(highscore_sprite);
                menuwindow.draw(previousbutton_sprite);
                menuwindow.draw(musicbutton_sprite);
                menuwindow.draw(highscoreText);
            }


            menuwindow.display();  //Displying all the sprites
        }

    }


};
