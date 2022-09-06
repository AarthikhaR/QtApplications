#ifndef ROCKWIDGET_H
#define ROCKWIDGET_H

#include <QObject>
#include <QWidget>

class RockWidget : public QWidget
{
public:
    explicit RockWidget(QWidget *parent = nullptr);

signals:
    void buttonClicked();

public slots:

private slots:
    void click();

private:
    QSize sizeHint() const override;
};

#endif // ROCKWIDGET_H
