
// mfc_endDlg.h: 头文件
//

#pragma once
#include "Game.h"


// CmfcendDlg 对话框
class CmfcendDlg : public CDialogEx
{
// 构造
public:
	CmfcendDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_END_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_num;
	CString m_count;
	CString m_start;
	CListCtrl m_list;
	int num;
	int count;
	int start;
	Game* game;
	afx_msg void OnBnClickedSet();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedReset();
	CButton m_set;
	CButton m_star;
};
