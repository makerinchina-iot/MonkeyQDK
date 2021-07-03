
#include <QApplication>
#include <QDir>

#include <QDebug>

#include <extensionsystem/pluginmanager.h>
#include <extensionsystem/pluginspec.h>
#include <extensionsystem/iplugin.h>

int main(int argc, char *argv[])
{

    QApplication a(argc,argv);

//    QDir::setCurrent(a.applicationDirPath());

    a.setApplicationName("appName");
    a.setApplicationDisplayName("appDisname");
    a.setDesktopFileName("deskName");
    a.setApplicationVersion("0.01");
    a.setOrganizationDomain("com.makerinchina.cn");
    a.setOrganizationName("makerinchina");

    using namespace ExtensionSystem;

    //plugin mange
    PluginManager pluginManger;

    //plugin IID, only Plugins with this IID are loaded
    PluginManager::setPluginIID(QLatin1String("monkeyqdk.qtc.plugin"));

    //plugin path
    QStringList pluginPath;
    pluginPath<<a.applicationDirPath()+"/plugins";

    qDebug()<<"plugin path:"<<a.applicationDirPath()+"/plugins";
    pluginManger.setPluginPaths(pluginPath);

    //load
    pluginManger.loadPlugins();

    //shutdown when app exit
    QObject::connect(&a,&QApplication::aboutToQuit,&pluginManger,&PluginManager::shutdown);

    //coreplugin
    const QVector<PluginSpec*> plugins = pluginManger.plugins();
    PluginSpec *corespec = nullptr;
    //find corespec
    qDebug()<<__FILE__<<" at line "<<__LINE__<<" :"<<"find core plugin";
    for(PluginSpec* spec: plugins){

        qDebug()<<__FILE__<<" at line "<<__LINE__<<" :"<<"spec for plugin name "<<spec->name();

        if(spec->name() == QLatin1String("CorePlugin")){
            corespec = spec;
            break;
        }
    }

    //load coreplugin
    if(corespec){
        corespec->plugin()->remoteCommand(QStringList(),QString(),QStringList());
    }else{

        //not found core plugin
        qDebug()<<__FILE__<<" at line "<<__LINE__<<" :"<<"no corePlugin found,exit.";
        pluginManger.shutdown();

        a.quit();
        return -1;
    }

    int ret = a.exec();

    return ret;
}
