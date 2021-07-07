#include "fancypage.h"

namespace Core {

FancyPage::FancyPage(QObject *parent) : QObject(parent),
    m_pageButton(new QPushButton),
    m_pageWidget(nullptr)
{
    m_pageButton->setCheckable(true);
}

QPushButton *Core::FancyPage::pageButton()
{
    return m_pageButton;
}

QWidget *Core::FancyPage::pageWidget()
{
    return m_pageWidget;
}

void Core::FancyPage::setButtonName(const QString &text)
{
    m_pageButton->setText(text);

    m_pageButton->setObjectName(text);
}

void Core::FancyPage::setWidget(QWidget *widget)
{
    m_pageWidget = widget;
}

}
