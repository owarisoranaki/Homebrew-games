// ステージ
class CStage : public CMyMover {
public:
	int MYSHIP_DEATH_COUNT = 0;
	int MYSHIP_DEATH_TIME = 0;
	float SOUND_VOLUME1=0.4f, SOUND_VOLUME2=0.3f, SOUND_VOLUME3=0.2f, SOUND_VOLUME4=0.15f, SOUND_VOLUME5=0.1f ;
	int BAD_END_RIGHTTIME = 0;
	float L_R = 0.45f;
	float L_G = 0.45f;
	float L_B = 0.45f;
	float L_W = 0.45f;
	int BGM_TIME = 0;
	int DEFENS_LIGHT_TIME = 0;
	float RGB = 0;
	float AW_MINPLU = 0;
	int STAGE_COLOR = 0;
	int MEKAPEN_NUMBER=0;
	int PATIKOMA_NUMBER=0;
	void* operator new(size_t n) { return StageList.New(n); }
	void operator delete(void* p) { StageList.Delete(p); }
	CStage() : CMyMover(StageList) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// ステージ_01
class CStage_01 : public CMyMover {
public:
	void* operator new(size_t n){ return Stage_01List.New(n); }
	void operator delete(void* p) { Stage_01List.Delete(p); }
	CStage_01() : CMyMover(Stage_01List) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// ステージ_02
class CStage_02 : public CMyMover {
public:
	void* operator new(size_t n){ return Stage_02List.New(n); }
	void operator delete(void* p) { Stage_02List.Delete(p); }
	CStage_02() : CMyMover(Stage_02List) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// ステージ_gate
class CStage_gate : public CMyMover {
public:
	float w = 0;
	void* operator new(size_t n){ return Stage_gateList.New(n); }
	void operator delete(void* p) { Stage_gateList.Delete(p); }
	CStage_gate() : CMyMover(Stage_gateList) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// ステージ_gate2
class CStage_gate2 : public CMyMover {
public:
	float w = 0;
	float Y = 0;
	void* operator new(size_t n){ return Stage_gate2List.New(n); }
	void operator delete(void* p) { Stage_gate2List.Delete(p); }
	CStage_gate2() : CMyMover(Stage_gate2List) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// ステージ_gate3
class CStage_gate3 : public CMyMover {
public:
	float Y = 0;
	void* operator new(size_t n){ return Stage_gate3List.New(n); }
	void operator delete(void* p) { Stage_gate3List.Delete(p); }
	CStage_gate3() : CMyMover(Stage_gate3List) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// ステージ_gate4
class CStage_gate4 : public CMyMover {
public:
	float Y = 0;
	void* operator new(size_t n){ return Stage_gate4List.New(n); }
	void operator delete(void* p) { Stage_gate4List.Delete(p); }
	CStage_gate4() : CMyMover(Stage_gate4List) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// ステージセンターゲート左
class CStage_Centergate_L : public CMyMover {
public:
	int TIME = 0;
	void* operator new(size_t n){ return Stage_Centergate_LList.New(n); }
	void operator delete(void* p) { Stage_Centergate_LList.Delete(p); }
	CStage_Centergate_L() : CMyMover(Stage_Centergate_LList) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// ステージセンターゲート右
class CStage_Centergate_R : public CMyMover {
public:
	int TIME = 0;
	void* operator new(size_t n){ return Stage_Centergate_RList.New(n); }
	void operator delete(void* p) { Stage_Centergate_RList.Delete(p); }
	CStage_Centergate_R() : CMyMover(Stage_Centergate_RList) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// ステージセンターゲート左右
class CStage_Centergate_LR : public CMyMover {
public:
	int ROTA_TIME = 0;
	void* operator new(size_t n){ return Stage_Centergate_LRList.New(n); }
	void operator delete(void* p) { Stage_Centergate_LRList.Delete(p); }
	CStage_Centergate_LR() : CMyMover(Stage_Centergate_LRList) {}
	void Reset();
	void Move();
};
//==================================================================================================================
// モニター
class CMonitor : public CMyMover {
public:
	void* operator new(size_t n){ return MonitorList.New(n); }
	void operator delete(void* p) { MonitorList.Delete(p); }
	CMonitor() : CMyMover(MonitorList) {}
	void Reset();
	void Move();
};