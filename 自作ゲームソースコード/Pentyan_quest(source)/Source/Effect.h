// Œø‰Ê
class CEffect : public CMyMover {
public:
	void* operator new(size_t n) { return EffectList.New(n); }
	void operator delete(void* p) { EffectList.Delete(p); }
	CEffect() : CMyMover(EffectList) {}
	void Reset();
	void Move();
};
class CEffect1 : public CMyMover {
public:
	void* operator new(size_t n){ return Effect1List.New(n); }
	void operator delete(void* p) { Effect1List.Delete(p); }
	CEffect1() : CMyMover(Effect1List) {}
	void Reset();
	void Move();
};
class CEffect2 : public CMyMover {
public:
	void* operator new(size_t n){ return Effect2List.New(n); }
	void operator delete(void* p) { Effect2List.Delete(p); }
	CEffect2() : CMyMover(Effect1List) {}
	void Reset();
	void Move();
};
class CEffect3 : public CMyMover {
public:
	void* operator new(size_t n){ return Effect3List.New(n); }
	void operator delete(void* p) { Effect3List.Delete(p); }
	CEffect3() : CMyMover(Effect1List) {}
	void Reset();
	void Move();
};
class CEffect4 : public CMyMover {
public:
	void* operator new(size_t n){ return Effect4List.New(n); }
	void operator delete(void* p) { Effect4List.Delete(p); }
	CEffect4() : CMyMover(Effect1List) {}
	void Reset();
	void Move();
};
class CEffect5 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect5List.New(n); }
	void operator delete(void* p) { Effect5List.Delete(p); }
	CEffect5() : CMyMover(Effect5List) {}
	void Reset();
	void Move();
};
class CEffect6 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect6List.New(n); }
	void operator delete(void* p) { Effect6List.Delete(p); }
	CEffect6() : CMyMover(Effect6List) {}
	void Reset();
	void Move();
};
class CEffect7 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect7List.New(n); }
	void operator delete(void* p) { Effect7List.Delete(p); }
	CEffect7() : CMyMover(Effect7List) {}
	void Reset();
	void Move();
};
class CEffect8 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect8List.New(n); }
	void operator delete(void* p) { Effect8List.Delete(p); }
	CEffect8() : CMyMover(Effect8List) {}
	void Reset();
	void Move();
};
class CEffect9 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect9List.New(n); }
	void operator delete(void* p) { Effect9List.Delete(p); }
	CEffect9() : CMyMover(Effect9List) {}
	void Reset();
	void Move();
};
class CEffect10 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect10List.New(n); }
	void operator delete(void* p) { Effect10List.Delete(p); }
	CEffect10() : CMyMover(Effect10List) {}
	void Reset();
	void Move();
};
class CEffect11 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect11List.New(n); }
	void operator delete(void* p) { Effect11List.Delete(p); }
	CEffect11() : CMyMover(Effect11List) {}
	void Reset();
	void Move();
};
class CEffect12 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect12List.New(n); }
	void operator delete(void* p) { Effect12List.Delete(p); }
	CEffect12() : CMyMover(Effect12List) {}
	void Reset();
	void Move();
};
class CEffect13 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect13List.New(n); }
	void operator delete(void* p) { Effect13List.Delete(p); }
	CEffect13() : CMyMover(Effect12List) {}
	void Reset();
	void Move();
};
class CEffect14 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect14List.New(n); }
	void operator delete(void* p) { Effect14List.Delete(p); }
	CEffect14() : CMyMover(Effect14List) {}
	void Reset();
	void Move();
};
class CEffect15 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect15List.New(n); }
	void operator delete(void* p) { Effect15List.Delete(p); }
	CEffect15() : CMyMover(Effect15List) {}
	void Reset();
	void Move();
};
class CEffect16 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect16List.New(n); }
	void operator delete(void* p) { Effect16List.Delete(p); }
	CEffect16() : CMyMover(Effect16List) {}
	void Reset();
	void Move();
};
class CEffect17 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect17List.New(n); }
	void operator delete(void* p) { Effect17List.Delete(p); }
	CEffect17() : CMyMover(Effect17List) {}
	void Reset();
	void Move();
};
class CEffect18 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect18List.New(n); }
	void operator delete(void* p) { Effect18List.Delete(p); }
	CEffect18() : CMyMover(Effect18List) {}
	void Reset();
	void Move();
};
class CEffect19 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect19List.New(n); }
	void operator delete(void* p) { Effect19List.Delete(p); }
	CEffect19() : CMyMover(Effect19List) {}
	void Reset();
	void Move();
};
class CEffect20 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect20List.New(n); }
	void operator delete(void* p) { Effect20List.Delete(p); }
	CEffect20() : CMyMover(Effect20List) {}
	void Reset();
	void Move();
};
class CEffect21 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect21List.New(n); }
	void operator delete(void* p) { Effect21List.Delete(p); }
	CEffect21() : CMyMover(Effect21List) {}
	void Reset();
	void Move();
};
class CEffect22 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect22List.New(n); }
	void operator delete(void* p) { Effect22List.Delete(p); }
	CEffect22() : CMyMover(Effect22List) {}
	void Reset();
	void Move();
};
class CEffect23 : public CMyMover {
public:
	int ef = 0;
	void* operator new(size_t n){ return Effect23List.New(n); }
	void operator delete(void* p) { Effect23List.Delete(p); }
	CEffect23() : CMyMover(Effect23List) {}
	void Reset();
	void Move();
};