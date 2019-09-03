#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "CashierWnd.h"

CCashierWnd::CCashierWnd(MySQL* pMySQL)
:m_pMySQL(pMySQL)
{

}
CCashierWnd::~CCashierWnd()
{

}

//WindowImplBase�ṩ�������麯��

//xml�ļ���Ӧ��Ŀ¼
CDuiString CCashierWnd::GetSkinFolder()
{
	return (_T(""));
}

//xml�ļ�����
CDuiString CCashierWnd::GetSkinFile()
{
	//return (_T("Cashier.xml"));
	return (_T("CashierManage.xml"));
}

//����������֣���ע�ᴰ��ʱ�����ṩ(�Լ����ù�)
LPCTSTR CCashierWnd::GetWindowClassName() const
{
	return _T("CashierWnd");
}



void CCashierWnd::Notify(TNotifyUI& msg)
{
	CDuiString strName = msg.pSender->GetName();
	if (msg.sType == _T("click"))
	{
		//CDuiString strBTNName = msg.pSender->GetName();
		if (strName == _T("BTN_CLOSE"))
			PostQuitMessage(0);//Close();�رմ���
		else if (strName == _T("BTN_MIN"))
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);//��С������
		else if (strName == _T("BTN_ADD"))
			//MessageBox(m_hWnd, _T("Test BTN_ADD"), _T("cashier"), IDOK);
			AddGoodsCount();
		else if (strName == _T("BTN_SUB"))
			//MessageBox(m_hWnd, _T("Test BTN_SUB"), _T("cashier"), IDOK);
			SubGoodsCount();
		else if (strName == _T("BTN_SELECT"))
			//MessageBox(m_hWnd, _T("Test BTN_SELECT"), _T("cashier"), IDOK);
			SelectGoods();
		else if (strName == _T("BTN_COMMIT"))
			 //MessageBox(m_hWnd, _T("Test BTN_COMMIT"), _T("cashier"), IDOK);
			//��ûд��
			CommitOrder();
		else if (strName == _T("BTN_CANCEL"))
			CancelOrder();
		else if (strName == _T("BTN_OK"))
			InsertGoodsList();
	}
}
void CCashierWnd::SelectGoods()
{
	//��ȡ��Ʒ����
	CDuiString strGoodsName = ((CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_NAME")))->GetText();

	//����SQL���
	string strSQL("select * from goodstable where GoodsName = '");
	strSQL += UnicodeToANSI(strGoodsName);
	strSQL += "';";

	//��Ӧ��䣬�޸Ĺ��캯��
	vector<vector<string>> vRet = m_pMySQL->Select(strSQL);
	if (vRet.empty())
	{
		MessageBox(m_hWnd, _T("���޴���Ʒ"), _T("cashier"), IDOK);
		return;
	}

	//��(�鵽��)ʣ�������ʾ������༭����
	((CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_LEFT")))->SetText(ANSIToUnicode(vRet[0][7]));
}
void CCashierWnd::AddGoodsCount()
{
	//����1
	CEditUI* pGoodLeft = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_LEFT"));
	CDuiString strLeft = pGoodLeft->GetText();//�õ�����Unicode����
	if (strLeft == _T("0"))
	{
		MessageBox(m_hWnd, _T("���������"), _T("cashier"), IDOK);
		return;
	}
	int count = 0;
	count = atoi(UnicodeToANSI(strLeft).c_str());//�ַ���ת��Ϊ����        [ȥת]
	--count;
	strLeft.Format(_T("%d"), count);//��count�Լ�֮���ʽ��ת��strCount    [��ת]
	pGoodLeft->SetText(strLeft);//��strLeftд��EDIT_GOODS_LEFT�ؼ�

	//(Ҫ���۵�)��Ʒ������1
	CEditUI* pGoodCount = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_COUNT"));
	CDuiString strCount = pGoodCount->GetText();//�õ�����Unicode����
	
	int sellcount = atoi(UnicodeToANSI(strCount).c_str());//�ַ���ת��Ϊ����[ȥת]
	++sellcount;
	strCount.Format(_T("%d"), sellcount);//[��ת]
	pGoodCount->SetText(strCount);//��strCountд��EDIT_GOODS_COUNT�ؼ�

}
void CCashierWnd::SubGoodsCount()
{
	//��Ʒ������ȥ1
	CEditUI* pGoodCount = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_COUNT"));
	CDuiString strCount = pGoodCount->GetText();//�õ�����Unicode����
	if (strCount == _T("0"))
	{
		MessageBox(m_hWnd, _T("��Ʒ�������Ѿ�Ϊ0"), _T("cashier"), IDOK);
		return;
	}
	int count = atoi(UnicodeToANSI(strCount).c_str());//�ַ���ת��Ϊ����
	--count;
	strCount.Format(_T("%d"), count);//��count����֮���ʽ��ת��strCount
	pGoodCount->SetText(strCount);//��strCountд�뵽�ؼ�pGoodCount

	//����1
	CEditUI* pGoodLeft = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_LEFT"));
	CDuiString strLeft = pGoodLeft->GetText();//�õ�����Unicode����

	count = atoi(UnicodeToANSI(strLeft).c_str());//�ַ���ת��Ϊ����
	++count;
	strLeft.Format(_T("%d"), count);//��count����֮���ʽ��ת��strLeft
	pGoodLeft->SetText(strLeft);//��strCountд�뵽�ؼ�pGoodCount
}

void CCashierWnd::InsertGoodsList()//���OK֮�󽫸ã������ۣ���Ʒ����list
{
	//1.�ӽ����ȡ��Ʒ�����Լ���������
	CEditUI* pstrGoodsName = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_NAME"));
	//CDuiString strGoodsName = pstrGoodsName->GetName();//��GetText()
	CDuiString strGoodsName = pstrGoodsName->GetText();
	CEditUI* pstrGoodsCount = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_COUNT")); 
	CDuiString strCount = pstrGoodsCount->GetText();

	//2.�����ݿ��ȡ��Ʒ�ļ۸��Լ�������λ
	string strSQL("select * from goodstable where GoodsName = '");
	strSQL += UnicodeToANSI(strGoodsName);
	strSQL += "';";
	vector<vector<string>> vRet = m_pMySQL->Select(strSQL);//��Ӧ���ݿ����,��vRet����select���
															//��������vRet�����в���
	//3.�ϼƼ۸�
	int count = atoi(UnicodeToANSI(strCount).c_str());
	double price = atof(vRet[0][5].c_str());//atof:�ַ���תΪdouble����
	//int price = atoi(vRet[0][5].c_str());//atoi:�ַ���תΪint����

	price = count * price;
	CDuiString strPrice;
	strPrice.Format(_T("%lf"), price);//double���������ʽ
	//strPrice.Format(_T("%d"), price);


	//4.����Ϣ���µ�List��
	CListTextElementUI* pItem = new CListTextElementUI;//List�е�һ�У�Ԫ�أ�
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("OrderList"));
	pList->Add(pItem);//pItem��ʾList�е�һ�У��±�0,1,2,3,4,...��ListCount��
	pItem->SetText(0, strGoodsName);
	pItem->SetText(1, ANSIToUnicode(vRet[0][5]));
	pItem->SetText(2, strCount);
	pItem->SetText(3, ANSIToUnicode(vRet[0][6]));
	pItem->SetText(4, strPrice);

	//5.����Ʒ�����Լ����Ƶı༭������
	((CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_NAME")))->SetText(_T(""));
	((CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_LEFT")))->SetText(_T(""));
	((CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODS_COUNT")))->SetText(_T(""));

}

void CCashierWnd::CancelOrder()//���������list��������Ʒ
{
	//���������Ʒ
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("OrderList"));//��List�ؼ�
	pList->RemoveAll();

}

void CCashierWnd::CommitOrder()//��list��������Ʒ���۲��������ݿ�
{
	//�ϲ��ܼ۸�
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("OrderList"));
	int count = pList->GetCount();//GetCount�ķ���ֵ������int���ʲ���Ҫת��

	double totalPrice = 0;
	for (int i = 0; i < count; ++i)
	{
		CListTextElementUI* pItem = (CListTextElementUI*)pList->GetItemAt(i);//��ȡlist�е�i������
		CDuiString strPrice = (CDuiString)pItem->GetText(4);//��ȡ�����е�5��(0,1,2,3,4)��0��ʼ��
		totalPrice += atof(UnicodeToANSI(strPrice).c_str());//��ÿ���еĵ�5�У��ܼ۸����
	}
	CDuiString strTotalPrice;
	strTotalPrice.Format(_T("%.02lf"), totalPrice);//��double����תΪCDuiString����strTotalPrice
	((CEditUI*)m_PaintManager.FindControl(_T("EDIT_TOTAL")))->SetText(strTotalPrice);//��strTotalPriceд��EDIT_TOTAL�ؼ�

	//������Ʒ�����ݿ�
	for (int i = 0; i < count; ++i)
	{
		CListTextElementUI* pItem = (CListTextElementUI*)pList->GetItemAt(i);///////��ȡlist��ÿ�����ݵ�pItem��������CListTextElementUI*
		CDuiString strCount = pItem->GetText(2);//��ȡÿ�е�3��Ԫ�أ����иó�����Ʒ������
		CDuiString strName = pItem->GetText(0);//��ȡû�е�1�У����г�����Ʒ�����ƣ�

		//int sellcount = atoi(UnicodeToANSI(strCount).c_str());//string-->int������һ������Ҫ������sellcount���Ϊ\x(sellcount)

		//����SQL��䡾���⣺����strSQL�������ʱint/doubleҲҪ����ANSI�ַ����Դ���
		string strSQL = (" update goodstable set Inventory = (Inventory - ");
		//strSQL += sellcount;
		strSQL += UnicodeToANSI(strCount);
		strSQL += ") where GoodsName='";
		strSQL += UnicodeToANSI(strName);
		strSQL += "';";
		m_pMySQL->Update(strSQL);
	}
	//���뱾�����ۼ�¼

	//������ʾ
	if (count != 0)
		MessageBox(m_hWnd, _T("�����ύ�ɹ�"), _T("Cashier"), IDOK);
	else if (pList->IsVisible())
		MessageBox(m_hWnd, _T("��ѡ��Ҫ���۵���Ʒ�������嵥"), _T("Cashier"), IDOK);
	else
		MessageBox(m_hWnd, _T("������Ʒ�޿��"), _T("Cashier"), IDOK);
}