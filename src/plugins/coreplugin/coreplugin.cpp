#include "coreplugin.h"

#include <QLabel>
#include <QDebug>
#include <QAction>
#include <QToolBar>

#include <coreplugin/dialogs/ioptionspage.h>
#include <coreplugin/dialogs/settingsdialog.h>

#include "systemsettings.h"

using namespace Core;

bool CorePlugin::initialize(const QStringList &, QString *)
{

    qDebug()<<__FILE__<<" at line "<<__LINE__<<" :"<<" coreplugin initialize";

    QMainWindow *mwin = new QMainWindow;

    QLabel *label = new QLabel(mwin);
    label->setText("corePlugin");
    mwin->setCentralWidget(label);
    mwin->setMinimumSize(800,400);
    mwin->setWindowTitle("MonkeyQDK 0.01 by MakerInChina");

    QAction *actSetting = new QAction("setting");
    connect(actSetting,&QAction::triggered,this,&CorePlugin::settingsDialog);

    QToolBar *mainToolbar = new QToolBar("ToolBar",mwin);

    mainToolbar->addAction(actSetting);

    mwin->addToolBar(Qt::TopToolBarArea,mainToolbar);

    m_mainWindow.reset(mwin);

    //system settings
    new SystemSettings();

    return true;
}

void CorePlugin::extensionsInitialized()
{

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
