#include "serialcombobox.h"

SerialComboBox::SerialComboBox(QWidget *parent)
{

}

void SerialComboBox::showPopup()
{
    emit opened();

    QComboBox::showPopup();
}
