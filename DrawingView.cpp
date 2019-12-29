
// DrawingView.cpp: CDrawingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"
#include "DrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawingView

IMPLEMENT_DYNCREATE(CDrawingView, CView)

BEGIN_MESSAGE_MAP(CDrawingView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()

// CDrawingView 构造/析构

CDrawingView::CDrawingView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDrawingView::~CDrawingView()
{
}

BOOL CDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawingView 绘图

void CDrawingView::OnDraw(CDC* pDC)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		CShape* p = (CShape*)pDoc->m_Elements[i];
		p->Draw(pDC);
	}

	// TODO: 在此处为本机数据添加绘制代码
}


// CDrawingView 打印

BOOL CDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawingView 诊断

#ifdef _DEBUG
void CDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawingDoc* CDrawingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingDoc)));
	return (CDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingView 消息处理程序


void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if ((nFlags&MK_CONTROL) == MK_CONTROL)//Ctrl键按下
	{
		CDrawingDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)	return;
		Mydialog m_dialog;
		m_dialog.x = point.x;
		m_dialog.y = point.y;
		m_dialog.DoModal();
		CShape *p = NULL;
		switch (m_dialog.index)
		{
		case 0:
			p = new CSquare(m_dialog.x, m_dialog.y, m_dialog.wr);
			break;
		case 1:
			p = new CRectangle(m_dialog.x, m_dialog.y, m_dialog.wr, m_dialog.h);
			break;
		case 2:
			p = new CCircle(m_dialog.x, m_dialog.y, m_dialog.wr);
			break;
		case 3:
			p = new CEllipse(m_dialog.x, m_dialog.y, m_dialog.wr, m_dialog.h);
			break;
		case 4:
			p = new  CTriangle(m_dialog.x, m_dialog.y, m_dialog.wr);
			break;
		case 5:
			p = new  CText(m_dialog.x, m_dialog.y, m_dialog.text, m_dialog.wr, m_dialog.h);
			break;
		default:
		{
			MessageBox(L"请您选择图形类型！");
			break;
		}
		}
		p->get(m_dialog.color1, m_dialog.index1, m_dialog.lw, m_dialog.color2, m_dialog.index2);
		pDoc->m_Elements.Add(p);
		Invalidate();
		//// ----- 测试代码 end -----
		
	}
	CView::OnLButtonDown(nFlags, point);
}


void CDrawingView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)	return;
	if (pDoc->m_Elements.GetSize() > 0)
	{
		for (int i = (pDoc->m_Elements.GetSize() - 1); i >= 0; i--)
		{
			if (((CShape *)(pDoc->m_Elements[i]))->IsMatched(point))
			{
				Mydialog m_dialog;
				m_dialog.x = point.x;
				m_dialog.y = point.y;
				if (IDOK== m_dialog.DoModal())
				{
					CShape *p = NULL;
					switch (m_dialog.index)
					{
					case 0:
						p = new CSquare(m_dialog.x, m_dialog.y, m_dialog.wr);
						break;
					case 1:
						p = new CRectangle(m_dialog.x, m_dialog.y, m_dialog.wr, m_dialog.h);
						break;
					case 2:
						p = new CCircle(m_dialog.x, m_dialog.y, m_dialog.wr);
						break;
					case 3:
						p = new CEllipse(m_dialog.x, m_dialog.y, m_dialog.wr, m_dialog.h);
						break;
					case 4:
						p = new  CTriangle(m_dialog.x, m_dialog.y, m_dialog.wr);
						break;
					case 5:
						p = new  CText(m_dialog.x, m_dialog.y, m_dialog.text, m_dialog.wr, m_dialog.h);
						break;
					default:
					{
						MessageBox(L"请您选择图形类型！");
						break;
					}
					}
					p->get(m_dialog.color1, m_dialog.index1, m_dialog.lw, m_dialog.color2, m_dialog.index2);
					pDoc->m_Elements[i] = p;
					Invalidate();
					break;
				}
			}
		}
		CView::OnLButtonDblClk(nFlags, point);
	}
}

void CDrawingView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)	return;
	int num = pDoc->m_Elements.GetSize();
	if (pDoc->m_Elements.GetSize() > 0)
	{
		for (int i = (pDoc->m_Elements.GetSize() - 1); i >= 0; i--)
		{
			if (((CShape *)(pDoc->m_Elements[i]))->IsMatched(point))
			{
				int value = AfxMessageBox(L"你是否要删除？", MB_OKCANCEL);
				if (value == IDOK)
					pDoc->m_Elements.RemoveAt(i);
				Invalidate();
				break;

			}
		}
	}
	CView::OnRButtonDblClk(nFlags, point);
}
