#include "../headers/Colisiones.h"

bool Colisiones::colisiono(Colisiones &obj)
{
    return getBounds().intersects(obj.getBounds());
}
