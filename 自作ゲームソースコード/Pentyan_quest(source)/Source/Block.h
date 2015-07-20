// ÉuÉçÉbÉN
class CBlock : public CMyMover {
public:
	void* operator new(size_t n) { return BlockList.New(n); }
	void operator delete(void* p) { BlockList.Delete(p); }
	CBlock() : CMyMover(BlockList) {}
	void Reset();
	void Move();
};

class CBlock1 : public CMyMover {
public:
	void* operator new(size_t n){ return Block1List.New(n); }
	void operator delete(void* p) { Block1List.Delete(p); }
	CBlock1() : CMyMover(Block1List) {}
	void Reset();
	void Move();
};

class CBlock2 : public CMyMover {
public:
	int BKTime;//í«â¡
	void* operator new(size_t n){ return Block2List.New(n); }
	void operator delete(void* p) { Block2List.Delete(p); }
	CBlock2() : CMyMover(Block2List) {}
	void Reset();
	void Move();
};

class CBlock3 : public CMyMover {
public:
	void* operator new(size_t n){ return Block3List.New(n); }
	void operator delete(void* p) { Block3List.Delete(p); }
	CBlock3() : CMyMover(Block3List) {}
	void Reset();
	void Move();
};

class CBlock4 : public CMyMover {
public:
	void* operator new(size_t n){ return Block4List.New(n); }
	void operator delete(void* p) { Block4List.Delete(p); }
	CBlock4() : CMyMover(Block4List) {}
	void Reset();
	void Move();
};
class CBlock5 : public CMyMover {
public:
	void* operator new(size_t n){ return Block5List.New(n); }
	void operator delete(void* p) { Block5List.Delete(p); }
	CBlock5() : CMyMover(Block5List) {}
	void Reset();
	void Move();
};
class CBlock6 : public CMyMover {
public:
	void* operator new(size_t n){ return Block6List.New(n); }
	void operator delete(void* p) { Block6List.Delete(p); }
	CBlock6() : CMyMover(Block6List) {}
	void Reset();
	void Move();
};
class CBlock7 : public CMyMover {
public:
	void* operator new(size_t n){ return Block7List.New(n); }
	void operator delete(void* p) { Block7List.Delete(p); }
	CBlock7() : CMyMover(Block7List) {}
	void Reset();
	void Move();
};
class CBlock8 : public CMyMover {
public:
	void* operator new(size_t n){ return Block8List.New(n); }
	void operator delete(void* p) { Block8List.Delete(p); }
	CBlock8() : CMyMover(Block8List) {}
	void Reset();
	void Move();
};
class CBlock9 : public CMyMover {
public:
	void* operator new(size_t n){ return Block9List.New(n); }
	void operator delete(void* p) { Block9List.Delete(p); }
	CBlock9() : CMyMover(Block9List) {}
	void Reset();
	void Move();
};
class CBlock10 : public CMyMover {
public:
	void* operator new(size_t n){ return Block10List.New(n); }
	void operator delete(void* p) { Block10List.Delete(p); }
	CBlock10() : CMyMover(Block10List) {}
	void Reset();
	void Move();
};
class CBlock11 : public CMyMover {
public:
	void* operator new(size_t n){ return Block11List.New(n); }
	void operator delete(void* p) { Block11List.Delete(p); }
	CBlock11() : CMyMover(Block11List) {}
	void Reset();
	void Move();
};
class CBlock12 : public CMyMover {
public:
	void* operator new(size_t n){ return Block12List.New(n); }
	void operator delete(void* p) { Block12List.Delete(p); }
	CBlock12() : CMyMover(Block12List) {}
	void Reset();
	void Move();
};
class CBlock13 : public CMyMover {
public:
	void* operator new(size_t n){ return Block13List.New(n); }
	void operator delete(void* p) { Block13List.Delete(p); }
	CBlock13() : CMyMover(Block13List) {}
	void Reset();
	void Move();
};
class CBlock14 : public CMyMover {
public:
	void* operator new(size_t n){ return Block14List.New(n); }
	void operator delete(void* p) { Block14List.Delete(p); }
	CBlock14() : CMyMover(Block14List) {}
	void Reset();
	void Move();
};
class CBlock15 : public CMyMover {
public:
	void* operator new(size_t n){ return Block15List.New(n); }
	void operator delete(void* p) { Block15List.Delete(p); }
	CBlock15() : CMyMover(Block15List) {}
	void Reset();
	void Move();
};
class CBlock16 : public CMyMover {
public:
	void* operator new(size_t n){ return Block16List.New(n); }
	void operator delete(void* p) { Block16List.Delete(p); }
	CBlock16() : CMyMover(Block16List) {}
	void Reset();
	void Move();
};
class CBlock17 : public CMyMover {
public:
	void* operator new(size_t n){ return Block17List.New(n); }
	void operator delete(void* p) { Block17List.Delete(p); }
	CBlock17() : CMyMover(Block17List) {}
	void Reset();
	void Move();
};
class CBlock18 : public CMyMover {
public:
	void* operator new(size_t n){ return Block18List.New(n); }
	void operator delete(void* p) { Block18List.Delete(p); }
	CBlock18() : CMyMover(Block18List) {}
	void Reset();
	void Move();
};
class CBlock19 : public CMyMover {
public:
	void* operator new(size_t n){ return Block19List.New(n); }
	void operator delete(void* p) { Block19List.Delete(p); }
	CBlock19() : CMyMover(Block19List) {}
	void Reset();
	void Move();
};
class CBlock20 : public CMyMover {
public:
	void* operator new(size_t n){ return Block20List.New(n); }
	void operator delete(void* p) { Block20List.Delete(p); }
	CBlock20() : CMyMover(Block20List) {}
	void Reset();
	void Move();
};
class CBlock21 : public CMyMover {
public:
	void* operator new(size_t n){ return Block21List.New(n); }
	void operator delete(void* p) { Block21List.Delete(p); }
	CBlock21() : CMyMover(Block21List) {}
	void Reset();
	void Move();
};
class CBlock22 : public CMyMover {
public:
	void* operator new(size_t n){ return Block22List.New(n); }
	void operator delete(void* p) { Block22List.Delete(p); }
	CBlock22() : CMyMover(Block22List) {}
	void Reset();
	void Move();
};
class CBlock23 : public CMyMover {
public:
	void* operator new(size_t n){ return Block23List.New(n); }
	void operator delete(void* p) { Block23List.Delete(p); }
	CBlock23() : CMyMover(Block23List) {}
	void Reset();
	void Move();
};
class CBlock24 : public CMyMover {
public:
	void* operator new(size_t n){ return Block24List.New(n); }
	void operator delete(void* p) { Block24List.Delete(p); }
	CBlock24() : CMyMover(Block24List) {}
	void Reset();
	void Move();
};
class CBlock25 : public CMyMover {
public:
	void* operator new(size_t n){ return Block25List.New(n); }
	void operator delete(void* p) { Block25List.Delete(p); }
	CBlock25() : CMyMover(Block25List) {}
	void Reset();
	void Move();
};
class CBlock26 : public CMyMover {
public:
	void* operator new(size_t n){ return Block26List.New(n); }
	void operator delete(void* p) { Block26List.Delete(p); }
	CBlock26() : CMyMover(Block26List) {}
	void Reset();
	void Move();
};
class CBlock27 : public CMyMover {
public:
	void* operator new(size_t n){ return Block27List.New(n); }
	void operator delete(void* p) { Block27List.Delete(p); }
	CBlock27() : CMyMover(Block27List) {}
	void Reset();
	void Move();
};
class CBlock28 : public CMyMover {
public:
	void* operator new(size_t n){ return Block28List.New(n); }
	void operator delete(void* p) { Block28List.Delete(p); }
	CBlock28() : CMyMover(Block28List) {}
	void Reset();
	void Move();
};
class CBlock29 : public CMyMover {
public:
	void* operator new(size_t n){ return Block29List.New(n); }
	void operator delete(void* p) { Block29List.Delete(p); }
	CBlock29() : CMyMover(Block29List) {}
	void Reset();
	void Move();
};
class CBlock30 : public CMyMover {
public:
	void* operator new(size_t n){ return Block30List.New(n); }
	void operator delete(void* p) { Block30List.Delete(p); }
	CBlock30() : CMyMover(Block30List) {}
	void Reset();
	void Move();
};
class CBlock31 : public CMyMover {
public:
	void* operator new(size_t n){ return Block31List.New(n); }
	void operator delete(void* p) { Block31List.Delete(p); }
	CBlock31() : CMyMover(Block31List) {}
	void Reset();
	void Move();
};