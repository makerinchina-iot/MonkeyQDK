#include "fancypage.h"

namespace Core {

FancyPage::FancyPage(QObject *parent) : QObject(parent),
    m_pageWidget(nullptr)
{

}

QWidget *FancyPage::pageWidget()
{
    return m_pageWidget;
}

QString FancyPage::pageBtnName() const
{
    return m_buttonName;
}

QIcon FancyPage::pageBtnIcon() const
{
    return m_buttonIcon;
}

void FancyPage::setButtonName(const QString &text)
{
    m_buttonName = text;
}

void FancyPage::setButtonIcon(const QIcon &icon)
{
    m_buttonIcon = icon;
}

void FancyPage::setWidget(QWidget *widget)
{
    m_pageWidget = widget;
}

}
