// メインブースト（左）効果
class CEffect_position : public CMyMover {
public:
	void* operator new(size_t n){ return Effect_positionList.New(n); }
	void operator delete(void* p) { Effect_positionList.Delete(p); }
	CEffect_position() : CMyMover(Effect_positionList) {}
	void Reset();
	void Move();
};

// メインブースト（右）効果
class CEffect_position2 : public CMyMover {
public:
	void* operator new(size_t n){ return Effect_position2List.New(n); }
	void operator delete(void* p) { Effect_position2List.Delete(p); }
	CEffect_position2() : CMyMover(Effect_position2List) {}
	void Reset();
	void Move();
};

// サブブースト（右）効果
class CEffect_sub_position : public CMyMover {
public:
	void* operator new(size_t n){ return Effect_sub_positionList.New(n); }
	void operator delete(void* p) { Effect_sub_positionList.Delete(p); }
	CEffect_sub_position() : CMyMover(Effect_sub_positionList) {}
	void Reset();
	void Move();
};

// サブブースト（左）効果
class CEffect_sub_position2 : public CMyMover {
public:
	void* operator new(size_t n){ return Effect_sub_position2List.New(n); }
	void operator delete(void* p) { Effect_sub_position2List.Delete(p); }
	CEffect_sub_position2() : CMyMover(Effect_sub_position2List) {}
	void Reset();
	void Move();
};
// 斬攻撃エフェクト効果
class CEffect_zan_position : public CMyMover {
public:
	int NEW_DELETE_COUNT = 0;
	void* operator new(size_t n){ return Effect_zan_positionList.New(n); }
	void operator delete(void* p) { Effect_zan_positionList.Delete(p); }
	CEffect_zan_position() : CMyMover(Effect_zan_positionList) {}
	void Reset();
	void Move();
};
// ショット攻撃エフェクト効果
class CEffect_shothit_position : public CMyMover {
public:
	int EFFECT_TIME = 0;
	void* operator new(size_t n){ return Effect_shothit_positionList.New(n); }
	void operator delete(void* p) { Effect_shothit_positionList.Delete(p); }
	CEffect_shothit_position() : CMyMover(Effect_shothit_positionList) {}
	void Reset();
	void Move();
};
// カミナリポジションエフェクト効果
class CEffect_volt_position : public CMyMover {
public:
	void* operator new(size_t n){ return Effect_volt_positionList.New(n); }
	void operator delete(void* p) { Effect_volt_positionList.Delete(p); }
	CEffect_volt_position() : CMyMover(Effect_volt_positionList) {}
	void Reset();
	void Move();
};
// カミナリ生成機エフェクト効果
class CEffect_thunder_machinery : public CMyMover {
public:
	float COLOR_W = 0;
	int THUNDER_COUNT = 0;
	int THUNDER_TIME = 0;
	int THUNDER_TIME2 = 0;
	int MOVE_COUNT = 0;
	int MOVE_CHANGE_COUNT = 0;
	float sp = 0;
	int MOVE_TIME = 0;
	void* operator new(size_t n){ return Effect_thunder_machineryList.New(n); }
	void operator delete(void* p) { Effect_thunder_machineryList.Delete(p); }
	CEffect_thunder_machinery() : CMyMover(Effect_thunder_machineryList) {}
	void Reset();
	void Move();
};
// ダメージエフェクトポジション(自機)
class CEffect_damage_position : public CMyMover {
public:
	float POSITION_Y=0;
	int COUNT = 0;
	void* operator new(size_t n){ return Effect_damage_positionList.New(n); }
	void operator delete(void* p) { Effect_damage_positionList.Delete(p); }
	CEffect_damage_position() : CMyMover(Effect_damage_positionList) {}
	void Reset();
	void Move();
};