#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "MainWnd.h"

//�����캯������������������ݿ�
//��ʽ�������캯��
//MainWnd::MainWnd(){}
MainWnd::MainWnd(MySQL* pMySQL)
:m_pMySQL(pMySQL)
{

}
MainWnd::~MainWnd()
{

}


//WindowImplBase�ṩ�������麯��

//xml�ļ���Ӧ��Ŀ¼
 CDuiString MainWnd::GetSkinFolder()
{
	 return (_T(""));
}

 //xml�ļ�����
 CDuiString MainWnd::GetSkinFile()
 {
	 return (_T("MainWnd - ����.xml"));
	 //return (_T("MainWnd.xml"));
	 //return (_T("CashierManage.xml"));
 }

 //����������֣���ע�ᴰ��ʱ�����ṩ(�Լ����ù�)
 LPCTSTR MainWnd::GetWindowClassName(void) const
 {
	 return (_T("MainWnd"));
 }




void MainWnd::Notify(TNotifyUI& msg)//Ա������
{
	CDuiString strName = msg.pSender->GetName();
	if (msg.sType == _T("click"))
	{
		//CDuiString strBTNName = msg.pSender->GetName();
		if (strName == _T("BTN_CLOSE"))
			PostQuitMessage(0);//Close();�رմ���
		else if (strName == _T("BTN_MIN"))
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);//��С������
		else if (strName == _T("BTN_SELECT"))
			//MessageBox(m_hWnd, _T("SelectBTN"), _T("cashier"), IDOK);
			SelectEmployeeInfo();
		else if (strName == _T("BTN_INSERT"))
			//MessageBox(m_hWnd, _T("InsertBTN"), _T("cashier"), IDOK);
			InsertEmployeeInfo();
		else if (strName == _T("BTN_UPDATE"))
			MessageBox(m_hWnd, _T("UpdateBTN"), _T("cashier"), IDOK);
		else if (strName == _T("BTN_DELETE"))
			//MessageBox(m_hWnd, _T("DeleteBTN"), _T("cashier"), IDOK);
			DeleteEmployeeInfo();
		else if (strName == _T("BTN_SELL_RECORD"))
			MessageBox(m_hWnd, _T("SellBTN"), _T("cashier"), IDOK);
	}
	else if (msg.sType = _T("selectchanged"))//option�ؼ�ֻ��ѡһ�����໥֮����л�����ʱ����selectchanged
	{
		/*if (strName == _T("OPTION_EMPLOYEE"))
			MessageBox(m_hWnd, _T("EMPLOYEE"), _T("cashier"), IDOK);
		else
			MessageBox(m_hWnd, _T("GOODS"), _T("cashier"), IDOK);*/

		CTabLayoutUI* pTab = (CTabLayoutUI*)m_PaintManager.FindControl(_T("tablayout"));//�ҿؼ�
		if (strName == _T("OPTION_EMPLOYEE"))
			pTab->SelectItem(0);//��һ��option:��Ա���Ĳ���
		else if (strName == _T("OPTION_GOODS"))
			pTab->SelectItem(1);//�ڶ���option:����Ʒ�Ĳ���
	}
	else if (msg.sType == _T("windowinit"))
	{
		//���ڳ�ʼ���ڼ䣬��һЩ�ռ��ʼ��
#if 1
		CComboBoxUI* pGender = (CComboBoxUI*)m_PaintManager.FindControl(_T("usergender"));
		pGender->SelectItem(0);

		CComboBoxUI* pPosition = (CComboBoxUI*)m_PaintManager.FindControl(_T("position"));
		pPosition->SelectItem(0);

		CComboBoxUI* pSelect = (CComboBoxUI*)m_PaintManager.FindControl(_T("COMOB_SELECT"));
		pSelect->SelectItem(0);
#endif
	}
}



void MainWnd::SelectEmployeeInfo()
{
	//vector<vector<string>> vRet1 = m_pMySQL->Select(strSQL);//��vRet������select�Ĳ�ѯ���
	//if (vRet1.empty())
	//	return;

	CComboBoxUI* pCombo = (CComboBoxUI*)m_PaintManager.FindControl(_T("COMOB_SELECT"));
	CDuiString strStyle = pCombo->GetText();

	//�������ݿ����
	string strSQL("select * from employee ");

	if (strStyle == _T("��"))
		strSQL += ";";
	else if (strStyle == _T("����"))
	{
		strSQL += "where name = '";
		CEditUI* pstrName = (CEditUI*)m_PaintManager.FindControl(_T("username"));
		//CDuiString strName = pstrName->GetName();//��ȡ�ؼ�����
		CDuiString strName = pstrName->GetText();//������ʲôѽ��//��ȡ�ؼ�����
		if (strName.IsEmpty())
		{
			MessageBox(m_hWnd, _T("�������ѯ�û�������"), _T("Cashier"), IDOK);
			return;
		}
		strSQL += UnicodeToANSI(strName);
		strSQL += "';";
	}													//edit��Ҫ�������֣���gettext()
														//combo��Ҫѡ�����֣�������gettext()���õ�����comboѡ��ѡ���е����֣�
	else if (strStyle == _T("�Ա�"))					//��getname ��ʱ��õ���comboĬ�ϵ��ı�������û���أ�
	{													//����ȷ���Բ��ԣ�����֤
		CComboBoxUI* pGender = (CComboBoxUI*)m_PaintManager.FindControl(_T("usergender"));
		CDuiString strGender = pGender->GetText();/////������getname
		if (strGender.IsEmpty())
		{
			MessageBox(m_hWnd, _T("�������Ա�"), _T("Cashier"), IDOK);
			return;
		}

		strSQL += "where gender = '";
		
		//if (strGender == _T("��"))
		//{
		strSQL += UnicodeToANSI(strGender);
		strSQL += "';";
		//}
	}
	else if (strStyle == _T("н��"))
	{
		CEditUI* pSalary = (CEditUI*)m_PaintManager.FindControl(_T("usersalary"));
		CDuiString strSalary = pSalary->GetText();
		//�пգ�
		if (strSalary.IsEmpty())
		{
			MessageBox(m_hWnd, _T("������н��"), _T("Cashier"), IDOK);
			return;
		}
		strSQL += "where salary = '";
		
		strSQL += UnicodeToANSI(strSalary);//////���ﵽ���費��Ҫת��--->��Ҫ
		strSQL += "';";

	}

	
	
	//�Ƚ�ԭ����list���
	CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T("ListEmployeeInfo"));
	pListUI->RemoveAll();

	vector<vector<string>> vRet = m_pMySQL->Select(strSQL);//��ӦstrSQL���ݿ���䣬��������浽vRet��
	if (vRet.empty())
	{
		return;
	}

	//Ȼ�����select��ѯ������뵽list
	for (size_t i = 0; i < vRet.size(); ++i)
	{
		vector<string>& strItem = vRet[i];//vRet[i]���������ҵ���һ������
		CListTextElementUI* pData = new CListTextElementUI;
		pListUI->Add(pData);//ÿ����ѭ�����һ��
		pData->SetAttribute(_T("align"), _T("center"));//���ֶ��뷽ʽ������

		//��������е�ÿһ��Ԫ�أ������ݿ��Ӧ��
		pData->SetText(0, ANSIToUnicode(strItem[1]));
		pData->SetText(1, ANSIToUnicode(strItem[2]));
		pData->SetText(2, ANSIToUnicode(strItem[3]));
		pData->SetText(3, ANSIToUnicode(strItem[5]));
		pData->SetText(4, ANSIToUnicode(strItem[6]));
		pData->SetText(5, ANSIToUnicode(strItem[7]));
	}

}

//�����ǲ��뻹��ɾ�����ȹ����ݿ�Ĳ���ɾ�����ٹ�list
void MainWnd::DeleteEmployeeInfo()
{
	//1.��ȡ��ǰѡ��
	CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T("ListEmployeeInfo"));
	//pListUI->RemoveAll();
	int lineNo = pListUI->GetCurSel();//��ȡ��ǰѡ����
	CListTextElementUI* pRow = (CListTextElementUI*)pListUI->GetItemAt(lineNo);//��ȡ��ǰѡ������
	CDuiString strName = pRow->GetText(0);//��ȡ���е�һ��Ԫ��(����)  //	�����⣺ɾ��ʱδ��ȡ����������һ�У�������ɾ��ʧ�ܡ�

																
	//2.�����ݿ��н���Ա������Ϣɾ��

	////����SQL����
	//string strSQL("delete from employee where id = ");
	//strSQL += lineNo;
	string strSQL("delete from employee where name = '");
	strSQL += UnicodeToANSI(strName);
	strSQL += ("';");


	
	//�����ݿ��н�������¼ɾ��
	m_pMySQL->Delete(strSQL);//���⣺���ݿ���������Ѿ�����delete��Ϊʲô��װ���ݿ��ʱ����Ҫ��Delete(strSQL)�أ�-->ֻ�ǵ�����mysql_query����װ��һ���жϴ���mysql_error����
	

	//3.��List���Ƴ�
	pListUI->RemoveAt(lineNo);//RemoveAt(�к�):�Ƴ�����
}

void MainWnd::InsertEmployeeInfo()
{
	//1.�ӽ����ȡԱ����Ϣ
	CEditUI* pstrname = (CEditUI*)m_PaintManager.FindControl(_T("username"));
	CDuiString strName = pstrname->GetText();

	CComboBoxUI* pstrGender = (CComboBoxUI*)m_PaintManager.FindControl(_T("usergender"));
	CDuiString strGender = pstrGender->GetText();
	CDuiString strBirthday = ((CEditUI*)m_PaintManager.FindControl(_T("userbirthday")))->GetText();//�϶�Ϊһ��ע�����ţ�Ҫ��ǰ������е�������
	CDuiString strPosition = ((CComboBoxUI*)m_PaintManager.FindControl(_T("position")))->GetText();//�϶�Ϊһ��ע�����ţ�Ҫ��ǰ������е�������
	CDuiString strTel = ((CEditUI*)m_PaintManager.FindControl(_T("telphone")))->GetText();//�϶�Ϊһ��ע�����ţ�Ҫ��ǰ������е�������
	CDuiString strSalary = ((CEditUI*)m_PaintManager.FindControl(_T("usersalary")))->GetText();//�϶�Ϊһ��ע�����ţ�Ҫ��ǰ������е�������

	CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T("ListEmployeeInfo"));
	//pListUI->GetCount();

	char szCount[32] = { 0 };
	_itoa(pListUI->GetCount() + 3, szCount, 10);

	//2.����SQL����,��Ա����Ϣ�������ݿ�                                   ///////////////�����⣺�������д�����²���һ��NULL��
	/*string strSQL("insert into employee values(id = ");
	strSQL += szCount;
	strSQL += ",name = '";
	strSQL += UnicodeToANSI(strName);
	strSQL += "',gender = '";
	strSQL += UnicodeToANSI(strGender);
	strSQL += "', birthday = '";
	strSQL += UnicodeToANSI(strBirthday);
	strSQL += "', password = '123',position = '";
	strSQL += UnicodeToANSI(strPosition);
	strSQL += "', telphone = '";
	strSQL += UnicodeToANSI(strTel);
	strSQL += "', salary = ";
	strSQL += UnicodeToANSI(strSalary);
	strSQL += ");";*/

	//�޸�mysql�������
	string strSQL("insert into employee values( ");
	strSQL += szCount;
	strSQL += ",'";
	strSQL += UnicodeToANSI(strName);
	strSQL += "', '";
	strSQL += UnicodeToANSI(strGender);
	strSQL += "',  '";
	strSQL += UnicodeToANSI(strBirthday);
	strSQL += "',  '123', '";
	strSQL += UnicodeToANSI(strPosition);
	strSQL += "',  '";
	strSQL += UnicodeToANSI(strTel);
	strSQL += "',  ";
	strSQL += UnicodeToANSI(strSalary);
	strSQL += ");";

	//��ӦSQL����
	m_pMySQL->Insert(strSQL);


	//3.����Ա������Ϣ���뵽List
	CListTextElementUI* pItem = new CListTextElementUI;//��ȡlist��������Ϣ
	//CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T("ListEmployeeInfo"));
	pListUI->Add(pItem);//list�����һ��
	pItem->SetText(0, strName);
	pItem->SetText(1, strGender);
	pItem->SetText(2, strBirthday);
	pItem->SetText(3, strPosition);
	pItem->SetText(4, strTel);
	pItem->SetText(5, strSalary);

}
