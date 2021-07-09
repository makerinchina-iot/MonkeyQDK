#include "serialpagewidget.h"
#include "ui_serialpagewidget.h"
#include "serialcombobox.h"

SerialPageWidget::SerialPageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialPageWidget)
{
    ui->setupUi(this);

    m_baudRates = QSerialPortInfo::standardBaudRates();
    ui->inputLineEdit->setPlaceholderText(tr("Type text and hit Enter to send."));

    //signal
    connect(ui->serialportComboBox, &SerialComboBox::opened, this, &SerialPageWidget::updatePortList);
    connect(ui->inputLineEdit, &InputLineEdit::returnPressed,this,&SerialPageWidget::sendInput);
}

SerialPageWidget::~SerialPageWidget()
{
    delete ui;
}

void SerialPageWidget::sendInput()
{

}

void SerialPageWidget::updatePortList()
{
    m_ports.clear();
    ui->serialportComboBox->clear();

    const QList<QSerialPortInfo> serialportInfos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : serialportInfos){
        const QString portName = info.portName();

        if(!portName.isEmpty()){
            m_ports.append(info);

            //TODO,
            //use qmodel
            ui->serialportComboBox->addItem(info.portName());
        }
    }

}
