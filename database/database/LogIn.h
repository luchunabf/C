#pragma once
#include "Common.h"
//#include "mysql.h"
#include "MySQL.h"

class LogInWnd : public WindowImplBase
{
public:
	//LogInWnd();
	LogInWnd(MySQL* pMySQL);//��ʽ�������в������캯��
	~LogInWnd();

	//��Ϣ��Ӧ
	virtual void Notify(TNotifyUI& msg);

	void LogIn();

protected:
	//WindowImplBase�ṩ�������麯��

	//xml�ļ���Ӧ��Ŀ¼
	virtual CDuiString  GetSkinFolder();

	//xml�ļ�����
	virtual CDuiString GetSkinFile();

	//����������֣���ע�ᴰ��ʱ�����ṩ(�Լ����ù�)
	virtual LPCTSTR GetWindowClassName() const;

private:
	MySQL* m_pMySQL;
};