#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTreeWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

    void init();
    void updateParentItem(QTreeWidgetItem *item);

public slots:
    void treeItemChanged(QTreeWidgetItem *item, int column);

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
