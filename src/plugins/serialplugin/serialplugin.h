#ifndef SERIALPLUGIN_H
#define SERIALPLUGIN_H

#include <extensionsystem/iplugin.h>
#include <extensionsystem/pluginmanager.h>
#include "serial_global.h"

class SerialPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "monkeyqdk.qtc.plugin" FILE "serialplugin.json")

public:
    SerialPlugin();

private:
    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;
};

#endif // SERIALPLUGIN_H
