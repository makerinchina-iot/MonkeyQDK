#ifndef FANCYPAGE_H
#define FANCYPAGE_H

#include <QObject>

#include "core_global.h"

#include <QPushButton>

namespace Core {

class CORE_EXPORT FancyPage : public QObject
{
    Q_OBJECT
public:
    explicit FancyPage(QObject *parent = nullptr);

    QWidget *pageWidget();
    QString pageBtnName() const;
    QIcon   pageBtnIcon() const;

private:
    QString m_buttonName;
    QWidget *m_pageWidget;
    QIcon m_buttonIcon;

protected:
    void setButtonName(const QString &text);
    void setButtonIcon(const QIcon &icon);
    void setWidget(QWidget *widget);

signals:

};

}

#endif // FANCYPAGE_H
