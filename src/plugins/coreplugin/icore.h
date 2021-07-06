#ifndef ICORE_H
#define ICORE_H

#include <QObject>
#include <core_global.h>

class CORE_EXPORT ICore : public QObject
{
    Q_OBJECT
public:
    explicit ICore(QObject *parent = nullptr);

    ~ICore();
signals:

};

#endif // ICORE_H
