#pragma once
#include "QVAPELib.h"
#include <QtPlugin>
QT_BEGIN_NAMESPACE
class QString;
class QMainWindow;
class QAction;
QT_END_NAMESPACE

class APPPLUGINENGINE_EXPORT IApplication
{
public:
	IApplication(void);
	~IApplication(void);
	
	virtual	QString Caption() const = 0;

	virtual QString Name() const = 0;

	virtual QMainWindow *MainWindow() const = 0 ;

	virtual bool IsVisible() const = 0;

	virtual void ClickTool(QAction *pAction, bool bCommandClick) const = 0;


};
Q_DECLARE_INTERFACE(IApplication,"whu.rs.AppPluginT.Application/1.0") 