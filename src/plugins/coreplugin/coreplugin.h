#ifndef COREPLUGIN_H
#define COREPLUGIN_H

#include <QObject>
#include <extensionsystem/iplugin.h>

#include <QMainWindow>

class CorePlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "monkeyqdk.qtc.plugin" FILE "coreplugin.json")
public:
    explicit CorePlugin(){}

    ~CorePlugin(){}

    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;
    QObject* remoteCommand(const QStringList &, const QString &, const QStringList &) override;

private:
    QScopedPointer<QMainWindow> m_mainWindow;

private slots:
    void settingsDialog();

signals:

};

#endif // COREPLUGIN_H
