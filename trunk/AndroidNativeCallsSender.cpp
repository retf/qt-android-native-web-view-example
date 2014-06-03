#include "AndroidNativeCallsSender.h"

//-----------------------------------------------------------------------------
CAndroidNativeCallsSender::CAndroidNativeCallsSender()
{
    QAndroidJniEnvironment jniEnv;
    QAndroidJniObject qObjAct = QAndroidJniObject::callStaticObjectMethod( "org/qtproject/qt5/android/QtNative",
                                                                           "activity",
                                                                           "()Landroid/app/Activity;" );
    jobject objAct = qObjAct.object<jobject>();
    m_objectRef = jniEnv->NewGlobalRef( objAct );
    jclass cls = jniEnv->GetObjectClass( objAct );
    if( cls )
    {
        m_createNewWebViewMID = jniEnv->GetMethodID( cls, "createNewWebView", "(I)V" );
        m_removeWebViewMID = jniEnv->GetMethodID( cls, "removeWebView", "(I)V" );
        m_attachWebViewToMainLayoutMID = jniEnv->GetMethodID( cls, "attachWebViewToMainLayout", "(I)V" );
        m_moveWebViewMID = jniEnv->GetMethodID( cls, "moveWebView", "(III)V" );
        m_resizeWebViewMID = jniEnv->GetMethodID( cls, "resizeWebView", "(III)V" );
        m_loadUrlAtWebViewMID = jniEnv->GetMethodID( cls, "loadUrlAtWebView", "(ILjava/lang/String;)V" );
        m_loadHtmlAtWebViewMID = jniEnv->GetMethodID( cls, "loadHtmlAtWebView", "(ILjava/lang/String;)V" );
    }
}

//-----------------------------------------------------------------------------
CAndroidNativeCallsSender::~CAndroidNativeCallsSender()
{
    if( m_objectRef != NULL )
    {
        QAndroidJniEnvironment jniEnv;
        jniEnv->DeleteGlobalRef( m_objectRef );
    }
}

//-----------------------------------------------------------------------------
void CAndroidNativeCallsSender::createNewWebView( int id ) const
{
    if( m_createNewWebViewMID )
    {
        QAndroidJniEnvironment jniEnv;
        jniEnv->CallVoidMethod( m_objectRef, m_createNewWebViewMID, id );
    }
}

//-----------------------------------------------------------------------------
void CAndroidNativeCallsSender::removeWebView( int id ) const
{
    if( m_removeWebViewMID )
    {
        QAndroidJniEnvironment jniEnv;
        jniEnv->CallVoidMethod( m_objectRef, m_removeWebViewMID, id );
    }
}

//-----------------------------------------------------------------------------
void CAndroidNativeCallsSender::attachWebViewToMainLayout( int id ) const
{
    if( m_attachWebViewToMainLayoutMID )
    {
        QAndroidJniEnvironment jniEnv;
        jniEnv->CallVoidMethod( m_objectRef, m_attachWebViewToMainLayoutMID, id );
    }
}

//-----------------------------------------------------------------------------
void CAndroidNativeCallsSender::moveWebView( int id, int x, int y ) const
{
    if( m_moveWebViewMID )
    {
        QAndroidJniEnvironment jniEnv;
        jniEnv->CallVoidMethod( m_objectRef, m_moveWebViewMID, id, x, y );
    }
}

//-----------------------------------------------------------------------------
void CAndroidNativeCallsSender::resizeWebView( int id, int w, int h ) const
{
    if( m_resizeWebViewMID )
    {
        QAndroidJniEnvironment jniEnv;
        jniEnv->CallVoidMethod( m_objectRef, m_resizeWebViewMID, id, w, h );
    }
}

//-----------------------------------------------------------------------------
void CAndroidNativeCallsSender::loadUrlAtWebView( int id, QString const& url ) const
{
    if( m_loadUrlAtWebViewMID )
    {
        QAndroidJniEnvironment jniEnv;
        jstring jurl = jniEnv->NewStringUTF( url.toUtf8().constData() );
        jniEnv->CallVoidMethod( m_objectRef,
                                m_loadUrlAtWebViewMID,
                                id,
                                jurl );
        jniEnv->DeleteLocalRef( jurl );
    }
}

//-----------------------------------------------------------------------------
void CAndroidNativeCallsSender::loadHtmlAtWebView( int id, QString const& html ) const
{
    if( m_loadUrlAtWebViewMID )
    {
        QAndroidJniEnvironment jniEnv;
        jstring jhtml = jniEnv->NewStringUTF( html.toUtf8().constData() );
        jniEnv->CallVoidMethod( m_objectRef,
                                m_loadHtmlAtWebViewMID,
                                id,
                                jhtml );
        jniEnv->DeleteLocalRef( jhtml );
    }
}
