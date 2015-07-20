// メカペンギン
class CEnemy : public CMyMover {
public:
	int ENEMY_ATTACK_STARTTIME = 0;
	float VELO_Y_SP = 0;
	int POSITION = 0;
	int ENEMY_BLADE_HIT = 0;
	float HOMING_SP = 0;
	int SHOT_TIME = 0;
	int MOVE_CHANGE_TIME2 = 0;
	int MOVE_CHANGE_TIME = 0;
	int MOVE_CHANGE_COUNT=0;
	int COS_SIN_TIME = 0;
	int MOVE_COS_SIN_TIME = 0;
	int VIB_TIME = 0;
	int COLOR_TIME = 0;
	float SP = 0.8f;
	CVector SCALE_COPY = 0;
	int SCALE_TIME = 0;
	int IMPACT_COUNT = 0;
	//大爆発音
	void Big_bomb(){
		GetWave(L"ENEMY_ATACK\\big_bomb.wav")->Play(1);
		GetWave(L"ENEMY_ATACK\\big_bomb.wav")->SetVolume(0.4f);
	}
	void* operator new(size_t n) { return EnemyList.New(n); }
	void operator delete(void* p) { EnemyList.Delete(p); }
	CEnemy() : CMyMover(EnemyList) {}
	void Reset();
	void Move();
};
// メカペンギン(オブジェクト)
class CEnemy_obj : public CMyMover {
public:
	void ANI_HABATAKI(){
		AnimationTime += 0.8f;
		Animation = Model->GetAnimation(L"habataki");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	};
	void* operator new(size_t n){ return Enemy_objList.New(n); }
	void operator delete(void* p) { Enemy_objList.Delete(p); }
	CEnemy_obj() : CMyMover(Enemy_objList) {}
	void Reset();
	void Move();
};
// 多脚ロボ
class CEnemy_takyaku : public CMyMover {
public:
	int ENEMY_ATTACK_STARTTIME = 0;
	int COS_SIN_TIME = 0;
	int BLADE_TIME = 0;
	int ROTA_TAIME = 0;
	int ACTION_TIME = 0;
	int ACTION_TIME2 = 0;
	int MOVE_CHANGE_COUNT = 0;
	int MOVE_CHANGE_COUNT2 = 0;
	float ET_LEN2 = 0;
	int MOVE_COUNT = 0;
	int JUMP_STATE = 0;
	int JUMP_STATE2 = 0;
	int TIME = 0;
	float HOMING_SP = 0;
	float GRAVITY_POWER = 0;


	void JUMP(){
		BLADE_TIME = 0;
		AttackState = 0;
		if (JUMP_STATE2 == 0){
			patikoma_ani_state = patikoma_ani_jump;
			JUMP_STATE2 = 1;
			TIME = 0;
		}
		if (JUMP_STATE2 == 1){
			TIME++;
			if (TIME <= 15){
				Rotation *= CQuaternion(AxisY(), -0.065f);
				Velocity.Y += 1.2f;
			}
			if (TIME == 80){
				patikoma_ani_state = patikoma_ani_walk;
				JUMP_STATE2 = 0;
			}
		}
	}
	void MOVE(float HOMING_SP){
		BLADE_TIME = 0;
		JUMP_STATE2 = 0;
		AttackState = 0;
		patikoma_ani_state = patikoma_ani_walk;
		MyShipList.Apply([&](CMover*m){
			Position.Homing(m->Position, HOMING_SP);
		});
	}
	void ROTATION_ACTION(){
		AttackState = 1;
		JUMP_STATE2 = 0;
		patikoma_ani_state = patikoma_ani_walk;
		Rotation *= CQuaternion(AxisY(), -0.06f);
		MyShipList.Apply([&](CMover*m){
			Enemy_takyakuList.Apply([&](CMover*e){
				CHit Fhit;
				float Body_r = 4.0f;//4.0
				float Body_r2 = 4.0f;//4.0
				if (Fhit.SphereAndModel(m->Position, Body_r2, e, e->Model)){
					Velocity.Y = 0;
					//吹き飛ばしダメージ
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					m->Position = Fhit.Position[1] + (v*Body_r2) *1;
				}
			});
		});
	}

	void* operator new(size_t n){ return Enemy_takyakuList.New(n); }
	void operator delete(void* p) { Enemy_takyakuList.Delete(p); }
	CEnemy_takyaku() : CMyMover(Enemy_takyakuList) {}
	void Reset();
	void Move();
};
// 多脚ロボモデル
class CEnemy_takyaku_obj : public CMyMover {
public:
	float HOMING_SP = 0;
	float GRAVITY_POWER = 0;
	void ANI_WALK(){
		AnimationTime += 0.8f;
		Animation = Model->GetAnimation(L"walk");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	};
	void ANI_JUMP(){
		AnimationTime += 1.3f;
		Animation = Model->GetAnimation(L"jump");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	};
	void* operator new(size_t n){ return Enemy_takyaku_objList.New(n); }
	void operator delete(void* p) { Enemy_takyaku_objList.Delete(p); }
	CEnemy_takyaku_obj() : CMyMover(Enemy_takyaku_objList) {}
	void Reset();
	void Move();
};
//=========================================（ボ ス）=============================================
enum Canon_past_state{ CANON_PAST_OFF, CANON_PAST_ON };
enum Model_state{ Model_normal_walk, Model_canon, Model_normal_Wgun, Model_normal_discovery };

// ボス
class CEnemy_Boss : public CMyMover {
public:
	int BEAM_TIME = 0;
	int ROTA_TIME = 0;
	int BEAM_COUNT = 0;
	//ビーム音
	void E_beam(){
		GetWave(L"ENEMY_ATACK\\e_beam.wav")->Play(1);
		GetWave(L"ENEMY_ATACK\\e_beam.wav")->SetVolume(0.3f);
	}
	void* operator new(size_t n){ return Enemy_BossList.New(n); }
	void operator delete(void* p) { Enemy_BossList.Delete(p); }
	CEnemy_Boss() : CMyMover(Enemy_BossList) {}
	void Reset();
	void Move();
};

// ボスモデル
class CEnemy_Boss_model : public CMyMover {
public:
	int CANON_CHANGE_TIME = 0;
	int CANON_PAST_STATE = 0;
	int NORMAL_TYPE_ATTACK_CHANGE_COUNT = 0;
	int NORMAL_TYPE_ATTACK_CHANGE_TIME = 0;
	int WALK_CONT = 0;
	int MODEL_CHANGE_COUNT = 0;
	int MODEL_CHANGE_TIME = 0;
	void ANI_WALK(){
		AnimationTime += 0.8f;
		Animation = Model->GetAnimation(L"walk");
		if (AnimationTime >= Animation->MaxTime) AnimationTime = Animation->MinTime;
	};
	void ANI_W_GUN(){
		if (AnimationTime<40){
			AnimationTime += 0.5f;
		}
		Animation = Model->GetAnimation(L"w_gun");
	};
	int CHANGE_MODEL_COUNT = 0;
	void* operator new(size_t n){ return Enemy_Boss_modelList.New(n); }
	void operator delete(void* p) { Enemy_Boss_modelList.Delete(p); }
	CEnemy_Boss_model() : CMyMover(Enemy_Boss_modelList) {}
	void Reset();
	void Move();
};