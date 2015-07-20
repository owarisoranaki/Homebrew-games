// ƒAƒCƒeƒ€
class CItem : public CMyMover {
public:
	int heart = 0;
	void* operator new(size_t n) { return ItemList.New(n); }
	void operator delete(void* p) { ItemList.Delete(p); }
	CItem() : CMyMover(ItemList) {}
	void Reset();
	void Move();
};
class CItem1 : public CMyMover {
public:
	void* operator new(size_t n){ return Item1List.New(n); }
	void operator delete(void* p) { Item1List.Delete(p); }
	CItem1() : CMyMover(Item1List) {}
	void Reset();
	void Move();
};
class CItem2 : public CMyMover {
public:
	void* operator new(size_t n){ return Item2List.New(n); }
	void operator delete(void* p) { Item2List.Delete(p); }
	CItem2() : CMyMover(Item2List) {}
	void Reset();
	void Move();
};
class CItem3 : public CMyMover {
public:
	void* operator new(size_t n){ return Item3List.New(n); }
	void operator delete(void* p) { Item3List.Delete(p); }
	CItem3() : CMyMover(Item3List) {}
	void Reset();
	void Move();
};
class CItem4 : public CMyMover {
public:
	void* operator new(size_t n){ return Item4List.New(n); }
	void operator delete(void* p) { Item4List.Delete(p); }
	CItem4() : CMyMover(Item4List) {}
	void Reset();
	void Move();
};
class CItem5 : public CMyMover {
public:
	void* operator new(size_t n){ return Item5List.New(n); }
	void operator delete(void* p) { Item5List.Delete(p); }
	CItem5() : CMyMover(Item5List) {}
	void Reset();
	void Move();
};
class CItem6 : public CMyMover {
public:
	void* operator new(size_t n){ return Item6List.New(n); }
	void operator delete(void* p) { Item6List.Delete(p); }
	CItem6() : CMyMover(Item6List) {}
	void Reset();
	void Move();
};
class CItem7 : public CMyMover {
public:
	void* operator new(size_t n){ return Item7List.New(n); }
	void operator delete(void* p) { Item7List.Delete(p); }
	CItem7() : CMyMover(Item7List) {}
	void Reset();
	void Move();
};
class CItem8 : public CMyMover {
public:
	void* operator new(size_t n){ return Item8List.New(n); }
	void operator delete(void* p) { Item8List.Delete(p); }
	CItem8() : CMyMover(Item8List) {}
	void Reset();
	void Move();
};
class CItem9 : public CMyMover {
public:
	void* operator new(size_t n){ return Item9List.New(n); }
	void operator delete(void* p) { Item9List.Delete(p); }
	CItem9() : CMyMover(Item9List) {}
	void Reset();
	void Move();
};
class CItem10 : public CMyMover {
public:
	void* operator new(size_t n){ return Item10List.New(n); }
	void operator delete(void* p) { Item10List.Delete(p); }
	CItem10() : CMyMover(Item10List) {}
	void Reset();
	void Move();
};
class CItem11 : public CMyMover {
public:
	void* operator new(size_t n){ return Item11List.New(n); }
	void operator delete(void* p) { Item11List.Delete(p); }
	CItem11() : CMyMover(Item11List) {}
	void Reset();
	void Move();
};
class CItem12 : public CMyMover {
public:
	void* operator new(size_t n){ return Item12List.New(n); }
	void operator delete(void* p) { Item12List.Delete(p); }
	CItem12() : CMyMover(Item12List) {}
	void Reset();
	void Move();
};
class CItem13 : public CMyMover {
public:
	void* operator new(size_t n){ return Item13List.New(n); }
	void operator delete(void* p) { Item13List.Delete(p); }
	CItem13() : CMyMover(Item13List) {}
	void Reset();
	void Move();
};