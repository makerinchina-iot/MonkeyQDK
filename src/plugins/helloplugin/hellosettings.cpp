#include "hellosettings.h"

#include <QCoreApplication>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "ui_HelloSettings.h"

using namespace Core;

class HelloSettingsPageWidget : public Core::IOptionsPageWidget
{
public:
    HelloSettingsPageWidget() {
        m_ui.setupUi(this);

        m_ui.comboBox->addItems(QStringList()<<"test1"<<"test2"<<"test3");

    }

    void apply() override;

private:
    Ui::HelloSettings m_ui;
};

void HelloSettingsPageWidget::apply()
{
    qDebug()<<" hello settings apply";
}

HelloSettings::HelloSettings()
{
    setId("HelloSetting");
    setDisplayName("general");
    setCategory("HelloSetting");
    setCategoryIconPath(":/image/settingscategory.png");
    setWidgetCreator([] {return new HelloSettingsPageWidget;});
}

