#include "../admobimpl.h"
#include <QtAndroid>
const char * className = "org/qtproject/example/AdMob/AdMobView";
//const char * className = "org/qtproject/example/MainActivity";
AdMobImpl::AdMobImpl()
{
    qDebug("AdMobImpl constructor");
    internal = QAndroidJniObject(className,
                                 "(Landroid/app/Activity;)V",
                                 QtAndroid::androidActivity().object<jobject>());//QAndroidJniObject::callStaticMethod<void> (factoryClassName,
                                                     //  "fibonacci");
}
AdMobImpl::~AdMobImpl()
{
    internal.callMethod<void>("removeFromParent");
}

void AdMobImpl::setX(int x)
{
    internal.callMethod<void>("setX", "(I)V", x);
}

void AdMobImpl::setY(int y)
{
    internal.callMethod<void>("setY", "(I)V", y);
}
void AdMobImpl::setWidth(int width)
{
    internal.callMethod<void>("setWidth", "(I)V", width);
}
void AdMobImpl::setHeight(int height)
{
    internal.callMethod<void>("setHeight", "(I)V", height);
}

void AdMobImpl::setVisibility(bool visible)
{
    internal.callMethod<void>("setVisibility", "(B)V", visible);
}
void AdMobImpl::setAdUnitId(const QString& adUnitId)
{

    qDebug(adUnitId.toStdString().c_str());
    jstring jAdUnitId = QAndroidJniObject::fromString(adUnitId).object<jstring>();
    internal.callMethod<void>("setAdUnitId", "(Ljava/lang/String;)V", QAndroidJniObject::fromString(adUnitId).object<jstring>());

}

void AdMobImpl::setAdSize(int adSize)
{
    qDebug("c++ setAdSize called");
    internal.callMethod<void>("setAdSize", "(I)V", adSize);
}
