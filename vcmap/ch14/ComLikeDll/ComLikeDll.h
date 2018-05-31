#define NOKIA_MOBILE_PHONE	0
#define NATIVE_MOBILE_PHONE	1

bool _declspec(dllexport) CreateObject(int type, void ** ppObject);
