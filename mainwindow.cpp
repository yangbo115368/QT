#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::connectDB()
{
   QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("localhost");
   db.setPort(3306);
   db.setUserName("root");
   db.setPassword("13752118662yb");
   db.setDatabaseName("lock.db");
   if(!db.open())
   {
       //MainWindow::on_pushButton_clicked();
      // QMessageBox::warning(this,"wrong",db.lastError().text());
       qDebug()<<"not open"<<endl;
       return false;
   }
   else
   {
       qDebug()<<"open sucess"<<endl;
   }
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(QString("SELECT * FROM `lock.db`.lock"));
    //model->removeColumn(2);  //这是指不显示第几列
    ui->tableView->setModel(model);//设置模型
   //设置表头
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("IP"));
    model->setHeaderData(2, Qt::Horizontal, tr("Battary"));
    model->setHeaderData(3, Qt::Horizontal, tr("Lockstate"));
    model->setHeaderData(4, Qt::Horizontal, tr("Locklocate"));
    model->setHeaderData(5, Qt::Horizontal, tr("Dmgstate"));
    model->setHeaderData(6, Qt::Horizontal, tr("SoftV"));
    model->setHeaderData(7, Qt::Horizontal, tr("HardV"));
   //设置列自适应宽度
    QHeaderView* headerView = ui->tableView->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//是否可以编辑
}
