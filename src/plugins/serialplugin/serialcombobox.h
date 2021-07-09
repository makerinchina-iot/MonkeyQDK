#ifndef SERIALCOMBOBOX_H
#define SERIALCOMBOBOX_H

#include <QObject>
#include <QComboBox>
#include <QWidget>

class SerialComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit SerialComboBox(QWidget *parent = nullptr);
    void showPopup() override;

signals:
    void opened();
};

#endif // SERIALCOMBOBOX_H
