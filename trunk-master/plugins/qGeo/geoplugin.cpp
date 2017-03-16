#pragma once
#include "geoplugin.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

GeoPlugin::GeoPlugin()
{
	m_pApplication = NULL;
}

GeoPlugin::~GeoPlugin()
{

}

QImage GeoPlugin::Image() const
{
	return QImage();
}

QString GeoPlugin::Caption() const
{
	return QString("GeoPlugin plugin");
}

QString GeoPlugin::ToolTip() const
{
	return QString("GeoPlugin plugin");
}

bool GeoPlugin::Enable() const
{
	return true;
}

QString GeoPlugin::Name() const
{
	return QString("GeoPlugin");
}

void GeoPlugin::OnCreate( IApplication *pHook )
{
	m_pApplication = pHook;
}

bool GeoPlugin::IsCreate() const
{
	return  Tool != NULL;
}

void GeoPlugin::Connect()
{
	if (Tool)
	{
		QObject * pOject = (QObject *)Tool;
		QObject::connect(pOject, SIGNAL(triggered()), this, SLOT(Click()));
	}
}

void GeoPlugin::Click()
{
	QMessageBox::information(NULL, tr("Test"),tr("Do you really want to quit the project?"));
}




