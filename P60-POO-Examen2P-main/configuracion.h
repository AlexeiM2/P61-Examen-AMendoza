#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QDialog>
#include <QColorDialog>

namespace Ui {
class Configuracion;
}

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    explicit Configuracion(QWidget *parent = nullptr);
    ~Configuracion();

    const QColor &color() const;
    int ancho() const;

    void setColor(const QColor &newColor);
    void setAncho(int newAncho);

private slots:
    void on_btnColor_released();

    void on_inDimension_valueChanged(int value);

private:
    Ui::Configuracion *ui;
    QColor m_color;
    int m_ancho;

    void setWidgetColor();
};

#endif // CONFIGURACION_H
