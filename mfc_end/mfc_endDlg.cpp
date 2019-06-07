
// mfc_endDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "mfc_end.h"
#include "mfc_endDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcendDlg 对话框
int NUM;
int MAX;


CmfcendDlg::CmfcendDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_END_DIALOG, pParent)
	, m_num(_T(""))
	, m_count(_T(""))
	, m_start(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUM, m_num);
	DDX_Text(pDX, IDC_COUNT, m_count);
	DDX_Text(pDX, IDC_START, m_start);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, BTN_SET, m_set);
	DDX_Control(pDX, BTN_START, m_star);
}

BEGIN_MESSAGE_MAP(CmfcendDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BTN_SET, &CmfcendDlg::OnBnClickedSet)
	ON_BN_CLICKED(BTN_START, &CmfcendDlg::OnBnClickedStart)
	ON_BN_CLICKED(BTN_RESET, &CmfcendDlg::OnBnClickedReset)
END_MESSAGE_MAP()


// CmfcendDlg 消息处理程序

BOOL CmfcendDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_ONECLICKACTIVATE);
	m_list.InsertColumn(0, _T("第n轮"), LVCFMT_LEFT, 130);
	m_list.InsertColumn(1, _T("第x人出列"), LVCFMT_LEFT, 300);

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_star.EnableWindow(0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmfcendDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmfcendDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcendDlg::OnBnClickedSet() //设定数据 初始化
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	num = atoi(m_num); //num为总数人数 （从编辑框获取的变量为CString所以使用atoi转换为int，下同）
	count = atoi(m_count);//count为开始位置
	start = atoi(m_start);//start为计数
	game = new Game(); //建立一局游戏
	game->CreateGame(num); //输入游戏信息
	game->SetStart(count);//同上

	NUM = 0;//NUM记录表格数据条数，初始为0
	MAX = 0;//MAX记录已出局人数    这俩其实用一个就够，当时脑抽

	m_set.EnableWindow(0);//禁用此button
	m_star.EnableWindow(1);//激活“开始”button
}


void CmfcendDlg::OnBnClickedStart() //点一次出局一人
{
	// TODO: 在此添加控件通知处理程序代码
	int out = game->runonce(start);//出局一人切记录出局人标记
	CString str;
	str.Format("%d", NUM + 1); //int转CString
	m_list.InsertItem(NUM, str);//表格插入一行信息
	CString outno;
	outno.Format("%d", out);//同上
	CString output = "第" + outno + "名出列";//建立第二列内容
	m_list.SetItemText(NUM, 1, output); //跟前面一样

	NUM++;
	MAX++;

	if (MAX >= num) //判断是否游戏结束
	{
		m_star.EnableWindow(0);//禁用“开始”button
		return;
	}
}


void CmfcendDlg::OnBnClickedReset() //重置
{
	// TODO: 在此添加控件通知处理程序代码
	m_set.EnableWindow(1);//激活“设定”button
	m_star.EnableWindow(0);//禁用“开始”button
	m_num.SetString("");//清空输入框
	m_count.SetString("");//同上
	m_start.SetString("");//me too
	m_list.DeleteAllItems();//删除表格
	UpdateData(false);//使清空表格动作生效
}
