#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>

class Reproductor
{
    private:
        sf::Sound sound;
        sf::Music musica;
        sf::SoundBuffer buffer;
    public:
        void cargar(std::string sonido);
        void reproducir();
        void reproducirFondo();
        void frenarMusicaFondo();
        void reproducirSonidoLargo(std::string sonido);
        void frenarAudioLargo();
};

#endif // REPRODUCTOR_H
