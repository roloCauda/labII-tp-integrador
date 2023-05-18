#include <vector>
#include "BaseObject.h"
#include "Colisiones.h"
#include "Personaje.h"
#include "Principal.h"
#include "Llave.h"
#include "Enemigos.h"
#include "Bomba.h"
#include "GeneradorLlaves.h"
#include "Cajas.h"
#include "Vidas.h"
#include "Map.h"
#include "Reproductor.h"
#include "GeneradorEnemigos.h"
#include "GuardadorDePartida.h"
#include "Menu.h"

class Juego
{
private:
    sf::Event *evento;
    sf::RenderWindow *ventana;
    sf::Clock *reloj;
    sf::Time  *cronometro;
    Principal *principal;
    Bomba *bomba;
    Cajas *caja;
    Vidas *vidas;
    Vidas *corazon;
    int nivel=1;
    Map *mapa;
    Map *mapaColisiones;
    Menu *menu;
    std::vector <Llave*> arrayLlaves;
    std::vector <Enemigos*> arrayEnemigos;
    int llavesEnVentana[3]={5,2,3};
    int enemigosEnVentana[3]={3,4,1};
    Reproductor r;
    int _opcionesJuego=0;

    void renderizar();
    void dibujarLlaves();
    void dibujarEnemigos();
    void dibujarInterfaz();
    void dibujarPersonajes();
    bool logica();
    bool agarrarLlaves();
    void romperCajas();
    void explosion();
    void dibujarVidas();
    bool interseccionVidas();
    void interseccionBomba();
    void interseccionCaja();
    void dibujarBomba();
    void obtenerTiempo();
    void liberarMemoria();
    void dibujarCaja();
    void cambiarDeNivel();
    void explotandoBomba();
    void activarBomba();
    void sonidoJuego();
    void opcionMostrarMenu();
    void opcionMostrarJuego();
    void opcionGuardarJuego();
    void opcionGameOver();
    void opcionGanastes();

public:
    Juego(sf::Vector2u resolucion);
    bool colisiono=false;
    void iniciar();
};

