#include "hellopage.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

HelloPage::HelloPage()
{
    QWidget *helloWidget = new QWidget;

    QHBoxLayout *mainLayout = new QHBoxLayout(helloWidget);
    helloWidget->setLayout(mainLayout);

    QLabel *label = new QLabel(helloWidget);
    label->setText("Hello Page");
    QFont font("Microsoft YaHei", 10, 75);
    label->setFont(font);
    label->setStyleSheet("color:red;");
    label->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(label);

    QPushButton *btn = new QPushButton(helloWidget);
    btn->setText("HelloMessage");
    connect(btn,&QPushButton::clicked,[=](){
        QMessageBox::information(helloWidget, "HelloPlugin", "this is a demo plugin page");
    });

    mainLayout->addWidget(btn);

    setButtonName("Hello");
    setButtonIcon(QIcon(":/image/examples.png"));
    setWidget(helloWidget);
}
