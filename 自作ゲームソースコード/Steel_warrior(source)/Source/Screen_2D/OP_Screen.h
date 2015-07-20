// オープニング画面
class COP_Screen : public CMyMover {
public:
	int BGM_CHANGE_INTERVAL_TIME = 0;//OP_BGMからmission_BGMに切り替える間の間隔調整
	int SCREEN_FADE_COUNT = 0;//フェードアウトカウント
	int SCREEN_FADE_TIME = 0;//フェードアウトタイム
	float CR = 1;//赤
	float CG = 1;//緑
	float CB = 1;//青
	float CW = 1;//明度
	void* operator new(size_t n){ return OP_ScreenList.New(n); }
	void operator delete(void* p) { OP_ScreenList.Delete(p); }
	COP_Screen() : CMyMover(OP_ScreenList) {}
	void Reset();
	void Move();
};
// オープニング画面文字
class COP_Screen_Write : public CMyMover {
public:
	float CR = 1;//赤
	float CG = 1;//緑
	float CB = 1;//青
	float CW = 1;//明度
	int COLOR_TIME = 0;
	int COLOR_COUNT = 0;
	void* operator new(size_t n){ return OP_Screen_WriteList.New(n); }
	void operator delete(void* p) { OP_Screen_WriteList.Delete(p); }
	COP_Screen_Write() : CMyMover(OP_Screen_WriteList) {}
	void Reset();
	void Move();
};
// 画面切り替えライン0
class COP_RHINE0 : public CMyMover {
public:
	void* operator new(size_t n){ return OP_RHINE0List.New(n); }
	void operator delete(void* p) { OP_RHINE0List.Delete(p); }
	COP_RHINE0() : CMyMover(OP_RHINE0List) {}
	void Reset();
	void Move();
};
// 画面切り替えライン1
class COP_RHINE1 : public CMyMover {
public:
	void* operator new(size_t n){ return OP_RHINE1List.New(n); }
	void operator delete(void* p) { OP_RHINE1List.Delete(p); }
	COP_RHINE1() : CMyMover(OP_RHINE1List) {}
	void Reset();
	void Move();
};
// ライフゲージ土台
class COP_LIFEGAGE : public CMyMover {
public:
	float X = 0;
	float LIFE =0;
	float LIFE_DIFFERENCE = 0;
	void* operator new(size_t n){ return OP_LIFEGAGEList.New(n); }
	void operator delete(void* p) { OP_LIFEGAGEList.Delete(p); }
	COP_LIFEGAGE() : CMyMover(OP_LIFEGAGEList) {}
	void Reset();
	void Move();
};
// ライフゲージ
class COP_LIFEGAGE2 : public CMyMover {
public:
	int INVINCIBLE_COLOR_TIME = 0;
	float DAMAGE = 0;
	float X = 0;
	float LIFE = 0;
	float LIFE_DIFFERENCE = 0;
	void* operator new(size_t n){ return OP_LIFEGAGE2List.New(n); }
	void operator delete(void* p) { OP_LIFEGAGE2List.Delete(p); }
	COP_LIFEGAGE2() : CMyMover(OP_LIFEGAGE2List) {}
	void Reset();
	void Move();
};
// ブーストゲージ土台
class COP_BOOSTGAGE : public CMyMover {
public:
	float BOOST_LIFE = 0;
	float X=0;
	void* operator new(size_t n){ return OP_BOOSTGAGEList.New(n); }
	void operator delete(void* p) { OP_BOOSTGAGEList.Delete(p); }
	COP_BOOSTGAGE() : CMyMover(OP_BOOSTGAGEList) {}
	void Reset();
	void Move();
};
// ブーストゲージ
class COP_BOOSTGAGE2 : public CMyMover {
public:
	float BOOST_LIFE = 0;
	float X = 0;
	void* operator new(size_t n){ return OP_BOOSTGAGE2List.New(n); }
	void operator delete(void* p) { OP_BOOSTGAGE2List.Delete(p); }
	COP_BOOSTGAGE2() : CMyMover(OP_BOOSTGAGE2List) {}
	void Reset();
	void Move();
};
// ライフゲージ	枠
class COP_LIFEGAGE_FRAME : public CMyMover {
public:
	void* operator new(size_t n){ return OP_LIFEGAGE_FRAMEList.New(n); }
	void operator delete(void* p) { OP_LIFEGAGE_FRAMEList.Delete(p); }
	COP_LIFEGAGE_FRAME() : CMyMover(OP_LIFEGAGE_FRAMEList) {}
	void Reset();
	void Move();
};
// タイム
class COP_TIME : public CMyMover {
public:
	int TIME_COUNT = 0;
	int TIME_SWITCH = 0;
	void* operator new(size_t n){ return OP_TIMEList.New(n); }
	void operator delete(void* p) { OP_TIMEList.Delete(p); }
	COP_TIME() : CMyMover(OP_TIMEList) {}
	void Reset();
	void Move();
};
// メッセージ枠
class COP_MESSAGE_FRAME : public CMyMover {
public:
	int MESSAGE_COUNT0 = 0;
	void* operator new(size_t n){ return OP_MESSAGE_FRAMEList.New(n); }
	void operator delete(void* p) { OP_MESSAGE_FRAMEList.Delete(p); }
	COP_MESSAGE_FRAME() : CMyMover(OP_MESSAGE_FRAMEList) {}
	void Reset();
	void Move();
};
// ターゲット枠
class COP_TARGET_FRAME : public CMyMover {
public:
	void* operator new(size_t n){ return OP_TARGET_FRAMEList.New(n); }
	void operator delete(void* p) { OP_TARGET_FRAMEList.Delete(p); }
	COP_TARGET_FRAME() : CMyMover(OP_TARGET_FRAMEList) {}
	void Reset();
	void Move();
};
// ムービー枠
class COP_MOVIE_FRAME : public CMyMover {
public:
	void* operator new(size_t n){ return OP_MOVIE_FRAMEList.New(n); }
	void operator delete(void* p) { OP_MOVIE_FRAMEList.Delete(p); }
	COP_MOVIE_FRAME() : CMyMover(OP_MOVIE_FRAMEList) {}
	void Reset();
	void Move();
};
// ガンゲージ枠
class COP_GUN_FRAME : public CMyMover {
public:
	void* operator new(size_t n){ return OP_GUN_FRAMEList.New(n); }
	void operator delete(void* p) { OP_GUN_FRAMEList.Delete(p); }
	COP_GUN_FRAME() : CMyMover(OP_GUN_FRAMEList) {}
	void Reset();
	void Move();
};
// ガンゲージ枠2
class COP_GUN_FRAME2 : public CMyMover {
public:
	void* operator new(size_t n){ return OP_GUN_FRAME2List.New(n); }
	void operator delete(void* p) { OP_GUN_FRAME2List.Delete(p); }
	COP_GUN_FRAME2() : CMyMover(OP_GUN_FRAME2List) {}
	void Reset();
	void Move();
};
// ガンゲージ
class COP_GUN_GAGE : public CMyMover {
public:
	float GAGE_LIFE = 0;
	float GAGE_SCALE = 0;
	float DAMAGE = 0;
	float RECOVERY = 0;
	float MOVE_POSITION = 0;
	float X = 0;
	void* operator new(size_t n){ return OP_GUN_GAGEList.New(n); }
	void operator delete(void* p) { OP_GUN_GAGEList.Delete(p); }
	COP_GUN_GAGE() : CMyMover(OP_GUN_GAGEList) {}
	void Reset();
	void Move();
};
// フェードアウト黒画面画面
class Cfade_black : public CMyMover {
public:
	int SCREEN_FADE_COUNT = 0;//フェードアウトカウント
	int SCREEN_FADE_TIME = 0;//フェードアウトタイム
	float CR = 1;//赤
	float CG = 1;//緑
	float CB = 1;//青
	float CW = 1;//明度
	void* operator new(size_t n){ return fade_blackList.New(n); }
	void operator delete(void* p) { fade_blackList.Delete(p); }
	Cfade_black() : CMyMover(fade_blackList) {}
	void Reset();
	void Move();
};
// エンド画面
class CEND : public CMyMover {
public:
	int SCREEN_FADE_COUNT = 0;//フェードアウトカウント
	int SCREEN_FADE_TIME = 0;//フェードアウトタイム
	float CR = 1;//赤
	float CG = 1;//緑
	float CB = 1;//青
	float CW = 1;//明度
	void* operator new(size_t n){ return ENDList.New(n); }
	void operator delete(void* p) { ENDList.Delete(p); }
	CEND() : CMyMover(ENDList) {}
	void Reset();
	void Move();
};

// PUSH_C文字
class CPush_c : public CMyMover {
public:
	int RESET_ON_COUNT=0;
	int RESET_ON_TIME = 0;
	int SCREEN_FADE_COUNT = 0;//フェードアウトカウント
	int SCREEN_FADE_TIME = 0;//フェードアウトタイム
	float CR = 1;//赤
	float CG = 1;//緑
	float CB = 1;//青
	float CW = 1;//明度
	void* operator new(size_t n){ return Push_cList.New(n); }
	void operator delete(void* p) { Push_cList.Delete(p); }
	CPush_c() : CMyMover(Push_cList) {}
	void Reset();
	void Move();
};
// HELP0画面
class CHELP0 : public CMyMover {
public:
	int COLOR_COUNT = 0;
	int SCREEN_FADE_COUNT = 0;//フェードアウトカウント
	int SCREEN_FADE_TIME = 0;//フェードアウトタイム
	float CR = 1;//赤
	float CG = 1;//緑
	float CB = 1;//青
	float CW = 1;//明度
	void* operator new(size_t n){ return HELP0List.New(n); }
	void operator delete(void* p) { HELP0List.Delete(p); }
	CHELP0() : CMyMover(HELP0List) {}
	void Reset();
	void Move();
};
// HELP1画面
class CHELP1 : public CMyMover {
public:
	int COLOR_COUNT = 0;
	int SCREEN_FADE_COUNT = 0;//フェードアウトカウント
	int SCREEN_FADE_TIME = 0;//フェードアウトタイム
	float CR = 1;//赤
	float CG = 1;//緑
	float CB = 1;//青
	float CW = 1;//明度
	void* operator new(size_t n){ return HELP1List.New(n); }
	void operator delete(void* p) { HELP1List.Delete(p); }
	CHELP1() : CMyMover(HELP1List) {}
	void Reset();
	void Move();
};