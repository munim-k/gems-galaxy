#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/audio.hpp>
using namespace sf;
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(1055,556), "MAIN MENU");
    window.setVerticalSyncEnabled(true);


    //GEMS GALAXY heading data(heading,headingfont):
    sf::Font headingfont;
    headingfont.loadFromFile("minecraft.ttf");
    sf::Text heading;
    heading.setFont(headingfont);
    heading.setCharacterSize(50);
    heading.Bold;
    heading.setString("GEMS GALAXY");
    heading.setFillColor(sf::Color::Red);
    heading.setLetterSpacing(2);
    heading.move(sf::Vector2f(300, 10));
    heading.setStyle(sf::Text::Underlined | sf::Text::Bold);

    sf::RectangleShape headbox(sf::Vector2f(535,75));
    headbox.setFillColor(sf::Color::Black);
    headbox.move(275, 5);


    //mine background imagine load:
    sf::Texture main;
    sf::Image mainmenu;
    mainmenu.loadFromFile("mainmenu.png");
    main.loadFromImage(mainmenu);
    sf::Sprite mainsprite;
    mainsprite.setTexture(main);
   
    //main menu options load:
    sf::Texture buttonone;
    
    sf::Image newgame;
    newgame.loadFromFile("newgame.png");
    buttonone.loadFromImage(newgame);
    sf::RectangleShape button1(sf::Vector2f(250,60));
    button1.setPosition(420, 150);
    const sf::Texture* buttonone1 = &buttonone;
    button1.setTexture(buttonone1);

    sf::Texture buttontwo;
    sf::Image stop;
    stop.loadFromFile("stop.png");
    buttontwo.loadFromImage(stop);
    sf::RectangleShape button2(sf::Vector2f(200, 90));
    button2.setPosition(440, 200);
    const sf::Texture* buttontwo2 = &buttontwo;
    button2.setTexture(buttontwo2);
    
    sf::Texture mutebutton;
    sf::Image mute;
    mute.loadFromFile("mute.png");
    mutebutton.loadFromImage(mute);
    sf::CircleShape mute1(22);
    mute1.setPosition(6, 0);
    const sf::Texture* mutebutton1 = &mutebutton;
    mute1.setTexture(mutebutton1);

    Texture fullbutton1;
    Image full;
    full.loadFromFile("fullscreen.png");
    fullbutton1.loadFromImage(full);
    CircleShape full1(22);
    const Texture* fullbutton = &fullbutton1;
    full1.setTexture(fullbutton);
    full1.move(6, 0);
    
    Texture crossbutton1;
    Image cross;
    cross.loadFromFile("cross.png");
    crossbutton1.loadFromImage(cross);
    CircleShape cross1(22);
    const Texture* crossbutton = &crossbutton1;
    cross1.setTexture(crossbutton);
    cross1.move(1008,0);

    
    
    //music:
    sf::Mouse theMouse;
    SoundBuffer mainmusic;
    mainmusic.loadFromFile("music.wav");
    Sound music;
    music.setBuffer(mainmusic);
    music.setPlayingOffset(sf::seconds(8.f));
    music.play();
    music.setLoop(true);
    int flag = 1;
    int game = 0;
    
    

    

    


    while (window.isOpen())
    {  
        sf::Event closing;
        while (window.pollEvent(closing))
        {
            if (closing.type == sf::Event::Closed)
                window.close();
            
            sf::Event mainmenu;
            while (window.pollEvent(mainmenu));
            {
                window.clear();
                window.draw(mainsprite);
                window.draw(headbox);
                window.draw(heading);
                window.draw(button1);
                window.draw(full1);
                window.draw(cross1);
                window.draw(button2);
                window.draw(mute1);
                window.display();


                //music control:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (button2.getGlobalBounds().contains(theMouse.getPosition(window).x, theMouse.getPosition(window).y) == true) {
                        window.close();
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (flag == 1)
                    {
                        if (mute1.getGlobalBounds().contains(theMouse.getPosition(window).x, theMouse.getPosition(window).y) == true) {
                            flag = 0;
                        }
                    }
                    else if (flag == 0)
                    {
                        if (mute1.getGlobalBounds().contains(theMouse.getPosition(window).x, theMouse.getPosition(window).y) == true) {
                            flag = 1;
                            music.play();
                        }
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (cross1.getGlobalBounds().contains(theMouse.getPosition(window).x, theMouse.getPosition(window).y) == true) {
                            window.close();
                        }
                    }
                    
                }
                if (flag == 0)
                {
                    music.stop();
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (button1.getGlobalBounds().contains(theMouse.getPosition(window).x, theMouse.getPosition(window).y) == true) {
                        game = 1;
                        window.close();
                    }
                }               
            }            
        }
     }
   if (game == 1)
    {
       //time count start;
        Clock gametime;
        Time gametimedisplay;

        //window:
        RenderWindow gamewindow(VideoMode(1202, 600), "GEMS GALAXY");
        gamewindow.setVerticalSyncEnabled(true);
        //newgame: 
        
        //background:
        Texture background;
        Image bg;
        bg.loadFromFile("scene.png");
        background.loadFromImage(bg);
        Sprite newgamebg;
        newgamebg.setTexture(background);



        //grid:
        Texture gridtexture1;
        Image gridimage;
        gridimage.loadFromFile("samplegrid.png");
        gridtexture1.loadFromImage(gridimage);
        RectangleShape grid(Vector2f(500, 500));
        const Texture* gridtexture = &gridtexture1;
        grid.setTexture(gridtexture);
        grid.setPosition(75, 80);
        
        //buttons:
        Texture pause1;
        Image pausebutton;
        pausebutton.loadFromFile("pause.png");
        pause1.loadFromImage(pausebutton);
        RectangleShape pauseshape(Vector2f(120,50));
        const Texture* pause = &pause1;
        pauseshape.setTexture(pause);
        pauseshape.move(1000, 0);
        //
        Texture crossbutton1;
        Image cross;
        cross.loadFromFile("cross2.png");
        crossbutton1.loadFromImage(cross);
        CircleShape cross2(22);
        const Texture* crossbutton = &crossbutton1;
        cross2.setTexture(crossbutton);
        cross2.move(1155, 0);

        //time bar:
        Texture timebartexture1;
        Image timebar100;
        timebar100.loadFromFile("100%.png");
        timebartexture1.loadFromImage(timebar100);
        RectangleShape timebar(Vector2f(300, 30));
        const Texture* timebartexture = &timebartexture1;
        timebar.setTexture(timebartexture);
        timebar.move(180, 40);

        Image timebar90;
        timebar90.loadFromFile("90%.png");

        Image timebar80;
        timebar80.loadFromFile("80%.png");

        Image timebar70;
        timebar70.loadFromFile("70%.png");

        Image timebar60;
        timebar60.loadFromFile("60%.png");

        Image timebar50;
        timebar50.loadFromFile("50%.png");

        Image timebar40;
        timebar40.loadFromFile("40%.png");

        Image timebar30;
        timebar30.loadFromFile("30%.png");
        
        Image timebar20;
        timebar20.loadFromFile("20%.png");

        Image timebar10;
        timebar10.loadFromFile("10%.png");

        //scoreboard:
        Texture scoreboardtexture1;
        Image scoreboardimage;
        scoreboardimage.loadFromFile("score.png");
        scoreboardtexture1.loadFromImage(scoreboardimage);
        RectangleShape scoreboard(Vector2f(450, 500));
        const Texture* scoreboardtexture = &scoreboardtexture1;
        scoreboard.setTexture(scoreboardtexture);
        scoreboard.move(650, -50);

        Text score;
        score.setFont(headingfont);
        score.setString("SCORE");
        score.Bold;
        score.move(770, 120);
        score.setCharacterSize(60);
        score.setFillColor(Color::Black);
        score.setOutlineColor(Color::Green);
        score.setOutlineThickness(5);
      
        while (gamewindow.isOpen())
        {
            gametimedisplay = gametime.getElapsedTime();
            sf::Event closing;
            while (gamewindow.pollEvent(closing))
            {
                if (closing.type == sf::Event::Closed)
                    gamewindow.close();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (cross2.getGlobalBounds().contains(theMouse.getPosition(gamewindow).x, theMouse.getPosition(gamewindow).y) == true) {
                        gamewindow.close();
                    }
                }

                gamewindow.clear();
                gamewindow.draw(newgamebg);
                gamewindow.draw(grid);
                gamewindow.draw(cross2);
                gamewindow.draw(pauseshape);                                                                                    //change later!!!!!!!!!!!!!!!!!!!!
                gamewindow.draw(timebar);
                gamewindow.draw(scoreboard);
                gamewindow.draw(score);
                gamewindow.display();
            }
            //timebar updates:
            if (gametimedisplay.asSeconds() < 21 && gametimedisplay.asSeconds() > 10)
            {
                timebartexture1.loadFromImage(timebar90);
            }
            else if (gametimedisplay.asSeconds() < 31 && gametimedisplay.asSeconds() > 20)
            {
                timebartexture1.loadFromImage(timebar80);
            }
            else if (gametimedisplay.asSeconds() < 41 && gametimedisplay.asSeconds() > 30)
            {
                timebartexture1.loadFromImage(timebar70);
            }
            else if (gametimedisplay.asSeconds() < 51 && gametimedisplay.asSeconds() > 40)
            {
                timebartexture1.loadFromImage(timebar60);
            }
            else if (gametimedisplay.asSeconds() < 61 && gametimedisplay.asSeconds() > 50)
            {
                timebartexture1.loadFromImage(timebar50);
            }
            else if (gametimedisplay.asSeconds() < 71 && gametimedisplay.asSeconds() > 60)
            {
                timebartexture1.loadFromImage(timebar40);
            }
            else if (gametimedisplay.asSeconds() < 81 && gametimedisplay.asSeconds() > 70)
            {
                timebartexture1.loadFromImage(timebar30);
            }
            else if (gametimedisplay.asSeconds() < 91 && gametimedisplay.asSeconds() > 80)
            {
                timebartexture1.loadFromImage(timebar20);
            }
            else if (gametimedisplay.asSeconds() < 101 && gametimedisplay.asSeconds() > 90)
            {
                timebartexture1.loadFromImage(timebar10);
            }
            else if (gametimedisplay.asSeconds()>101) cout << "game over";                                                      //change later!!!!!!!!!!!!!!!!!!!
            
        }
   }
    return 0;
}