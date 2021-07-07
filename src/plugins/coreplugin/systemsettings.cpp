#include "systemsettings.h"

#include "ui_SystemSettings.h"

#include <QDebug>

using namespace Core;

class SystemSettingsWidget : public Core::IOptionsPageWidget
{
public:
    SystemSettingsWidget() {
        m_ui.setupUi(this);
        m_ui.comboBox->addItems(QStringList()<<"set1"<<"set2"<<"set3");
    }

    void apply() override;

private:
    Ui::SystemSettings m_ui;
};

void SystemSettingsWidget::apply()
{
    qDebug()<<" system settings apply";
}

SystemSettings::SystemSettings()
{
    setId("SystemSetting");
    setCategory("System");
    setDisplayName("SystemSetting");
    setWidgetCreator([] {return new SystemSettingsWidget;});
}
