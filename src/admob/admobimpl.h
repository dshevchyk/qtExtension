#ifndef ADMOBIMPL_H
#define ADMOBIMPL_H

#include <QtGlobal>

#ifdef Q_OS_ANDROID
#include <QAndroidJniObject>
#endif

#if defined(__OBJC__)
@class QtAdMobBannerDelegate;
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
    void setAdUnitId(const QString& adUnitId);
    void setAdSize(int adSize);
private:
#ifdef Q_OS_ANDROID
    QAndroidJniObject internal;

#endif

#if defined(__OBJC__)
    QtAdMobBannerDelegate* m_AdMob;
#endif
};

#endif // ADMOBIMPL_H
