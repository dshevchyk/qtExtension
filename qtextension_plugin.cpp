#include "qtextension_plugin.h"
#include "admobqml.h"

#include <qqml.h>

void QtExtensionPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<AdMobQml>(uri, 1, 0, "AdMobQml");
}

