// ’e
class CBullet : public CMyMover {
public:
	void* operator new(size_t n) { return BulletList.New(n); }
	void operator delete(void* p) { BulletList.Delete(p); }
	CBullet() : CMyMover(BulletList) {}
	void Reset();
	void Move();
};
class CBullet1 : public CMyMover {
public:
	int KRM = 0;
	int TIME = 0;
	void* operator new(size_t n){ return Bullet1List.New(n); }
	void operator delete(void* p) { Bullet1List.Delete(p); }
	CBullet1() : CMyMover(Bullet1List) {}
	void Reset();
	void Move();
};
class CBullet2 : public CMyMover {
public:
	int KRM = 0;
	int TIME = 0;
	void* operator new(size_t n){ return Bullet2List.New(n); }
	void operator delete(void* p) { Bullet2List.Delete(p); }
	CBullet2() : CMyMover(Bullet2List) {}
	void Reset();
	void Move();
};


