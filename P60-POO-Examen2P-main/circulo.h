#ifndef CIRCULO_H
#define CIRCULO_H
#include<QColor>
#include <QPoint>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

class Circulo : public QPoint
{
public:
    Circulo();
    Circulo(int xpos, int ypos, int dim);
    QColor m_color;


    int dimension() const;
    void setDimension(int newDimension);

    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

private:
    int m_dimension;
    int x;
    int y;
};

#endif // CIRCULO_H
