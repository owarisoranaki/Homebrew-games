// オープニング背景
class COP : public CMyMover {
public:
	//int OP2 = 0;
	void* operator new(size_t n){ return OPList.New(n); }
	void operator delete(void* p) { OPList.Delete(p); }
	COP() : CMyMover(OPList) {}
	void Reset();
	void Move();
};
// ゲームオーバー背景
class COP1 : public CMyMover {
public:
	void* operator new(size_t n){ return OP1List.New(n); }
	void operator delete(void* p) { OP1List.Delete(p); }
	COP1() : CMyMover(OP1List) {}
	void Reset();
	void Move();
};
// クリア背景
class COP2 : public CMyMover {
public:
	void* operator new(size_t n){ return OP2List.New(n); }
	void operator delete(void* p) { OP2List.Delete(p); }
	COP2() : CMyMover(OP2List) {}
	void Reset();
	void Move();
};