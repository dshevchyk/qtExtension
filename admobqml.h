#ifndef ADMOBQML_H
#define ADMOBQML_H

#include <QQuickItem>

class AdMobQml : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(AdMobQml)

public:
    AdMobQml(QQuickItem *parent = 0);
    ~AdMobQml();
};

#endif // ADMOBQML_H
