#pragma once
#include "QVAPELib.h"

#include <QtPlugin>
QT_BEGIN_NAMESPACE
class QString;
class QMainWindow;
class QAction;
class QImage;
class IApplication;
QT_END_NAMESPACE
#define  IAppPlugin_IID "whu.rs.AppPluginT.AppPlugin/1.0"
class APPPLUGINENGINE_EXPORT IAppPlugin : public QObject
{
	Q_OBJECT
public:
	IAppPlugin(void);
	~IAppPlugin(void);

	virtual QImage Image() const  = 0;

	virtual QString Caption() const  = 0;

	virtual QString ToolTip() const  = 0;

	virtual bool Enable() const  = 0;

	virtual QString Name() const  = 0;
	
	virtual void OnCreate(IApplication *pHook) = 0;

	virtual bool IsCreate()	const  = 0;

	virtual void Connect() = 0;
	
	QAction * Tool;
public slots:
	virtual void  Click() = 0;

};
Q_DECLARE_INTERFACE(IAppPlugin, IAppPlugin_IID) 

