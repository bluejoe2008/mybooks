class CPerson : public CObject
{
DECLARE_SERIAL(CPerson)
private:
	CString _name;
	int _age;
	bool _gender;
	CString _words;
public:
	CPerson();
	CPerson(CString name, int age, bool gender = true);
	CString getName();
	CString getWords();
	void setWords(CString words);
	int getAge();
	bool isMale();
	void say();
	void say(CString msg);
	virtual void Serialize(CArchive& ar);
};

