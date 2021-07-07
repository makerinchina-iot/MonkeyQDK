#ifndef SYSTEMSETTINGS_H
#define SYSTEMSETTINGS_H

#include <QObject>
#include <coreplugin/dialogs/ioptionspage.h>

class SystemSettings : public Core::IOptionsPage
{
public:
    SystemSettings();
};

#endif // SYSTEMSETTINGS_H
