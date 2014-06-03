#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
    , m_webVeiw( NULL )
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

    if( m_webVeiw )
        delete m_webVeiw;
}

void MainWindow::on_pushButton_clicked()
{
    if( !m_webVeiw )
    {
        m_webVeiw = new QtCustomAndroidWebView( this );
        m_webVeiw->move( 10, 45 );
        m_webVeiw->resize( 700, 600 );
    }

    m_webVeiw->loadURL( ui->lineEdit->text() );
}
