// ���@
class CMyShip : public CMyMover {
public:
	int kurima = 0;
	int Play = 0;
	int TT=0;
	int state1=0;
	int bom = 0;
	int syot=0;
	int kura;
	//int BP=0;//�ǉ�
	int pause;//�ǉ�
	int MutekiTime;//�ǉ�
	void* operator new(size_t n) { return MyShipList.New(n); }
	void operator delete(void* p) { MyShipList.Delete(p); }
	CMyShip() : CMyMover(MyShipList) {}
	void Reset();
	void Move();
};

