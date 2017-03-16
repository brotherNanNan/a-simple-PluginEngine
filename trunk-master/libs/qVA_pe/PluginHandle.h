#pragma once

#include "QVAPELib.h"

#include <QMap>
#include <QString>

class IApplication;
class IAppPlugin;
class QObject;
class APPPLUGINENGINE_EXPORT PluginHandle
{
public:
	PluginHandle(void);
	~PluginHandle(void);

	void AddPlugins();

	void AddPlugins(const QString & sFile, QMap<QString, IAppPlugin*> &plugins);

	void AddPlugins(QObject* plugin, QMap<QString, IAppPlugin*> &plugins);

	IAppPlugin* GetPlugin(const QString &sPluginName);

	static PluginHandle *StaticInstances();

	static void ReleaseInstances();
public:
	IApplication *m_MainApplication;

	QMap<QString, IAppPlugin*> m_AppPlugins;

	QMap<QString, IAppPlugin*> m_AppPluginInstances;
};

