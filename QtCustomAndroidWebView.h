#pragma once

#include <QtWidgets/QWidget>
#include <QtCore/QPoint>

#include "AndroidNativeCallsSender.h"

class QtCustomAndroidWebView : public QWidget
{
    Q_OBJECT
public:
    explicit QtCustomAndroidWebView( QWidget *parent = 0 );
    ~QtCustomAndroidWebView();

    void loadURL( QString const& url ) const;
    void loadHtmlData( QString const& data ) const;

    void move( int x, int y );
    void move( QPoint const& p );
    void resize( int w, int h );

    int androidID() const { return m_androidID; }

protected:
    static int sm_tag;
    int m_androidID;
    CAndroidNativeCallsSender m_nativeSender;

    int generateNewTag();

signals:

public slots:
};
