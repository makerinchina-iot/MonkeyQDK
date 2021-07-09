#ifndef HELLOSETTINGS_H
#define HELLOSETTINGS_H

#include "hello_global.h"
#include <coreplugin/dialogs/ioptionspage.h>

class HELLOPLUGIN_EXPORT HelloSettings : public Core::IOptionsPage
{
public:
    HelloSettings();
};

#endif // HELLOSETTINGS_H
