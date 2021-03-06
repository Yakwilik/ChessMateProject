#include "menu.hpp"

namespace Chess {
    void startMenu(Window & window) {


        Chess::Button playBut("./images/play.png");
        playBut.setSize(250, 53);
        playBut.setPosition(settings::getXw()/2 - playBut.getSize().x/2, settings::getYw() *4/13);


        Chess::Button optionBut("./images/option.png");
        optionBut.setSize(231, 53);
        optionBut.setPosition(settings::getXw()/2 - optionBut.getSize().x/2, settings::getYw() *6/13);


        Chess::Button exitBut("./images/exit.png");
        exitBut.setSize(149, 53);
        exitBut.setPosition(settings::getXw() / 2 - exitBut.getSize().x/2, settings::getYw() *8/13);




        sf::Texture menuBackground;
        menuBackground.loadFromFile("./images/menu.png");
        sf::Sprite menuBg(menuBackground);
        menuBg.setScale(settings::getXw()/ 1333, settings::getYw()  / 751);
        menuBg.setPosition(0, 0);

        bool isMenu = 1;
        int menuNum = 0;

        bool pressed = 0;



        sf::Clock clock;
        //////////////////////////////МЕНЮ///////////////////
        while (isMenu) {
            sf::Event event;
            sf::Event::EventType temp;
             while (window.pollEvent(event)) {
                 if (event.type == sf::Event::Closed) {
                     std::exit(0);
                     }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        std::exit(0);
                }
                //на будущее
                /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    rectS.move(0, -1);
                    rectPos = rectS.getPosition();
                    */
                if (event.type == sf::Event::Resized) {
                    window.getSizeNew();
                 }

                if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                    if (event.mouseButton.button == sf::Mouse::Left)
                        pressed = true;
                } else if (menuNum == 0)
                    {pressed = false;}


                if (pressed) {
                    if (event.type == sf::Event::MouseButtonReleased) {
                        if (menuNum == 1) {
                            //isMenu = false;

                            selectMode(window);
                            event.type = temp;
                            pressed = false;
                        }
                        if (menuNum == 2) {
                            options(window);
                            event.type = temp;
                            pressed = false;
                        }
                        if (menuNum == 3) {
                            pressed = false;
                            std::exit(0);
                        }  //
                    }
                }

             }


            float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
            clock.restart(); //перезагружает время
            time = time / 8000; //скорость игры

            //красим кнопка обратно в белый цвет в цикле, если мышь не касается кнопки.
            playBut.getSprite().setColor(sf::Color::White);
            optionBut.getSprite().setColor(sf::Color::White);
            exitBut.getSprite().setColor(sf::Color::White);

            // приравниваем индикатор касания кнопки нулю
            menuNum = 0;

            if (playBut.isTouch(window)) {playBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
            if (optionBut.isTouch(window)) {optionBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
            if (exitBut.isTouch(window)) {exitBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}

            window.draw(menuBg);
            window.draw(playBut.getSprite());
            window.draw(optionBut.getSprite());
            window.draw(exitBut.getSprite());
            window.display();
        }
    }

    void options(Window& window) {
        Chess::Button setTexture("./images/TextureOptions.png");
        setTexture.setSize(360, 53);
        setTexture.setPosition(settings::getXw() /2 - setTexture.getSize().x/2, settings::getYw() *4/13);


        Chess::Button optionBut("./images/WinSize.png");
        optionBut.setSize(452, 53);
        optionBut.setPosition(settings::getXw() / 2 - optionBut.getSize().x/2, settings::getYw() *6/13);


        Chess::Button backBut("./images/backk.png");
        backBut.setSize(149, 53);
        backBut.setPosition(settings::getXw() / 2 - backBut.getSize().x/2, settings::getYw() *8/13);




        sf::Texture menuBackground;
        menuBackground.loadFromFile("./images/menu.png");
        sf::Sprite menuBg(menuBackground);
        menuBg.setScale(settings::getXw() / 1333, settings::getYw()  / 751);
        menuBg.setPosition(0, 0);

        bool isMenu = 1;
        int menuNum = 0;

        bool pressed = 0;



        sf::Clock clock;
        //////////////////////////////МЕНЮ///////////////////
        while (isMenu) {
            sf::Event event;
            sf::Event::EventType temp;
             while (window.pollEvent(event)) {
                 if (event.type == sf::Event::Closed) {
                     std::exit(0);
                     }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        std::exit(0);
                }
                //на будущее
                /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    rectS.move(0, -1);
                    rectPos = rectS.getPosition();
                    */
                if (event.type == sf::Event::Resized) {
                    window.getSizeNew();
                 }

                if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                    if (event.mouseButton.button == sf::Mouse::Left)
                        pressed = true;
                } else if (menuNum == 0)
                    {pressed = false;}


                if (pressed) {
                    if (event.type == sf::Event::MouseButtonReleased) {
                        if (menuNum == 1) {
                            //isMenu = false;

                            optionsTexture(window);
                            event.type = temp;
                            pressed = false;
                        }
                        if (menuNum == 2) {
                            setNewScreen(window);
                            event.type = temp;
                            pressed = false;
                        }
                        if (menuNum == 3) {
                            pressed = false;
                            isMenu = false;
                        }  //
                    }
                }

             }


            float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
            clock.restart(); //перезагружает время
            time = time / 8000; //скорость игры

            //красим кнопка обратно в белый цвет в цикле, если мышь не касается кнопки.
            setTexture.getSprite().setColor(sf::Color::White);
            optionBut.getSprite().setColor(sf::Color::White);
            backBut.getSprite().setColor(sf::Color::White);

            // приравниваем индикатор касания кнопки нулю
            menuNum = 0;

            if (setTexture.isTouch(window)) {setTexture.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
            if (optionBut.isTouch(window)) {optionBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
            if (backBut.isTouch(window)) {backBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}

            window.draw(menuBg);
            window.draw(setTexture.getSprite());
            window.draw(optionBut.getSprite());
            window.draw(backBut.getSprite());
            window.display();
        }

    }
    void optionsTexture(Window& window) {
           //  Загружаем фон
        sf::Texture menuBackground;
        menuBackground.loadFromFile("./images/menu.png");
        sf::Sprite menuBg(menuBackground);
        menuBg.setScale(settings::getXw() / 1333, settings::getYw() / 751);
        menuBg.setPosition(0, 0);

        //
        bool isMenu = 1;  // пока меню открыто
        int menuNum = 0;  // для номеров кнопок

        bool pressed = 0;

        //  кнопки

        Chess::Button setNewTextBut("./images/butOp1.png");
        setNewTextBut.setSize(565, 53);
        setNewTextBut.setPosition(settings::getXw()/2 - setNewTextBut.getSize().x/2, settings::getYw()*3/13);


        Chess::Button setPrevTextBut("./images/butOp2.png");
        setPrevTextBut.setSize(558, 53);
        setPrevTextBut.setPosition(settings::getXw()/2 - setPrevTextBut.getSize().x/2, settings::getYw()*7/13);

        Chess::Button saveBut("./images/save.png");
        saveBut.setSize(223, 53);
        saveBut.setPosition(settings::getXw()/2 - saveBut.getSize().x/2, settings::getYw()*9/13);

        Chess::Button backBut("./images/backk.png");
        backBut.setSize(141, 53);
        backBut.setPosition(settings::getXw()/2 - backBut.getSize().x/2, settings::getYw()*11/13);

        sf::Clock clock;


        setlocale(LC_ALL,"Rus");

        sf::Font font;
        font.loadFromFile("./Fonts/Montserrat-Regular.ttf");
        size_t font_size = 30 * settings::getSf() / 0.2;
        sf::Text curTexture("", font, font_size);

        wchar_t* cur_texture = L"текущая текстура: ";

        curTexture.setColor(sf::Color::White);
        curTexture.setOutlineThickness(2);

        sf::String currentTexture = sf::String(cur_texture);
        int case_num = 0;
        FigureTexture::defineMain_sprite();
        std::string pathfile = FigureTexture::getPath();
        while (isMenu) {
            sf::Event event;
            sf::Event::EventType temp;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    std::exit(0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    std::exit(0);
                }
                if (event.type == sf::Event::Resized) {
                    window.getSizeNew();
                 }
            }

            float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
            clock.restart(); //перезагружает время
            time = time / 8000; //скорость игры
            setNewTextBut.getSprite().setColor(sf::Color::White);
            setPrevTextBut.getSprite().setColor(sf::Color::White);
            saveBut.getSprite().setColor(sf::Color::White);
            backBut.getSprite().setColor(sf::Color::White);
            menuNum = 0;


            if (setNewTextBut.isTouch(window)) {setNewTextBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
            if (setPrevTextBut.isTouch(window)) {setPrevTextBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
            if (saveBut.isTouch(window)) {saveBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}
            if (backBut.isTouch(window)) {backBut.getSprite().setColor(sf::Color::Blue);menuNum = 4;}

            if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                if (event.mouseButton.button == sf::Mouse::Left)
                    pressed = true;
            } else if (menuNum == 0)
                    {pressed = false;}

            if (pressed) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (menuNum == 1) {
                        // isMenu = false;
                        switch (case_num) {
                        case 0:
                            FigureTexture::setMain_sprite(pathfile = "./images/pieces/wooden_pieces.png");
                            case_num++;
                            break;
                        case 1:
                            FigureTexture::setMain_sprite(pathfile = "./images/pieces/metallic_p.png");
                            case_num++;
                            break;
                        case 2:
                            FigureTexture::setMain_sprite(pathfile = "./images/pieces/pieces_classic.png");
                            case_num++;
                            break;
                        case 3:
                            FigureTexture::setMain_sprite(pathfile = "./images/pieces/Pieces_colored.png");
                            case_num++;
                            break;
                        case 4:
                            FigureTexture::setMain_sprite(pathfile = "./images/pieces/rofl_pieces.png");
                            case_num++;
                            break;
                        case 5:
                            FigureTexture::setMain_sprite(pathfile = "./images/pieces/east_and_west.png");
                            case_num = 0;
                            break;
                        default:
                            case_num = 0;
                            break;
                        }

                        event.type = temp;
                        pressed = false;
                    }
                    if (menuNum == 2) {
                        // isMenu = false;

                        FigureTexture::setMain_sprite(pathfile = "./images/pieces/piecesTru.png");
                        case_num = 0;
                        event.type = temp;
                        pressed = false;
                    }
                    if (menuNum == 3) {
                        // isMenu = false;

                        FigureTexture::saveMain_sprite();
                        event.type = temp;
                        pressed = false;
                    }


                    if (menuNum == 4) {
                        isMenu = false;
                        event.type = temp;
                        pressed = false;
                        // startMenu(window);
                        // startMenu(window);
                    }
                }

            }
            curTexture.setString(currentTexture + pathfile);
            curTexture.setPosition(settings::getXw()  / 2 - (wcslen(cur_texture) * font_size / 4 + pathfile.length() * font_size / 4), settings::getYw() * 5/13);


            window.draw(menuBg);
            window.draw(setNewTextBut.getSprite());
            window.draw(setPrevTextBut.getSprite());
            window.draw(saveBut.getSprite());
            window.draw(backBut.getSprite());
            window.draw(curTexture);
            window.display();

        }

    }

    void setNewScreen(Window& window) {
           //  Загружаем фон
        sf::Texture menuBackground;
        menuBackground.loadFromFile("./images/menu.png");
        sf::Sprite menuBg(menuBackground);
        menuBg.setScale(settings::getXw() / 1333, settings::getYw() / 751);
        menuBg.setPosition(0, 0);

        //
        bool isMenu = 1;  // пока меню открыто
        int menuNum = 0;  // для номеров кнопок

        bool pressed = 0;

        //  кнопки

        Chess::Button setNewSizeBut("./images/WinSize.png");
        setNewSizeBut.setSize(452, 53);
        setNewSizeBut.setPosition(settings::getXw()/2 - setNewSizeBut.getSize().x/2, settings::getYw()*3/13);


        Chess::Button setPrevSizetBut("./images/BackSize.png");
        setPrevSizetBut.setSize(669, 53);
        setPrevSizetBut.setPosition(settings::getXw()/2 - setPrevSizetBut.getSize().x/2, settings::getYw()*7/13);

        Chess::Button saveBut("./images/save.png");
        saveBut.setSize(223, 53);
        saveBut.setPosition(settings::getXw()/2 - saveBut.getSize().x/2, settings::getYw()*9/13);

        /*Chess::Button ApplyBut("./images/ApplyBut.png");
        ApplyBut.setSize(241, 53);
        ApplyBut.setPosition(settings::getXw()/1.5 - ApplyBut.getSize().x/2, settings::getYw()*9/13);*/

        Chess::Button backBut("./images/backk.png");
        backBut.setSize(141, 53);
        backBut.setPosition(settings::getXw()/2 - backBut.getSize().x/2, settings::getYw()*11/13);

        sf::Clock clock;


        setlocale(LC_ALL,"Rus");

        sf::Font font;
        font.loadFromFile("./Fonts/Montserrat-Regular.ttf");
        size_t font_size = 30 * settings::getSf() / 0.2;
        sf::Text curTexture("", font, font_size);

        wchar_t* cur_texture = L"Текущее разрешние: ";

        curTexture.setColor(sf::Color::White);
        curTexture.setOutlineThickness(2);

        sf::String currentTexture = sf::String(cur_texture);
        int case_num = 2;
        float case_numb = settings::getSffromFile();
        bool isSaved;
        FigureTexture::defineMain_sprite();
        float Xw = case_numb*4800;
        float Yw = case_numb*3120;

        std::string pathfile = std::to_string((int)Xw) + "x" + std::to_string((int)Yw);
        while (isMenu) {
            sf::Event event;
            sf::Event::EventType temp;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    std::exit(0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    std::exit(0);
                }
                if (event.type == sf::Event::Resized) {
                    window.getSizeNew();
                 }
            }

            float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
            clock.restart(); //перезагружает время
            time = time / 8000; //скорость игры
            setNewSizeBut.getSprite().setColor(sf::Color::White);
            setPrevSizetBut.getSprite().setColor(sf::Color::White);
            saveBut.getSprite().setColor(sf::Color::White);
            //ApplyBut.getSprite().setColor(sf::Color::White);
            backBut.getSprite().setColor(sf::Color::White);
            menuNum = 0;


            if (setNewSizeBut.isTouch(window)) {setNewSizeBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
            if (setPrevSizetBut.isTouch(window)) {setPrevSizetBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
            if (saveBut.isTouch(window)) {saveBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}
            //if (ApplyBut.isTouch(window)) {ApplyBut.getSprite().setColor(sf::Color::Blue);menuNum = 4;}
            if (backBut.isTouch(window)) {backBut.getSprite().setColor(sf::Color::Blue);menuNum = 5;}

            if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                if (event.mouseButton.button == sf::Mouse::Left)
                    pressed = true;
            } else if (menuNum == 0)
                    {pressed = false;}

            if (pressed) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (menuNum == 1) {
                        // isMenu = false;
                        case_num++;
                        switch (case_num) {
                        case 2:
                            settings::setSF(case_num * 0.1);
                            pathfile = "960x624";
                            break;
                        case 3:
                            settings::setSF(case_num * 0.1);
                            pathfile = "1440x936";
                            break;
                        case 4:
                            settings::setSF(case_num * 0.1);
                            pathfile = "1920x1248";
                            break;
                        case 5:
                            settings::setSF(case_num * 0.1);
                            pathfile = "1920x1248";
                            break;
                        case 6:
                            settings::setSF(case_num * 0.1);
                            pathfile = "2400x1560";
                            break;
                        case 7:
                            settings::setSF(case_num * 0.1);
                            pathfile = "3360x2184";
                            case_num = 1;
                            break;
                        default:
                            case_num = 1;
                            break;
                        }

                        event.type = temp;
                        pressed = false;
                    }
                    if (menuNum == 2) {
                        // isMenu = false;

                        settings::setSF(0.2);
                        pathfile = "960x624";
                        case_num = 2;
                        event.type = temp;
                        pressed = false;
                    }
                    if (menuNum == 3) {
                        // isMenu = false;

                        isSaved = true;
                        event.type = temp;
                        pressed = false;
                    }

                    /*if (menuNum == 4) {
                        // isMenu = false;


                        isSaved = true;
                        event.type = temp;
                        pressed = false;
                        execl("./ChessMate.out", NULL, case_num);
                    }*/


                    if (menuNum == 5) {
                        if (!isSaved) {
                            settings::setSF(0.2);
                            case_num = 2;
                        }
                        isMenu = false;
                        event.type = temp;
                        pressed = false;
                        // startMenu(window);
                        // startMenu(window);
                    }
                }

            }
            curTexture.setString(currentTexture + pathfile);
            curTexture.setPosition(settings::getXw()  / 2 - (wcslen(cur_texture) * font_size / 4 + pathfile.length() * font_size / 4), settings::getYw() * 5/13);


            window.draw(menuBg);
            window.draw(setNewSizeBut.getSprite());
            window.draw(setPrevSizetBut.getSprite());
            window.draw(saveBut.getSprite());
            //window.draw(ApplyBut.getSprite());
            window.draw(backBut.getSprite());

            window.draw(curTexture);
            window.display();

        }

    }
    void selectMode(Window& window) {

        //  Загружаем фон
        sf::Texture menuBackground;
        menuBackground.loadFromFile("./images/menu.png");
        sf::Sprite menuBg(menuBackground);
        menuBg.setScale(settings::getXw()  / 1333, settings::getYw() / 751);
        menuBg.setPosition(0, 0);

        //
        bool isMenu = 1;  // пока меню открыто
        int menuNum = 0;  // для номеров кнопок

        bool pressed = 0;

        //  кнопки

        Chess::Button singlePlayBut("./images/singlePlay.png");
        singlePlayBut.setSize(561, 53);
        singlePlayBut.setPosition(settings::getXw() /2 - singlePlayBut.getSize().x/2, settings::getYw()*4/13);


        Chess::Button onlineGameBut("./images/online_game.png");
        onlineGameBut.setSize(270, 53);
        onlineGameBut.setPosition(settings::getXw() /2 - onlineGameBut.getSize().x/2, settings::getYw()*6/13);

        Chess::Button backBut("./images/backk.png");
        backBut.setSize(141, 53);
        backBut.setPosition(settings::getXw() /2 - backBut.getSize().x/2, settings::getYw()*8/13);

        sf::Clock clock;

        while (isMenu) {
            sf::Event event;
            sf::Event::EventType temp;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    std::exit(0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    std::exit(0);
                }
                if (event.type == sf::Event::Resized) {
                    window.getSizeNew();
                 }
            }

            float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
            clock.restart(); //перезагружает время
            time = time / 8000; //скорость игры
            singlePlayBut.getSprite().setColor(sf::Color::White);
            onlineGameBut.getSprite().setColor(sf::Color::White);
            backBut.getSprite().setColor(sf::Color::White);
            menuNum = 0;


            if (singlePlayBut.isTouch(window)) {singlePlayBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
            if (onlineGameBut.isTouch(window)) {onlineGameBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
            if (backBut.isTouch(window)) {backBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}

            if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                if (event.mouseButton.button == sf::Mouse::Left)
                    pressed = true;
            } else if (menuNum == 0)
                    {pressed = false;}

            if (pressed) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (menuNum == 1) {
                        // isMenu = false;

                        startGame(window, ONE_PLAYER);
                        event.type = temp;
                        pressed = false;
                    }
                    if (menuNum == 2) {
                        // isMenu = false;

                        selectH(window);
                        event.type = temp;
                        pressed = false;
                    }
                    if (menuNum == 3) {
                        isMenu = false;
                        event.type = temp;
                        pressed = false;
                        // startMenu(window);
                        // startMenu(window);
                    }
                }

            }

            window.draw(menuBg);
            window.draw(singlePlayBut.getSprite());
            window.draw(onlineGameBut.getSprite());
            window.draw(backBut.getSprite());
            window.display();

        }


    }


    void selectH(Window& window) {

            //  Загружаем фон
            sf::Texture menuBackground;
            menuBackground.loadFromFile("./images/menu.png");
            sf::Sprite menuBg(menuBackground);
            menuBg.setScale(settings::getXw()  / 1333, settings::getYw() / 751);
            menuBg.setPosition(0, 0);

            //
            bool isMenu = 1;  // пока меню открыто
            int menuNum = 0;  // для номеров кнопок
            bool pressed = 0;

            //  кнопки

            Chess::Button createBut("./images/createGame.png");
            createBut.setSize(268, 53);
            createBut.setPosition(settings::getXw() /2 - createBut.getSize().x / 2, settings::getYw()*4/13);


            Chess::Button joinBut("./images/joinGame.png");
            joinBut.setSize(467, 53);
            joinBut.setPosition(settings::getXw() /2 - joinBut.getSize().x / 2, settings::getYw()*6/13);

            Chess::Button backBut("./images/backk.png");
            backBut.setSize(141, 53);
            backBut.setPosition(settings::getXw() /2 - backBut.getSize().x / 2, settings::getYw()*8/13);

            sf::Clock clock;

            while (isMenu) {
                sf::Event event;
                sf::Event::EventType temp;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        std::exit(0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        std::exit(0);
                    }
                    if (event.type == sf::Event::Resized) {
                        window.getSizeNew();
                    }
                }

                float time = clock.getElapsedTime().asMicroseconds();  // дать прошедшее время в микросекундах
                clock.restart();  // перезагружает время
                time = time / 8000;  // скорость игры
                createBut.getSprite().setColor(sf::Color::White);
                joinBut.getSprite().setColor(sf::Color::White);
                backBut.getSprite().setColor(sf::Color::White);
                menuNum = 0;


                if (createBut.isTouch(window)) { createBut.getSprite().setColor(sf::Color::Blue); menuNum = 1; }
                if (joinBut.isTouch(window)) { joinBut.getSprite().setColor(sf::Color::Blue); menuNum = 2; }
                if (backBut.isTouch(window)) { backBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }

                if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                    if (event.mouseButton.button == sf::Mouse::Left)
                        pressed = true;
                } else if (menuNum == 0)
                    {pressed = false;}

                if (pressed) {
                    if (event.type == sf::Event::MouseButtonReleased) {
                        if (menuNum == 1) {
                            // add create menu
							// createGameMenu(window);

                            startGame(window, HOST);
                            event.type = temp;
                            pressed = false;
                        }  // если нажали первую кнопку, то выходим из меню
                        if (menuNum == 2) {
                            // add join menu
							// joinGameMenu(window);

                            startGame(window, CLIENT);
                            event.type = temp;
                            pressed = false;
                        }
                        if (menuNum == 3) {
                            isMenu = false;
                            event.type = temp;
                            pressed = false;

                            // selectMode(window);
                        }  // add implementation of option
                    }

                }

                window.draw(menuBg);
                window.draw(createBut.getSprite());
                window.draw(joinBut.getSprite());
                window.draw(backBut.getSprite());
                // window.draw(ipTxt);
                window.display();

            }
        }

	void createGameMenu(Window& window, Gameplay& gameplay) {
		//  Загружаем фон
        sf::Texture menuBackground;
        menuBackground.loadFromFile("./images/menu.png");
        sf::Sprite menuBg(menuBackground);
        menuBg.setScale(settings::getXw()  / 1333, settings::getYw() / 751);
        menuBg.setPosition(0, 0);

        //
        bool isMenu = 1;  // пока меню открыто
        int menuNum = 0;  // для номеров кнопок
        bool pressed = 0;

		sf::IpAddress host_ip;
        // host_ip.getPublicAddress(sf::seconds(5.3f));
        host_ip.getLocalAddress();

        // текст для вывода IP
        sf::Font font;//шрифт
        font.loadFromFile("./Fonts/Montserrat.TTF");
        sf::Text ipTxt(" ", font, 40);
        ipTxt.setStyle(sf::Text::Bold);
        ipTxt.setFillColor(sf::Color::White);
        ipTxt.setOutlineColor(sf::Color::Black);
        ipTxt.setOutlineThickness(2);
        ipTxt.setString("Your IP address: " + sf::IpAddress::getLocalAddress().toString());
        ipTxt.setPosition(settings::getXw() /4, settings::getYw()*6/13);

        sf::Text inviteTxt("Report your IP to friend", font, 40);
        inviteTxt.setStyle(sf::Text::Bold);
        inviteTxt.setFillColor(sf::Color::White);
        inviteTxt.setOutlineColor(sf::Color::Black);
        inviteTxt.setOutlineThickness(2);
        inviteTxt.setPosition(settings::getXw() /4, settings::getYw()*4/13);

		Chess::Button backBut("./images/backk.png");
    	backBut.setSize(141, 53);
    	backBut.setPosition(settings::getXw() /2 - backBut.getSize().x / 2, settings::getYw()*8/13);

        // Chess::TextField inputText(15);

		sf::Clock clock;

        while (isMenu) {
            sf::Event event;
            sf::Event::EventType temp;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    std::exit(0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    std::exit(0);
                }
                if (event.type == sf::Event::Resized) {
                    window.getSizeNew();
                }
            }

            float time = clock.getElapsedTime().asMicroseconds();  // дать прошедшее время в микросекундах
            clock.restart();  // перезагружает время
            time = time / 8000;  // скорость игры
            backBut.getSprite().setColor(sf::Color::White);
            menuNum = 0;


            if (backBut.isTouch(window)) { backBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }

            if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                if (event.mouseButton.button == sf::Mouse::Left)
                    pressed = true;
            } else if (menuNum == 0)
                {pressed = false;}

            if (pressed) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    // if (menuNum == 1) {
                    //     startGame(window, HOST);
                    //     event.type = temp;
                    //     pressed = false;
                    // }  // if connected, then start game
                    if (menuNum == 3) {
                        isMenu = false;
                        event.type = temp;
                        pressed = false;
                        // selectMode(window);
                    }  // add implementation of option
                }

            }

            window.draw(menuBg);
            window.draw(backBut.getSprite());
            window.draw(ipTxt);
            window.draw(inviteTxt);
            window.display();

            // gameplay.host();
            isMenu = false;
        }
	}

	std::string joinGameMenu(Window& window) {  // add connection + space to enter ipTxt
		//  Загружаем фон
        sf::Texture menuBackground;
        menuBackground.loadFromFile("./images/menu.png");
        sf::Sprite menuBg(menuBackground);
        menuBg.setScale(settings::getXw()  / 1333, settings::getYw() / 751);
        menuBg.setPosition(0, 0);

        //
        bool isMenu = 1;  // пока меню открыто
        int menuNum = 0;  // для номеров кнопок
        bool pressed = 0;

		Chess::Button backBut("./images/backk.png");
    	backBut.setSize(141, 53);
    	backBut.setPosition(settings::getXw() /2 - backBut.getSize().x / 2, settings::getYw()*8/13);

		sf::Clock clock;

        // Chess::TextField plInput(15);
        // plInput.setPosition(30, 30);

        // input text
        sf::Font font;
        font.loadFromFile("./Fonts/Montserrat.TTF");
        std::string playerInput;
        sf::Text playerText("", font, 40);
        playerText.setPosition(settings::getXw() /4, settings::getYw()*6/13);
        playerText.setColor(sf::Color::White);
        playerText.setOutlineThickness(2);

        sf::Text joinTxt("Enter friend's IP here:", font, 40);
        joinTxt.setPosition(settings::getXw() /4, settings::getYw()*4/13);
        joinTxt.setColor(sf::Color::White);
        joinTxt.setOutlineThickness(2);


        while (isMenu) {
            sf::Event event;
            sf::Event::EventType temp;

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    std::exit(0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    std::exit(0);
                }
                if (event.type == sf::Event::Resized) {
                    window.getSizeNew();
                }
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128) {
                        if (event.text.unicode == 8) {
                            playerInput = playerInput.substr(0, playerInput.size() - 1);
                        } else if ((event.text.unicode >= '0' && event.text.unicode <= '9') || event.text.unicode == '.') {
                            playerInput += event.text.unicode;
                        }
                        playerText.setString(playerInput);
                    }
                }
                window.draw(playerText);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    isMenu = false;
                }
            }

            float time = clock.getElapsedTime().asMicroseconds();  // дать прошедшее время в микросекундах
            clock.restart();  // перезагружает время
            time = time / 8000;  // скорость игры
            backBut.getSprite().setColor(sf::Color::White);
            menuNum = 0;


            if (backBut.isTouch(window)) { backBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }

            if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                if (event.mouseButton.button == sf::Mouse::Left)
                    pressed = true;
            } else if (menuNum == 0)
                {pressed = false;}

            if (pressed) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    // if (menuNum == 1) {
                    //     startGame(window, CLIENT);
                    //     event.type = temp;
                    //     pressed = false;
                    // }  // if connected, then start game
                    if (menuNum == 3) {
                        isMenu = false;
                        event.type = temp;
                        pressed = false;
                        // selectMode(window);
                    }  // add implementation of option
                }
            }

            window.draw(menuBg);
            window.draw(playerText);
            window.draw(joinTxt);
            window.draw(backBut.getSprite());
            window.display();

        }
        return playerInput;
	}

    void startGame(Window& window, GameMode mode) {

        sf::Clock clock;
        int menuNum = 0;
        bool isGame = true;
        bool GameOver = false;

        bool pressed = 0;

        Chess::Gameplay gameplay;
        gameplay.setSide();
        gameplay.setGameMode(mode);

        if (mode == HOST) {
            createGameMenu(window, gameplay);
            if (!gameplay.host()) {
                isGame = false;
            }
        } else if (mode == CLIENT) {
            if (!gameplay.client(joinGameMenu(window))) {
                isGame = false;
            }
        }

        gameplay.updateSprites();

        // GameOverBG
        //sf::Texture endGameBg;
        //endGameBg.loadFromFile("./images/endgame.png");
        //sf::Sprite endGameBgSprite(endGameBg);
        //endGameBgSprite.setPosition(0, 0);
        sf::Texture menuBackground;
        menuBackground.loadFromFile("./images/endgameBg.png");
        sf::Sprite menuBg(menuBackground);
        menuBg.setScale(settings::getSf() * 0.5 / 0.2, settings::getSf() * 0.5 / 0.2);
        menuBg.setPosition(0, 0);

        // button exit through class Button
        Chess::Button exitBut("./images/exit.png");
        exitBut.setSize(X_EXIT, Y_EXIT);
        exitBut.setPosition(settings::getXw()  - 200, settings::getYw() - 100 * settings::getSf() / 0.2);


        // кнопка назад
        Chess::Button backBut("./images/back.png");
        backBut.setSize(X_BACK, Y_BACK);
        backBut.setPosition(100, settings::getYw() - 100 * settings::getSf() / 0.2);

        // add board and figure
        float scale = settings::getSf();
        Chess::BoardTexture board_texture("./images/boardTru.jpg");
        Chess::FigureTexture figures_testure;
        board_texture.setBoardScale(settings::getSf());

        sf::Vector2i playSpace;
        playSpace.x = settings::getPsX();
        playSpace.y = settings::getPsY();
        board_texture.setPlaySpace(playSpace);

        while (isGame) {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
            clock.restart(); //перезагружает время
            time = time / 8000;


            sf::Event event;
            sf::Event::EventType temp;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    std::exit(0);
                }
                // берем новый размер окна, чтобы можно было задать новую рабочую зону для кнопок
                if (event.type == sf::Event::Resized) {
                    window.getSizeNew();
                }

                menuNum = 0;
                exitBut.getSprite().setColor(sf::Color::White);
                backBut.getSprite().setColor(sf::Color::White);

                // изначально соотношение размеров окон 1:1, но после ресайза это отношение меняется, и мы по-прежнему можем нажимать на кнопки в зоне их расположения
                if (exitBut.isTouch(window)) {exitBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
                if (backBut.isTouch(window)) {backBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}

                if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                    if (event.mouseButton.button == sf::Mouse::Left)
                        pressed = true;
                } else if (menuNum == 0)
                    {pressed = false;}

                if (pressed) {
                    if (event.type == sf::Event::MouseButtonReleased) {
                        if (menuNum == 1) {

                            std::exit(0);
                            pressed = false;
                        }
                        if (menuNum == 2)  {

                            isGame = false;
                            event.type = temp;
                            pressed = false;
                            // selectMode(window);
                        }
                    }
                }

                gameplay.play(event, pos); // proveryaet hod
            }

            window.clear();
            window.clear(sf::Color(129, 181, 221));



            if (gameplay.isGameOver()) {
                GameOver = true;
                isGame = false;
            } else {
                menuNum = 0;
                window.draw(board_texture.getSprite());
                window.draw(exitBut.getSprite());
                window.draw(backBut.getSprite());
                gameplay.recieveBoardState();
                gameplay.updateSprites();
                gameplay.drawFigures(window, pos);
            }

            window.display();

        } // while(isGame)

        backBut.setPosition(settings::getXw()  / 2 - backBut.getSize().x / 2, 285 * settings::getSf() / 0.2);
        exitBut.setPosition(settings::getXw()  / 2 - exitBut.getSize().x / 2, 388 * settings::getSf() / 0.2);
        setlocale(LC_ALL,"Rus");

        sf::Font font;
        font.loadFromFile("./Fonts/Montserrat-Regular.ttf");
        size_t font_size = 50 * settings::getSf() / 0.2;
        sf::Text winnerText("", font, font_size);

        wchar_t* whites = L"Победитель – белые";
        wchar_t* blacks = L"Победитель – черные";

        winnerText.setPosition(settings::getXw()  / 2 - wcslen(whites) * font_size / 4, 200 * settings::getSf() / 0.2);
        winnerText.setColor(sf::Color::White);
        winnerText.setOutlineThickness(2);


        if (gameplay.getSide() == BLACK) {
            sf::String winner = sf::String(whites);
            winnerText.setString(winner);
        } else {
            sf::String winner = sf::String(blacks);
            winnerText.setString(winner);
        }










        while (GameOver) {

            float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
            clock.restart(); //перезагружает время
            time = time / 8000;

            sf::Event event;
            sf::Event::EventType temp;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    std::exit(0);
                }
                // берем новый размер окна, чтобы можно было задать новую рабочую зону для кнопок
                if (event.type == sf::Event::Resized) {
                    window.getSizeNew();
                }

                menuNum = 0;
                exitBut.getSprite().setColor(sf::Color::White);
                backBut.getSprite().setColor(sf::Color::White);

                if (exitBut.isTouch(window)) {exitBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
                if (backBut.isTouch(window)) {backBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}

                if (event.type == sf::Event::MouseButtonPressed && menuNum != 0) {
                    if (event.mouseButton.button == sf::Mouse::Left)
                        pressed = true;
                } else if (menuNum == 0)
                    {pressed = false;}


                if (pressed) {
                    if (event.type == sf::Event::MouseButtonReleased) {
                        if (menuNum == 1) {
                            pressed = false;
                            std::exit(0);
                        }
                        if (menuNum == 2)  {
                            pressed = false;
                            GameOver = false;
                            event.type = temp;
                            // selectMode(window);
                        }
                    }
                }

            }
            window.clear(sf::Color(255, 255, 255));
            window.draw(board_texture.getSprite());
            window.draw(menuBg);
            window.draw(exitBut.getSprite());
            window.draw(backBut.getSprite());
            window.draw(winnerText);
            window.display();
        }


    }  // startGame

}  // namespace Chess

/*
// input ip
const std::string Chess::TextField::getText() const{
    return m_text;
}

void Chess::TextField::setPosition(float x, float y){
    sf::Transformable::setPosition(x, y);
    m_rect.setPosition(x, y);
}

bool Chess::TextField::contains(sf::Vector2f point) const{
    return m_rect.getGlobalBounds().contains(point);
}

void Chess::TextField::setFocus(bool focus){
    m_hasfocus = focus;
    if (focus){
        m_rect.setOutlineColor(sf::Color::Blue);
    }
    else{
        m_rect.setOutlineColor(sf::Color(127, 127, 127)); // Gray color
    }
}

void Chess::TextField::handleInput(sf::Event event) {
    if (!m_hasfocus || event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 8){   // Delete key
            m_text = m_text.substr(0, m_text.size() - 1);
        } else if (m_text.size() < m_size){
            m_text += event.text.unicode;
        }
    }
}

void Chess::TextField::draw(sf::Text text) {

}*/