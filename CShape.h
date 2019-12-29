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
	virtual void Draw(CDC*pDC) = 0;//����ͼԪ
	virtual bool IsMatched(CPoint pnt) = 0;//���Ƿ�����ͼ���ڲ�
	virtual void Serialize(CArchive& ar) = 0;
	void get(COLORREF Bc, int Bt, int Bw, COLORREF  Fc, int Ft);
protected:
	ElementType Type;//ͼԪ����
	int OrgX;//ԭ������
	int OrgY;
	COLORREF   BorderColor;//�߽���ɫ
	int BorderType;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	int BorderWidth;//�߽���
	COLORREF  FillColor;//�����ɫ
	int FillType;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
};
class CSquare : public CShape
{
public:
	CSquare();
	CSquare(int x, int y, int w);
	void Draw(CDC*pDC);//����������
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
private:
	int width;

	DECLARE_SERIAL(CSquare)//������CSquare֧�����л�
};
// CShape

class CRectangle :public CShape

{

private:
	int width;//���εĿ�
	int height;//���εĸ�
public:

	CRectangle();
	CRectangle(int x, int y, int w, int h);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);

	~CRectangle();

	DECLARE_SERIAL(CRectangle); //������WRectangle��֧�����л�

};
class CCircle :public CShape
{
private:
	int Radius;//Բ�İ뾶
public:

	CCircle();
	~CCircle();
	CCircle(int x, int y, int r);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CCircle); //������WCircle��֧�����л�
};
class CEllipse :public CShape
{
private:

	int HRadius;//��Բ��ˮƽ����
	int VRadius;//��Բ�Ĵ�ֱ����

public:

	CEllipse();
	~CEllipse();
	CEllipse(int x, int y, int hr, int vr);

	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CEllipse); //������WEllipse��֧�����л�
};
class CTriangle :public CShape

{

private:

	int Length;//�������εı߳�

public:

	CTriangle();
	~CTriangle();
	CTriangle(int x, int y, int l);

	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CTriangle)//������WRectangle��֧�����л�

};

class CText :public CShape

{

private:

	CString TextContent; // �ı�������
	int height;
	int TextAngle; // �ı�����ת�Ƕ�

public:

	CText();
	~CText();
	CText(int x, int y, CString t, int ta,int h);

	void Draw(CDC* pDC);//�����ı�����
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CText)//������WRectangle��֧�����л�
	

};
