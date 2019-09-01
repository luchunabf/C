#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <tchar.h>
///////////////////////�������
//#include <WinImplBase.h>

//int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
//{
//	::MessageBox(NULL, _T("Hello World !"), NULL, NULL);
//	return 0;
//}
#pragma once
#include <UIlib.h>
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif


class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR    GetWindowClassName() const   { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile()                { return _T("duilib3.xml"); }
	virtual CDuiString GetSkinFolder()              { return _T(""); }

	virtual void  InitWindow()
	{
		CActiveXUI* pActiveXUI = static_cast<CActiveXUI*>(m_PaintManager.FindControl(_T("ActiveXDemo1")));

		if (pActiveXUI)
		{
			IWebBrowser2* pWebBrowser = NULL;

			pActiveXUI->SetDelayCreate(false);              // �൱�ڽ�����������DelayCreate���Ը�ΪFALSE����duilib�Դ���FlashDemo����Կ���������ΪTRUE             
			pActiveXUI->CreateControl(CLSID_WebBrowser);    // �൱�ڽ�����������Clsid����������{8856F961-340A-11D0-A96B-00C04FD705A2}��������CLSID_WebBrowser������뿴��Ӧ��ֵ�����<ExDisp.h>
			pActiveXUI->GetControl(IID_IWebBrowser2, (void**)&pWebBrowser);

			if (pWebBrowser != NULL)
			{
				//pWebBrowser->Navigate(L"https://code.google.com/p/duilib/",NULL,NULL,NULL,NULL);  
				pWebBrowser->Navigate(L"http://www.baidu.com/", NULL, NULL, NULL, NULL);  // ���ڹȸ�ʱ��ʱ��ǽ�����Ի��ɷ�Ӧ�����վ
				pWebBrowser->Release();
			}
		}

		//�ı������
		CProgressUI* pProgress = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("ProgressDemo1")));
		pProgress->SetValue(100);




		CDuiString str;
		CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("ListDemo1")));

		// ���List�б����ݣ�������Add(pListElement)����SetText
		for (int i = 0; i < 100; i++)
		{
			CListTextElementUI* pListElement = new CListTextElementUI;
			pListElement->SetTag(i);
			pList->Add(pListElement);

			str.Format(_T("%d"), i);
			pListElement->SetText(0, str);
			pListElement->SetText(1, _T("haha"));
		}
	}

	virtual void Notify(TNotifyUI& msg)//Notify��������Ϣ֪ͨ���������еĿؼ���Ϣ�����������л������ᾭ�����
	{
		if (msg.sType == _T("selectchanged"))
		{
			CDuiString    strName = msg.pSender->GetName();
			CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tabTest")));

			if (strName == _T("OptionDemo1"))
				pControl->SelectItem(0);
			else if (strName == _T("OptionDemo2"))
				pControl->SelectItem(1);
			else if (strName == _T("OptionDemo3"))
				pControl->SelectItem(2);
		}



		else if (msg.sType == _T("click"))//////////////////////��׽��Ϣ��������ʱ���رմ���
		{
			CDuiString strName = msg.pSender->GetName();
			//CButtonUI* pControl = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("tabTest")));
			if (strName == _T("button4"))
			{
				//pControl->;
				::CloseWindow(m_hWnd);//�رմ���
				::DestroyWindow(m_hWnd);
			}

		}

		__super::Notify(msg);
	}
};

//int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
//{
//	CPaintManagerUI::SetInstance(hInstance);
//
//	CDuiFrameWnd duiFrame;
//	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
//	duiFrame.CenterWindow();
//	duiFrame.ShowModal();
//	return 0;
//}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;


	//CDuiFrameWnd duiFrame;
	CDuiFrameWnd *pFrame = new CDuiFrameWnd;
	pFrame->Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pFrame->CenterWindow();
	pFrame->ShowModal();




	delete pFrame;
	::CoUninitialize();
	return 0;
}