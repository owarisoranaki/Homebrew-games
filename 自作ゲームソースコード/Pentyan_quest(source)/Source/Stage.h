// ステージ
class CStage : public CMyMover {
public:
	int MYSHIP_DELETE_TYPE = 0;
	int GBGM = 0;
	int GOV1=0;
	void* operator new(size_t n) { return StageList.New(n); }
	void operator delete(void* p) { StageList.Delete(p); }
	CStage() : CMyMover(StageList) {}
	void Reset();
	void Move();
};

class CStage2 : public CMyMover {
public:
	void* operator new(size_t n){ return Stage2List.New(n); }
	void operator delete(void* p) { Stage2List.Delete(p); }
	CStage2() : CMyMover(Stage2List) {}
	void Reset();
	void Move();
};

