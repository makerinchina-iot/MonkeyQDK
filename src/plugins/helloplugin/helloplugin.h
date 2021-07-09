#ifndef HELLOPLUGIN_H
#define HELLOPLUGIN_H

#include <QObject>
#include <hello_global.h>
#include <extensionsystem/iplugin.h>

class HelloPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "monkeyqdk.qtc.plugin" FILE "helloplugin.json")
public:
    HelloPlugin();
    ~HelloPlugin();

private:
    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;

signals:

};

#endif // HELLOPLUGIN_H
