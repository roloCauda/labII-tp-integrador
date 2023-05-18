#include "Reproductor.h"
#include <SFML/Audio.hpp>

void Reproductor::cargar(std::string sonido){
    buffer.loadFromFile(sonido);
    sound.setBuffer(buffer);
}

void Reproductor::reproducir(){
    sound.play();
}

void Reproductor::reproducirFondo(){
    musica.openFromFile("./src/sounds/fondo.ogg");
    musica.setLoop(true);
    musica.setVolume(5);
    musica.play();
}

void Reproductor::frenarMusicaFondo(){
    musica.pause();
}

void Reproductor::reproducirSonidoLargo(std::string sonido)
{
    musica.openFromFile(sonido);
    musica.setVolume(100);
    musica.play();
}

void Reproductor::frenarAudioLargo()
{
    musica.pause();
}
