package org.qtproject.qt5.android.bindings;

public interface NativeCalls {
    public void createNewWebView(int tag);
    public void removeWebView(int tag);
    public void moveWebView(int tag, int x, int y);
    public void resizeWebView(int tag, int w, int h);
    public void attachWebViewToMainLayout(int tag);
    public void loadUrlAtWebView(int tag, String url);
    public void loadHtmlAtWebView(int tag, String html);
}
