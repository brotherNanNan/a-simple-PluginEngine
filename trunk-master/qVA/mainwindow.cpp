#include "mainwindow.h"
#include <QMenu>
#include <QToolBar>
#include <QtCore/QMap>
#include "ui_mainwindow.h"
#include "PluginHandle.h"
#include "IAppPlugin.h"
#include "MainApplication.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::Init()
{
	if (!m_pApp)
	{
		m_pApp = new MainApplication(this);
	}

	// 插件管理
	PluginHandle * pluginHandle = PluginHandle::StaticInstances();
	if (!pluginHandle)
	{
		return false;
	}

	pluginHandle->m_MainApplication = m_pApp;

	// 添加所有插件
	pluginHandle->AddPlugins();

	QMap<QString, IAppPlugin*> &AppPlugins = pluginHandle->m_AppPlugins;

	if (AppPlugins.count() == 0)
	{
		return false;
	}

	// 测试，后期可根据xml进行配置
	QMenuBar * menuBar = this->menuBar();
	QMenu * menu = new QMenu("Plugin", menuBar);
	menuBar->addMenu(menu);
	for (QMap<QString, IAppPlugin*>::iterator it = AppPlugins.begin(); it != AppPlugins.end(); ++it)
	{
		QAction *action = menu->addAction(it.value()->Caption());
		action->setObjectName(it.value()->Name());
		action->setEnabled(true);
		it.value()->Tool = action;
		// 设置完需要连接
		it.value()->Connect();
	}
	return true;
}
