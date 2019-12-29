#include "stdafx.h"
#include "CShape.h"
IMPLEMENT_SERIAL(CSquare, CObject, 1)//实现类CSquare的序列化，指定版本为1
IMPLEMENT_SERIAL(CRectangle, CObject, 1)
IMPLEMENT_SERIAL(CCircle, CObject, 1)
IMPLEMENT_SERIAL(CEllipse, CObject, 1)
IMPLEMENT_SERIAL(CTriangle, CObject, 1)
IMPLEMENT_SERIAL(CText, CObject, 1)
CShape::CShape()
{
}


CShape::~CShape()
{
}

void CShape::get(COLORREF Bc, int Bt, int Bw, COLORREF Fc, int Ft)
{
	BorderColor = Bc;
	BorderType = Bt;
	BorderWidth = Bw;
	FillColor = Fc;
	FillType = Ft;
}

CSquare::CSquare()
{
}

CSquare::CSquare(int x, int y, int w)
{
	OrgX = x;
	OrgY = y;
	width = w;
}

void CSquare::Draw(CDC * pDC)
{
	
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width / 2, OrgY + width / 2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CSquare::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateRectRgn(OrgX - width / 2, OrgY + width / 2, OrgX + width / 2, OrgY - width / 2);
	bool matched = rgn.PtInRegion(pnt);
	if (1 == matched)
		return true;
	else
		return false;
}

void CSquare::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
	}
}
//长方形
CRectangle::CRectangle()
{
}

CRectangle::CRectangle(int x, int y, int w, int h)
{
	OrgX = x;
	OrgY = y;
	width = w;
	height = h;
}

void CRectangle::Draw(CDC * pDC)
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Rectangle(OrgX - width / 2, OrgY - height / 2, OrgX + width / 2, OrgY + height / 2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CRectangle::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateRectRgn(OrgX - width / 2, OrgY - height / 2, OrgX + width / 2, OrgY + height / 2);
	bool matched = rgn.PtInRegion(pnt);
	if (1 == matched)
		return true;
	else
		return false;
}

void CRectangle::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
		ar << height;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
		ar >> height;
	}
}

CRectangle::~CRectangle()
{
}

CCircle::CCircle()
{
}

CCircle::~CCircle()
{
}

CCircle::CCircle(int x, int y, int r)
{
	OrgX = x;
	OrgY = y;
	Radius = r;
}

void CCircle::Draw(CDC * pDC)
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Ellipse(OrgX - Radius/ 2, OrgY - Radius / 2, OrgX + Radius / 2, OrgY + Radius / 2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CCircle::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateEllipticRgn(OrgX - Radius / 2, OrgY - Radius / 2, OrgX + Radius / 2, OrgY + Radius / 2);
	bool matched = rgn.PtInRegion(pnt);
	if (1 == matched)
		return true;
	else
		return false;
}

void CCircle::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << Radius;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> Radius;
	}
}

CEllipse::CEllipse()
{
}

CEllipse::~CEllipse()
{
}

CEllipse::CEllipse(int x, int y, int vr, int hr)
{
	OrgX = x;
	OrgY = y;
	VRadius = vr;
	HRadius = hr;
}

void CEllipse::Draw(CDC * pDC)
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Ellipse(OrgX - VRadius / 2, OrgY - HRadius / 2, OrgX + VRadius / 2, OrgY + HRadius / 2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CEllipse::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateEllipticRgn(OrgX - VRadius / 2, OrgY - HRadius / 2, OrgX + VRadius / 2, OrgY + HRadius / 2);
	bool matched = rgn.PtInRegion(pnt);
	if (1 == matched)
		return true;
	else
		return false;
}

void CEllipse::Serialize(CArchive & ar)
{

	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << VRadius;
		ar << HRadius;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> VRadius;
		ar >> HRadius;
	}
}

CTriangle::CTriangle()
{
}

CTriangle::~CTriangle()
{
}

CTriangle::CTriangle(int x, int y, int l)
{
	OrgX = x;
	OrgY = y;
	Length = l;
}

void CTriangle::Draw(CDC * pDC)
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	//绘制图形
	double x1 = double(OrgX), y1 = double(OrgY) - double(Length) / SQRT3;
	double x2 = double(OrgX) - double(Length) / 2, y2 = double(OrgY) + double(Length) / (2 * SQRT3);
	double x3 = double(OrgX) + double(Length) / 2, y3 = double(OrgY) + double(Length) / (2 * SQRT3);
	CPoint points[3] = { CPoint(int(x1), int(y1)), CPoint(int(x2), int(y2)), CPoint(int(x3), int(y3)) };
	pDC->Polygon(points, 3);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CTriangle::IsMatched(CPoint pnt)
{
	CRgn rgn;
	CPoint ptVertex[3];
	ptVertex[0].x = long(OrgX - Length / 2);
	ptVertex[0].y = long(OrgY + (sqrt(1.0 / 12)) * Length);
	ptVertex[1].x = long(OrgX);
	ptVertex[1].y = long(OrgY - (sqrt(1.0 / 3)) * Length);
	ptVertex[2].x = long(OrgX + (Length / 2));
	ptVertex[2].y = long(OrgY + (sqrt(1.0 / 12)) * Length);
	rgn.CreatePolygonRgn(ptVertex, 3, ALTERNATE);
	BOOL flag = rgn.PtInRegion(pnt);
	if (flag)
		return true;
	else
		return false;
}

void CTriangle::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << Length;
	}
	else
	{
		//读取文件
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;
		ar >> BorderColor >> BorderType >> BorderWidth;
		ar >> FillColor >> FillType;
		ar >> Length;
	}
}

CText::CText()
{
}

CText::~CText()
{
}

CText::CText(int x, int y, CString t, int ta,int h)
{
	OrgX = x;
	OrgY = y;
	TextContent = t;
	TextAngle = ta*10;
	height = h;
}

void CText::Draw(CDC * pDC)
{
	LOGFONT logfont;
	lstrcpy(logfont.lfFaceName, _T("楷体_GB2312"));
	logfont.lfWeight = 0;
	logfont.lfWidth = 40;
	logfont.lfHeight = height;
	logfont.lfEscapement = TextAngle;
	logfont.lfUnderline = FALSE;
	logfont.lfItalic = FALSE;
	logfont.lfStrikeOut = FALSE;
	logfont.lfCharSet = GB2312_CHARSET;
	HFONT hFont, *hOldFont;
	hFont = CreateFontIndirect(&logfont);
	hOldFont = (HFONT*)pDC->SelectObject(hFont);
	pDC->SetBkColor(FillColor);
	pDC->SetTextColor(BorderColor);
	pDC->TextOutW(OrgX, OrgY, TextContent);
	pDC->SelectObject(hOldFont);
}

bool CText::IsMatched(CPoint pnt)
{
	SIZE  size;
	double a = TextAngle * 3.1415926 / 180.0;
	HFONT pNewFont = CreateFont(70, 40, TextAngle, 0, 40, FALSE, FALSE, FALSE, GB2312_CHARSET, OUT_CHARACTER_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH&FF_SWISS, _T("楷体_GB2312"));
	HDC hDC = CreateCompatibleDC(NULL);
	SelectObject(hDC, pNewFont);
	if (GetTextExtentPoint32(hDC, TextContent, wcslen(TextContent), &size))
	{
		CRgn rgn;
		POINT ptVertex[4];
		ptVertex[0].x = OrgX;
		ptVertex[0].y = OrgY;
		ptVertex[1].x = long(OrgX + cos(a) * size.cx);
		ptVertex[1].y = long(OrgY - sin(a) * size.cx);
		ptVertex[2].x = long(OrgX + sin(a) * size.cy + cos(a) * size.cx);
		ptVertex[2].y = long(OrgY + cos(a) * size.cy - sin(a) * size.cx);
		ptVertex[3].x = long(OrgX + sin(a) * size.cy);
		ptVertex[3].y = long(OrgY + cos(a) * size.cy);
		rgn.CreatePolygonRgn(ptVertex, 4, WINDING);
		BOOL flag = rgn.PtInRegion(pnt);
		if (flag)
			return true;
		else
			return false;
	}
	else
		return false;
}

void CText::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << TextContent << TextAngle;
	}
	else

	{
		//读取文件
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;
		ar >> BorderColor >> BorderType >> BorderWidth;
		ar >> FillColor >> FillType;
		ar << TextContent << TextAngle;
	}
}
