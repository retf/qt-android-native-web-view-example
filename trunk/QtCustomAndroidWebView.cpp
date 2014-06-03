#include "QtCustomAndroidWebView.h"

//#include <QtWidgets/QLayout>

//-----------------------------------------------------------------------------
int QtCustomAndroidWebView::sm_tag = 0;

//-----------------------------------------------------------------------------
QtCustomAndroidWebView::QtCustomAndroidWebView( QWidget *parent )
    : QWidget( parent )
    , m_androidID( generateNewTag() )
{
//    if( parent && parent->layout() )
//        parent->layout()->addWidget( this );

    m_nativeSender.createNewWebView( androidID() );
    m_nativeSender.attachWebViewToMainLayout( androidID() );
}

//-----------------------------------------------------------------------------
QtCustomAndroidWebView::~QtCustomAndroidWebView()
{
    m_nativeSender.removeWebView( androidID() );
}

//-----------------------------------------------------------------------------
void QtCustomAndroidWebView::loadURL( QString const& url ) const
{
    m_nativeSender.loadUrlAtWebView( androidID(), url );
}

//-----------------------------------------------------------------------------
void QtCustomAndroidWebView::loadHtmlData( QString const& data ) const
{
    m_nativeSender.loadHtmlAtWebView( androidID(), data );
}

//-----------------------------------------------------------------------------
void QtCustomAndroidWebView::move( int x, int y )
{
    QWidget::move( x, y );
    m_nativeSender.moveWebView( androidID(), x, y );
}

//-----------------------------------------------------------------------------
void QtCustomAndroidWebView::move( QPoint const& p )
{
    QtCustomAndroidWebView::move( p.x(), p.y() );
}

//-----------------------------------------------------------------------------
void QtCustomAndroidWebView::resize( int w, int h )
{
    QWidget::resize( w, h );
    m_nativeSender.resizeWebView( androidID(), w, h );
}

//-----------------------------------------------------------------------------
int QtCustomAndroidWebView::generateNewTag()
{
    sm_tag++;
    return sm_tag;
}
