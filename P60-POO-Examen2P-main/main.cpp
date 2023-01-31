#include "juego.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //NOMBRE: ALEXANDRO SEBASTIAN MENDOZA PROAÑO
    //CEDULA: 1750807602
    QApplication a(argc, argv);
    Juego w;
    w.show();
    return a.exec();
}
