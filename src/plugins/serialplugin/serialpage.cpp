#include "serialpage.h"

#include "serialpagewidget.h"

SerialPage::SerialPage()
{
    setButtonName("Serial");
    setButtonIcon(QIcon(":/icon/image/serialmonitor.png"));
    setWidget(new SerialPageWidget);
}
