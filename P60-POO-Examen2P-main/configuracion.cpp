#include "configuracion.h"
#include "ui_configuracion.h"

Configuracion::Configuracion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuracion)
{
    ui->setupUi(this);
    m_color.setRgb(0,0,0);
    setWidgetColor();
}

Configuracion::~Configuracion()
{
    delete ui;
}

void Configuracion::on_btnColor_released()
{
    m_color = QColorDialog::getColor(m_color,
                                        this,
                                        "Paleta Color");
    Configuracion::setWidgetColor();
}

void Configuracion::setColor(const QColor &newColor)
{
    m_color = newColor;
}

void Configuracion::setAncho(int newAncho)
{
    m_ancho = newAncho;
}

void Configuracion::setWidgetColor()
{

        int r = m_color.red();
        int g = m_color.green();
        int b = m_color.blue();
        QString style = "background-color: rgb(" + QString::number(r) + ", " + QString::number(g) + ", " + QString::number(b) + ")";
        ui->wigetColor->setStyleSheet(style);
}

const QColor &Configuracion::color() const
{
    return m_color;
}

int Configuracion::ancho() const
{
    return m_ancho;
}


void Configuracion::on_inDimension_valueChanged(int value)
{
    m_ancho = value;
    Configuracion::color();
}

