#pragma once


// CHitCounter

class CHitCounter : public CStatic
{
	DECLARE_DYNAMIC(CHitCounter)

public:
	int m_hits;
	int GetHits() const { return m_hits; }
	void SetHits(int val) { m_hits = val; }

	CHitCounter();
	virtual ~CHitCounter();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClicked();
};


