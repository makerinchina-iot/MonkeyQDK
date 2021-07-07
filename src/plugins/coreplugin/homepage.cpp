#include "homepage.h"

#include <QVBoxLayout>
#include <QLabel>

HomePage::HomePage()
{

    QWidget *homepageWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(homepageWidget);
    homepageWidget->setLayout(mainLayout);
    QLabel *homelabel = new QLabel(homepageWidget);
    homelabel->setText("Home Page");
    QFont font("Microsoft YaHei", 10, 75);
    homelabel->setFont(font);
    homelabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(homelabel);

    setButtonName("Home");
    setWidget(homepageWidget);

}
