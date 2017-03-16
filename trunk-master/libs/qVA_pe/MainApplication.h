#pragma once
#include "QVAPELib.h"

#include <QtPlugin>
QT_BEGIN_NAMESPACE
class QString;
class QMainWindow;
class QAction;
QT_END_NAMESPACE
#include "IApplication.h"
#include <QMap>
#include <QMenu>
#include <QToolBar>

class APPPLUGINENGINE_EXPORT MainApplication : public QObject, public IApplication
{
	Q_OBJECT
	Q_INTERFACES(IApplication)
public:
	MainApplication();
	MainApplication(QMainWindow *pWindow);

	~MainApplication(void);

	virtual void ClickTool( QAction *pAction, bool bCommandClick ) const;

	virtual QString Caption() const;

	virtual QString Name() const;

	virtual QMainWindow * MainWindow() const;

	virtual bool IsVisible() const;

protected: 
	QMainWindow *   m_pMainWindow;
	QString         m_AppCaption;
	QString			m_AppName;
	bool			m_bIsVisible;

	QMap<QString, QMenu*>      m_Menus;
	QMap<QString, QToolBar*>   m_ToolBars;
};