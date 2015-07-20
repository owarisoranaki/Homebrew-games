// •Ší
class CWeapon : public CMyMover {
public:
	int wp = 0;
	void* operator new(size_t n) { return WeaponList.New(n); }
	void operator delete(void* p) { WeaponList.Delete(p); }
	CWeapon() : CMyMover(WeaponList) {}
	void Reset();
	void Move();
};
//’Ç‰Á
class CWeapon1 : public CMyMover {
public:
	void* operator new(size_t n){ return WeaponList.New(n); }
	void operator delete(void* p) { WeaponList.Delete(p); }
	CWeapon1() : CMyMover(WeaponList) {}
	void Reset();
	void Move();
};

//’Ç‰Á
class CWeapon2 : public CMyMover {
public:
	int wp = 0;
	void* operator new(size_t n){ return Weapon2List.New(n); }
	void operator delete(void* p) { Weapon2List.Delete(p); }
	CWeapon2() : CMyMover(Weapon2List) {}
	void Reset();
	void Move();
};

//’Ç‰Á
class CWeapon3 : public CMyMover {
public:

	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon3List.New(n); }
	void operator delete(void* p) { Weapon3List.Delete(p); }
	CWeapon3() : CMyMover(Weapon3List) {}
	void Reset();
	void Move();
};

//’Ç‰Á
class CWeapon4 : public CMyMover {
public:

	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon4List.New(n); }
	void operator delete(void* p) { Weapon4List.Delete(p); }
	CWeapon4() : CMyMover(Weapon4List) {}
	void Reset();
	void Move();
};

class CWeapon5 : public CMyMover {
public:

	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon5List.New(n); }
	void operator delete(void* p) { Weapon5List.Delete(p); }
	CWeapon5() : CMyMover(Weapon5List) {}
	void Reset();
	void Move();
};

class CWeapon6 : public CMyMover {
public:

	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon6List.New(n); }
	void operator delete(void* p) { Weapon6List.Delete(p); }
	CWeapon6() : CMyMover(Weapon6List) {}
	void Reset();
	void Move();
};

class CWeapon7 : public CMyMover {
public:

	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon7List.New(n); }
	void operator delete(void* p) { Weapon7List.Delete(p); }
	CWeapon7() : CMyMover(Weapon7List) {}
	void Reset();
	void Move();
};
class CWeapon8 : public CMyMover {
public:

	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon8List.New(n); }
	void operator delete(void* p) { Weapon8List.Delete(p); }
	CWeapon8() : CMyMover(Weapon8List) {}
	void Reset();
	void Move();
};
class CWeapon9 : public CMyMover {
public:

	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon9List.New(n); }
	void operator delete(void* p) { Weapon9List.Delete(p); }
	CWeapon9() : CMyMover(Weapon9List) {}
	void Reset();
	void Move();
};

class CWeapon10 : public CMyMover {
public:

	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon10List.New(n); }
	void operator delete(void* p) { Weapon10List.Delete(p); }
	CWeapon10() : CMyMover(Weapon10List) {}
	void Reset();
	void Move();
};

class CWeapon11 : public CMyMover {
public:
	int wepp = 0;
	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon11List.New(n); }
	void operator delete(void* p) { Weapon11List.Delete(p); }
	CWeapon11() : CMyMover(Weapon11List) {}
	void Reset();
	void Move();
};

class CWeapon12 : public CMyMover {
public:
	int wepp = 0;
	int State1;
	int wp = 0;
	void* operator new(size_t n){ return Weapon12List.New(n); }
	void operator delete(void* p) { Weapon12List.Delete(p); }
	CWeapon12() : CMyMover(Weapon12List) {}
	void Reset();
	void Move();
};