#ifndef QTEXTENSION_PLUGIN_H
#define QTEXTENSION_PLUGIN_H

#include <QQmlExtensionPlugin>

class QtExtensionPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // QTEXTENSION_PLUGIN_H
