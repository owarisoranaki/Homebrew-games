// “G
class CEnemy : public CMyMover {
public:
	int Ept,Ept2;
	int ETP;
	void* operator new(size_t n) { return EnemyList.New(n); }
	void operator delete(void* p) { EnemyList.Delete(p); }
	CEnemy() : CMyMover(EnemyList) {}
	void Reset();
	void Move();
};

class CEnemy2 : public CMyMover {
public:
	int ATP=0;
	int Bst=0;
	int Ept2;
	int ETP2;
	void* operator new(size_t n){ return Enemy2List.New(n); }
	void operator delete(void* p) { Enemy2List.Delete(p); }
	CEnemy2() : CMyMover(Enemy2List) {}
	void Reset();
	void Move();
};

class CEnemy3 : public CMyMover {
public:
	float LEN_COPY = 0;
	int COUNT = 0;
	CVector HOME_POSITION = 0;
	float X_COPY = 0;
	int TEXTURE_CHANGE = 0;
	float X=0, Y = 0;
	CVector HomePosition;
	int Bst = 0;
	int Ept3;
	int ETP2;
	void* operator new(size_t n){ return Enemy3List.New(n); }
	void operator delete(void* p) { Enemy3List.Delete(p); }
	CEnemy3() : CMyMover(Enemy3List) {}
	void Reset();
	void Move();
};
class CEnemy5 : public CMyMover {
public:
	int Bst = 0;
	int Ept3;
	int ETP2;
	void* operator new(size_t n){ return Enemy5List.New(n); }
	void operator delete(void* p) { Enemy5List.Delete(p); }
	CEnemy5() : CMyMover(Enemy5List) {}
	void Reset();
	void Move();
};
class CEnemy6 : public CMyMover {
public:
	int Bst = 0;
	int Ept3;
	int ETP2;
	void* operator new(size_t n){ return Enemy6List.New(n); }
	void operator delete(void* p) { Enemy6List.Delete(p); }
	CEnemy6() : CMyMover(Enemy6List) {}
	void Reset();
	void Move();
};
class CEnemy7 : public CMyMover {
public:
	int MutekiTime=0;//’Ç‰Á
	int Bst = 0;
	int Ept3;
	int ETP2;
	void* operator new(size_t n){ return Enemy7List.New(n); }
	void operator delete(void* p) { Enemy7List.Delete(p); }
	CEnemy7() : CMyMover(Enemy7List) {}
	void Reset();
	void Move();
};
class CEnemy8 : public CMyMover {
public:
	int muteki1=0;
	int MutekiTime = 0;
	int MutekiTime1 = 0;
	int atama = 0;
	int wp = 0;
	int KM = 0;
	int kao=0;
	//int Bst = 0;
	int Ept3;
	int ETP2;
	void* operator new(size_t n){ return Enemy8List.New(n); }
	void operator delete(void* p) { Enemy8List.Delete(p); }
	CEnemy8() : CMyMover(Enemy8List) {}
	void Reset();
	void Move();
};
class CEnemy9 : public CMyMover {
public:
	int wp = 0;
	int KM = 0;
	int kao = 0;
	//int Bst = 0;
	int Ept3;
	int ETP2;
	void* operator new(size_t n){ return Enemy9List.New(n); }
	void operator delete(void* p) { Enemy9List.Delete(p); }
	CEnemy9() : CMyMover(Enemy9List) {}
	void Reset();
	void Move();
};
class CEnemy10 : public CMyMover {
public:
	int wp = 0;
	int KM = 0;
	int kao = 0;
	//int Bst = 0;
	int Ept3;
	int ETP2;
	void* operator new(size_t n){ return Enemy10List.New(n); }
	void operator delete(void* p) { Enemy10List.Delete(p); }
	CEnemy10() : CMyMover(Enemy10List) {}
	void Reset();
	void Move();
};