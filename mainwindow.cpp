#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi(this);

    m_webVeiw = new QtCustomAndroidWebView( this );
    m_webVeiw->move( 10, 30 );
    m_webVeiw->resize( 300, 200 );
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_webVeiw;
}

void MainWindow::on_pushButton_clicked()
{
    m_webVeiw->loadURL( ui->lineEdit->text() );
}
