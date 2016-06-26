#ifndef QtAdMobBannerIosProtected_H
#define QtAdMobBannerIosProtected_H

#include "../admobimpl.h"

class QtAdMobBannerIosProtected
{
public:
    QtAdMobBannerIosProtected();
    ~QtAdMobBannerIosProtected();

    static void OnLoaded(AdMobImpl* handler, bool status);
    static void OnLoading(AdMobImpl* handler);
    static void OnClosed(AdMobImpl* handler);
    static void OnWillLeaveApplication(AdMobImpl* handler);
};

#endif //QtAdMobBannerIosProtected_H
