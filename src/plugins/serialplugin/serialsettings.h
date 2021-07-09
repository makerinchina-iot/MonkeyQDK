#ifndef SERIALSETTINGS_H
#define SERIALSETTINGS_H

#include <coreplugin/dialogs/ioptionspage.h>

class SerialSettings : public Core::IOptionsPage
{
public:
    SerialSettings();

    void apply() override;
    void finish() override;
};

#endif // SERIALSETTINGS_H
