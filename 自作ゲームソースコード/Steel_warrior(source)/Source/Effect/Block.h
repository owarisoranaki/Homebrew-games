// ブロック
class CBlock : public CMyMover {
public:
	
	void* operator new(size_t n) { return BlockList.New(n); }
	void operator delete(void* p) { BlockList.Delete(p); }
	CBlock() : CMyMover(BlockList) {}
	void Reset();
	void Move();
};
// ランプ
class CLamp : public CMyMover {
public:

	void* operator new(size_t n){ return LampList.New(n); }
	void operator delete(void* p) { LampList.Delete(p); }
	CLamp() : CMyMover(LampList) {}
	void Reset();
	void Move();
};
