﻿
// MFCGuideView.h: CMFCGuideView 类的接口
//

#pragma once


class CMFCGuideView : public CView
{
protected: // 仅从序列化创建
	CMFCGuideView() noexcept;
	DECLARE_DYNCREATE(CMFCGuideView)

// 特性
public:
	CMFCGuideDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCGuideView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCGuideView.cpp 中的调试版本
inline CMFCGuideDoc* CMFCGuideView::GetDocument() const
   { return reinterpret_cast<CMFCGuideDoc*>(m_pDocument); }
#endif

