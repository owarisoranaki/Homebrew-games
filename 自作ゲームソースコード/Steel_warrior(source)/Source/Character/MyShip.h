//�A�j���[�V�����؂�ւ��萔
enum ani_type{idl,lan};
//�A�N�V�����i�A�j���[�V�����j�؂�ւ��萔
enum action_type{normal,attack,dash,dash_attack,shot_attack};
//���n�萔
enum landing_type{landing_off,landing_on};
//�_�b�V���a�؂�ւ��萔
enum dash_zan_change{dash_zan_off,dash_zan_on};
//�㏸ONOFF�萔
enum jamp_type{up_off,up_on};
//�󒆍U��ON_OFF�萔
enum Air_blade_attack_type{ air_blade_attack_off, air_blade_attack_on};
//�_�b�V���U���n���萔
enum Dash_attack_count{ dash_attack_off, dash_attack_on};
//�i���b�N�I���j�󒆈ړ��A�j���[�V�����؂�ւ�
enum Air_rl_moveani{ air_rl_moveani_go, air_rl_moveani_right, air_rl_moveani_left };

// ���@
class CMyShip : public CMyMover {
public:
	//test
	int WARP_COUNT = 0;//�v���[���p�ϐ�
	int DELETE_ENEMY_COUNT = 0;//�v���[���p�ϐ�


	int RANG_E_COUNT = 0;
	int RANG_ET_COUNT = 0;
	CMover *E_PO = 0;
	CMover *E_PO1 = 0;
	CMover *E_PO2 = 0;
	CMover *OE_PO = 0;
	int TANSA = 0;

	//���b�N�I�������G�����ϐ�
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
	CMover* EP_P = NULL;//�ŏ��̃^�[�Q�b�g����
	CMover* EP_P2 = NULL;//�ŏ��̃^�[�Q�b�g����

	
	CVector ENEMY_POSI_COPY = 0;
	float ATTACK_ANI_SP = 0;//�ʏ�U���A�j���X�s�[�h
	float AnimationTime_Copy = 0;//�A�j���[�V�����^�C���R�s�[
	int ATTACK_TIME=0;//�ʏ�U�����o�ϐ�
	int ATTACK_COUNT = 0;//�ʏ�U�����o�ϐ�
	int ATTACK_MOUSE_COUNT = 0;//�ʏ�U���}�E�X�N���b�N���o�ϐ�
	int NORMAL_MOVE_TIME = 0;//�ʏ�ړ����o�ϐ�
	int NORMAL_MOVE_COUNT = 0;//�ʏ�ړ����o�ϐ�
	int ACTION_TYPE = 0;//�A�N�V�����i�A�j���[�V�����j�؂�ւ��ϐ�
	float LAN_SP = 0;//�ʏ�ړ��X�s�[�h�ϐ�
	int ANI_TYPE = 0;//�A�j���[�V�����ύX�ϐ�
	int ATTACK_ANITIME_RESET = 0;//�A�^�b�N�A�j���^�C�����Z�b�g�ϐ�
	float JUMP_ROTATION_ATTACK_SP = 0;//��]�U���X�s�[�h�ϐ�
	int JUMP_ROTATION_ATTACK_TIME = 0;//��]�U���^�C���ϐ�
	CVector Rote_VeloZ = 0;//AxisZ()�R�s�[�ϐ�
	int LANDING_TYPE = 1;//���n�ϐ�
	int DASH_ZANANI_TYPE = 0;//�_�b�V���U���؂�ւ��ϐ�
	int DASH_COUNT = 0;//�_�b�V���L�[���͕ϐ�
	int DASH_TIME = 0;//�_�b�V���L�[���͊��o�ϐ�
	float DASH_SP = 0;//�_�b�V���X�s�[�h
	int DASH_COUNT2 = 0;//�_�b�V���L�[���͕ϐ�2
	int DASH_TIME2 = 0;//�_�b�V���L�[���͊��o�ϐ�2
	float DASH_SP2 = 0;//�_�b�V���X�s�[�h2
	int DASH_COUNT3 = 0;//�_�b�V���L�[���͕ϐ�3
	int DASH_TIME3 = 0;//�_�b�V���L�[���͊��o�ϐ�3
	float DASH_SP3 = 0;//�_�b�V���X�s�[�h3
	int DASH_COUNT4 = 0;//�_�b�V���L�[���͕ϐ�4
	int DASH_TIME4 = 0;//�_�b�V���L�[���͊��o�ϐ�4
	float DASH_SP4 = 0;//�_�b�V���X�s�[�h4
	int DASH_COUNT5 = 0;//�_�b�V���L�[���͕ϐ�5
	int DASH_TIME5 = 0;//�_�b�V���L�[���͊��o�ϐ�5
	float DASH_SP5 = 0;//�_�b�V���X�s�[�h5
	int DASH_COUNT6 = 0;//�_�b�V���L�[���͕ϐ�6
	int DASH_TIME6 = 0;//�_�b�V���L�[���͊��o�ϐ�6
	float DASH_SP6 = 0;//�_�b�V���X�s�[�h6
	int DASH_COUNT7 = 0;//�_�b�V���L�[���͕ϐ�7
	int DASH_TIME7 = 0;//�_�b�V���L�[���͊��o�ϐ�7
	float DASH_SP7 = 0;//�_�b�V���X�s�[�h7
	int DASH_COUNT8 = 0;//�_�b�V���L�[���͕ϐ�8
	int DASH_TIME8 = 0;//�_�b�V���L�[���͊��o�ϐ�8
	float DASH_SP8 = 0;//�_�b�V���X�s�[�h8
	int DASH_ATTACK_TIME = 0;//�_�b�V���A�^�b�N���o�ϐ�
	int DASH_ATTACK_COUNT = 0;//�_�b�V���A�^�b�N���o�ϐ�
	int DASH_ZAN_CHANGE = 0;//�_�b�V���a�؂�ւ��ϐ�
	int GUN_ATTACK_TIME = 0;//�K���A�j�����o�ϐ�
	int GUN_ATTACK_COUNT = 0;//�K���A�j�����o�ϐ�
	int WEAPON_CHANGE_COUNT = 0;//�E�F�A�|���ύX�ϐ�
	int BLADEWEAPON_CHANGE_NORMAL_TYPE = 0;//�m�[�}�����[�h�u���[�h�E�F�A�|���ύX�ϐ�
	int GUN_WEAPON_CHANGE_COUNT = 0;//�m�[�}�����[�h�K���E�F�A�|���ύX�ϐ�
	int GUN_WEAPON_CHANGE_NORMAL_TYPE = 0;//�m�[�}�����[�h�K���E�F�A�|���ύX�ϐ�
	float GRAVITY_POWER = 0;//�d�͐��l�ϐ�
	int JAMP_TYPE = 0;//�󒆈ړ�ONOFF
	int DASH_IRREGULAR_COUNT = 0;//�΂߃_�b�V���L�[���͐���ϐ�
	int DASH_IRREGULAR_COUNT2 = 0;//�΂߃_�b�V���L�[���͐���ϐ�
	int DASH_IRREGULAR_COUNT3 = 0;//�΂߃_�b�V���L�[���͐���ϐ�
	int DASH_IRREGULAR_COUNT4 = 0;//�΂߃_�b�V���L�[���͐���ϐ�
	float AIR_MOVE = 0;//�󒆈ړ�
	CVector AxisY_Velocity = 0;//AxisY()�p�ϐ�
	int UP_COUNT = 0;
	int UP_TIME = 0;
	int UP_TIME2 = 0;
	float UP_SP = 0;
	//int SECOND_UP_COUNT = 0;//�ď㏸�����ɂ�ϐ�
	int AIR_DASHAFTER_MOVE = 0;//�_�b�V����ړ�
	int AIR_DASHAFTER_MOVECOUNT = 0;//�_�b�V����ړ�
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
//====================================�ʏ�ړ��A�j���[�V����===============================================
	//�ҋ@
	void Robo_ani_idl(){
		AnimationTime += 1.0f;
		Animation = Model->GetAnimation(L"idl");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	}
	//�ʏ�ړ��i�������j
	void Robo_ani_lan(){
		AnimationTime += 1.0f;
		Animation = Model->GetAnimation(L"lan");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	}
//=======================================�_�b�V���ړ�=======================================================
	//�u�[�X�g
	void Robo_ani_boost(){
		AnimationTime = 0.0f;
		Animation = Model->GetAnimation(L"boost");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	}
//=======================================�󒆃_�b�V���㎝���ړ�==============================================
	//�󒆃_�b�V���㎝���ړ�
	void Robo_ani_afteamove(){
		AnimationTime = 0.0f;
		Animation = Model->GetAnimation(L"aftea_move");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	}
	//�󒆃_�b�V���㎝���E�ړ��i���b�N�I�����j
	void Robo_ani_afteamove_r(){
		AnimationTime = 1.0f;
		Animation = Model->GetAnimation(L"aftea_move_rl");
	}
	//�󒆃_�b�V���㎝�����ړ��i���b�N�I�����j
	void Robo_ani_afteamove_l(){
		AnimationTime = 59.0f;
		Animation = Model->GetAnimation(L"aftea_move_rl");
	}
//===========================================��=================================================================
	//���U��
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


// ���@�ړ��p���f��
class CMyShip_Move_Model : public CMyMover {
public:
	void* operator new(size_t n){ return MyShip_Move_ModelList.New(n); }
	void operator delete(void* p) { MyShip_Move_ModelList.Delete(p); }
	CMyShip_Move_Model() : CMyMover(MyShip_Move_ModelList) {}
	void Reset();
	void Move();
};

// ���@�ړ��p���f��2
class CMyShip_Move_Model2 : public CMyMover {
public:
	int CAMERA_ROTA_COUNT = 0;
	CQuaternion CAMERA_ROTA = 0;//Rotation�R�s�[
	int CAMERA_ROTE_TIME = 0;
	int CAMERA_COUNT = 0;
	int CAMERA_COUNT2 = 0;
	int CAMERA_COUNT3 = 0;
	int CAMERA_TIME = 0;
	float MOUSE_WHEEL = 0;//�}�E�X�z�C�[��
	float MOUSE_WHEEL_COPY = 0;//�}�E�X�z�C�[���R�s�[

	void* operator new(size_t n){ return MyShip_Move_Model2List.New(n); }
	void operator delete(void* p) { MyShip_Move_Model2List.Delete(p); }
	CMyShip_Move_Model2() : CMyMover(MyShip_Move_Model2List) {}
	void Reset();
	void Move();
};

// ���@�ړ��p���f��3
class CMyShip_Move_Model3 : public CMyMover {
public:
	void* operator new(size_t n){ return MyShip_Move_Model3List.New(n); }
	void operator delete(void* p) { MyShip_Move_Model3List.Delete(p); }
	CMyShip_Move_Model3() : CMyMover(MyShip_Move_Model3List) {}
	void Reset();
	void Move();
};

// ���@�ړ��p���f��4
class CMyShip_Move_Model4 : public CMyMover {
public:
	void* operator new(size_t n){ return MyShip_Move_Model4List.New(n); }
	void operator delete(void* p) { MyShip_Move_Model4List.Delete(p); }
	CMyShip_Move_Model4() : CMyMover(MyShip_Move_Model4List) {}
	void Reset();
	void Move();
};

// ���@�ړ��p���f��5
class CMyShip_Move_Model5 : public CMyMover {
public:
	void* operator new(size_t n){ return MyShip_Move_Model5List.New(n); }
	void operator delete(void* p) { MyShip_Move_Model5List.Delete(p); }
	CMyShip_Move_Model5() : CMyMover(MyShip_Move_Model5List) {}
	void Reset();
	void Move();
};