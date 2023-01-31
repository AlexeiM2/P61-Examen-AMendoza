#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include <QDebug>
#include "configuracion.h"
#include "circulo.h"
#include <QPoint>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Juego; }
QT_END_NAMESPACE

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    Juego(QWidget *parent = nullptr);
    ~Juego();
protected:
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_btnArriba_released();

    void on_btnAbajo_released();

    void on_btnIzqueirda_released();

    void on_btnDerecha_released();

    void on_actionConfigraci0n_triggered();

    void on_actionSalir_triggered();

    void on_marco_customContextMenuRequested(const QPoint &pos);

    void dibujar();

private:
    Ui::Juego *ui;
    Circulo *m_circulo;
    QImage *miImagen;
    QPainter *mPainter;
};
#endif // JUEGO_H
