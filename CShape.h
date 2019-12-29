#pragma once
#include <afx.h>
#define SQRT3 1.73
#define SQRT2 1.41
enum ElementType { NOTSET, SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };

class CShape : public CObject
{
public:
	CShape();
	virtual ~CShape();
	virtual void Draw(CDC*pDC) = 0;//绘制图元
	virtual bool IsMatched(CPoint pnt) = 0;//点是否落在图形内部
	virtual void Serialize(CArchive& ar) = 0;
	void get(COLORREF Bc, int Bt, int Bw, COLORREF  Fc, int Ft);
protected:
	ElementType Type;//图元类型
	int OrgX;//原点坐标
	int OrgY;
	COLORREF   BorderColor;//边界颜色
	int BorderType;//边界线型--实线、虚线、虚点线等
	int BorderWidth;//边界宽度
	COLORREF  FillColor;//填充颜色
	int FillType;//填充类型--实心、双对角、十字交叉等
};
class CSquare : public CShape
{
public:
	CSquare();
	CSquare(int x, int y, int w);
	void Draw(CDC*pDC);//绘制正方形
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
private:
	int width;

	DECLARE_SERIAL(CSquare)//声明类CSquare支持序列化
};
// CShape

class CRectangle :public CShape

{

private:
	int width;//矩形的宽
	int height;//矩形的高
public:

	CRectangle();
	CRectangle(int x, int y, int w, int h);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);

	~CRectangle();

	DECLARE_SERIAL(CRectangle); //声明类WRectangle是支持序列化

};
class CCircle :public CShape
{
private:
	int Radius;//圆的半径
public:

	CCircle();
	~CCircle();
	CCircle(int x, int y, int r);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CCircle); //声明类WCircle是支持序列化
};
class CEllipse :public CShape
{
private:

	int HRadius;//椭圆的水平半轴
	int VRadius;//椭圆的垂直半轴

public:

	CEllipse();
	~CEllipse();
	CEllipse(int x, int y, int hr, int vr);

	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CEllipse); //声明类WEllipse是支持序列化
};
class CTriangle :public CShape

{

private:

	int Length;//正三角形的边长

public:

	CTriangle();
	~CTriangle();
	CTriangle(int x, int y, int l);

	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CTriangle)//声明类WRectangle是支持序列化

};

class CText :public CShape

{

private:

	CString TextContent; // 文本的内容
	int height;
	int TextAngle; // 文本的旋转角度

public:

	CText();
	~CText();
	CText(int x, int y, CString t, int ta,int h);

	void Draw(CDC* pDC);//绘制文本函数
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CText)//声明类WRectangle是支持序列化
	

};
