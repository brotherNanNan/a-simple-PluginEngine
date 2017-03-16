#ifndef GEOPLUGIN_H
#define GEOPLUGIN_H

#include "QGEOPlugin.h"
#include "IAppPlugin.h"

class GEOPLUGIN_EXPORT GeoPlugin: public QObject, public IAppPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID IAppPlugin_IID)
	Q_INTERFACES(IAppPlugin)

public:
	GeoPlugin();
	~GeoPlugin();

	virtual QImage Image() const;

	virtual QString Caption() const;

	virtual QString ToolTip() const;

	virtual bool Enable() const;

	virtual QString Name() const;

	virtual void OnCreate( IApplication *pHook );

	virtual bool IsCreate() const;


public slots:
	virtual void Click();

	virtual void Connect();

private:
	IApplication *m_pApplication;
};

#endif // GEOPLUGIN_H
