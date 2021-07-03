#include "coreplugin.h"

#include <QLabel>
#include <QDebug>

bool CorePlugin::initialize(const QStringList &, QString *)
{

    qDebug()<<__FILE__<<" at line "<<__LINE__<<" :"<<" coreplugin initialize";

    QMainWindow *mwin = new QMainWindow;

    QLabel *label = new QLabel(mwin);
    label->setText("corePlugin");
    mwin->setCentralWidget(label);
    mwin->setMinimumSize(800,400);
    mwin->setWindowTitle("MonkeyQDK 0.01 by MakerInChina");

    m_mainWindow.reset(mwin);

    return true;
}

void CorePlugin::extensionsInitialized()
{
//    m_mainWindow->extensionsInitialized();
}

QObject *CorePlugin::remoteCommand(const QStringList &, const QString &, const QStringList &)
{
    m_mainWindow->show();

    return nullptr;
}
