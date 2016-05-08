#ifndef ADMOBQML_H
#define ADMOBQML_H

#include <QQuickItem>

class AdMobImpl;
class AdMobQml : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(AdMobQml)

    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
public:
    AdMobQml(QQuickItem *parent = 0);
    ~AdMobQml();

    void setMessage(const QString &a) {
        if (a != m_message) {
            m_message = a;
            emit messageChanged();
        }
    }
    QString message() const {
        return m_message;
    }

    Q_INVOKABLE QPointF absolutePosition();
signals:
    void messageChanged();
private slots:
    void slotParentChanged();
    void slotOnXChanged();
    void slotOnYChanged();
    void slotOnWidthChanged();
    void slotOnHeightChanged();
    void slotOnVisibilityChanged();
private:
    AdMobImpl* impl_;
    QString m_message;
};

#endif // ADMOBQML_H
