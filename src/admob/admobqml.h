#ifndef ADMOBQML_H
#define ADMOBQML_H

#include <QQuickItem>
class EAdSize : public QObject
{
Q_OBJECT

public:
    enum AdMobBannerSize {
        BANNER = 0,
        FULL_BANNER = 1,
        LARGE_BANNER = 2,
        LEADERBOARD = 3,
        MEDIUM_RECTANGLE = 4,
        WIDE_SKYSCRAPER = 5,
        SMART_BANNER = 6,
        UNKNOWN = -1
    };
    Q_ENUMS(AdMobBannerSize)

    static void declareQML() {
        qmlRegisterType<EAdSize>("AdSize", 1, 0, "AdSize");
    }
};


class AdMobImpl;
class AdMobQml : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(AdMobQml)

    Q_PROPERTY(int adSize READ adSize WRITE setAdSize NOTIFY adSizeChanged)
    Q_PROPERTY(QString adUnitId READ adUnitId WRITE setAdUnitId NOTIFY adUnitIdChanged)
public:
    AdMobQml(QQuickItem *parent = 0);
    ~AdMobQml();

    void setAdSize(int size);
    int adSize() const;

    void setAdUnitId(const QString &a);
    QString adUnitId() const;

    Q_INVOKABLE QPointF absolutePosition();

    static void declareQML() {
        qmlRegisterType<AdMobQml,1>("AdMobQml", 1, 0, "AdMobQml");
    }
signals:
    void adSizeChanged();
    void adUnitIdChanged();
private slots:
    void slotParentChanged();
    void slotOnXChanged();
    void slotOnYChanged();
    void slotOnWidthChanged();
    void slotOnHeightChanged();
    void slotOnVisibilityChanged();
    void slotOnAdUnitIdChanged();
    void slotOnAdSizeChanged();
private:
    AdMobImpl* impl_;
    QString adUnitId_ = "Unknown";//can only be set once
    int adSize_ = EAdSize::AdMobBannerSize::UNKNOWN;//can only be set once
};

#endif // ADMOBQML_H
