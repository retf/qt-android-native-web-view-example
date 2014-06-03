#pragma once

#include <jni.h>
#include <QtAndroidExtras/QtAndroidExtras>
#include <QtCore/QString>

class CAndroidNativeCallsSender
{
public:
    CAndroidNativeCallsSender();
    ~CAndroidNativeCallsSender();

    void createNewWebView( int id ) const;
    void removeWebView( int id ) const;
    void attachWebViewToMainLayout( int id ) const;
    void moveWebView( int id, int x, int y ) const;
    void resizeWebView( int id, int w, int h ) const;
    void loadUrlAtWebView( int id, QString const& url ) const;
    void loadHtmlAtWebView( int id, QString const& html ) const;

protected:
    jmethodID m_createNewWebViewMID;
    jmethodID m_removeWebViewMID;
    jmethodID m_attachWebViewToMainLayoutMID;
    jmethodID m_moveWebViewMID;
    jmethodID m_resizeWebViewMID;
    jmethodID m_loadUrlAtWebViewMID;
    jmethodID m_loadHtmlAtWebViewMID;

    jobject m_objectRef;
};
