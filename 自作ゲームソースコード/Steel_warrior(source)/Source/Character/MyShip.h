//アニメーション切り替え定数
enum ani_type{idl,lan};
//アクション（アニメーション）切り替え定数
enum action_type{normal,attack,dash,dash_attack,shot_attack};
//着地定数
enum landing_type{landing_off,landing_on};
//ダッシュ斬切り替え定数
enum dash_zan_change{dash_zan_off,dash_zan_on};
//上昇ONOFF定数
enum jamp_type{up_off,up_on};
//空中攻撃ON_OFF定数
enum Air_blade_attack_type{ air_blade_attack_off, air_blade_attack_on};
//ダッシュ攻撃始動定数
enum Dash_attack_count{ dash_attack_off, dash_attack_on};
//（ロックオン）空中移動アニメーション切り替え
enum Air_rl_moveani{ air_rl_moveani_go, air_rl_moveani_right, air_rl_moveani_left };

// 自機
class CMyShip : public CMyMover {
public:
	//test
	int WARP_COUNT = 0;//プレゼン用変数
	int DELETE_ENEMY_COUNT = 0;//プレゼン用変数


	int RANG_E_COUNT = 0;
	int RANG_ET_COUNT = 0;
	CMover *E_PO = 0;
	CMover *E_PO1 = 0;
	CMover *E_PO2 = 0;
	CMover *OE_PO = 0;
	int TANSA = 0;

	//ロックオン中策敵処理変数
	int EP_COUNT = 0;
	int ENEMY_COUNT = 0;
	int ENEMY_All3 = 0;
	int TARGETSELECTION_TIME = 0;
	int TARGETSELECTION_COUNT = 0;
	int TARGETSELECTION_TIMECONSTANT = 0;
	int TARGETSELECTION_RESET = 0;
	float E_LEN = FLT_MAX;
	CMover *COLSE_E = NULL;
	float ET_LEN = FLT_MAX;
	float E_LEN2 = FLT_MAX;
	CMover *COLSE_ET = NULL;
	CMover *COLSE_E2 = NULL;
	float E_LEN_S = 0;
	float ET_LEN_S = 0;
	float E_LEN_S2 = 0;
	int AIR_RL_MOVEANI = 0;
	CMover* MEKAPEN = NULL;
	CMover* PATIKOMA = NULL;
	CMover* BOSS = NULL;
	CMover* EP_P = NULL;//最初のターゲット決定
	CMover* EP_P2 = NULL;//最初のターゲット決定

	
	CVector ENEMY_POSI_COPY = 0;
	float ATTACK_ANI_SP = 0;//通常攻撃アニメスピード
	float AnimationTime_Copy = 0;//アニメーションタイムコピー
	int ATTACK_TIME=0;//通常攻撃感覚変数
	int ATTACK_COUNT = 0;//通常攻撃感覚変数
	int ATTACK_MOUSE_COUNT = 0;//通常攻撃マウスクリック感覚変数
	int NORMAL_MOVE_TIME = 0;//通常移動感覚変数
	int NORMAL_MOVE_COUNT = 0;//通常移動感覚変数
	int ACTION_TYPE = 0;//アクション（アニメーション）切り替え変数
	float LAN_SP = 0;//通常移動スピード変数
	int ANI_TYPE = 0;//アニメーション変更変数
	int ATTACK_ANITIME_RESET = 0;//アタックアニメタイムリセット変数
	float JUMP_ROTATION_ATTACK_SP = 0;//回転攻撃スピード変数
	int JUMP_ROTATION_ATTACK_TIME = 0;//回転攻撃タイム変数
	CVector Rote_VeloZ = 0;//AxisZ()コピー変数
	int LANDING_TYPE = 1;//着地変数
	int DASH_ZANANI_TYPE = 0;//ダッシュ攻撃切り替え変数
	int DASH_COUNT = 0;//ダッシュキー入力変数
	int DASH_TIME = 0;//ダッシュキー入力感覚変数
	float DASH_SP = 0;//ダッシュスピード
	int DASH_COUNT2 = 0;//ダッシュキー入力変数2
	int DASH_TIME2 = 0;//ダッシュキー入力感覚変数2
	float DASH_SP2 = 0;//ダッシュスピード2
	int DASH_COUNT3 = 0;//ダッシュキー入力変数3
	int DASH_TIME3 = 0;//ダッシュキー入力感覚変数3
	float DASH_SP3 = 0;//ダッシュスピード3
	int DASH_COUNT4 = 0;//ダッシュキー入力変数4
	int DASH_TIME4 = 0;//ダッシュキー入力感覚変数4
	float DASH_SP4 = 0;//ダッシュスピード4
	int DASH_COUNT5 = 0;//ダッシュキー入力変数5
	int DASH_TIME5 = 0;//ダッシュキー入力感覚変数5
	float DASH_SP5 = 0;//ダッシュスピード5
	int DASH_COUNT6 = 0;//ダッシュキー入力変数6
	int DASH_TIME6 = 0;//ダッシュキー入力感覚変数6
	float DASH_SP6 = 0;//ダッシュスピード6
	int DASH_COUNT7 = 0;//ダッシュキー入力変数7
	int DASH_TIME7 = 0;//ダッシュキー入力感覚変数7
	float DASH_SP7 = 0;//ダッシュスピード7
	int DASH_COUNT8 = 0;//ダッシュキー入力変数8
	int DASH_TIME8 = 0;//ダッシュキー入力感覚変数8
	float DASH_SP8 = 0;//ダッシュスピード8
	int DASH_ATTACK_TIME = 0;//ダッシュアタック感覚変数
	int DASH_ATTACK_COUNT = 0;//ダッシュアタック感覚変数
	int DASH_ZAN_CHANGE = 0;//ダッシュ斬切り替え変数
	int GUN_ATTACK_TIME = 0;//ガンアニメ感覚変数
	int GUN_ATTACK_COUNT = 0;//ガンアニメ感覚変数
	int WEAPON_CHANGE_COUNT = 0;//ウェアポン変更変数
	int BLADEWEAPON_CHANGE_NORMAL_TYPE = 0;//ノーマルモードブレードウェアポン変更変数
	int GUN_WEAPON_CHANGE_COUNT = 0;//ノーマルモードガンウェアポン変更変数
	int GUN_WEAPON_CHANGE_NORMAL_TYPE = 0;//ノーマルモードガンウェアポン変更変数
	float GRAVITY_POWER = 0;//重力数値変数
	int JAMP_TYPE = 0;//空中移動ONOFF
	int DASH_IRREGULAR_COUNT = 0;//斜めダッシュキー入力制御変数
	int DASH_IRREGULAR_COUNT2 = 0;//斜めダッシュキー入力制御変数
	int DASH_IRREGULAR_COUNT3 = 0;//斜めダッシュキー入力制御変数
	int DASH_IRREGULAR_COUNT4 = 0;//斜めダッシュキー入力制御変数
	float AIR_MOVE = 0;//空中移動
	CVector AxisY_Velocity = 0;//AxisY()用変数
	int UP_COUNT = 0;
	int UP_TIME = 0;
	int UP_TIME2 = 0;
	float UP_SP = 0;
	//int SECOND_UP_COUNT = 0;//再上昇かくにん変数
	int AIR_DASHAFTER_MOVE = 0;//ダッシュ後移動
	int AIR_DASHAFTER_MOVECOUNT = 0;//ダッシュ後移動
	int AIR_AFTER_ANI = 0;
	int AIR_BLADE_ATTACK = 0;
	int AIR_BLADE_TIME = 0;
	int AIR_BLADE_ATTACK_TYPE = 0;
	int AIR_BLADE_ATTACK_COUNT = 0;
	int AIR_AFTER_ATTACK_ONOFF = 0;
	int AIR_GUNSHOT_COUNT = 0;
	int AIR_GUNSHOT_ONOFF = 0;
	int AIR_GUNSHOT_TIME = 0;
	int AIR_GUNSHOT_TIME_COUNT = 0;
	int AIR_MOVE_CHANGE = 0;
	int INVINCIBLE_COLOR_TIME = 0;
	int DAMAGE_COUNT_TIME = 0;
	

	void* operator new(size_t n) { return MyShipList.New(n); }
	void operator delete(void* p) { MyShipList.Delete(p); }
	CMyShip() : CMyMover(MyShipList) {}
	void Reset();
	void Move();
//====================================通常移動アニメーション===============================================
	//待機
	void Robo_ani_idl(){
		AnimationTime += 1.0f;
		Animation = Model->GetAnimation(L"idl");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	}
	//通常移動（早歩き）
	void Robo_ani_lan(){
		AnimationTime += 1.0f;
		Animation = Model->GetAnimation(L"lan");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	}
//=======================================ダッシュ移動=======================================================
	//ブースト
	void Robo_ani_boost(){
		AnimationTime = 0.0f;
		Animation = Model->GetAnimation(L"boost");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	}
//=======================================空中ダッシュ後持続移動==============================================
	//空中ダッシュ後持続移動
	void Robo_ani_afteamove(){
		AnimationTime = 0.0f;
		Animation = Model->GetAnimation(L"aftea_move");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	}
	//空中ダッシュ後持続右移動（ロックオン中）
	void Robo_ani_afteamove_r(){
		AnimationTime = 1.0f;
		Animation = Model->GetAnimation(L"aftea_move_rl");
	}
	//空中ダッシュ後持続左移動（ロックオン中）
	void Robo_ani_afteamove_l(){
		AnimationTime = 59.0f;
		Animation = Model->GetAnimation(L"aftea_move_rl");
	}
//===========================================音=================================================================
	//剣振り
	void Blade_motion_se(){
		GetWave(L"ACTION\\blade_motion.wav")->Play(1);
		GetWave(L"ACTION\\blade_motion.wav")->SetVolume(0.3f);
	}
	void Blade_motion2_se(){
		GetWave(L"ACTION\\blade_motion2.wav")->Play(1);
		GetWave(L"ACTION\\blade_motion2.wav")->SetVolume(0.3f);
	}
	void Jet_se(){
		GetWave(L"ACTION\\jet.wav")->Play(1);
		GetWave(L"ACTION\\jet.wav")->SetVolume(0.3f);
	}
	void Beam_se(){
		GetWave(L"ACTION\\beam.wav")->Play(1);
		GetWave(L"ACTION\\beam.wav")->SetVolume(0.3f);
	}
};


// 自機移動用モデル
class CMyShip_Move_Model : public CMyMover {
public:
	void* operator new(size_t n){ return MyShip_Move_ModelList.New(n); }
	void operator delete(void* p) { MyShip_Move_ModelList.Delete(p); }
	CMyShip_Move_Model() : CMyMover(MyShip_Move_ModelList) {}
	void Reset();
	void Move();
};

// 自機移動用モデル2
class CMyShip_Move_Model2 : public CMyMover {
public:
	int CAMERA_ROTA_COUNT = 0;
	CQuaternion CAMERA_ROTA = 0;//Rotationコピー
	int CAMERA_ROTE_TIME = 0;
	int CAMERA_COUNT = 0;
	int CAMERA_COUNT2 = 0;
	int CAMERA_COUNT3 = 0;
	int CAMERA_TIME = 0;
	float MOUSE_WHEEL = 0;//マウスホイール
	float MOUSE_WHEEL_COPY = 0;//マウスホイールコピー

	void* operator new(size_t n){ return MyShip_Move_Model2List.New(n); }
	void operator delete(void* p) { MyShip_Move_Model2List.Delete(p); }
	CMyShip_Move_Model2() : CMyMover(MyShip_Move_Model2List) {}
	void Reset();
	void Move();
};

// 自機移動用モデル3
class CMyShip_Move_Model3 : public CMyMover {
public:
	void* operator new(size_t n){ return MyShip_Move_Model3List.New(n); }
	void operator delete(void* p) { MyShip_Move_Model3List.Delete(p); }
	CMyShip_Move_Model3() : CMyMover(MyShip_Move_Model3List) {}
	void Reset();
	void Move();
};

// 自機移動用モデル4
class CMyShip_Move_Model4 : public CMyMover {
public:
	void* operator new(size_t n){ return MyShip_Move_Model4List.New(n); }
	void operator delete(void* p) { MyShip_Move_Model4List.Delete(p); }
	CMyShip_Move_Model4() : CMyMover(MyShip_Move_Model4List) {}
	void Reset();
	void Move();
};

// 自機移動用モデル5
class CMyShip_Move_Model5 : public CMyMover {
public:
	void* operator new(size_t n){ return MyShip_Move_Model5List.New(n); }
	void operator delete(void* p) { MyShip_Move_Model5List.Delete(p); }
	CMyShip_Move_Model5() : CMyMover(MyShip_Move_Model5List) {}
	void Reset();
	void Move();
};