#include "datbasesql.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

namespace Utils {

struct DatabaseSQLPrivate{
    QSqlDatabase database;
    QString error;
};

DatabaseSQL::DatabaseSQL(QObject *parent)
    : QObject(parent)
    , d(new DatabaseSQLPrivate)
{
    qDebug() << tr("Qt currently supports database drivers:")
             << QSqlDatabase::drivers();
}

DatabaseSQL::~DatabaseSQL()
{
}

bool DatabaseSQL::openSQL(const DatabaseParam &param)
{
    if("MySQL" == param.type)
        return openMySQL(param.ip,
                         param.port,
                         param.databaseName,
                         param.uesrname,
                         param.password);
    else if("SQLite" == param.type)
        return openSQLite(param.databaseName);
    d->error = tr("Unknow SQL type!");
    return false;
}

QSqlQuery DatabaseSQL::query(const QString &sql)
{
    QSqlQuery q;
    if(!q.exec(sql)){
        d->error = QString(tr("DataBase Query Error: %1 !").
                           arg(q.lastError().text()));
        return q;
    }
    return q;
}

QString DatabaseSQL::errorString() const
{
    return d->error;
}

bool DatabaseSQL::tableContains(const QString &tableName)
{
    return d->database.tables().contains(tableName);
}

bool DatabaseSQL::openMySQL(const QString &ip,
                            int port,
                            const QString &databaseName,
                            const QString &username,
                            const QString &password)
{
    if (!QSqlDatabase::drivers().contains("QMYSQL")){
        qDebug() <<tr("Unable to load database, "
                      "This program needs the MYSQL driver!");
        return false;
    }

    if(ip.isEmpty()) {
        d->error = tr("MySQL IP Empty!");
        return false;
    }
    if(port<=0 || port >65536){
        d->error = tr("MySQL Port Error!");
        return false;
    }
    if(databaseName.isEmpty()){
        d->error = tr("MySQL Database Name Empty!");
        return false;
    }
    if(username.isEmpty()){
        d->error = tr("MySQL Username Empty!");
        return false;
    }
    if(password.isEmpty()){
        d->error = tr("MySQL Password Empty!");
        return false;
    }

    d->database = QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
    d->database.setHostName(ip);
    d->database.setPort(port);                    //连接数据库端口号
    d->database.setDatabaseName(databaseName);    //连接数据库名
    d->database.setUserName(username);            //数据库用户名
    d->database.setPassword(password);            //数据库密码

    if(d->database.open()) return true;

    d->error = QString(tr("MySQL Open Error: %1 !").arg(d->database.lastError().text()));
    return false;
}

bool DatabaseSQL::openSQLite(const QString &databaseName)
{
    if (!QSqlDatabase::drivers().contains("QSQLITE")){
        qDebug() << tr("Unable to load database, "
                       "This program needs the SQLITE driver");
        return false;
    }

    if(databaseName.isEmpty()){
        d->error = tr("SQLite Database Name Empty!");
        return false;
    }
    /*---------------------------------------------------------/
     *      在navicat中把数据加密了，但是用setPassWord()无效,     /
     *      可以打开数据库，但是查询失败,                         /
     *      QT的sql库中是否无法加密sqlite，                      /
     *      只能使用第三方插件或者自己实现加密功能                 /
     *--------------------------------------------------------*/
    d->database = QSqlDatabase::addDatabase("QSQLITE");
    d->database.setDatabaseName(databaseName);
    if(d->database.open()) return true;

    d->error = QString(tr("SQLite Open Error: %1 !").
                       arg(d->database.lastError().text()));
    return false;
}

}
