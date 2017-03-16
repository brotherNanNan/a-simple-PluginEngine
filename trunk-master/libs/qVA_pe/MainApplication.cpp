#include "MainApplication.h"
#include <QString>
#include <QAction>

MainApplication::MainApplication(QMainWindow *pWindow)
	:m_pMainWindow(pWindow),m_AppCaption("²å¼þ²âÊÔÏµÍ³"), 
	m_AppName("AppPluginTest"),	m_bIsVisible(true)
{

}

MainApplication::MainApplication()
{

}

MainApplication::~MainApplication(void)
{
}

void MainApplication::ClickTool( QAction *pAction, bool bCommandClick ) const
{
	if (pAction)
	{
		pAction->trigger();
	}
}

QString MainApplication::Caption() const
{
	return m_AppCaption;
}

QString MainApplication::Name() const
{
	return m_AppName;
}

QMainWindow * MainApplication::MainWindow() const
{
	return m_pMainWindow;
}

bool MainApplication::IsVisible() const
{
	return m_bIsVisible;
}