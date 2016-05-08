#include "admobqml.h"
#include "admobimpl.h"

AdMobQml::AdMobQml(QQuickItem *parent):
    QQuickItem(parent),
    impl_(new AdMobImpl())
{
    connect(this, SIGNAL(parentChanged(QQuickItem *)), this, SLOT(slotParentChanged()));
    connect(this, SIGNAL(widthChanged()), this, SLOT(slotOnWidthChanged()));
    connect(this, SIGNAL(heightChanged()), this, SLOT(slotOnHeightChanged()));
    connect(this, SIGNAL(visibleChanged()), this, SLOT(slotOnVisibilityChanged()));
    connect(this, SIGNAL(adUnitIdChanged()), this, SLOT(slotOnAdUnitIdChanged()));
    connect(this, SIGNAL(adSizeChanged()), this, SLOT(slotOnAdSizeChanged()));

    //manual update
    slotOnWidthChanged();
    slotOnHeightChanged();
    slotOnVisibilityChanged();
}

AdMobQml::~AdMobQml()
{
    delete impl_;
}

//can only be set once
void AdMobQml::setAdSize(int size) {
    if (size != adSize_) {
        adSize_ = size;
        emit adSizeChanged();
    }
}
int AdMobQml::adSize() const {
    return adSize_;
}

//can only be set once
void AdMobQml::setAdUnitId(const QString &a) {
    if (a != adUnitId_) {
        adUnitId_ = a;
        emit adUnitIdChanged();
    }
}
QString AdMobQml::adUnitId() const {
    return adUnitId_;
}
QPointF AdMobQml::absolutePosition() {
        QPointF p(0, 0);
        QQuickItem * item = this;
        while (item != nullptr) { // absolute position relative to _rootUI
            p += item->position();
            item = item->parentItem();
        }
        return p;
    }
void AdMobQml::slotParentChanged()
{

    qDebug("AdMobQml::slotParentChanged()");
    disconnect(this, SLOT(slotOnXChanged()));
    disconnect(this, SLOT(slotOnYChanged()));

    QQuickItem * item = this;
    while (item != nullptr) { // absolute position relative to _rootUI
        connect(item, SIGNAL(xChanged()), this, SLOT(slotOnXChanged()));
        connect(item, SIGNAL(yChanged()), this, SLOT(slotOnYChanged()));
        item = item->parentItem();
    }
    slotOnXChanged();
    slotOnYChanged();
    slotOnVisibilityChanged();
}

void AdMobQml::slotOnXChanged()
{
    auto position = absolutePosition();
    impl_->setX((int)position.x());
}

void AdMobQml::slotOnYChanged()
{
    auto position = absolutePosition();
    impl_->setY((int)position.y());
}

void AdMobQml::slotOnWidthChanged()
{
    impl_->setWidth((int)width());
}

void AdMobQml::slotOnHeightChanged()
{
    impl_->setHeight((int)height());
}

void AdMobQml::slotOnVisibilityChanged()
{
    qDebug("slotOnVisibilityChanged");
    if(this->parentItem())
        impl_->setVisibility(isVisible());
    else
        impl_->setVisibility(false);
}
void AdMobQml::slotOnAdUnitIdChanged()
{

    qDebug("slotOnAdUnitIdChanged");
    qDebug(adUnitId_.toStdString().c_str());
    impl_->setAdUnitId(adUnitId_);
}

void AdMobQml::slotOnAdSizeChanged()
{
    impl_->setAdSize(adSize_);

}
