#include "serialplugin.h"

#include "serialsettings.h"
#include "serialpage.h"

SerialPlugin::SerialPlugin()
{

}

bool SerialPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments);
    Q_UNUSED(errorString);

    new SerialSettings();

    ExtensionSystem::PluginManager::addObject(new SerialPage);

    return true;
}

void SerialPlugin::extensionsInitialized()
{

}
