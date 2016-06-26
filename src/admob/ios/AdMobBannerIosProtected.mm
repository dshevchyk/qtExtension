#include "AdMobBannerIosProtected.h"


QtAdMobBannerIosProtected::QtAdMobBannerIosProtected() {}
QtAdMobBannerIosProtected::~QtAdMobBannerIosProtected() {}

void QtAdMobBannerIosProtected::OnLoaded(AdMobImpl* handler, bool status)
{
    if (!handler)
    {
        return;
    }

    //handler->OnStatusChanged(status);
}

void QtAdMobBannerIosProtected::OnLoading(AdMobImpl* handler)
{
    if (!handler)
    {
        return;
    }

    //handler->OnLoading();
}

void QtAdMobBannerIosProtected::OnClosed(AdMobImpl *handler)
{
    if (!handler)
    {
        return;
    }

    //handler->OnClosed();
}

void QtAdMobBannerIosProtected::OnWillLeaveApplication(AdMobImpl* handler)
{
    if (!handler)
    {
        return;
    }

    //handler->OnClicked();
}
