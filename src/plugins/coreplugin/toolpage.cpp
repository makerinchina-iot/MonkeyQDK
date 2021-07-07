#include "toolpage.h"

#include <QVBoxLayout>
#include <QLabel>

ToolPage::ToolPage()
{

    QWidget *toolpageWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(toolpageWidget);
    toolpageWidget->setLayout(mainLayout);
    QLabel *toollabel = new QLabel(toolpageWidget);
    toollabel->setText("Tool Page");
    QFont font("Microsoft YaHei", 10, 75);
    toollabel->setFont(font);
    toollabel->setStyleSheet("color:red;");
    toollabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(toollabel);

    setButtonName("Tool");
    setWidget(toolpageWidget);
}
