#ifndef COREPLUGIN_H
#define COREPLUGIN_H

#include <QObject>
#include <extensionsystem/iplugin.h>

#include <QMainWindow>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "fancytabwidget/fancytabwidget.h"

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

    QButtonGroup *m_pageButtons;
    QVBoxLayout *m_buttonLayout;
    QStackedWidget *m_pageStacks;

    FancyTabWidgetUtils::FancyTabWidget *m_fancyTabWidgt;

    static int m_tabIndex;

private slots:
    void settingsDialog();

signals:

};

#endif // COREPLUGIN_H
