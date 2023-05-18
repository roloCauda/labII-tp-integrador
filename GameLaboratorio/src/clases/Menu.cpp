#include "Menu.h"

Menu::Menu()
{
    _texture->loadFromFile("./src/sprites/menu_opcion_1.png");
    _sprite = new sf::Sprite(*_texture);
}

void Menu::update(int &_opcionesJuego, sf::Event* event)
{
   switch(_opcionMenu){
        case 1:
            _texture->loadFromFile("./src/sprites/menu_opcion_1.png");
            _sprite->setTexture(*_texture);
        break;
        case 2:
            _texture->loadFromFile("./src/sprites/menu_opcion_2.png");
            _sprite->setTexture(*_texture);
        break;
        case 3:
            _texture->loadFromFile("./src/sprites/menu_opcion_3.png");
            _sprite->setTexture(*_texture);
        break;
   }
   if(event->type == sf::Event::KeyPressed)
   {
        std::cout<< event->key.code << std::endl;

        if ((event->key.code == sf::Keyboard::Down) && _opcionMenu < 3)
        {
            _opcionMenu++;
        }
        if ((event->key.code == sf::Keyboard::Up) && _opcionMenu > 0)
        {
            _opcionMenu--;
        }

        if(event->key.code == sf::Keyboard::Enter){
            _opcionesJuego=_opcionMenu;
        }
   }

}

void Menu::gameOver(int &_opcionesJuego){
    _texture->loadFromFile("./src/sprites/game_over.jpg");
    _sprite->setTexture(*_texture);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        _opcionesJuego = 0;
        r.frenarAudioLargo();
        r.reproducirFondo();
    }
}

void Menu::ganaste()
{
    _texture->loadFromFile("./src/sprites/ganaste.png");
    _sprite->setTexture(*_texture);
}
