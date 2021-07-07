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

    QPushButton *pageButton();
    QWidget *pageWidget();

private:
    QPushButton *m_pageButton;
    QWidget *m_pageWidget;

protected:
    void setButtonName(const QString &text);
    void setWidget(QWidget *widget);

signals:

};

}

#endif // FANCYPAGE_H
