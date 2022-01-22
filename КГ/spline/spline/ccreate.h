// ReVoL 2018 Primer Template
// ccreate.h
void setwf(HWND W,HFONT F){SendMessage(W,WM_SETFONT,(WPARAM)F,0);}
void setwp(HWND W,WNDPROC F){SetWindowLong(W,GWL_WNDPROC,(LONG)F);}
HWND CCreatePaintBox(HINSTANCE M,HWND P,int L,int T,int W,int H,WNDPROC F){HWND w=CreateWindow("STATIC",0,0x52810000,L,T,W,H,P,0,M,0);if(w){setwp(w,F);}return w;}
HWND CCreateStatic(HINSTANCE M,HWND P,int L,int T,int W,int H,WNDPROC F){HWND w=CreateWindow("STATIC",0,0x50000000,L,T,W,H,P,0,M,0);if(w){setwp(w,F);}return w;}
HWND CCreateLabel(HINSTANCE M,HWND P,int L,int T,int W,int H,HFONT F,const char* t){HWND w=CreateWindow("STATIC",t,0x50000000,L,T,W,H,P,0,M,0);if(W){setwf(w,F);}return w;}
HWND CCreateRadioPT(HINSTANCE M,HWND P,int L,int T,int W,int H,int id,HFONT F,const char* t){HWND w=CreateWindow("BUTTON",t,0x50015009,L,T,W,H,P,(HMENU)id,M,0);if(W){setwf(w,F);}return w; }
HWND CCreateNumber3D(HINSTANCE M,HWND P,int L,int T,int W,int H,int ID,HFONT F){HWND w=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT",0,0x50012000,L,T,W,H,P,(HMENU)ID,M,0); if(W){setwf(w,F);} return w;}
HFONT CCreateFont(HWND W,const char* n,int s){return CreateFont(-MulDiv(s,GetDeviceCaps(GetDC(W),LOGPIXELSY),72),0,0,0,0,0,0,0,RUSSIAN_CHARSET,0,0,0,0,n);}
