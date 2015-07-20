#include "Main.h"

// 変数
CMoverList StageList(sizeof(CStage), 100);
CMoverList Stage_01List(sizeof(CStage_01), 100);
CMoverList Stage_02List(sizeof(CStage_02), 100);
CMoverList Stage_gateList(sizeof(CStage_gate), 100);
CMoverList Stage_gate2List(sizeof(CStage_gate2), 100);
CMoverList Stage_gate3List(sizeof(CStage_gate3), 100);
CMoverList Stage_gate4List(sizeof(CStage_gate4), 100);
CMoverList Stage_Centergate_LList(sizeof(CStage_Centergate_L), 100);
CMoverList Stage_Centergate_RList(sizeof(CStage_Centergate_R), 100);
CMoverList Stage_Centergate_LRList(sizeof(CStage_Centergate_LR), 100);
CMoverList MonitorList(sizeof(CMonitor), 100);
CMoverList MyShipList(sizeof(CMyShip), 100);
CMoverList MyShip_Move_ModelList(sizeof(CMyShip_Move_Model), 100);
CMoverList MyShip_Move_Model2List(sizeof(CMyShip_Move_Model2), 100);
CMoverList MyShip_Move_Model3List(sizeof(CMyShip_Move_Model3), 100);
CMoverList MyShip_Move_Model4List(sizeof(CMyShip_Move_Model4), 100);
CMoverList MyShip_Move_Model5List(sizeof(CMyShip_Move_Model5), 100);
CMoverList EnemyList(sizeof(CEnemy), 1000);
CMoverList Enemy_BossList(sizeof(CEnemy_Boss), 1000);
CMoverList Enemy_Boss_modelList(sizeof(CEnemy_Boss_model), 1000);
CMoverList Enemy_objList(sizeof(CEnemy_obj), 1000);
CMoverList Enemy_takyakuList(sizeof(CEnemy_takyaku), 1000);
CMoverList Enemy_takyaku_objList(sizeof(CEnemy_takyaku_obj), 1000);
CMoverList WeaponList(sizeof(CWeapon), 10000);
CMoverList Weapon_GunList(sizeof(CWeapon_Gun), 10000);
CMoverList BulletList(sizeof(CBullet), 10000);
CMoverList Bullet2List(sizeof(CBullet2), 10000);
CMoverList Bullet3List(sizeof(CBullet3), 10000);
CMoverList Bullet4List(sizeof(CBullet4), 10000);
CMoverList Bullet5List(sizeof(CBullet5), 10000);
CMoverList Bullet6List(sizeof(CBullet6), 10000);
CMoverList Bullet7List(sizeof(CBullet7), 10000);
CMoverList Bullet8List(sizeof(CBullet8), 10000);
CMoverList Bullet9List(sizeof(CBullet9), 10000);
CMoverList EffectList(sizeof(CEffect), 10000);
CMoverList Effect2List(sizeof(CEffect2), 10000);
CMoverList Effect3List(sizeof(CEffect3), 10000);
CMoverList Effect4List(sizeof(CEffect4), 10000);
CMoverList Effect5List(sizeof(CEffect5), 10000);
CMoverList Effect6List(sizeof(CEffect6), 10000);
CMoverList Effect7List(sizeof(CEffect7), 10000);
CMoverList Effect8List(sizeof(CEffect8), 10000);
CMoverList Effect9List(sizeof(CEffect9), 10000);
CMoverList Effect10List(sizeof(CEffect10), 10000);
CMoverList Effect11List(sizeof(CEffect11), 10000);
CMoverList Effect12List(sizeof(CEffect12), 10000);
CMoverList Effect13List(sizeof(CEffect13), 10000);
CMoverList Effect14List(sizeof(CEffect14), 10000);
CMoverList Effect15List(sizeof(CEffect15), 10000);
CMoverList Effect16List(sizeof(CEffect16), 10000);
CMoverList Effect17List(sizeof(CEffect17), 10000);
CMoverList Effect18List(sizeof(CEffect18), 10000);
CMoverList Effect19List(sizeof(CEffect19), 10000);
CMoverList Effect20List(sizeof(CEffect20), 10000);
CMoverList Effect21List(sizeof(CEffect21), 10000);
CMoverList Effect22List(sizeof(CEffect22), 10000);
CMoverList Icon0List(sizeof(CIcon0), 100);
CMoverList Effect_positionList(sizeof(CEffect_position), 10000);
CMoverList Effect_position2List(sizeof(CEffect_position2), 10000);
CMoverList Effect_sub_positionList(sizeof(CEffect_sub_position), 10000);
CMoverList Effect_sub_position2List(sizeof(CEffect_sub_position2), 10000);
CMoverList Effect_zan_positionList(sizeof(CEffect_zan_position), 10000);
CMoverList Effect_shothit_positionList(sizeof(CEffect_shothit_position), 10000);
CMoverList Effect_volt_positionList(sizeof(CEffect_volt_position), 10000);
CMoverList Effect_thunder_machineryList(sizeof(CEffect_thunder_machinery), 10000);
CMoverList Effect_damage_positionList(sizeof(CEffect_damage_position), 10000);
CMoverList BlockList(sizeof(CBlock), 10000);
CMoverList LampList(sizeof(CLamp), 10000);
CMoverList ItemList(sizeof(CItem), 1000);
CMoverList Item2List(sizeof(CItem2), 1000);
CMoverList Item3List(sizeof(CItem3), 1000);
CMoverList Item4List(sizeof(CItem4), 1000);
CMoverList CameraList(sizeof(CCamera), 100);
CMoverList LightList(sizeof(CLight), 100);
CMoverList OP_ScreenList(sizeof(COP_Screen), 100);
CMoverList OP_Screen_WriteList(sizeof(COP_Screen_Write), 100);
CMoverList OP_RHINE0List(sizeof(COP_RHINE0), 100);
CMoverList OP_RHINE1List(sizeof(COP_RHINE1), 100);
CMoverList OP_LIFEGAGEList(sizeof(COP_LIFEGAGE), 100);
CMoverList OP_LIFEGAGE2List(sizeof(COP_LIFEGAGE2), 100);
CMoverList OP_BOOSTGAGEList(sizeof(COP_BOOSTGAGE), 100);
CMoverList OP_BOOSTGAGE2List(sizeof(COP_BOOSTGAGE2), 100);
CMoverList OP_LIFEGAGE_FRAMEList(sizeof(COP_LIFEGAGE_FRAME), 100);
CMoverList OP_GUN_FRAMEList(sizeof(COP_GUN_FRAME), 100);
CMoverList OP_GUN_FRAME2List(sizeof(COP_GUN_FRAME2), 100);
CMoverList OP_GUN_GAGEList(sizeof(COP_GUN_GAGE), 100);
CMoverList OP_TIMEList(sizeof(COP_TIME), 100);
CMoverList OP_MESSAGE_FRAMEList(sizeof(COP_MESSAGE_FRAME), 100);
CMoverList OP_TARGET_FRAMEList(sizeof(COP_MESSAGE_FRAME), 100);
CMoverList OP_MOVIE_FRAMEList(sizeof(COP_MOVIE_FRAME), 100);
CMoverList ENDList(sizeof(CEND), 100);
CMoverList fade_blackList(sizeof(Cfade_black), 100);
CMoverList Push_cList(sizeof(CPush_c), 100);
CMoverList HELP0List(sizeof(CHELP0), 100);
CMoverList HELP1List(sizeof(CHELP1), 100);

CCamera* Camera;
int myship_death;
int clear_bgm_change_time;
int reset_switch;
int end_screen_switch;
int fade_black_switch;
int bad_end_message_time;
int bad_end_bgm_time;
int good_end_bgm_time;
int last_one_minutessound_time;
int last_one_minutes;
int timeleft;
int movie_cancel_type;
int movie_stop_count;//ムービー＆BGM途中stop
int bgm_state;
int clear_reset;
int clear;
int boss_moveimodel_change;
int boss_startup;
int boss_movie_state ;
int enemy_start_attack = 0;
int enemy_start_state = 0;
int enemy_startup;
float my_damage;
int MESSAGE_TIME;
int MESSAGE_COUNT;
float MESSAGE_VOL;
float MESSAGE_BGM_VOL;
int op_bgm_time;
int mission_bgm_time;
int defence_combat_bgm_time;
int normal_bgm_time;
int mission_complete_bgm_time;
int mission_failure_bgm_time;
int clearend_bgm_time;
int failureend_bgm_time;
int defence_combatrelease_time;
int boss_combat_bgm_time;

int centergate_movietype;
int icon0_type;
int mekapen_number;
int patikoma_number;
int selection_camera_reset;
int targetmarker_red;
int targetenemy_truefalse;
int targetselection;
int enemy_count;
int gun_gage_consumption;
int gun_gage_life;
int Score;
int blade_hold;
int blade;
int gun;
int weapon_chang;
int weapon_chang_name;
int blade_hand_chang;
int screen_switch;
int dash_type;
int rota_attack_type;
int beam_launch;
int gun_hande_Angle;
int boost_main1_switch;
int boost_main2_switch;
int boost_sub_switch;
int boost_subup_switch;
float boost_life;
int boost_gage_switch;
int boost_recovery_switch;
int myship_landing_type;
int air_gage_switch;
int time_micro;
int time_micro2;
int time_second;
int time_second2;
int time_minute;
int time_minute2;
int time_when;
int time_when2;
int time_type;
int enemy_shot_hit_type;
int enemy_slash_hit_tyape;
int myship_invincible_type;
float myship_damage;
int message_frame_type;
int message_frame_switch;
int camera_combat_state_type;
int all_combat_type;
int message_switch;
int moviecamera_rotat_type;
int target_frame_type;
int movie_cancel;
int gunshot_camera_type;
int patikoma_ani_state;
//テスト変数数値
int test_no;
float ftest;
float test_floatx;
float test_floaty;
float test_floatz;
float test_float2x;
float test_float2y;
float test_float2z;
// ゲーム本体
class CMyGame : public CGame {
public:
	int Time=0;
	bool Pause, PrevPause;
	CFont* Font;
	CFont* Font1;
	CFont* Font2;
	CFont* Font3;
	CFont* Font4;
	CFont* Font5;
	CFont* Font6;
	CFont* Font8;
	CFont* Font9;
	CFont* Font10;
	CFont* Font_rhine;

	// 初期化
	CMyGame::CMyGame() : CGame(L"My Game") {
		const wchar_t fontchar[] =
			L"[|1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ#e$%&tgh:bxdrpcqazwsui!,kfv@^-jn]/m'(){}_`";
		Font10 = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font10.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 24, 40, 2, 2);
		Font9 = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font9.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 18, 34, 2, 2);
		Font8 = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font8.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 18, 34, 2, 2);
		Font6 = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font7.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 12, 26, 2, 2);
		Font5 = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font6.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 18, 34, 2, 2);
		Font4 = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font5.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 18, 34, 2, 2);
		Font3 = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font4.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 18, 34, 2, 2);
		Font2 = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font2.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 18, 34, 2, 2);
		Font1 = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font1.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 24, 44, 2, 2);
		Font  = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font2.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 16, 32, 2, 2);
		Font_rhine = new CFont(Graphics->GetDevice(), ExePath + L"..\\Font\\Font_rhine.png", 0, fontchar, 16.0f / 256, 32.0f / 256, 20, 26, 2, 2);
		//NetworkInput.Open(Config.GetValue(L"Server"), Config.GetIntValue(L"Port"));
		Reset();
	}

	// リセット
	void Reset() {
		Sound->Stop();
		StageList.Clear();
		Stage_01List.Clear();
		Stage_02List.Clear();
		Stage_gateList.Clear();
		Stage_gate2List.Clear();
		Stage_gate3List.Clear();
		Stage_gate4List.Clear();
		Stage_Centergate_LList.Clear();
		Stage_Centergate_RList.Clear();
		Stage_Centergate_LRList.Clear();
		MonitorList.Clear();
		MyShipList.Clear();
		MyShip_Move_ModelList.Clear();
		MyShip_Move_Model2List.Clear();
		MyShip_Move_Model3List.Clear();
		MyShip_Move_Model4List.Clear();
		MyShip_Move_Model5List.Clear();
		EnemyList.Clear();
		Enemy_BossList.Clear();
		Enemy_Boss_modelList.Clear();
		Enemy_objList.Clear();
		Enemy_takyakuList.Clear();
		Enemy_takyaku_objList.Clear();
		WeaponList.Clear();
		Weapon_GunList.Clear();
		BulletList.Clear();
		Bullet2List.Clear();
		Bullet3List.Clear();
		Bullet4List.Clear();
		Bullet5List.Clear();
		Bullet6List.Clear();
		Bullet7List.Clear();
		Bullet8List.Clear();
		Bullet9List.Clear();
		EffectList.Clear();
		Effect2List.Clear();
		Effect3List.Clear();
		Effect4List.Clear();
		Effect5List.Clear();
		Effect6List.Clear();
		Effect7List.Clear();
		Effect8List.Clear();
		Effect9List.Clear();
		Effect10List.Clear();
		Effect11List.Clear();
		Effect12List.Clear();
		Effect13List.Clear();
		Effect14List.Clear();
		Effect15List.Clear();
		Effect16List.Clear();
		Effect17List.Clear();
		Effect18List.Clear();
		Effect19List.Clear();
		Effect20List.Clear();
		Effect21List.Clear();
		Effect22List.Clear();
		Icon0List.Clear();
		Effect_positionList.Clear();
		Effect_position2List.Clear();
		Effect_sub_positionList.Clear();
		Effect_sub_position2List.Clear();
		Effect_zan_positionList.Clear();
		Effect_shothit_positionList.Clear();
		Effect_volt_positionList.Clear();
		Effect_thunder_machineryList.Clear();
		Effect_damage_positionList.Clear();
		BlockList.Clear();
		LampList.Clear();
		ItemList.Clear();
		Item2List.Clear();
		Item3List.Clear();
		Item4List.Clear();
		CameraList.Clear();
		LightList.Clear();
		OP_ScreenList.Clear();
		OP_Screen_WriteList.Clear();
		OP_RHINE0List.Clear();
		OP_RHINE1List.Clear();
		OP_LIFEGAGEList.Clear();
		OP_LIFEGAGE2List.Clear();
		OP_BOOSTGAGEList.Clear();
		OP_BOOSTGAGE2List.Clear();
		OP_LIFEGAGE_FRAMEList.Clear();
		OP_GUN_FRAMEList.Clear();
		OP_GUN_FRAME2List.Clear();
		OP_GUN_GAGEList.Clear();
		OP_TIMEList.Clear();
		OP_MESSAGE_FRAMEList.Clear();
		OP_TARGET_FRAMEList.Clear();
		OP_MOVIE_FRAMEList.Clear();
		ENDList.Clear();
		HELP0List.Clear();
		HELP1List.Clear();
		fade_blackList.Clear();

		Score=0;
		//追加
		myship_death = myship_death_off;
		clear_bgm_change_time = 0;
		good_end_bgm_time = 0;
		reset_switch = reset_off;
		end_screen_switch = end_screen_off;
		fade_black_switch = fade_black_off;
		bad_end_bgm_time=0;
		bad_end_message_time = 0;
		last_one_minutes = last_one_minutes_off;
		timeleft = timeleft_yes;
		boss_combat_bgm_time = 0;
		movie_cancel_type = 0;
		movie_stop_count = stop_count_off;
		bgm_state = 100;
		clear_reset = clear_reset_off;
		clear = clear_off;
		boss_moveimodel_change = boss_moveimodel_change_off;
		boss_startup = boss_startup_off;
		boss_movie_state = boss_movie_off;
		enemy_start_attack = enemy_start_attack_off;
		enemy_start_state = enemy_start_off;
		enemy_startup = Enemy_startup_off;
		my_damage = 0;
		MESSAGE_TIME=0;
		MESSAGE_COUNT=0;
		MESSAGE_VOL=0;
		MESSAGE_BGM_VOL=0;
		op_bgm_time=0;
		mission_bgm_time=0;
		defence_combat_bgm_time=0;
		normal_bgm_time=0;
		mission_complete_bgm_time=0;
		mission_failure_bgm_time=0;
		clearend_bgm_time=0;
		failureend_bgm_time=0;
		defence_combatrelease_time = 0;

		centergate_movietype = centergate_movie_off;
		icon0_type = icon0_off;
		ftest = 0;
		test_floatx=0;
		test_floaty=0;
		test_floatz=0;
		test_float2x=0;
		test_float2y=0;
		test_float2z=0;
		mekapen_number = 0;
		patikoma_number = 0;
		selection_camera_reset = selection_camera_reset_off;
		targetmarker_red = 0;
		targetenemy_truefalse = targetenemy_truefalse_off;
		targetselection = targetselection_off;
		enemy_count = 0;
		patikoma_ani_state = patikoma_ani_walk;
		gun_gage_consumption = gun_gage_consumption_off;
		gun_gage_life=0;
		gunshot_camera_type = gunshot_camera_off;
		movie_cancel = Movie_cancel_off;
		MESSAGE_BGM_VOL = 0;
		MESSAGE_VOL=0.3f;
		target_frame_type = target_frame_off;
		moviecamera_rotat_type = moviecamera_rotat_off;
		MESSAGE_COUNT = 0;
		message_switch = message_off;
		camera_combat_state_type = camera_combat_state_off;
		all_combat_type = all_combat_off;
		message_frame_switch = message_frame_switch_off;
		message_frame_type = message_frame_off;
		myship_damage=0;
		myship_invincible_type = myship_invincible_off;
		air_gage_switch = air_gage_off;
		enemy_shot_hit_type = enemy_shot_hit_off;
		myship_landing_type = myship_landing_on;
		boost_recovery_switch=boost_recovery_off;
		boost_gage_switch=boost_gage_off;
		boost_life = 0;
		boost_subup_switch=boost_subup_off;
		boost_sub_switch = boost_sub_off;
		boost_main1_switch = boost_main1_off;
		boost_main2_switch = boost_main2_off;
		beam_launch = beam_off;
		rota_attack_type=rota_attack_off;
		dash_type=dash_off;
		screen_switch = screen_off;
		blade_hand_chang = 0;
		test_no = 0;
		blade_hold=0;
		blade=0;
		gun=0;
		time_micro=0;
		time_micro2=0;
		time_second=0;
		time_second2 = 0;
		time_minute=0;
		time_minute2 = 0;
		time_when=0;
		time_when2 = 0;
		time_type = time_type_off;
		weapon_chang = 0;
		weapon_chang_name = 0;

		Pause=PrevPause=false;

		Camera=New<CCamera>();
		New<CStage>();
	}

	// 移動
	void Move() {
		if (reset_switch == reset_on){
			Reset();
		}
		if (clear_reset == clear_reset_on)Reset();
		if (!PrevPause && KeyState[0][DIK_V]) Pause = !Pause;
		PrevPause=KeyState[0][DIK_V];
		if (!Pause) {
			StageList.Move();
			Stage_01List.Move();
			Stage_02List.Move();
			Stage_gateList.Move();
			Stage_gate2List.Move();
			Stage_gate3List.Move();
			Stage_gate4List.Move();
			Stage_Centergate_LList.Move();
			Stage_Centergate_RList.Move();
			Stage_Centergate_LRList.Move();
			MonitorList.Move();
			MyShipList.Move();
			MyShip_Move_ModelList.Move();
			MyShip_Move_Model2List.Move();
			MyShip_Move_Model3List.Move();
			MyShip_Move_Model4List.Move();
			MyShip_Move_Model5List.Move();
			EnemyList.Move();
			Enemy_BossList.Move();
			Enemy_Boss_modelList.Move();
			Enemy_objList.Move();
			Enemy_takyakuList.Move();
			Enemy_takyaku_objList.Move();
			WeaponList.Move();
			Weapon_GunList.Move();
			BulletList.Move();
			Bullet2List.Move();
			Bullet3List.Move();
			Bullet4List.Move();
			Bullet5List.Move();
			Bullet6List.Move();
			Bullet7List.Move();
			Bullet8List.Move();
			Bullet9List.Move();
			EffectList.Move();
			Effect2List.Move();
			Effect3List.Move();
			Effect4List.Move();
			Effect5List.Move();
			Effect6List.Move();
			Effect7List.Move();
			Effect8List.Move();
			Effect9List.Move();
			Effect10List.Move();
			Effect11List.Move();
			Effect12List.Move();
			Effect13List.Move();
			Effect14List.Move();
			Effect15List.Move();
			Effect16List.Move();
			Effect17List.Move();
			Effect18List.Move();
			Effect19List.Move();
			Effect20List.Move();
			Effect21List.Move();
			Effect22List.Move();
			Icon0List.Move();
			Effect_positionList.Move();
			Effect_position2List.Move();
			Effect_sub_positionList.Move();
			Effect_sub_position2List.Move();
			Effect_zan_positionList.Move();
			Effect_shothit_positionList.Move();
			Effect_volt_positionList.Move();
			Effect_thunder_machineryList.Move();
			Effect_damage_positionList.Move();
			BlockList.Move();
			LampList.Move();
			LightList.Move();
			ItemList.Move();
			Item2List.Move();
			Item3List.Move();
			Item4List.Move();
			CameraList.Move();
			OP_GUN_FRAMEList.Move();
			OP_GUN_FRAME2List.Move();
			OP_GUN_GAGEList.Move();
			OP_ScreenList.Move();
			OP_Screen_WriteList.Move();
			OP_RHINE0List.Move();
			OP_RHINE1List.Move();
			OP_LIFEGAGEList.Move();
			OP_LIFEGAGE2List.Move();
			OP_BOOSTGAGEList.Move();
			OP_BOOSTGAGE2List.Move();
			OP_LIFEGAGE_FRAMEList.Move();
			OP_TIMEList.Move();
			OP_MESSAGE_FRAMEList.Move();
			OP_TARGET_FRAMEList.Move();
			OP_MOVIE_FRAMEList.Move();
			ENDList.Move();
			HELP0List.Move();
			HELP1List.Move();
			fade_blackList.Move();
			Push_cList.Move();
			Time++;
		}
	}

	// 描画
	void Draw() {
		CBasicRenderer& r=*Renderer;
		r.ClearRenderTarget=true;
		r.Color=CColor(0, 0, 0, 1);
		r.Camera=Camera;
		r.LightList=&LightList;
		r.Perspective=r.ZBuffer=r.Sort=r.Billboard=true;

		r.ShadowSize=1024;
		r.ShadowCascade=3;
		r.ShadowEdge=0.5f;
		r.ShadowOffset=0.001f;
		r.ShadowRoot=2;
		r.NearZ = 1;//近い位置のカメラ描画
		r.FarZ = 3000;//描画する遠くの限界値

		//Bloom&Fog
		//r.FogColor = CColor(1, 1, 0, 1.0f);
		r.BloomBlurColor = KeyState[0][DIK_P] ? CColor(0, 0, 0, 0) : CColor(1, 1, 1, 0.9f);
		r.BloomSample = KeyState[0][DIK_O] ? 0 : 1.0f;

		//r.BlurFront = true;
		r.BlurAddAlpha = true;
		r.BlurScale = CVector(2.5f, 2.5f, 1.0f);//2.5f, 2.5f, 1  1.1で＝

		//r.FocusSample = KeyState[0][DIK_X] ? 0 : 2;
		//r.FocusRange[0] = 10;
		//r.FocusRange[1] = 40;
		//r.FocusRange[2] = 70;
		//r.FocusRange[3] = 900;
	
		r.Remove();
		r.Add(StageList);
		r.Add(Stage_01List);
		r.Add(Stage_02List);
		r.Add(Stage_gateList);
		r.Add(Stage_gate2List);
		r.Add(Stage_gate3List);
		r.Add(Stage_gate4List);
		r.Add(Stage_Centergate_RList);
		r.Add(Stage_Centergate_LList);
		r.Add(Stage_Centergate_LRList);
		r.Add(MonitorList);
		r.Add(BlockList);
		r.Add(LampList);
		r.Add(EffectList);
		r.Add(Effect2List);
		r.Add(Effect3List);
		r.Add(Effect4List);
		r.Add(Effect5List);
		r.Add(Effect6List);
		r.Add(Effect7List);
		r.Add(Effect8List);
		r.Add(Effect9List);
		r.Add(Effect10List);
		r.Add(Effect11List);
		r.Add(Effect12List);
		r.Add(Effect13List);
		r.Add(Effect14List);
		r.Add(Effect15List);
		r.Add(Effect16List);
		r.Add(Effect17List);
		r.Add(Effect18List);
		r.Add(Effect19List);
		r.Add(Effect20List);
		r.Add(Effect21List);
		r.Add(Effect22List);
		r.Add(Icon0List);
		r.Add(Effect_positionList);
		r.Add(Effect_position2List);
		r.Add(Effect_sub_positionList);
		r.Add(Effect_sub_position2List);
		r.Add(Effect_zan_positionList);
		r.Add(Effect_shothit_positionList);
		r.Add(Effect_volt_positionList);
		r.Add(Effect_thunder_machineryList);
		r.Add(Effect_damage_positionList);
		r.Add(WeaponList);
		r.Add(Weapon_GunList);
		r.Add(MyShipList);
		r.Add(MyShip_Move_ModelList);
		r.Add(MyShip_Move_Model2List);
		r.Add(MyShip_Move_Model3List);
		r.Add(MyShip_Move_Model4List);
		r.Add(MyShip_Move_Model5List);
		r.Add(ItemList);
		r.Add(Item2List);
		r.Add(Item3List);
		r.Add(Item4List);
		r.Add(EnemyList);
		r.Add(Enemy_BossList);
		r.Add(Enemy_Boss_modelList);
		r.Add(Enemy_objList);
		r.Add(Enemy_takyakuList);
		r.Add(Enemy_takyaku_objList);
		r.Add(BulletList);
		r.Add(Bullet2List);
		r.Add(Bullet3List);
		r.Add(Bullet4List);
		r.Add(Bullet5List);
		r.Add(Bullet6List);
		r.Add(Bullet7List);
		r.Add(Bullet8List);
		r.Add(Bullet9List);
		r.Render();

		// 2D
		r.Camera = 0; // デフォルトのカメラを使用
		r.ClearRenderTarget = false; // 画面消去なし
		r.Perspective = r.ZBuffer = r.Sort = r.Billboard = false; // 遠近なし、Zバッファなし、Zソートなし、ビルボードなし
		r.Remove();
		r.Add(OP_LIFEGAGEList);
		r.Add(OP_LIFEGAGE2List);
		r.Add(OP_BOOSTGAGEList);
		r.Add(OP_BOOSTGAGE2List);
		r.Add(OP_LIFEGAGE_FRAMEList);
		r.Add(OP_TIMEList);
		r.Add(OP_MESSAGE_FRAMEList);
		r.Add(OP_TARGET_FRAMEList);
		r.Add(OP_MOVIE_FRAMEList);
		r.Add(OP_RHINE0List);
		r.Add(OP_RHINE1List);
		r.Add(OP_ScreenList);
		r.Add(OP_Screen_WriteList);
		r.Add(OP_GUN_FRAME2List);
		r.Add(OP_GUN_GAGEList);
		r.Add(OP_GUN_FRAMEList);
		r.Add(fade_blackList);
		r.Add(HELP0List);
		r.Add(HELP1List);
		r.Add(ENDList);
		r.Add(Push_cList);
		r.Render();

		//＜＜UI数値＆文字＞＞
		//完全戦闘モードON＆センターゲートムービー中ではない＆警報ムービー中ではない＆ボスムービー中ではない
		if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on&&fade_black_switch == fade_black_off){
			//テスト
			MyShipList.Apply([&](CMover* m){
			    /*Font->DrawText(wstring(L"TEST ") + ToStr(ftest), 600, 140, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
				Font->DrawText(wstring(L"X ") + ToStr(m->Position.X), 600, 170, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
				Font->DrawText(wstring(L"Y ") + ToStr(m->Position.Y), 600, 200, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
				Font->DrawText(wstring(L"Z ") + ToStr(m->Position.Z), 600, 230, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
				Font->DrawText(wstring(L"RX ") + ToStr(test_float2x), 600, 260, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
				Font->DrawText(wstring(L"RY ") + ToStr(test_float2y), 600, 290, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
				Font->DrawText(wstring(L"RZ ") + ToStr(test_float2z), 600, 320, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
				Font->DrawText(wstring(L"RW ") + ToStr(Camera->Rotation.w), 600, 350, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
				Font->DrawText(wstring(L"COUNT ") + ToStr(enemy_count), 600, 380, CColor(1, 1, 1, 1), CColor(0, 1, 1, 1));
				Font->DrawText(wstring(L"TARGET ") + ToStr(targetselection), 600, 410, CColor(1, 1, 1, 1), CColor(0, 1, 1, 1));*/
			});
			//HELP
			Font10->DrawText(wstring(L"[|1234"), 630, 35, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
			//ビームエネルギーゲージ（数値）
			if (gun_gage_life >= 100){
				Font6->DrawText(wstring(L"   |500"), 687, 560, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
				Font6->DrawText(wstring(L"") + ToStr(gun_gage_life), 687, 560, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
			}
			else if (gun_gage_life < 100){
				Font6->DrawText(wstring(L"   |500"), 687, 560, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				Font6->DrawText(wstring(L"") + ToStr(gun_gage_life), 687, 560, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
			}
			//破壊ポイント（数値）
			Font2->DrawText(wstring(L"BREAK"), 3, 539, CColor(1.0f, 1.0f, 0.5f, 1), CColor(0.6f, 0.5f, 0.2f, 1));
			Font->DrawText(wstring(L"POIMT"), 6, 564, CColor(1.0f, 1.0f, 0.5f, 1), CColor(0.6f, 0.5f, 0.2f, 1));
			Font2->DrawText(wstring(L"") + ToStr(Score), 105, 550, CColor(1.0f, 1.0f, 0.5f, 1), CColor(0.6f, 0.5f, 0.2f, 1));
			//ブレードON（文字）
			if (weapon_chang_name == chang_blade){
				Font2->DrawText(wstring(L"BLADE"), 15, 73, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
			}
			//ガンON（文字）
			if (weapon_chang_name == chang_gun){
				Font2->DrawText(wstring(L"G U M"), 15, 73, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
			}
			//ライン（文字）
			Font_rhine->DrawText(wstring(L"11111 "), 10, 90, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
			//タイム（数値）
			if (time_when2 == 0 && time_when == 0 && time_minute2 == 0 && time_minute == 0){
				//タイム(時)
				/*Font2->DrawText(wstring(L"") + ToStr(time_when2), 562, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				Font2->DrawText(wstring(L"") + ToStr(time_when), 582, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				//:
				Font2->DrawText(wstring(L"["), 602, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));*/
				//タイム(分)
				Font2->DrawText(wstring(L"") + ToStr(time_minute2), 622, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				Font2->DrawText(wstring(L"") + ToStr(time_minute), 642, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				//:
				Font2->DrawText(wstring(L"["), 662, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				//タイム(秒)
				Font2->DrawText(wstring(L"") + ToStr(time_second2), 682, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				Font2->DrawText(wstring(L"") + ToStr(time_second), 702, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				//:
				Font2->DrawText(wstring(L"["), 722, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				//タイム(マイクロ)
				Font2->DrawText(wstring(L"") + ToStr(time_micro2), 742, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
				Font2->DrawText(wstring(L"") + ToStr(time_micro), 762, 5, CColor(1, 0, 0, 1), CColor(0, 0, 0, 1));
			}
			else{
				//タイム(時)
				/*Font2->DrawText(wstring(L"") + ToStr(time_when2), 562, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
				Font2->DrawText(wstring(L"") + ToStr(time_when), 582, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
				//:
				Font2->DrawText(wstring(L"["), 602, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));*/
				//タイム(分)
				Font2->DrawText(wstring(L"") + ToStr(time_minute2), 622, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
				Font2->DrawText(wstring(L"") + ToStr(time_minute), 642, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
				//:
				Font2->DrawText(wstring(L"["), 662, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
				//タイム(秒)
				Font2->DrawText(wstring(L"") + ToStr(time_second2), 682, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
				Font2->DrawText(wstring(L"") + ToStr(time_second), 702, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
				//:
				Font2->DrawText(wstring(L"["), 722, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
				//タイム(マイクロ)
				Font2->DrawText(wstring(L"") + ToStr(time_micro2), 742, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
				Font2->DrawText(wstring(L"") + ToStr(time_micro), 762, 5, CColor(1, 1, 1, 1), CColor(0, 0, 0, 1));
			}
		}
//------------------------------------------------------------------------------------------------------------------------------------
		//ムービー途中stop
		if (movie_stop_count == stop_count_off){
			if (KeyState[0][DIK_V] && !OldKeyState[0][DIK_V])movie_stop_count = stop_count_on;
		}
		else if (movie_stop_count == stop_count_on){
			if (KeyState[0][DIK_V] && !OldKeyState[0][DIK_V])movie_stop_count = stop_count_off;
		}

		//＜＜BGM切り替え＞＞
		//OP BGM(COP_Screen::Move())
		if (bgm_state == op_bgm_on){
			op_bgm_time++;
			if (op_bgm_time == 1){
				GetWave(L"BGM\\op_bgm.wav")->Play(-1);//0は音なし,1は１度だけ再生,-1は繰り返し
				GetWave(L"BGM\\op_bgm.wav")->SetVolume(0.35f);
			}
			if (op_bgm_time >= 2)op_bgm_time = 2;
		}
		//ミッションムービーBGM
		else if (bgm_state == mission_bgm_on){
			GetWave(L"BGM\\op_bgm.wav")->SetVolume(0.0f);
			mission_bgm_time++;
			if (mission_bgm_time==1){
				GetWave(L"BGM\\missionmovie_bgm.wav")->Play(1);//0は音なし,1は１度だけ再生,-1は繰り返し
				GetWave(L"BGM\\missionmovie_bgm.wav")->SetVolume(0.20f);
			}
			if (mission_bgm_time >= 2)mission_bgm_time = 2;
		}
		//通常BGM(CCamera::Move()&CStage::Move())
		else  if (bgm_state == normal_bgm_on){
			GetWave(L"BGM\\missionmovie_bgm.wav")->SetVolume(0.0f);
			GetWave(L"BGM\\defence_combat.wav")->SetVolume(0.0f);
			normal_bgm_time++;
			if (normal_bgm_time==1){
				GetWave(L"BGM\\normal_bgm.wav")->Play(-1);//0は音なし,1は１度だけ再生,-1は繰り返し
			}
			if (normal_bgm_time>=1){
				GetWave(L"BGM\\normal_bgm.wav")->SetVolume(0.20f);
				normal_bgm_time = 2;
			}
		}
		//警報戦闘BGM(CCamera::Move())
		else if (bgm_state == defence_combat_bgm_on){
			GetWave(L"BGM\\normal_bgm.wav")->SetVolume(0.0f);
			defence_combat_bgm_time++;
			if (defence_combat_bgm_time==1){
				GetWave(L"BGM\\siren.wav")->Play(-1);//0は音なし,1は１度だけ再生,-1は繰り返し
				GetWave(L"BGM\\siren.wav")->SetVolume(0.3f);
			}
			if (defence_combat_bgm_time == 180){
				GetWave(L"BGM\\siren.wav")->SetVolume(0.05f);
				GetWave(L"BGM\\defence_combat.wav")->Play(-1);//0は音なし,1は１度だけ再生,-1は繰り返し
				GetWave(L"BGM\\defence_combat.wav")->SetVolume(0.3f);
			}
			if (defence_combat_bgm_time == 230){
				GetWave(L"BGM\\siren.wav")->SetVolume(0.02f);
			}
			if (defence_combat_bgm_time == 304){
				GetWave(L"BGM\\siren.wav")->SetVolume(0.0f);
			}
			if (defence_combat_bgm_time >= 305){
				defence_combat_bgm_time = 305;
			}
		}
		////警報解除()
		else if (bgm_state == defence_combatrelease_on){
			GetWave(L"BGM\\defence_combat.wav")->SetVolume(0.0f);
			defence_combatrelease_time++;
			if (defence_combatrelease_time==1){
				GetWave(L"BGM\\defencerelease_bgm.wav")->Play(1);
				GetWave(L"BGM\\defencerelease_bgm.wav")->SetVolume(3.0f);
			}
			if (defence_combatrelease_time >= 2)defence_combatrelease_time = 2;
		}
		//ボス戦闘BGM
		else if (bgm_state == boss_combat_bgm_on){
			GetWave(L"BGM\\normal_bgm.wav")->SetVolume(0.0f);
			boss_combat_bgm_time++;
			if (boss_combat_bgm_time==1){
				GetWave(L"BOSSBGM\\boss_bgm1.wav")->Play(-1);
				GetWave(L"BOSSBGM\\boss_bgm1.wav")->SetVolume(2.0f);
			}
			if (boss_combat_bgm_time >= 2)boss_combat_bgm_time = 2;
		}
		//ミッションコンプリートムービーBGM
		else if (bgm_state == mission_complete_bgm_on){

		}
		//ミッション失敗BGM
		else if (bgm_state == mission_failure_bgm_on){
			GetWave(L"BGM\\op_bgm.wav")->SetVolume(0.0f);
			GetWave(L"BGM\\missionmovie_bgm.wav")->SetVolume(0.0f);
			GetWave(L"BGM\\defence_combat.wav")->SetVolume(0.0f);
			GetWave(L"BGM\\normal_bgm.wav")->SetVolume(0.0f);
			GetWave(L"BGM\\siren.wav")->SetVolume(0.0f);
			GetWave(L"BOSSBGM\\boss_bgm1.wav")->SetVolume(0.0f);
			bad_end_bgm_time++;
			if (bad_end_bgm_time==1){
				if (myship_death == myship_death_off){
					message_frame_switch = message_frame_switch_on;
				}
				message_switch = message_on;
				MESSAGE_TIME = 2001;//messageをケース10に飛ばす
				MESSAGE_COUNT = 10;
			}
			if (bad_end_bgm_time == 20){
				GetWave(L"BGM\\bad_end.wav")->Play(-1);
				GetWave(L"BGM\\bad_end.wav")->SetVolume(2.0f);
				//message_frame_switch = message_frame_switch_off;
			}
			if (bad_end_bgm_time > 20){
				bad_end_bgm_time = 21;
			}
		}
		//クリアED BGM
		else if (bgm_state == clearend_bgm_on){
			GetWave(L"BGM\\op_bgm.wav")->SetVolume(0.0f);
			GetWave(L"BGM\\missionmovie_bgm.wav")->SetVolume(0.0f);
			GetWave(L"BGM\\defence_combat.wav")->SetVolume(0.0f);
			GetWave(L"BGM\\siren.wav")->SetVolume(0.0f);
			GetWave(L"BOSSBGM\\boss_bgm1.wav")->SetVolume(0.0f);
			good_end_bgm_time++;
			if (good_end_bgm_time == 1){
				MESSAGE_TIME = 2173;
				MESSAGE_COUNT = 12;
				message_switch = message_on;
				message_frame_switch = message_frame_switch_on;
				if (end_screen_switch == end_screen_off){
					GetWave(L"BGM\\normal_bgm.wav")->SetVolume(0.20f);
				}
			}
			if (good_end_bgm_time>1){
				good_end_bgm_time = 2;
			}
			if (end_screen_switch == end_screen_on){
				clear_bgm_change_time++;
				GetWave(L"BGM\\normal_bgm.wav")->SetVolume(0.0f);
				if (clear_bgm_change_time == 1){
					GetWave(L"BGM\\good_clear_bgm.wav")->Play(-1);
					GetWave(L"BGM\\good_clear_bgm.wav")->SetVolume(2.0f);
				}
				if (clear_bgm_change_time>1){
					clear_bgm_change_time = 2;
				}

			}
		}
		//バットED BGM
		else if (bgm_state == failureend_bgm_on){
			
		}


		//(残り一分以下の警報)
		if (last_one_minutes == last_one_minutes_on){
			last_one_minutessound_time++;
			if (last_one_minutessound_time==1){
				GetWave(L"system\\alarm.wav")->Play(-1);
			}
			if (last_one_minutessound_time > 2){
				last_one_minutessound_time = 2;
			}
			GetWave(L"system\\alarm.wav")->SetVolume(0.2f);
		}
		else if (last_one_minutes == last_one_minutes_off){
			GetWave(L"system\\alarm.wav")->SetVolume(0.0f);
		}


		//（BGMストップ）
		if (movie_stop_count == stop_count_off){
			GetWave(L"BGM\\missionmovie_bgm.wav")->Resume();
			GetWave(L"BGM\\normal_bgm.wav")->Resume();
			GetWave(L"BGM\\siren.wav")->Resume();
			GetWave(L"BGM\\defence_combat.wav")->Resume();
			GetWave(L"BGM\\defencerelease_bgm.wav")->Resume();
			GetWave(L"system\\alarm.wav")->Resume();
		}
		if (movie_stop_count == stop_count_on){
			GetWave(L"BGM\\missionmovie_bgm.wav")->Pause();
			GetWave(L"BGM\\normal_bgm.wav")->Pause();
			GetWave(L"BGM\\siren.wav")->Pause();
			GetWave(L"BGM\\defence_combat.wav")->Pause();
			GetWave(L"BGM\\defencerelease_bgm.wav")->Pause();
			GetWave(L"system\\alarm.wav")->Pause();
		}
//---------------------------------------------------------------------------------------------------------------------------------------------
		//＜＜メッセージ＞＞
		//（メッセージストップ）
		if (message_switch == message_on){
			if (movie_stop_count == stop_count_off){
				MESSAGE_TIME++;
				MESSAGE_VOL = 0.3f;//0.3
			}
			if (movie_stop_count == stop_count_on){
				MESSAGE_VOL = 0.0f;//0.3
			}
				//message切り替え
				if (MESSAGE_TIME==245){
					MESSAGE_COUNT=1;//1
				}
				//ターゲット画像表示
				if (MESSAGE_TIME == 500){
					target_frame_type = target_frame_on;
				}
				if (MESSAGE_TIME == 720){
					MESSAGE_COUNT=2;//2
				}
				if (MESSAGE_TIME == 1021){
					MESSAGE_COUNT=3;//3
				}
				if (MESSAGE_TIME == 1531){//1506
					camera_combat_state_type = camera_combat_state_on;
					target_frame_type = target_frame_off;
				}
				if (MESSAGE_TIME == 1581){
					MESSAGE_COUNT=4;//4
				}
				if (MESSAGE_TIME == 1654){
					message_switch = message_off;
					MESSAGE_TIME = 1655;
					MESSAGE_COUNT=5;//5
				}
				//アイコン光OFF
				if (MESSAGE_TIME == 1653){
					moviecamera_rotat_type = moviecamera_rotat_off;
					message_frame_switch = message_frame_switch_off;
				}
				//赤ゲート解除AI
				if (MESSAGE_TIME == 1656){
					message_frame_switch = message_frame_switch_on;
					GetWave(L"BGM\\normal_bgm.wav")->SetVolume(0.03f);
				}
				if (MESSAGE_TIME == 1690){
					MESSAGE_COUNT = 6;//6
				}
				//中央ゲート解除AI
				if (MESSAGE_TIME == 1821){
					MESSAGE_COUNT = 8;//8
					message_frame_switch = message_frame_switch_on;
				}
			switch (MESSAGE_COUNT){
			case 0://起動
				Font3->DrawText(wstring(L"[|1234567890AB"), 285, 520, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME == 10){
					GetWave(L"AI\\ririsukidou.wav")->Play(1);
				}
				if (movie_stop_count == stop_count_off){
					GetWave(L"AI\\ririsukidou.wav")->SetVolume(MESSAGE_VOL);
					GetWave(L"AI\\ririsukidou.wav")->Resume();
				}
				if (movie_stop_count == stop_count_on){
					GetWave(L"AI\\ririsukidou.wav")->Pause();
				}
				break;
			case 1://ミッションの確認
				Font4->DrawText(wstring(L"[|1234567890ABCDEFGHIJKLMNOPQ"), 170, 520, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				Font4->DrawText(wstring(L"RSTUVWXYZ#e$%&tgh:"), 170, 543, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME == 249){
					GetWave(L"AI\\missionkakunin.wav")->Play(1);
				}
				if (movie_stop_count == stop_count_off){
					GetWave(L"AI\\missionkakunin.wav")->SetVolume(MESSAGE_VOL);
					GetWave(L"AI\\missionkakunin.wav")->Resume();
				}
				if (movie_stop_count == stop_count_on){
					GetWave(L"AI\\missionkakunin.wav")->Pause();
				}
				break;
			case 2:
				Font4->DrawText(wstring(L"bxdrpcqazwsui!,kfv@^-jn]/m'"), 170, 520, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME == 721){
					GetWave(L"AI\\missionkakunin1.wav")->Play(1);
				}
				if (movie_stop_count == stop_count_off){
					GetWave(L"AI\\missionkakunin1.wav")->SetVolume(MESSAGE_VOL);
					GetWave(L"AI\\missionkakunin1.wav")->Resume();
				}
				if (movie_stop_count == stop_count_on){
					GetWave(L"AI\\missionkakunin1.wav")->Pause();
				}
				break;
			case 3:
				Font5->DrawText(wstring(L"[|1234567890ABCDEFGHIJ"), 240, 520, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME >= 1241)Font5->DrawText(wstring(L"KL"), 350, 543, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME >= 1321)Font5->DrawText(wstring(L"  MN"), 350, 543, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME >= 1391)Font5->DrawText(wstring(L"    OP"), 350, 543, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME >= 1461)Font5->DrawText(wstring(L"      QR"), 350, 543, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME >= 1531)Font5->DrawText(wstring(L"        S"), 350, 543, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME == 1022){
					GetWave(L"AI\\countdown.wav")->Play(1);
				}
				if (movie_stop_count == stop_count_off){
					GetWave(L"AI\\countdown.wav")->SetVolume(MESSAGE_VOL);
					GetWave(L"AI\\countdown.wav")->Resume();
				}
				if (movie_stop_count == stop_count_on){
					GetWave(L"AI\\countdown.wav")->Pause();
				}
				break;
			case 4:
				if (MESSAGE_TIME >= 1608)Font5->DrawText(wstring(L"TUVWXYZ#"), 360, 520, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME == 1609){
					GetWave(L"AI\\start.wav")->Play(1);
				}
				if (movie_stop_count == stop_count_off){
					GetWave(L"AI\\start.wav")->SetVolume(MESSAGE_VOL);
					GetWave(L"AI\\start.wav")->Resume();
				}
				if (movie_stop_count == stop_count_on){
					GetWave(L"AI\\start.wav")->Pause();
				}
				break;
			case 5:

				break;
			case 6:
				Font8->DrawText(wstring(L"[|1234567890A"), 320, 545, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				if (MESSAGE_TIME == 1690){
					GetWave(L"AI\\geatkaijo.wav")->Play(1);
					GetWave(L"BGM\\normal_bgm.wav")->SetVolume(0.1f);
				}
				if (MESSAGE_TIME == 1810){
					message_frame_switch = message_frame_switch_off;
				}
				if (MESSAGE_TIME == 1820){
					message_switch = message_off;
					MESSAGE_COUNT = 7;
					bgm_state = normal_bgm_on;
					GetWave(L"BGM\\normal_bgm.wav")->SetVolume(0.2f);
				}
				break;
			case 7:

				break;
			case 8:
				//新たな通路解放AI
				if (MESSAGE_TIME >= 1860){
					Font8->DrawText(wstring(L"EFGHIJKLMNOPQRST"), 310, 545, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
					if (MESSAGE_TIME == 1860){
						GetWave(L"AI\\center_geat_open.wav")->Play(1);
						GetWave(L"AIM\\center_geat_open.wav")->SetVolume(0.1f);
					}
				}
				if (MESSAGE_TIME == 2000){
					message_frame_switch = message_frame_switch_off;
					message_switch = message_off;
					MESSAGE_COUNT = 9;
				}
				break;
			case 9:
				
				break;
			case 10:
				if (MESSAGE_TIME == 2030 && myship_death == myship_death_off){
					GetWave(L"AI\\timeover.wav")->Play(1);
					GetWave(L"AIM\\timeover.wav")->SetVolume(0.1f);
				}
				if (MESSAGE_TIME >= 2030 && myship_death == myship_death_off){
					Font8->DrawText(wstring(L"xdrpcqazwsui!,kfv@^-"), 260, 545, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				}
				if (MESSAGE_TIME == 2172){
					message_frame_switch = message_frame_switch_off;
					message_switch = message_off;
					fade_black_switch = fade_black_on;
					MESSAGE_COUNT = 11;
				}
				break;
			case 11:
				
				break;
			case 12:
				if (MESSAGE_TIME == 2190){
					GetWave(L"AI\\good_clear.wav")->Play(1);
					GetWave(L"AI\\good_clear.wav")->SetVolume(1.2f);
				}
				if (MESSAGE_TIME >= 2190 && MESSAGE_TIME <= 2310){
					Font9->DrawText(wstring(L"[|1234567890ABCDEFGH"), 260, 545, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				}
				if (MESSAGE_TIME > 2320){
					Font9->DrawText(wstring(L"IJKLMNOPQR"), 340, 545, CColor(1.0f, 1.0f, 1.0f, 1), CColor(0.0f, 0.0f, 0.0f, 1));
				}
				if (MESSAGE_TIME == 2420){
					message_frame_switch = message_frame_switch_off;
					message_switch = message_off;
					fade_black_switch = fade_black_on;
					MESSAGE_COUNT = 13;
				}
				break;
			case 13:

				break;
			}
		}

		//ゲームオーバーメッセージ
		if (clear == clear_bad_on){
			bad_end_message_time++;
			if (bad_end_message_time==1){

			}
			if (bad_end_message_time>1){
				bad_end_message_time = 2;
			}
		}
		ftest = MESSAGE_TIME;
	//--------------ムービーキャンセル--------------
		if (movie_cancel == Movie_cancel_on){
			if (movie_cancel_type == 0){
				MESSAGE_COUNT = 5;
				MESSAGE_TIME = 1655;
				movie_cancel_type = 1;
			}
			 MESSAGE_VOL = 0;
			 message_frame_type = message_frame_on;//アイコン表示
			 GetWave(L"AI\\ririsukidou.wav")->SetVolume(MESSAGE_VOL);
			 GetWave(L"AI\\missionkakunin.wav")->SetVolume(MESSAGE_VOL);
			 GetWave(L"AI\\missionkakunin1.wav")->SetVolume(MESSAGE_VOL);
			 GetWave(L"AI\\countdown.wav")->SetVolume(MESSAGE_VOL);
			 GetWave(L"AI\\start.wav")->SetVolume(MESSAGE_VOL);
		}
	}
};

// アプリケーションの起動
CMyGame* Game;
INT WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, INT) {
	Game=new CMyGame();
	Game->Run();
	delete Game;
	return 0;
}

