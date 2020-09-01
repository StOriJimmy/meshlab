/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "interfaces.h"
//#include "scriptsyntax.h"

#include<QMap>
#include<QObject>

/**
\brief This class provides the basic tools for managing all the plugins. It is used by both meshlab and meshlab server.
*/
class PluginManager
{
public:
    PluginManager();
    ~PluginManager();
    enum TypeIO{IMPORT,EXPORT};
	void loadPlugins(RichParameterList& defaultGlobal);
	void loadPlugins(RichParameterList& defaultGlobal, const QDir& pluginsDirectory);
    QString pluginsCode() const;

    int numberIOPlugins() const;
    inline QVector<MeshFilterInterface*>& meshFilterPlugins()  {return meshFilterPlug;}
    inline QVector<MeshRenderInterface*>& meshRenderPlugins()  {return meshRenderPlug;}
    inline QVector<MeshDecorateInterface*>& meshDecoratePlugins()  {return meshDecoratePlug;}
    inline QVector<MeshEditInterfaceFactory*>& meshEditFactoryPlugins()  {return meshEditInterfacePlug;}

    static QString getDefaultPluginDirPath();
    static QString getBaseDirPath();

    QMap<QString,RichParameterList> generateFilterParameterMap();

    MeshDecorateInterface* getDecoratorInterfaceByName(const QString& name);


    QMap<QString, QAction*> actionFilterMap;
    QMap<QString, MeshFilterInterface*> stringFilterMap;
    QMap<QString,MeshIOInterface*> allKnowInputFormats;
    QMap<QString,MeshIOInterface*> allKnowOutputFormats;
    QStringList inpFilters;
    QStringList outFilters;

    QVector<MeshIOInterface*> meshIOPlug;
    QVector<MeshFilterInterface*> meshFilterPlug;
    QVector<MeshRenderInterface*> meshRenderPlug;
    QVector<MeshDecorateInterface*> meshDecoratePlug;
    QVector<MeshEditInterfaceFactory*> meshEditInterfacePlug;
    QVector<QAction *> editActionList;
    QVector<QAction *> decoratorActionList;
    // Used for unique destruction - this "owns" all IO, Filter, Render, and Decorate plugins
    QVector<MeshCommonInterface *> ownerPlug;

    QStringList pluginsLoaded;

    static QString osDependentFileBaseName(const QString& plname);
    static QString osIndependentPluginName(const QString& plname);

private:
    QDir pluginsDir;


    void knownIOFormats();
};

#endif // PLUGINMANAGER_H
