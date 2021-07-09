#include "helloplugin.h"

#include <QMessageBox>

#include <extensionsystem/pluginmanager.h>

#include "hellosettings.h"
#include "hellopage.h"

HelloPlugin::HelloPlugin()
{

}

HelloPlugin::~HelloPlugin()
{

}

bool HelloPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments);
    Q_UNUSED(errorString);

    //hello settings
    new HelloSettings();

    ExtensionSystem::PluginManager::addObject(new HelloPage);

    return true;
}

void HelloPlugin::extensionsInitialized()
{
}
