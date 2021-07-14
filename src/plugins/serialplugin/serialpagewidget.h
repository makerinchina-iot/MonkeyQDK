#ifndef SERIALPAGEWIDGET_H
#define SERIALPAGEWIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <serialcontrol.h>

namespace Ui {
class SerialPageWidget;
}

class SerialPageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPageWidget(QWidget *parent = nullptr);
    ~SerialPageWidget();

private:
    Ui::SerialPageWidget *ui;

    QList<QSerialPortInfo> m_ports;
    QList<qint32> m_baudRates;

    SerialControl *m_serialContrl;

private slots:
    void sendInput();

private:
    void updatePortList();
};

#endif // SERIALPAGEWIDGET_H
