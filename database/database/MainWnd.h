#pragma once
#include "Common.h"
//#include "mysql.h"
#include "MySQL.h"

class MainWnd : public WindowImplBase
{
public:
	//MainWnd();
	MainWnd(MySQL* pMySQL);//�����캯������������������ݿ�
	~MainWnd();

	virtual void Notify(TNotifyUI& msg);

protected:
	//WindowImplBase�ṩ�������麯��

	//xml�ļ���Ӧ��Ŀ¼
	virtual CDuiString  GetSkinFolder();
	
	//xml�ļ�����
	virtual CDuiString GetSkinFile();

	//����������֣���ע�ᴰ��ʱ�����ṩ(�Լ����ù�)
	virtual LPCTSTR GetWindowClassName() const;

	void SelectEmployeeInfo();

	void DeleteEmployeeInfo();

	void InsertEmployeeInfo();
private:
	MySQL* m_pMySQL;
};