#include "serialsettings.h"

#include "ui_SerialSettingsWidget.h"

class SerialSettingsWidget : public Core::IOptionsPageWidget
{
public:
    SerialSettingsWidget() {
        m_ui.setupUi(this);


    }

    void apply() override;

private:
    Ui::SerialSettingsWidget m_ui;
};

void SerialSettingsWidget::apply()
{

}

SerialSettings::SerialSettings()
{
    setId("Serial");
    setCategory("Serial");
    setDisplayName("Serial");
    setWidgetCreator([]{return new SerialSettingsWidget;});
}

void SerialSettings::apply()
{

}

void SerialSettings::finish()
{

}
