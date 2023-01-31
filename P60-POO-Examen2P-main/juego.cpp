#include "juego.h"
#include "ui_juego.h"
#include "configuracion.h"
#include "ui_configuracion.h"
#include <QPainter>
#include <QFileDialog>
#include <QColor>
Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    m_circulo = new Circulo;
    ui->setupUi(this);
    m_color=Qt::black;
    int m_ancho=100;
    m_color2.setRgb(228, 228, 228);
    miImagen = new QImage(this->size(),QImage::Format_ARGB32);
    mPainter = new QPainter(miImagen);
    miImagen->fill(m_color2);

}

Juego::~Juego()
{
    delete ui;

}
void Juego::dibujar()
{

    QPen pincel;
    pincel.setWidth(3);
    pincel.setColor(m_color);
    mPainter->setPen(pincel);
    //mPainter->drawEllipse(50,20,100,100);
    mPainter->drawEllipse(m_circulo->getX(), m_circulo->getY(), m_circulo->dimension(), m_circulo->dimension());
    update();
}
void Juego::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawImage(10, 10, *miImagen);
}


void Juego::on_btnArriba_released()
{
    if(m_circulo->getY()==23){
        return;
    }
    miImagen->fill(m_color2);
    m_circulo->setY(m_circulo->getY()-1);

    dibujar();
}


void Juego::on_btnAbajo_released()
{
    if(m_circulo->getY()==221){
        return;
    }
    miImagen->fill(m_color2);
    m_circulo->setY(m_circulo->getY()+1);
    dibujar();
}


void Juego::on_btnIzqueirda_released()
{
    if(m_circulo->getX()==2){
        return;
    }
    miImagen->fill(m_color2);
    m_circulo->setX(m_circulo->getX()-1);
    dibujar();
}


void Juego::on_btnDerecha_released()
{
    if(m_circulo->getX()==296){
        return;
    }
    miImagen->fill(m_color2);
    m_circulo->setX(m_circulo->getX()+1);
    dibujar();
}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color();
        qDebug() << config->ancho();
    }
    m_color = config->color();
    m_ancho = config->ancho();
    m_circulo->setDimension(m_ancho);

}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::on_btnIniciar_clicked()
{
    miImagen->fill(m_color2);
    dibujar();

}

