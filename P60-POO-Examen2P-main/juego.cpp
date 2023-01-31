#include "juego.h"
#include "ui_juego.h"

#include <QPainter>
#include <QFileDialog>

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    m_circulo = new Circulo;
    ui->setupUi(this);
    miImagen = new QImage(this->size(),QImage::Format_ARGB32);
    mPainter = new QPainter(miImagen);

    dibujar();
}

Juego::~Juego()
{
    delete ui;

}

void Juego::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawImage(10, 10, *miImagen);
}


void Juego::on_btnArriba_released()
{
    miImagen->fill(Qt::white);
    m_circulo->setY(m_circulo->getY()-1);
    if(m_circulo->getY()==0){
        return;
    }
    dibujar();
}


void Juego::on_btnAbajo_released()
{

}


void Juego::on_btnIzqueirda_released()
{

}


void Juego::on_btnDerecha_released()
{

}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
    }
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar()
{
    QPen pincel;
    pincel.setWidth(3);
    pincel.setColor(Qt::black);
    mPainter->setPen(pincel);
    //mPainter->drawEllipse(50,20,100,100);
    mPainter->drawEllipse(m_circulo->getX(), m_circulo->getY(), m_circulo->dimension(), m_circulo->dimension());
    update();
}

void Juego::on_marco_customContextMenuRequested(QPoint const&){

}
