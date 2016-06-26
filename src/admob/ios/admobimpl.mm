#include "../admobimpl.h"
#include "AdMobBannerIosProtected.h"

#include <GoogleMobileAds/GADBannerView.h>
#include <GoogleMobileAds/GADAdSize.h>
#include <QString>

@interface QtAdMobBannerDelegate : NSObject<GADBannerViewDelegate>

@property (nonatomic, strong) GADBannerView* bannerView;
@property (nonatomic, strong) NSMutableArray* testDevices;
@property (nonatomic, assign) AdMobImpl *handler;

- (id)initWithHandler:(AdMobImpl *)handler;
- (void)load;

@end

@implementation QtAdMobBannerDelegate

- (id)initWithHandler:(AdMobImpl *)handler
{
    self = [super init];
    if (self)
    {
        _handler = handler;
        _testDevices = [[NSMutableArray alloc] initWithArray:@[kGADSimulatorID]];
        _bannerView = [[GADBannerView alloc] initWithAdSize:kGADAdSizeBanner];
        _bannerView.delegate = self;

        UIApplication *application = [UIApplication sharedApplication];
        UIWindow *window = [[application windows] firstObject];
        UIViewController* rootViewController = [window rootViewController];
        UIView *view = rootViewController.view;

        _bannerView.rootViewController = rootViewController;
        [view addSubview:_bannerView];
    }
    return self;
}

- (void)dealloc
{
    [super dealloc];
    _handler = nil;
    [_bannerView removeFromSuperview];
    [_bannerView dealloc];
    _bannerView = nil;
}

- (void)load
{
    GADRequest *request = [GADRequest request];
    request.testDevices = _testDevices;
    [_bannerView loadRequest:request];

    QtAdMobBannerIosProtected::OnLoading(self.handler);
}

- (void)adViewDidReceiveAd:(GADBannerView *)view
{
    Q_UNUSED(view);

    QtAdMobBannerIosProtected::OnLoaded(self.handler, true);
}

- (void)adView:(GADBannerView *)view didFailToReceiveAdWithError:(GADRequestError *)error
{
    Q_UNUSED(view);
    Q_UNUSED(error);

    QtAdMobBannerIosProtected::OnLoaded(self.handler, false);
}

- (void)adViewDidDismissScreen:(GADBannerView *)bannerView
{
    Q_UNUSED(bannerView);

    QtAdMobBannerIosProtected::OnClosed(self.handler);
}

- (void)adViewWillLeaveApplication:(GADBannerView *)bannerView
{
    Q_UNUSED(bannerView);

    QtAdMobBannerIosProtected::OnWillLeaveApplication(self.handler);
}

@end


AdMobImpl::AdMobImpl()
{
    m_AdMob = [[QtAdMobBannerDelegate alloc] initWithHandler:this];
}

AdMobImpl::~AdMobImpl()
{
    m_AdMob = nil;
}

void AdMobImpl::setX(int x)
{
    CGRect frame = m_AdMob.bannerView.frame;
    frame.origin.x = x;
    m_AdMob.bannerView.frame = frame;
}

void AdMobImpl::setY(int y)
{
    CGRect frame = m_AdMob.bannerView.frame;

    CGFloat yOffset = [UIApplication sharedApplication].statusBarFrame.size.height;
    frame.origin.y = y + yOffset;
    m_AdMob.bannerView.frame = frame;
}
void AdMobImpl::setWidth(int width)
{
    CGRect frame = m_AdMob.bannerView.frame;
    frame.size.width = width;
    m_AdMob.bannerView.frame = frame;
}
void AdMobImpl::setHeight(int height)
{
    CGRect frame = m_AdMob.bannerView.frame;
    frame.size.height = height;
    m_AdMob.bannerView.frame = frame;
}

void AdMobImpl::setVisibility(bool visible)
{
    if(visible)
        m_AdMob.bannerView.hidden = NO;
    else
        m_AdMob.bannerView.hidden = YES;
}
void AdMobImpl::setAdUnitId(const QString& adUnitId)
{


    m_AdMob.bannerView.adUnitID = [NSString stringWithUTF8String:adUnitId.toUtf8().data()];
    [m_AdMob load];
}

void AdMobImpl::setAdSize(int adSize)
{
    static const int BANNER = 0;
    static const int FULL_BANNER = 1;
    static const int LARGE_BANNER = 2;
    static const int LEADERBOARD = 3;
    static const int MEDIUM_RECTANGLE = 4;
    static const int WIDE_SKYSCRAPER = 5;
    static const int SMART_BANNER = 6;

    GADAdSize newSize = kGADAdSizeBanner;
    switch (adSize)
    {
        case BANNER:
            newSize = kGADAdSizeBanner;
            break;
        case LARGE_BANNER:
            newSize = kGADAdSizeLargeBanner;
            break;
        case MEDIUM_RECTANGLE:
            newSize = kGADAdSizeMediumRectangle;
            break;
        case FULL_BANNER:
            newSize = kGADAdSizeFullBanner;
            break;
        case SMART_BANNER:
            newSize = kGADAdSizeSmartBannerLandscape;
            break;
        case WIDE_SKYSCRAPER:
            newSize = kGADAdSizeSkyscraper;
            break;
    }

    if (!CGSizeEqualToSize(m_AdMob.bannerView.adSize.size, newSize.size) ||
        m_AdMob.bannerView.adSize.flags != newSize.flags)
    {
        m_AdMob.bannerView.adSize = newSize;
    }
}
