#include "homepage.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QIcon>

#include <fancytabwidget/fancytabwidget.h>
#include <fancytabwidget/fancybutton.h>

using namespace FancyTabWidgetUtils;

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
    setButtonIcon(QIcon(":/icon/image/home.png"));
    setWidget(homepageWidget);

}
