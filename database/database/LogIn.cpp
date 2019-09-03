#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "LogIn.h"
#include "MainWnd.h"
#include "CashierWnd.h"

LogInWnd::LogInWnd(MySQL* pMySQL)
:m_pMySQL(pMySQL)
{

}
LogInWnd::~LogInWnd()
{}


//xml�ļ�Ŀ¼
CDuiString LogInWnd::GetSkinFolder()
{
	return _T("");
}

//xml�ļ�������
CDuiString LogInWnd::GetSkinFile()
{
	return _T("LogInWnd.xml");
}


//����������֣���ע�ᴰ��ʱ�����ṩ(�Լ����ù�)
LPCTSTR LogInWnd::GetWindowClassName(void) const
{
	return _T("LogInWnd");
}


void LogInWnd::Notify(TNotifyUI& msg)
{
	CDuiString strName = msg.pSender->GetName();
	if (msg.sType == _T("click"))
	{
		//CDuiString strBTNName = msg.pSender->GetName();
		if (strName == _T("BTN_CLOSE"))
			PostQuitMessage(0);//Close();�رմ���
		else if (strName == _T("BTN_MIN"))
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);//��С������
		else if (strName == _T("BTN_LOGIN"))
			//MessageBox(m_hWnd, _T("LOGIN"), _T("cashier"), IDOK);
			LogIn();
	}
}

void LogInWnd::LogIn()
{
	//�ӱ༭���ȡ�û����Լ�����
	CEditUI* pEditUerName = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_NAME"));
	//CDuiString strUerName = pEditUerName->GetText();
	//CDuiString strUerName = _T("����")/*pEditUerName->GetText()*/;
	CDuiString strUerName = pEditUerName->GetText();


	CEditUI* pEditPassword = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_PASSWORD"));
	//CDuiString strUserPassword = pEditPassword->GetText();
	//CDuiString strUserPassword = _T("123")/*pEditPassword->GetText()*/;
	CDuiString strUserPassword = pEditPassword->GetText();


	if (strUerName.IsEmpty())
	{
		MessageBox(m_hWnd, _T("�������û���"), _T("cashier"), IDOK);
		return;
	}
	if (strUserPassword.IsEmpty())
	{
		MessageBox(m_hWnd, _T("�������û�����"), _T("cashier"), IDOK);
		return;
	}
	//��ѯ���ݿ⣬�����û��Ƿ����
	string strSQL("select * from employee where Name = '");
	strSQL += UnicodeToANSI(strUerName);
	strSQL += "';";

	//����ѯ�����vRet����
	vector<vector<string>> vRet = m_pMySQL->Select(strSQL);
	if (vRet.empty())
	{
		MessageBox(m_hWnd, _T("�û�������"), _T("cashier"), IDOK);
		return;
	}
	string userpassword = UnicodeToANSI(strUserPassword);
	if (userpassword != vRet[0][4])
	{
		MessageBox(m_hWnd, _T("�û��������"), _T("cashier"), IDOK);
		return;
	}

	//���ص�¼����
	ShowWindow(false);

	if (vRet[0][5] == "����Ա")
	{
		//����������(�û����ڵĻ�)
		MainWnd mainWnd(m_pMySQL);
		mainWnd.Create(NULL, _T("MainWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
		mainWnd.CenterWindow();
		mainWnd.ShowModal();
	}
	//else if (vRet[0][5] == "�ۻ�Ա")
	else
	{
		CCashierWnd cashWnd(m_pMySQL);
		cashWnd.Create(NULL, _T("CashierWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
		cashWnd.CenterWindow();
		cashWnd.ShowModal();
	}


}
















#if 0//���������һ�μ򵥲���
void LogInWnd::LogIn()
{
	//�ӱ༭���л�ȡ�û����Լ�����
	CEditUI* pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("u"));////////
	CDuiString StrUserName = pEditUserName->GetText();

	CEditUI* pEditPassword = (CEditUI*)m_PaintManager.FindControl(_T("u"));////////
	CDuiString StrUserPassword = pEditPassword->GetText();

	if (StrUserName.IsEmpty())
	{
		MessageBox(m_hWnd, _T("�������û���"), _T("cashier"), IDOK);
		return;
	}
	if (StrUserPassword.IsEmpty())
	{
		MessageBox(m_hWnd, _T("����������"), _T("cashier"), IDOK);
		return;
	}



	//��ѯ���ݿ⣬�����û��Ƿ����
	//string
	string strSQL("select * from employee where name = '");

	//ASCII UNICODE

	//strSQL += StrUserName;
	strSQL += UnicodeToANSI(StrUserName);
	strSQL += "';";

	//strSQL = "select * from employee;";������һ��
	vector<vector<string>> vRet =  m_pMySQL->Select(strSQL);
	if (vRet.empty())
	{
		MessageBox(m_hWnd, _T("�û�������"), _T("Cashier"), IDOK);
		return;
	}
	string userpassword = UnicodeToANSI(StrUserPassword);//�ж������Ƿ�ƥ��
	if(userpassword != vRet[0][4])
	{
		MessageBox(m_hWnd, _T("�û��������"), _T("Cashier"), IDOK);
		return;
	}



	//���ص�¼����
	ShowWindow(false);
	if (0)
	{
		//����������
		MainWnd mainWnd;
		mainWnd.Create(NULL, _T("MainWnd"), UI_WNDSTYLE_FRAME)
	}
}
#endif
