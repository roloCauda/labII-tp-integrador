#include "../headers/Juego.h"
#include <iostream>
#include <SFML/Audio.hpp>


using namespace std;

Juego::Juego(sf::Vector2u resolucion)
{
    r.reproducirFondo();
    ventana = new sf::RenderWindow(sf::VideoMode(resolucion.x,resolucion.y),"Bank Attack");
    ventana->setFramerateLimit(60);
    iniciar();
    GuardadorDePartida g;

    int i =0;
    while(g.leerDeDisco(i++))
    {
        principal->setPosition(g.getPosicionJugador());
        principal->obenerLlave(g.getLlavesObtenidas());
        llavesEnVentana[0]-=g.getLlavesObtenidas();
        cout << "Juego Cargado!" << endl;
    }

     while (ventana->isOpen())
    {
        ventana->clear();
        evento = new sf::Event;
        while (ventana->pollEvent(*evento))
        {
            if(_opcionesJuego == 0)
            {
                menu->update(_opcionesJuego, evento);
            }
            if (evento->type == sf::Event::Closed)
                ventana->close();
        }

        switch(_opcionesJuego){
        case 0: opcionMostrarMenu(); break;
        case 1: opcionMostrarJuego(); break;
        case 3: opcionGameOver(); break;
        case 4: opcionGanastes(); break;
        }
        ventana->display();
    }

    liberarMemoria();
}
void Juego::iniciar()
{
    reloj = new sf::Clock;
    cronometro = new sf::Time;
    principal = new Principal;
    arrayEnemigos = (new GeneradorEnemigos(nivel))->crearTodas();
    arrayLlaves = (new GeneradorLlaves(nivel))->crearTodas();
    caja = new Cajas;
    caja->setPosition(sf::Vector2i(734,524));
    vidas = new Vidas;
    corazon = new Vidas;
    mapa = new Map;
    bomba = new Bomba;
    menu = new Menu;
}

void Juego::opcionMostrarMenu()
{
    ventana->draw(*menu);
}
void Juego::opcionMostrarJuego()
{
    logica();
    renderizar();
}

void Juego::opcionGuardarJuego()
{
    GuardadorDePartida g;
    cout << "Guardando Partida" << endl;
    g.guardarPartida(
        vidas->getCantidadVidas(),
        principal->getCantidadLlavesObtenidas(),
        principal->getPosicion(),
        enemigosEnVentana[0]
    );
}

void Juego::opcionGameOver()
{
    menu->gameOver(_opcionesJuego);
    ventana->draw(*menu);
}

void Juego::opcionGanastes()
{
    if(nivel == 3){
        ventana->setFramerateLimit(1);
        menu->ganaste();
        ventana->draw(*menu);
    }
}

void Juego::activarBomba()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& bomba->getEstado()== vacio)
    {
        bomba->setPosition(principal->getPosicion());
        bomba->setEstado(sinExplotar);
    }
}

void Juego::explotandoBomba()
{
    bomba->updateExplotion();
    ventana->draw(*bomba);
}


void Juego::renderizar()
{
    ventana->draw(mapa->getSprite());
    dibujarInterfaz();
    explotandoBomba();
    dibujarLlaves();
    dibujarVidas();
    dibujarEnemigos();
    dibujarPersonajes();
    dibujarCaja();
}


void Juego::dibujarInterfaz()
{
    sf::Font font;
    font.loadFromFile("./src/font/stocky.ttf");
    sf::Text text;
    sf::Color color(200, 255, 255);
    text.setFont(font);
    text.setPosition(120,10);
    text.setString(std::to_string(principal->getCantidadLlavesObtenidas()));
    ventana->draw(text);

}

void Juego::dibujarLlaves()
{
    for(int i =0; i < llavesEnVentana[nivel-1]; i++)
    {
        if(arrayLlaves[i] != nullptr)
        {
            ventana->draw(*arrayLlaves[i]);
        }
    }
}

void Juego::dibujarVidas()
{
    sf::Text textVidas;
    sf::Font font;
    font.loadFromFile("./src/font/stocky.ttf");
    textVidas.setFont(font);
    textVidas.setPosition (20,10);
    textVidas.setString(std::to_string(vidas->getCantidadVidas()));
    ventana->draw(textVidas);
    ventana->draw(*corazon);
}


void Juego::dibujarEnemigos()
{
    for(int i =0; i < enemigosEnVentana[nivel-1] ; i++)
    {
        if(arrayEnemigos[i] != nullptr)
        {
            arrayEnemigos[i]->update();
            ventana->draw(*arrayEnemigos[i]);
        }
    }

}

void Juego::dibujarPersonajes()
{
    if(vidas->getCantidadVidas()>0)
    {
        ventana->draw(*principal);
    }
}

void Juego::dibujarCaja()
{
    ventana->draw(*caja);
}

bool Juego::logica()
{
    activarBomba();
    principal->update(bomba, mapa);

    if(agarrarLlaves())
    {
        r.cargar("./src/sounds/ring.ogg");
        r.reproducir();
    }
    if(interseccionVidas())
    {
        r.cargar("./src/sounds/guardias.ogg");
        r.reproducir();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        opcionGuardarJuego();
    }
    interseccionCaja();
    interseccionBomba();
    return false;
}

bool Juego::agarrarLlaves()
{
    for(int i =0; i < llavesEnVentana[nivel-1]; i++)
    {
        if(arrayLlaves[i] != nullptr && principal->getBounds().intersects(arrayLlaves[i]->getBounds()))
        {
            delete arrayLlaves[i];
            arrayLlaves[i] = nullptr;
            principal->obenerLlave(1);
            return true;
        }
    }
    return false;
}

bool Juego::interseccionVidas()
{
    {
        for(int i =0; i < enemigosEnVentana[nivel-1] ; i++)
        {
            if(arrayEnemigos[i] != nullptr && principal->getBounds().intersects(arrayEnemigos[i]->getBounds()))
            {
                vidas->descontar();
                if(vidas->getCantidadVidas()==0){
                    _opcionesJuego=3;
                    vidas->setVidas(3);
                    r.frenarMusicaFondo();
                    r.reproducirSonidoLargo("./src/sounds/kloster.ogg");
                }
                principal->setPosition(sf::Vector2i(60,120));
                return true;
            }
        }
        return false;
    }

}

void Juego::interseccionBomba()
{
    for(int i =0; i < enemigosEnVentana[nivel-1] ; i++)
    {
        if(arrayEnemigos[i] != nullptr && bomba->getEstado()==explotando)
        {
            if (bomba->getBounds().intersects(arrayEnemigos[i]->getBounds()))
            {
                delete arrayEnemigos[i];
                arrayEnemigos[i] = nullptr;
            }
        }
    }
}

void Juego::interseccionCaja()
{
    if (caja->getBounds().intersects(principal->getBounds()))
    {
        cambiarDeNivel();
    }
}

void Juego::cambiarDeNivel()
{
    if(nivel==3)
    {
        _opcionesJuego=4;
        r.frenarMusicaFondo();
        r.reproducirSonidoLargo("./src/sounds/victory.ogg");
        return;
    }

    nivel = nivel+1;
    if(nivel==2){
        for(int i =0; i < enemigosEnVentana[nivel-2] ; i++)
        {
            delete arrayEnemigos[i];
            arrayEnemigos[i] = nullptr;
        }
        for(int i =0; i < llavesEnVentana[nivel-2] ; i++)
        {
            delete arrayLlaves[i];
            arrayLlaves[i] = nullptr;
        }
        arrayEnemigos = (new GeneradorEnemigos(nivel))->crearTodas();
        arrayLlaves = (new GeneradorLlaves(nivel))->crearTodas();
        principal->setPosition(sf::Vector2i(40,110));
        mapa->segundoMapa();
    }

    if(nivel==3){
        mapa->tercerMapa();
        principal->setPosition(sf::Vector2i(100,100));
    }
}

void Juego::liberarMemoria()
{
    delete reloj;
    delete cronometro;
    delete principal;
    delete caja;
    delete vidas;
    delete corazon;
    delete mapa;
    delete bomba;
}
