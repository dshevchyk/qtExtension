#ifndef ADMOBIMPL_H
#define ADMOBIMPL_H

#include <QtGlobal>

#ifdef Q_OS_ANDROID
#include <QAndroidJniObject>
#endif

class AdMobImpl
{
public:
    AdMobImpl();
    ~AdMobImpl();
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setVisibility(bool visible);

#ifdef Q_OS_ANDROID
private:
    QAndroidJniObject internal;
#endif
};

#endif // ADMOBIMPL_H
