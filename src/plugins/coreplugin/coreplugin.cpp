#include "coreplugin.h"

#include <QLabel>
#include <QDebug>
#include <QAction>
#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <coreplugin/dialogs/ioptionspage.h>
#include <coreplugin/dialogs/settingsdialog.h>
#include <extensionsystem/pluginmanager.h>

#include <coreplugin/fancypage.h>

#include "systemsettings.h"
//#include "fancytabwidget/fancytabwidget.h"

#include "homepage.h"
#include "toolpage.h"

using namespace Core;
using namespace FancyTabWidgetUtils;

bool CorePlugin::initialize(const QStringList &, QString *)
{

    qDebug()<<__FILE__<<" at line "<<__LINE__<<" :"<<" coreplugin initialize";

    QMainWindow *mwin = new QMainWindow;

    mwin->setWindowTitle("MonkeyQDK 0.01 by MakerInChina");

    QAction *actSetting = new QAction("setting");
    connect(actSetting,&QAction::triggered,this,&CorePlugin::settingsDialog);

    QToolBar *mainToolbar = new QToolBar("ToolBar",mwin);

    mainToolbar->addAction(actSetting);

    mwin->addToolBar(Qt::TopToolBarArea,mainToolbar);

    //add page layout
//    QWidget *mainWidget = new QWidget(mwin);
//    QHBoxLayout *mainLayout = new QHBoxLayout(mainWidget);
//    mainWidget->setLayout(mainLayout);
//    m_pageButtons = new QButtonGroup(mainWidget);
//    m_pageStacks = new QStackedWidget(mainWidget);
//    m_buttonLayout = new QVBoxLayout(mainWidget);
//    m_buttonLayout->setContentsMargins(0,0,0,0);
//    m_buttonLayout->setSpacing(0);

//    mainLayout->addLayout(m_buttonLayout);
//    mainLayout->addWidget(m_pageStacks);
//    mainLayout->setStretch(0,2);
//    mainLayout->setStretch(1,8);

    m_fancyTabWidgt = new FancyTabWidget();
    mwin->setCentralWidget(m_fancyTabWidgt);
    mwin->setMinimumSize(800,600);

    m_mainWindow.reset(mwin);

    //system settings
    new SystemSettings();

    //home page load
    ExtensionSystem::PluginManager::addObject(new HomePage());

    //tool page load
//    ExtensionSystem::PluginManager::addObject(new ToolPage());

    return true;
}

int CorePlugin::m_tabIndex = 0;

void CorePlugin::extensionsInitialized()
{
   QVector<QObject*> pagesObject = ExtensionSystem::PluginManager::allObjects();

//   QPushButton *homeBtn = nullptr;

   for(QObject* objPage:pagesObject){
       FancyPage *page = qobject_cast<FancyPage*>(objPage);

       if(!page->pageWidget()){
           continue;
       }

       qDebug()<<" pages button add:"<<page->pageButton()->text();

//       if(page->pageButton()->objectName() == "Home"){
//           homeBtn = page->pageButton();
//       }

       m_fancyTabWidgt->insertTab(m_tabIndex, page->pageWidget(),QIcon(":/icon/image/mode_Design.png"), page->pageButton()->objectName());
        m_fancyTabWidgt->setTabEnabled(m_tabIndex,true);

       m_tabIndex++;

//       m_pageButtons->addButton(page->pageButton());
//       m_buttonLayout->addWidget(page->pageButton());

//       m_pageStacks->addWidget(page->pageWidget());

//       connect(page->pageButton(),&QPushButton::clicked,[=](){
//           m_pageStacks->setCurrentWidget(page->pageWidget());
//           page->pageButton()->setChecked(true);
//       });

       //remove from plugin pool
       connect(this, &IPlugin::destroyed, this, [=]{
           ExtensionSystem::PluginManager::removeObject(objPage);
       });
   }

   //init page
//   homeBtn->setChecked(true);

//   m_buttonLayout->addStretch();


}

QObject *CorePlugin::remoteCommand(const QStringList &, const QString &, const QStringList &)
{
    m_mainWindow->show();

    return nullptr;
}

void CorePlugin::settingsDialog()
{
    SettingsDialog *settingDialog = new SettingsDialog;

    settingDialog->exec();

}

