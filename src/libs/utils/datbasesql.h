#ifndef DATBASESQL_H
#define DATBASESQL_H

#include "utils_global.h"

#include <QObject>
#include <QSqlQuery>

namespace Utils {

struct UTILS_EXPORT DatabaseParam{
    QString type = "MySQL";     //"SQLite"
    QString ip = "127.0.0.1";
    int port = 3306;
    QString databaseName;
    QString uesrname;
    QString password;
};

struct DatabaseSQLPrivate;
class UTILS_EXPORT DatabaseSQL : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseSQL(QObject *parent = nullptr);
    ~DatabaseSQL();

    bool openSQL(const DatabaseParam&);
    QSqlQuery query(const QString &sql);
    QString errorString() const;

    bool tableContains(const QString &tableName);

private:
    bool openMySQL(const QString &ip,
                   int port,
                   const QString &databaseName,
                   const QString &username,
                   const QString &password);
    bool openSQLite(const QString &databaseName);

    QScopedPointer<DatabaseSQLPrivate> d;
};

}

#endif // DATBASESQL_H
