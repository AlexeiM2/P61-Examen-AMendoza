#include "circulo.h"

Circulo::Circulo()

{
    this->setX(149);
    this->setY(140);
    this->setDimension(200);
}

Circulo::Circulo(int xpos, int ypos, int dim)

{

    this->setX(xpos);
    this->setY(ypos);
    this->setDimension(dim);
}

int Circulo::getY() const
{
    return y;
}

void Circulo::setY(int newY)
{
    y = newY;
}

int Circulo::getX() const
{
    return x;
}

void Circulo::setX(int newX)
{
    x = newX;
}

int Circulo::dimension() const
{
    return m_dimension;
}

void Circulo::setDimension(int newDimension)
{
    m_dimension = newDimension;
}
