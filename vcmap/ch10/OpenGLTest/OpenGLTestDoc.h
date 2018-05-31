// OpenGLTestDoc.h : COpenGLTestDoc 类的接口
//


#pragma once


class COpenGLTestDoc : public CDocument
{
protected: // 仅从序列化创建
	COpenGLTestDoc();
	DECLARE_DYNCREATE(COpenGLTestDoc)

// 属性
public:
	void RenderScene(void);
	enum GLDisplayListNames { ArmPart1, ArmPart2 };
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~COpenGLTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


