#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    init();
    ui->treeWidget->move(0,0);
    resize(ui->treeWidget->size());
    connect(ui->treeWidget,&QTreeWidget::itemChanged, this, &MyWidget::treeItemChanged);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::init()
{
    ui->treeWidget->clear();                //清空原有数据
    ui->treeWidget->setHeaderHidden(true);  //隐藏表头

//    QTreeWidgetItem *group1 = new QTreeWidgetItem();
//    ui->treeWidget->addTopLevelItem(group1);
//    group1->setData(0, Qt::DisplayRole, "group1");
//    group1->setData(0, Qt::UserRole+1, "other");
//    QTreeWidgetItem *subItem11 = new QTreeWidgetItem();
//    group1->addChild(subItem11);

    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "group1");
    group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group1->setCheckState(0, Qt::Unchecked);    
    QTreeWidgetItem *subItem11 = new QTreeWidgetItem(group1);
    subItem11->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem11->setText(0, "subItem11");
    subItem11->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem12 = new QTreeWidgetItem(group1);
    subItem12->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem12->setText(0, "subItem12");
    subItem12->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem13 = new QTreeWidgetItem(group1);
    subItem13->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem13->setText(0, "subItem13");
    subItem13->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem14 = new QTreeWidgetItem(group1);
    subItem14->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem14->setText(0, "subItem14");
    subItem14->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0, "group2");
    group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group2->setCheckState(0, Qt::Unchecked);    
    QTreeWidgetItem *subItem21 = new QTreeWidgetItem(group2);
    subItem21->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem21->setText(0, "subItem21");
    subItem21->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem22 = new QTreeWidgetItem(group2);
    subItem22->setText(0, "subItem22");
    subItem22->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
    subItem22->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem23 = new QTreeWidgetItem(group2);
    subItem23->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem23->setText(0, "subItem23");
    subItem23->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem24 = new QTreeWidgetItem(group2);
    subItem24->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem24->setText(0, "subItem24");
    subItem24->setCheckState(0,Qt::Unchecked);
}

void MyWidget::updateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parent = item->parent();
    if (NULL == parent)
    {
        return;
    }

    int selectedCount = 0;
    for(int i=0; i<parent->childCount(); ++i)
    {
        if(Qt::Checked == parent->child(i)->checkState(0))
        {
            selectedCount++;
        }
    }

    if(selectedCount <= 0)
    {
        parent->setCheckState(0, Qt::Unchecked);
    }
    else if(selectedCount > 0 && selectedCount < parent->childCount())
    {
        parent->setCheckState(0, Qt::PartiallyChecked);
    }
    else if(selectedCount == parent->childCount())
    {
        parent->setCheckState(0, Qt::Checked);
    }
}

void MyWidget::treeItemChanged(QTreeWidgetItem *item, int column)
{    
    Q_UNUSED(column)
    Q_ASSERT(0 == column);

    Qt::CheckState state = item->checkState(0);
    if(Qt::Checked != state && Qt::Unchecked != state)
        return;

    int count = item->childCount();
    if (count > 0)
    {
        for (int i=0; i<count; ++i)
        {
            // 设置相同的状态，不会触发treeItemChanged信号
            item->child(i)->setCheckState(0, state);
        }
    }
    else
    {
        updateParentItem(item);
    }
}
