#include "serialpage.h"

#include "serialpagewidget.h"

SerialPage::SerialPage()
{
    setButtonName("SerialTool");
    setWidget(new SerialPageWidget);
}
