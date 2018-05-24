
// MFCKinect.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include <Kinect.h>
#include <opencv2\opencv.hpp>
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>//�ַ���
#include <conio.h>
#include <windows.h>

using namespace std;
using namespace cv;



// CMFCKinectApp: 
// �йش����ʵ�֣������ MFCKinect.cpp
//

class CMFCKinectApp : public CWinApp
{
public:
	CMFCKinectApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCKinectApp theApp;




// Safe release for interfaces
template<class Interface>
inline void SafeRelease(Interface *& pInterfaceToRelease)
{
	if (pInterfaceToRelease != NULL)
	{
		pInterfaceToRelease->Release();
		pInterfaceToRelease = NULL;
	}
}

class CBodyBasics
{
	//kinect 2.0 ����ȿռ�ĸ�*���� 424 * 512���ڹ�������˵��
	static const int        cDepthWidth = 512;
	static const int        cDepthHeight = 424;

	static const int        cColorWidth = 1920;   //��ɫͼ�Ĵ�С  
	static const int        cColorHeight = 1080;

public:
	CBodyBasics();
	~CBodyBasics();
	void                    Update();//��ùǼܡ�������ֵͼ����ȡ���ͼ�ȵ���Ϣ
	void                 InitializeDefaultSensor( int x);//���ڳ�ʼ��kinect

	//void                    ProcessDepth(const UINT16* pBuffer, int nWidth, int nHeight, USHORT nMinDepth, USHORT nMaxDepth);   //����õ������ͼ����  
	//void                    ProcessColor(RGBQUAD* pBuffer, int nWidth, int nHeight);   //����õ��Ĳ�ɫͼ����  

private:
	IKinectSensor*          m_pKinectSensor;//kinectԴ
	ICoordinateMapper*      m_pCoordinateMapper;//��������任
	IBodyFrameReader*       m_pBodyFrameReader;//���ڹǼ����ݶ�ȡ
	IDepthFrameReader*      m_pDepthFrameReader;//����������ݶ�ȡ
	RGBQUAD*                m_pDepthRGBX;
	IColorFrameReader*      m_pColorFrameReader;// Color reader  
	RGBQUAD*                m_pColorRGBX;
												//!!IBodyIndexFrameReader*  m_pBodyIndexFrameReader;//���ڱ�����ֵͼ��ȡ

												//ͨ����õ�����Ϣ���ѹǼܺͱ�����ֵͼ������
	void                    ProcessBody(int nBodyCount, IBody** ppBodies);
	//���Ǽܺ���
	void DrawBone(int pbody);
	//���ֵ�״̬����
	void DrawHandState(const DepthSpacePoint depthSpacePosition, HandState handState);

	//��ʾͼ���Mat
	cv::Mat skeletonImg;
	cv::Mat depthImg;
	cv::Mat depthcolorImg;
};

void outfile(string x, CString filepath);

void outpoint(int* pointSet, CString filepath);

void newfile();

void Filtering(DepthSpacePoint* pointSet, int pbody);

//void LineKinectreader(int Lineindex);
class CVplayerclass {
	static const int        cDepthWidth = 512;
	static const int        cDepthHeight = 424;

public:
	void chushihua();//��ʼ��
	void update(double point[51]);
	void process(double point[51]);
	void cvplay(double x, double y);
	cv::Mat cvplayer;
};

//void split(const char * str, const char * deli, vector<string> *list);//�ָ��ַ���