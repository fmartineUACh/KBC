
// MFCKinectDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCKinect.h"
#include "MFCKinectDlg.h"
#include "afxdialogex.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

int pCheckbox[25] = { 0,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0 };//�жϵ����
int gesture = 0;//gesture
extern int IsRecord;//�ж��Ƿ��¼
CString savefile("output.txt");//��¼�ļ���
int kline = 1;
int onplay = -1;
int onpicture = 1;//1=�������ͼ��2=���ͼ
int maxppbody = 1;
int maxline = 100;
int pos = 1;
bool cvplay = false;
bool cvzhen = false;
bool cvluzhi = false;
CString openfile("");

COLORREF  m_BrushBack = RGB(255, 0, 0);

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCKinectDlg �Ի���



CMFCKinectDlg::CMFCKinectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCKINECT_DIALOG, pParent)
	, filename(_T(""))
	, EDITpos(0)
	, firstline(0)
	, lastline(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCKinectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, filename);
	DDX_Control(pDX, IDC_EDIT1, GetFilename);
	DDX_Control(pDX, IDC_BUTTON2, StartRecord);
	DDX_Control(pDX, IDC_BUTTON3, StopRecord);
	DDX_Control(pDX, IDC_RADIO1, gesture1);
	DDX_Control(pDX, IDC_RADIO2, gesture2);
	DDX_Control(pDX, IDC_SCROLLBAR2, CSBar);
	DDX_Text(pDX, IDC_HSCROLL_EDIT, EDITpos);
	DDX_Text(pDX, IDC_EDIT3, firstline);
	DDX_Text(pDX, IDC_EDIT4, lastline);
	DDX_Control(pDX, IDC_EDIT2, m_brush);
}

BEGIN_MESSAGE_MAP(CMFCKinectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCKinectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMFCKinectDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCKinectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCKinectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCKinectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCKinectDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCKinectDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CMFCKinectDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CMFCKinectDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CMFCKinectDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CMFCKinectDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CMFCKinectDlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CMFCKinectDlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CMFCKinectDlg::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &CMFCKinectDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CMFCKinectDlg::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK12, &CMFCKinectDlg::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &CMFCKinectDlg::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK14, &CMFCKinectDlg::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK15, &CMFCKinectDlg::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK16, &CMFCKinectDlg::OnBnClickedCheck16)
	ON_BN_CLICKED(IDC_CHECK17, &CMFCKinectDlg::OnBnClickedCheck17)
	ON_BN_CLICKED(IDC_CHECK18, &CMFCKinectDlg::OnBnClickedCheck18)
	ON_BN_CLICKED(IDC_CHECK19, &CMFCKinectDlg::OnBnClickedCheck19)
	ON_BN_CLICKED(IDC_CHECK20, &CMFCKinectDlg::OnBnClickedCheck20)
	ON_BN_CLICKED(IDC_CHECK21, &CMFCKinectDlg::OnBnClickedCheck21)
	ON_BN_CLICKED(IDC_CHECK22, &CMFCKinectDlg::OnBnClickedCheck22)
	ON_BN_CLICKED(IDC_CHECK23, &CMFCKinectDlg::OnBnClickedCheck23)
	ON_BN_CLICKED(IDC_CHECK24, &CMFCKinectDlg::OnBnClickedCheck24)
	ON_BN_CLICKED(IDC_CHECK25, &CMFCKinectDlg::OnBnClickedCheck25)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCKinectDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCKinectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCKinectDlg::OnBnClickedRadio2)
	ON_STN_CLICKED(IDC_STATIC_CV1, &CMFCKinectDlg::OnStnClickedStaticCv1)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCKinectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCKinectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO8, &CMFCKinectDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO9, &CMFCKinectDlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &CMFCKinectDlg::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_RADIO11, &CMFCKinectDlg::OnBnClickedRadio11)
	ON_BN_CLICKED(IDC_RADIO12, &CMFCKinectDlg::OnBnClickedRadio12)
	ON_BN_CLICKED(IDC_RADIO13, &CMFCKinectDlg::OnBnClickedRadio13)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCKinectDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCKinectDlg::OnBnClickedButton9)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR2, &CMFCKinectDlg::OnNMThemeChangedScrollbar2)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR2, &CMFCKinectDlg::OnNMThemeChangedScrollbar2)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_HSCROLL_EDIT, &CMFCKinectDlg::OnEnChangeHscrollEdit)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCKinectDlg::OnBnClickedButton10)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCKinectDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCKinectDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCKinectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCKinectDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CMFCKinectDlg::OnBnClickedRadio7)
	ON_WM_CTLCOLOR()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMFCKinectDlg ��Ϣ�������

BOOL CMFCKinectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//��������
	CFont * f1; // ��������
	f1 = new CFont;
	f1->CreateFont(16, // nHeight 
		0, // nWidth 
		0, // nEscapement 
		0, // nOrientation 
		FW_BOLD, // nWeight 
		FALSE, // bItalic 
		FALSE, // bUnderline 
		0, // cStrikeOut 
		ANSI_CHARSET, // nCharSet 
		OUT_DEFAULT_PRECIS, // nOutPrecision 
		CLIP_DEFAULT_PRECIS, // nClipPrecision 
		DEFAULT_QUALITY, // nQuality 
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
		_T("Arial")); // lpszFac 

	GetDlgItem(IDC_STATIC1)->SetFont(f1);
	GetDlgItem(IDC_STATIC2)->SetFont(f1);
	GetDlgItem(IDC_STATIC3)->SetFont(f1);
	GetDlgItem(IDC_STATIC4)->SetFont(f1);
	GetDlgItem(IDC_STATIC5)->SetFont(f1);
	GetDlgItem(IDC_STATIC6)->SetFont(f1);
	GetDlgItem(IDC_STATIC7)->SetFont(f1);
	GetDlgItem(IDC_STATIC8)->SetFont(f1);

	CFont * f2; // �ı�����
	f2 = new CFont;
	f2->CreateFont(15, // nHeight 
		0, // nWidth 
		0, // nEscapement 
		0, // nOrientation 
		400, // nWeight 
		FALSE, // bItalic 
		FALSE, // bUnderline 
		0, // cStrikeOut 
		ANSI_CHARSET, // nCharSet 
		OUT_DEFAULT_PRECIS, // nOutPrecision 
		CLIP_DEFAULT_PRECIS, // nClipPrecision 
		DEFAULT_QUALITY, // nQuality 
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
		_T("Times New Roman")); // lpszFac 
	GetDlgItem(IDC_BUTTON1)->SetFont(f2);
	GetDlgItem(IDC_BUTTON2)->SetFont(f2);
	GetDlgItem(IDC_BUTTON3)->SetFont(f2);
	GetDlgItem(IDC_BUTTON4)->SetFont(f2);
	GetDlgItem(IDC_BUTTON7)->SetFont(f2);
	GetDlgItem(IDC_BUTTON6)->SetFont(f2);
	GetDlgItem(IDC_BUTTON9)->SetFont(f2);
	GetDlgItem(IDC_BUTTON10)->SetFont(f2);
	GetDlgItem(IDC_RADIO1)->SetFont(f2);
	GetDlgItem(IDC_RADIO2)->SetFont(f2);
	GetDlgItem(IDC_RADIO3)->SetFont(f2);
	GetDlgItem(IDC_RADIO4)->SetFont(f2);
	GetDlgItem(IDC_RADIO7)->SetFont(f2);
	GetDlgItem(IDC_RADIO6)->SetFont(f2);
	GetDlgItem(IDC_RADIO8)->SetFont(f2);
	GetDlgItem(IDC_RADIO9)->SetFont(f2);
	GetDlgItem(IDC_RADIO10)->SetFont(f2);
	GetDlgItem(IDC_RADIO11)->SetFont(f2);
	GetDlgItem(IDC_RADIO12)->SetFont(f2);
	GetDlgItem(IDC_RADIO13)->SetFont(f2);
	GetDlgItem(IDC_STATIC10)->SetFont(f2); 
	GetDlgItem(IDC_STATIC12)->SetFont(f2);
	GetDlgItem(IDC_STATIC)->SetFont(f2);
	GetDlgItem(IDC_HSCROLL_EDIT)->SetFont(f2);
	GetDlgItem(IDC_EDIT1)->SetFont(f2);
	GetDlgItem(IDC_EDIT3)->SetFont(f2);
	GetDlgItem(IDC_EDIT4)->SetFont(f2);



	//����������ɫ

	//if (pWnd->GetDlgCtrlID() == IDC_EDIT2) pDC->SetTextColor(RGB(255, 0, 0));
	m_ForeColor = RGB(0, 0, 0);
	m_BackColor = RGB(0, 0, 0);
	m_BkBrush.CreateSolidBrush(m_BackColor);
	p_Font = NULL;


	//���ÿؼ�λ��
	CWnd *pWnd;

	SetWindowPos(NULL, 0, 0, 950, 695, SWP_NOMOVE);

	pWnd = GetDlgItem(IDC_CHECK4);
	pWnd->MoveWindow(CRect(113, 340, 127, 355)); 

	pWnd = GetDlgItem(IDC_CHECK3);
	pWnd->MoveWindow(CRect(113, 360, 127, 375));

	pWnd = GetDlgItem(IDC_CHECK21);
	pWnd->MoveWindow(CRect(113, 380, 127, 395));

	pWnd = GetDlgItem(IDC_CHECK5);
	pWnd->MoveWindow(CRect(94, 380, 108, 395));

	pWnd = GetDlgItem(IDC_CHECK9);
	pWnd->MoveWindow(CRect(132, 380, 146, 395));

	pWnd = GetDlgItem(IDC_CHECK6);
	pWnd->MoveWindow(CRect(84, 400, 98, 415));

	pWnd = GetDlgItem(IDC_CHECK10);
	pWnd->MoveWindow(CRect(142, 400, 156, 415));

	pWnd = GetDlgItem(IDC_CHECK7);
	pWnd->MoveWindow(CRect(74, 420, 88, 435));

	pWnd = GetDlgItem(IDC_CHECK11);
	pWnd->MoveWindow(CRect(152, 420, 166, 435));

	pWnd = GetDlgItem(IDC_CHECK8);
	pWnd->MoveWindow(CRect(64, 440, 78, 455));

	pWnd = GetDlgItem(IDC_CHECK12);
	pWnd->MoveWindow(CRect(162, 440, 176, 455)); 

	pWnd = GetDlgItem(IDC_CHECK22);
	pWnd->MoveWindow(CRect(48, 440, 61, 455));

	pWnd = GetDlgItem(IDC_CHECK24);
	pWnd->MoveWindow(CRect(178, 440, 192, 455));

	pWnd = GetDlgItem(IDC_CHECK23);
	pWnd->MoveWindow(CRect(64, 457, 78, 472));

	pWnd = GetDlgItem(IDC_CHECK25);
	pWnd->MoveWindow(CRect(162, 457, 176, 472));

	pWnd = GetDlgItem(IDC_CHECK2);
	pWnd->MoveWindow(CRect(113, 420, 127, 435));

	pWnd = GetDlgItem(IDC_CHECK1);
	pWnd->MoveWindow(CRect(113, 457, 127, 472));

	pWnd = GetDlgItem(IDC_CHECK13);
	pWnd->MoveWindow(CRect(94, 462, 108, 477));

	pWnd = GetDlgItem(IDC_CHECK17);
	pWnd->MoveWindow(CRect(132, 462, 146, 477));

	pWnd = GetDlgItem(IDC_CHECK14);
	pWnd->MoveWindow(CRect(89, 482, 103, 496));

	pWnd = GetDlgItem(IDC_CHECK18);
	pWnd->MoveWindow(CRect(137, 482, 151, 496));

	pWnd = GetDlgItem(IDC_CHECK15);
	pWnd->MoveWindow(CRect(84, 501, 98, 516));

	pWnd = GetDlgItem(IDC_CHECK19);
	pWnd->MoveWindow(CRect(142, 501, 156, 516));

	pWnd = GetDlgItem(IDC_CHECK16);
	pWnd->MoveWindow(CRect(80, 521, 94, 536));

	pWnd = GetDlgItem(IDC_CHECK20);
	pWnd->MoveWindow(CRect(146, 521, 160, 536));

	pWnd = GetDlgItem(IDC_STATIC2);
	pWnd->MoveWindow(CRect(20, 20, 220, 250));   ////

	pWnd = GetDlgItem(IDC_RADIO3);				
	pWnd->MoveWindow(CRect(257, 180, 337, 195));    

	pWnd = GetDlgItem(IDC_RADIO6);
	pWnd->MoveWindow(CRect(257, 205, 337, 220));

	pWnd = GetDlgItem(IDC_RADIO7);
	pWnd->MoveWindow(CRect(257, 230, 337, 245));

	pWnd = GetDlgItem(IDC_RADIO4);
	pWnd->MoveWindow(CRect(257, 255, 337, 270));

	pWnd = GetDlgItem(IDC_RADIO8);
	pWnd->MoveWindow(CRect(280, 360, 330, 375));

	pWnd = GetDlgItem(IDC_RADIO9);
	pWnd->MoveWindow(CRect(280, 383, 330, 398));

	pWnd = GetDlgItem(IDC_RADIO10);
	pWnd->MoveWindow(CRect(280, 406, 330, 421));

	pWnd = GetDlgItem(IDC_RADIO11);
	pWnd->MoveWindow(CRect(280, 429, 330, 444));

	pWnd = GetDlgItem(IDC_RADIO12);
	pWnd->MoveWindow(CRect(280, 452, 330, 467));

	pWnd = GetDlgItem(IDC_RADIO13);
	pWnd->MoveWindow(CRect(280, 475, 330, 490));

	pWnd = GetDlgItem(IDC_EDIT2);
	pWnd->MoveWindow(CRect(35, 50, 205, 70));

	pWnd = GetDlgItem(IDC_BUTTON1);
	pWnd->MoveWindow(CRect(55, 90, 185, 130));

	pWnd = GetDlgItem(IDC_BUTTON2);
	pWnd->MoveWindow(CRect(55, 150, 185, 190));

	pWnd = GetDlgItem(IDC_BUTTON3);
	pWnd->MoveWindow(CRect(55, 150, 185, 190));

	pWnd = GetDlgItem(IDC_BUTTON6);
	pWnd->MoveWindow(CRect(55, 90, 185, 130));

	pWnd = GetDlgItem(IDC_STATIC1);
	pWnd->MoveWindow(CRect(250, 520, 350, 620));

	pWnd = GetDlgItem(IDC_RADIO1);
	pWnd->MoveWindow(CRect(290, 550, 330, 570));

	pWnd = GetDlgItem(IDC_RADIO2);
	pWnd->MoveWindow(CRect(290, 585, 330, 605));

	pWnd = GetDlgItem(IDC_STATIC3);
	pWnd->MoveWindow(CRect(20, 290, 220, 620));

	pWnd = GetDlgItem(IDC_STATIC4);
	pWnd->MoveWindow(CRect(370, 150, 920, 620));

	pWnd = GetDlgItem(IDC_STATIC_CV1);
	pWnd->MoveWindow(CRect(389, 173, 901, 597));

	pWnd = GetDlgItem(IDC_STATIC5);
	pWnd->MoveWindow(CRect(250, 150, 350, 290));

	pWnd = GetDlgItem(IDC_STATIC8);
	pWnd->MoveWindow(CRect(250, 330, 350, 500));

	pWnd = GetDlgItem(IDC_EDIT1);
	pWnd->MoveWindow(CRect(700, 45, 910, 70));

	pWnd = GetDlgItem(IDC_STATIC6);
	pWnd->MoveWindow(CRect(670, 20, 920, 120));

	pWnd = GetDlgItem(IDC_STATIC7);
	pWnd->MoveWindow(CRect(250, 20, 660, 120));

	pWnd = GetDlgItem(IDC_BUTTON4);
	pWnd->MoveWindow(CRect(700, 80, 795, 105));

	pWnd = GetDlgItem(IDC_BUTTON7);
	pWnd->MoveWindow(CRect(815, 80, 910, 105));

	pWnd = GetDlgItem(IDC_SCROLLBAR2);
	pWnd->MoveWindow(CRect(270, 90, 640, 105));

	pWnd = GetDlgItem(IDC_BUTTON9);
	pWnd->MoveWindow(CRect(270, 40, 330, 65));

	pWnd = GetDlgItem(IDC_STATIC10);
	pWnd->MoveWindow(CRect(338, 45, 420, 70));

	pWnd = GetDlgItem(IDC_HSCROLL_EDIT);
	pWnd->MoveWindow(CRect(420, 45, 450, 70));

	pWnd = GetDlgItem(IDC_BUTTON10);
	pWnd->MoveWindow(CRect(460, 40, 520, 65));

	pWnd = GetDlgItem(IDC_EDIT3);
	pWnd->MoveWindow(CRect(540, 45, 570, 65));

	pWnd = GetDlgItem(IDC_STATIC11);
	pWnd->MoveWindow(CRect(575, 45, 585, 70));

	pWnd = GetDlgItem(IDC_EDIT4);
	pWnd->MoveWindow(CRect(590, 45, 620, 65));

	pWnd = GetDlgItem(IDC_STATIC12);
	pWnd->MoveWindow(CRect(623, 45, 655, 70));

	pWnd = GetDlgItem(IDC_STATIC);
	pWnd->MoveWindow(CRect(200, 640, 750, 655));


	CString StopRecording("Recording Stopped");
	SetDlgItemText(IDC_EDIT2, StopRecording);
	CString pretext("(file path)");
	SetDlgItemText(IDC_EDIT1, pretext);
	//((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK5))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK6))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK7))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_CHECK8))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK9))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK10))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK11))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_CHECK12))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK13))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK14))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK15))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_CHECK16))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK17))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK18))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK19))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_CHECK20))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CHECK21))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_CHECK22))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_CHECK23))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_CHECK24))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_CHECK25))->SetCheck(BST_CHECKED);

	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE);
	((CButton *)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
	/*CheckButton mycheck;
	mycheck.pCheckbox[0] = (CButton*)GetDlgItem(IDC_CHECK1);
	mycheck.pCheckbox[1] = (CButton*)GetDlgItem(IDC_CHECK2);
	mycheck.pCheckbox[2] = (CButton*)GetDlgItem(IDC_CHECK3);
	mycheck.pCheckbox[3] = (CButton*)GetDlgItem(IDC_CHECK4);
	mycheck.pCheckbox[4] = (CButton*)GetDlgItem(IDC_CHECK5);
	mycheck.pCheckbox[5] = (CButton*)GetDlgItem(IDC_CHECK6);
	mycheck.pCheckbox[6] = (CButton*)GetDlgItem(IDC_CHECK7);
	mycheck.pCheckbox[7] = (CButton*)GetDlgItem(IDC_CHECK8);
	mycheck.pCheckbox[8] = (CButton*)GetDlgItem(IDC_CHECK9);
	mycheck.pCheckbox[9] = (CButton*)GetDlgItem(IDC_CHECK10);
	mycheck.pCheckbox[10] = (CButton*)GetDlgItem(IDC_CHECK11);
	mycheck.pCheckbox[11] = (CButton*)GetDlgItem(IDC_CHECK12);
	mycheck.pCheckbox[12] = (CButton*)GetDlgItem(IDC_CHECK13);
	mycheck.pCheckbox[13] = (CButton*)GetDlgItem(IDC_CHECK14);
	mycheck.pCheckbox[14] = (CButton*)GetDlgItem(IDC_CHECK15);
	mycheck.pCheckbox[15] = (CButton*)GetDlgItem(IDC_CHECK16);
	mycheck.pCheckbox[16] = (CButton*)GetDlgItem(IDC_CHECK17);
	mycheck.pCheckbox[17] = (CButton*)GetDlgItem(IDC_CHECK18);
	mycheck.pCheckbox[18] = (CButton*)GetDlgItem(IDC_CHECK19);
	mycheck.pCheckbox[19] = (CButton*)GetDlgItem(IDC_CHECK20);
	mycheck.pCheckbox[20] = (CButton*)GetDlgItem(IDC_CHECK21);
	mycheck.pCheckbox[21] = (CButton*)GetDlgItem(IDC_CHECK22);
	mycheck.pCheckbox[22] = (CButton*)GetDlgItem(IDC_CHECK23);
	mycheck.pCheckbox[23] = (CButton*)GetDlgItem(IDC_CHECK24);
	mycheck.pCheckbox[24] = (CButton*)GetDlgItem(IDC_CHECK25);*/

	//��cv���ڳ�ʼ����picture�ؼ�
	namedWindow("view", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("view");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_STATIC_CV1)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	//��ʼ��������
	/*CRect rect;
	GetClientRect(rect);
	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.nMin = 0;
	si.nMax = 100;
	si.nPage = 5;
	si.fMask = SIF_POS | SIF_RANGE | SIF_PAGE;
	CSBar.SetScrollInfo(&si, TRUE);
	CSBar.GetWindowRect(rt_mvScroll);
	ScreenToClient(rt_mvScroll);*/
	bool bredraw = 0;
	CSBar.SetScrollRange(1, maxline, bredraw);
	CSBar.SetScrollPos(1, bredraw);
	SetDlgItemInt(IDC_HSCROLL_EDIT, 1);



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCKinectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCKinectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCKinectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCKinectDlg::OnBnClickedButton1()
{
	CBodyBasics myKinect;
	int x = 0;
	myKinect.InitializeDefaultSensor(x);
	if (x = 1) {
		onplay = 1;
		StartRecord.EnableWindow(TRUE);
		StopRecord.EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON6)->ShowWindow(SW_SHOW);
		CSBar.EnableWindow(FALSE);

		gesture1.EnableWindow(TRUE);
		gesture2.EnableWindow(TRUE);
		newfile();

		CString str;
		str.Format(_T("%d"), x);
		LPCTSTR pStr = LPCTSTR(str);


		//MessageBox(pStr);

		cvplay = false;
		cvluzhi = true;
		cvzhen = false;

		while (onplay) {
			myKinect.Update();
			if (waitKey(27) >= 0)//����ESC�˳�  
			{
				break;
			}
		}
	}
	else {
		MessageBox(L"Kinect2.0 disconnecting!");
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CMFCKinectDlg::OnBnClickedButton6()
{
	onplay = 0;
	StartRecord.EnableWindow(FALSE);
	StopRecord.EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	gesture1.EnableWindow(FALSE);
	gesture2.EnableWindow(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCKinectDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	exit(0);
}


void CMFCKinectDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���ù�����
	TCHAR szFliter[] = _T("TEXT��*.txt��|*.txt|");
	//���챣���ļ��Ի���
	CFileDialog fileDlg(FALSE, _T("txt"), _T("output"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFliter, this);
	CString SaveFilePath;

	//�ļ�·��
	if (IDOK == fileDlg.DoModal())
	{
		SaveFilePath = fileDlg.GetPathName();
	
	
	savefile=SaveFilePath;
	IsRecord = 1;
	MessageBox(L"Start Recording");
	CString StartRecording("Recording");
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	SetDlgItemText(IDC_EDIT2,StartRecording);

	m_BrushBack = RGB(0, 225, 0);

	string x;
	switch (maxppbody)
	{
	case 1:x = "number of people:1\n";
		break;
	case 2:x = "number of people:2\n";
		break;
	case 3:x = "number of people:3\n";
		break;
	case 4:x = "number of people:4\n";
		break;
	case 5:x = "number of people:5\n";
		break;
	case 6:x = "number of people:6\n";
		break;
	default:
		break;
	}
	outfile(x, savefile);
	string y = "point";
	char z[8];
	for (int i = 0; i < 25; i++)
	{
		sprintf_s(z, "%d", i);
		if (pCheckbox[i] == 1) {
			x = y + z + ".x," + "point" + z + ".y,  ";
			outfile(x, savefile);
		}
	}
	x = "\n";
	outfile(x, savefile);


	GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK3)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK4)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK5)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK6)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK7)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK8)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK9)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK10)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK11)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK12)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK13)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK14)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK15)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK16)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK17)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK18)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK19)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK20)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK21)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK22)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK23)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK24)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK25)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO8)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO9)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO10)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO11)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO12)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO13)->EnableWindow(FALSE);
	}
}


void CMFCKinectDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	IsRecord = 0;
	MessageBox(L"Stop Recording");
	CString StopRecording("Recording Stopped");
	SetDlgItemText(IDC_EDIT2, StopRecording);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	//Record_btn.SetWindowTextW(L"����ֹͣ��¼");
	//mycheck.pCheckbox[0] = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	m_BrushBack = RGB(255, 0, 0);

	GetDlgItem(IDC_CHECK1)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK3)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK4)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK5)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK6)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK7)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK8)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK9)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK10)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK11)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK12)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK13)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK14)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK15)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK16)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK17)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK18)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK19)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK20)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK21)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK22)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK23)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK24)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK25)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO4)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO8)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO9)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO10)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO11)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO12)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO13)->EnableWindow(TRUE);
	//onplay = 0;
	//StartRecord.EnableWindow(FALSE);
	//StopRecord.EnableWindow(FALSE);
	//GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
	//GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	//GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	//GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	//gesture1.EnableWindow(FALSE);
	//gesture2.EnableWindow(FALSE);
}




void CMFCKinectDlg::OnBnClickedButton4()
{
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
	CVplayerclass KinectPlayer;

	//���ù�����
	TCHAR szFilter[] = _T("TEXT��*.txt��|*.txt|");

	//���챣���ļ��Ի���
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);

	CString strFilePath;

	//��ʾ���ļ��Ի���
	if (IDOK == fileDlg.DoModal())
	{
		//���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, strFilePath);
		CSBar.EnableWindow(FALSE);
		//string filename = "C:\\Users\\AA\\Desktop\\output.txt";
		ifstream sfile;
		//sfile.open(filename);
		sfile.open(strFilePath);
		kline = 0;
		int i = 1;
		int j = 1;
		char*pline; //line ָ��
		pline = NULL;
		char* c;
		char *gg;
		const char *d = ",";
		string line;

		double point[301] = {0};

		getline(sfile, line);

		const int len = line.length();
		c = new char[len + 1];
		strcpy_s(c, len + 1, line.c_str());

		cvplay = true;
		cvluzhi = false;
		cvzhen = false;

		KinectPlayer.chushihua();
		while (!sfile.eof()) {
			if (cvplay == false)break;
			kline = kline + 1;
			i = 1;
			pline = strtok_s(c, d, &gg);
			while (pline != NULL)
			{
				point[i] = atof(pline);
				printf("\t");
				pline = strtok_s(NULL, d, &gg);
				i++;
			}
			if (waitKey(27) >= 0)//����ESC�˳�  
			{
				break;
			}
			KinectPlayer.update(point);


			getline(sfile, line);
			const int len = line.length();
			c = new char[len + 1];
			strcpy_s(c, len + 1, line.c_str());
		}
		sfile.close();
	}


	////string filename = "C:\\Users\\AA\\Desktop\\output.txt";
	//ifstream sfile;
	////sfile.open(filename);
	//sfile.open(strFilePath);
	//kline = 0;
	//int i = 1;
	//int j = 1;
	//char*pline; //line ָ��
	//pline = NULL;
	//char* c;
	//char *gg;
	//const char *d = ",";
	//string line;

	//double point[51];

	//getline(sfile, line);

	//const int len = line.length();
	//c = new char[len + 1];
	//strcpy(c, line.c_str());

	//KinectPlayer.chushihua();
	//while (!sfile.eof()) {
		//kline = kline + 1;
		//i = 1;
		//pline = strtok_s(c, d, &gg);
		//while (pline != NULL)
		//{
			//point[i] = atof(pline);
			//printf("\t");
			//pline = strtok_s(NULL, d, &gg);
			//i++;
		//}
		//KinectPlayer.update(point);


		//getline(sfile,line);
		//const int len = line.length();
		//c = new char[len + 1];
		//strcpy(c, line.c_str());
	//}
	
	
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CMFCKinectDlg::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[0] = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[1] = ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[2] = ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[3] = ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[4] = ((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[5] = ((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[6] = ((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[7] = ((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[8] = ((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[9] = ((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[10] = ((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[11] = ((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[12] = ((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[13] = ((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[14] = ((CButton*)GetDlgItem(IDC_CHECK15))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[15] = ((CButton*)GetDlgItem(IDC_CHECK16))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck17()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[16] = ((CButton*)GetDlgItem(IDC_CHECK17))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck18()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[17] = ((CButton*)GetDlgItem(IDC_CHECK18))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck19()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[18] = ((CButton*)GetDlgItem(IDC_CHECK19))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck20()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[19] = ((CButton*)GetDlgItem(IDC_CHECK20))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck21()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[20] = ((CButton*)GetDlgItem(IDC_CHECK21))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck22()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[21] = ((CButton*)GetDlgItem(IDC_CHECK22))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck23()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[22] = ((CButton*)GetDlgItem(IDC_CHECK23))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck24()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[23] = ((CButton*)GetDlgItem(IDC_CHECK24))->GetCheck();
}


void CMFCKinectDlg::OnBnClickedCheck25()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pCheckbox[24] = ((CButton*)GetDlgItem(IDC_CHECK25))->GetCheck();
}







void CMFCKinectDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	gesture = 1;
}


void CMFCKinectDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	gesture = 0;
}


void CMFCKinectDlg::OnStnClickedStaticCv1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCKinectDlg::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	onpicture = 1;
}


void CMFCKinectDlg::OnBnClickedRadio4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	onpicture = 2;
}


void CMFCKinectDlg::OnBnClickedRadio8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	maxppbody = 1;
}


void CMFCKinectDlg::OnBnClickedRadio9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	maxppbody = 2;
}


void CMFCKinectDlg::OnBnClickedRadio10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	maxppbody = 3;
}


void CMFCKinectDlg::OnBnClickedRadio11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	maxppbody = 4;
}


void CMFCKinectDlg::OnBnClickedRadio12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	maxppbody = 5;
}


void CMFCKinectDlg::OnBnClickedRadio13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	maxppbody = 6;
}


void CMFCKinectDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CVplayerclass KinectPlayer;
	CString strFilePath;
	GetDlgItemText(IDC_EDIT1, strFilePath);
	ifstream sfile;
	//sfile.open(filename);
	sfile.open(strFilePath);
	kline = 0;
	int i = 1;
	int j = 1;
	char*pline; //line ָ��
	pline = NULL;
	char* c;
	char *gg;
	const char *d = ",";
	string line;

	double point[301] = { 0 };

	getline(sfile, line);

	const int len = line.length();
	c = new char[len + 1];
	strcpy_s(c, len + 1, line.c_str());

	cvplay = true;
	cvluzhi = false;
	cvzhen = false;

	KinectPlayer.chushihua();
	while (!sfile.eof()) {
		if (cvplay == false)break;
		kline = kline + 1;
		i = 1;
		pline = strtok_s(c, d, &gg);
		while (pline != NULL)
		{
			point[i] = atof(pline);
			printf("\t");
			pline = strtok_s(NULL, d, &gg);
			i++;
		}
		if (waitKey(27) >= 0)//����ESC�˳�  
		{
			break;
		}
		KinectPlayer.update(point);


		getline(sfile, line);
		const int len = line.length();
		c = new char[len + 1];
		strcpy_s(c, len + 1, line.c_str());
	}
	sfile.close();
}


void CMFCKinectDlg::OnBnClickedButton9()
{
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CVplayerclass KinectPlayer;
	//���ù�����
	TCHAR szFilter[] = _T("TEXT��*.txt��|*.txt|");

	//���챣���ļ��Ի���
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);

	CString strFilePath;

	//��ʾ���ļ��Ի���
	if (IDOK == fileDlg.DoModal()) {
		GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);

		strFilePath = fileDlg.GetPathName();
		openfile = strFilePath;
		ifstream sfile;
		//sfile.open(filename);
		sfile.open(strFilePath);
		kline = 0;
		int i = 1;
		char*pline; //line ָ��
		pline = NULL;
		char* c;
		char *gg;
		const char *d = ",";

		cvplay = false;
		cvluzhi = false;
		cvzhen = true;

		if (cvzhen) {
			string line;

			double point[301] = { 0 };
			getline(sfile, line);
			getline(sfile, line);
			getline(sfile, line);
			const int len = line.length();
			c = new char[len + 1];
			strcpy_s(c, len + 1, line.c_str());
			KinectPlayer.chushihua();
			i = 1;
			pline = strtok_s(c, d, &gg);
			while (pline != NULL)
			{
				point[i] = atof(pline);
				printf("\t");
				pline = strtok_s(NULL, d, &gg);
				i++;
			}
			KinectPlayer.update(point);
			sfile.close();

			ifstream kfile;
			kfile.open(strFilePath);
			getline(kfile, line);
			getline(kfile, line);
			int kline = 0;
			while (!kfile.eof()) {
				getline(kfile, line);
				kline = kline + 1;
			}
			maxline = kline;
			bool bredraw = 0;
			CSBar.EnableWindow(TRUE);
			CSBar.SetScrollRange(1, maxline, bredraw);
			CSBar.SetScrollPos(1, bredraw);
			SetDlgItemInt(IDC_HSCROLL_EDIT, 1);
			kfile.close();
		}
	}
}

void CMFCKinectDlg::OnNMThemeChangedScrollbar2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
	// ���� _WIN32_WINNT ���� >= 0x0501��
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CMFCKinectDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	pos = CSBar.GetScrollPos();
	switch (nSBCode) {
	case SB_LINEUP:pos -= 1;
		break;
	case SB_LINEDOWN:pos += 1;
		break;
	case SB_PAGEUP:pos -= 10;
		break;
	case SB_PAGEDOWN:pos += 10;
		break;
	case SB_TOP:pos = 1;
		break;
	case SB_BOTTOM:pos = maxline;
		break;
	case SB_THUMBPOSITION:pos = nPos;
		break;
	default:SetDlgItemInt(IDC_HSCROLL_EDIT, pos);
		return;
	}
	bool bredraw = 0;
	CSBar.SetScrollPos(pos, bredraw);

	CVplayerclass KinectPlayer;
	ifstream sfile;
	//sfile.open(filename);
	sfile.open(openfile);
	kline = 0;
	int i = 1;
	char*pline; //line ָ��
	pline = NULL;
	char* c;
	char *gg;
	const char *d = ",";
	string line;

	double point[301] = { 0 };
	getline(sfile, line);
	getline(sfile, line);
	for (int j = 1; j <= pos; j++)
	{
		getline(sfile, line);
	}
	const int len = line.length();
	c = new char[len + 1];
	strcpy_s(c, len + 1, line.c_str());
	KinectPlayer.chushihua();
	i = 1;
	pline = strtok_s(c, d, &gg);
	while (pline != NULL)
	{
		point[i] = atof(pline);
		printf("\t");
		pline = strtok_s(NULL, d, &gg);
		i++;
	}
	KinectPlayer.update(point);
	sfile.close();
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMFCKinectDlg::OnEnChangeHscrollEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//if (EDITpos <= maxline)
	//{
	//	CSBar.SetScrollPos(EDITpos);
	//}
	//if (EDITpos > maxline) {
	//	CSBar.SetScrollPos(maxline);
	//	EDITpos = maxline;
	//}
}


void CMFCKinectDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if (firstline<1 || firstline>lastline || lastline > maxline)
	{
		MessageBox(L"please input correct cutting frames");
	}
	else
	{
		//���ù�����
		TCHAR szFliter[] = _T("TEXT��*.txt��|*.txt|");
		//���챣���ļ��Ի���
		CFileDialog fileDlg(FALSE, _T("txt"), _T("output"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFliter, this);
		CString SaveFilePath;
		if (IDOK == fileDlg.DoModal())
		{
			SaveFilePath = fileDlg.GetPathName();
		}

		ifstream sfile;
		sfile.open(openfile);
		kline = 0;
		int i = 1;
		string line;
		getline(sfile, line);
		outfile(line, SaveFilePath);
		outfile("\n", SaveFilePath);
		getline(sfile, line);
		outfile(line, SaveFilePath);
		outfile("\n", SaveFilePath);
		for (int j = 1; j < firstline; j++)
		{
			getline(sfile, line);
		}
		for (int j = firstline; j <= lastline; j++)
		{
			getline(sfile, line);
			outfile(line, SaveFilePath);
			outfile("\n", SaveFilePath);
		}
		sfile.close();
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
		CSBar.EnableWindow(FALSE);
	}

}



void CMFCKinectDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CMFCKinectDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CMFCKinectDlg::OnBnClickedRadio5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	onpicture = 3;
}


void CMFCKinectDlg::OnBnClickedRadio6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	onpicture = 4;
}


void CMFCKinectDlg::OnBnClickedRadio7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	onpicture = 5;
}


//HBRUSH CMFCKinectDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//
//	// TODO:  �ڴ˸��� DC ���κ�����
//	pDC->SetTextColor(m_ForeColor);
//	pDC->SetBkColor(m_BackColor);
//	return (HBRUSH)m_BkBrush.GetSafeHandle();
//
//	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
//	return hbr;
//}


HBRUSH CMFCKinectDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

		if (pWnd->GetDlgCtrlID() == IDC_EDIT2)
		{
			pDC->SetTextColor(m_BrushBack);

		}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
