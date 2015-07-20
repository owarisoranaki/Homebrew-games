// パチコマキャノン
class CItem : public CMyMover {
public:
	int SHOT_COUNT = 0;
	int TIME_COUNT = 0;
	void E_beam(){
		GetWave(L"ENEMY_ATACK\\e_beam.wav")->Play(1);
		GetWave(L"ENEMY_ATACK\\e_beam.wav")->SetVolume(0.3f);
	}
	void* operator new(size_t n) { return ItemList.New(n); }
	void operator delete(void* p) { ItemList.Delete(p); }
	CItem() : CMyMover(ItemList) {}
	void Reset();
	void Move();
};

// パチコマキャノンジョイント
class CItem2 : public CMyMover {
public:
	void* operator new(size_t n){ return Item2List.New(n); }
	void operator delete(void* p) { Item2List.Delete(p); }
	CItem2() : CMyMover(Item2List) {}
	void Reset();
	void Move();
};

// パチコマブレード
class CItem3 : public CMyMover {
public:
	void* operator new(size_t n){ return Item3List.New(n); }
	void operator delete(void* p) { Item3List.Delete(p); }
	CItem3() : CMyMover(Item3List) {}
	void Reset();
	void Move();
};

// BOSS_GUN
class CItem4 : public CMyMover {
public:
	
	void* operator new(size_t n){ return Item4List.New(n); }
	void operator delete(void* p) { Item4List.Delete(p); }
	CItem4() : CMyMover(Item4List) {}
	void Reset();
	void Move();
};