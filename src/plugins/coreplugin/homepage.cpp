#include "homepage.h"

#include <QVBoxLayout>
#include <QLabel>

#include <fancytabwidget/fancytabwidget.h>

using namespace FancyTabWidgetUtils;

HomePage::HomePage()
{

//    FancyTabWidget *tabcontainer = new FancyTabWidget();
//    QVBoxLayout *tablayout = new QVBoxLayout(tabcontainer);
//    tabcontainer->setLayout(tablayout);

    QWidget *homepageWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(homepageWidget);
    homepageWidget->setLayout(mainLayout);

    QLabel *homelabel = new QLabel(homepageWidget);
    homelabel->setText("Home Page");
    QFont font("Microsoft YaHei", 10, 75);
    homelabel->setFont(font);
    homelabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(homelabel);

//    QWidget *homepageWidget2 = new QWidget();
//    QVBoxLayout *mainLayout2 = new QVBoxLayout(homepageWidget2);
//    homepageWidget->setLayout(mainLayout2);

//    QLabel *homelabel2 = new QLabel(homepageWidget2);
//    homelabel2->setText("Home2 Page");
//    QFont font2("Microsoft YaHei", 10, 75);
//    homelabel2->setFont(font);
//    homelabel2->setAlignment(Qt::AlignCenter);
//    mainLayout2->addWidget(homelabel2);

//    tabcontainer->insertTab(0, homepageWidget, QIcon(":/icon/image/blogs.png"), "hoome");
//    tabcontainer->insertTab(1, homepageWidget2,QIcon(":/icon/image/community.png"), "home2");
//    tabcontainer->setTabEnabled(0,true);
//    tabcontainer->setTabEnabled(1,true);

    setButtonName("Home");
    setWidget(homepageWidget);

}
