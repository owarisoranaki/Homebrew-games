#include "..\Main\Main.h"

// ＜自機の初期化＞
void CMyShip::Reset() {
	Model = GetModel(L"ROBO\\Robo_Yo10.x");//機体モデル::Yo09
	SpecularColor = CColor(1, 1, 1, 9);//金属の様な反射(R,G,B,A)Aは数値が小さいと広く明るい、数値が小さいと鈍く鋭い感じ
	Scale = CVector(1, 1, 1)*0.6f;//機体サイズ
	Rotation = RotationY(0.0f);
	New<CWeapon>()->Owner = this;//武器オーナー
	New<CWeapon_Gun>()->Owner = this;//武器オーナー
	New<CEffect_position>()->Owner = this;//エフェクトposition右
	New<CEffect_position2>()->Owner = this;//エフェクトposition左
	New<CEffect_sub_position>()->Owner = this;//エフェクトsub_position右
	New<CEffect_sub_position2>()->Owner = this;//エフェクトsub_position左
	Life = 3500;//3500
	ENEMY_COUNT = enemy_count;
	TARGETSELECTION_TIMECONSTANT = 30;
	
}

// ＜自機の移動＞
void CMyShip::Move() {
	//=========================================================重力=================================================================
	//--ジャンプモードになっていない
	if (JAMP_TYPE == up_off){
		GRAVITY_POWER = -1.01f;
	}
	//--重力加算--
	AxisY_Velocity.Y += GRAVITY_POWER;
	//--座標に加速度加算--
	Position += Velocity;//左右前後移動
	Position.Y += AxisY_Velocity.Y;//上下移動
	//---重力加算上限---
	if (Velocity.Y <= -1){
		Velocity.Y = -1;
	}
	if (AxisY_Velocity.Y <= -0.1f){
		AxisY_Velocity.Y = -0.1f;
	}
	//========================================================位置調整==============================================================
	if (Position.Y <= 0.0f){
		Position.Y = 0.0f;
		Velocity.Y = 0;
		myship_landing_type = myship_landing_on;//着地
		
	}
	if (myship_landing_type == myship_landing_on){
		boost_recovery_switch = boost_recovery_on;//回復
		UP_COUNT = 0;//ジャンプカウント初期化
		//空中ダッシュ移動後移動可能
		AIR_DASHAFTER_MOVECOUNT = 0;
		//空中ブレード攻撃中着地した場合初期化
		AIR_BLADE_ATTACK = 0;
		AIR_BLADE_TIME = 0;
		AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
		air_gage_switch = air_gage_off;
	}
	//===================================================移動&アニメーション========================================================
	//＜ムービー終了により操作可能状態＞
	if (all_combat_type == all_combat_on && (enemy_startup == Enemy_startup_on || enemy_startup == Enemy_startup_off) && boss_movie_state != boss_movie_on&&end_screen_switch == end_screen_off){
	//スピード初期化
	Velocity.X = 0.0f;
	Velocity.Z = 0.0f;
		//ブレードタイプとガンタイプ両方共通
		if (weapon_chang == chang_blade || weapon_chang == chang_gun){
			//着地していてジャンプしていない
			if (myship_landing_type == myship_landing_on){
				//静止＆通常移動モード
				if (ACTION_TYPE == normal || ACTION_TYPE == dash || ACTION_TYPE == attack){
					//カメラ同調モデル2
					MyShip_Move_Model4List.Apply([&](CMover*Mm){
						//通常移動スピード
						LAN_SP = 0.53f;//0.4f
						//前進
						if (KeyState[0][DIK_W]){
							boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
							if (ACTION_TYPE != attack){
								Velocity += Mm->AxisZ()*LAN_SP;
							}
							if (ACTION_TYPE == attack){
								Velocity += Mm->AxisZ()*0.0001f;
							}
							if (ACTION_TYPE == normal&&ACTION_TYPE != attack){
								ANI_TYPE = lan;
							}
							NORMAL_MOVE_TIME = 0;
						}
						//後進
						if (KeyState[0][DIK_S]){
							boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
							if (ACTION_TYPE != attack){
								Velocity -= Mm->AxisZ()*LAN_SP;
							}
							if (ACTION_TYPE == attack){
								Velocity -= Mm->AxisZ()*0.0001f;
							}
							if (ACTION_TYPE == normal&&ACTION_TYPE != attack){
								ANI_TYPE = lan;
							}
							NORMAL_MOVE_TIME = 0;
						}
						//右進
						if (KeyState[0][DIK_D]){
							boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
							if (ACTION_TYPE != attack){
								Velocity += Mm->AxisX()*LAN_SP;
							}
							if (ACTION_TYPE == attack){
								Velocity += Mm->AxisX()*0.0001f;
							}
							if (ACTION_TYPE == normal&&ACTION_TYPE != attack){
								ANI_TYPE = lan;
							}
							NORMAL_MOVE_TIME = 0;
						}
						//左進
						if (KeyState[0][DIK_A]){
							boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
							if (ACTION_TYPE != attack){
								Velocity -= Mm->AxisX()*LAN_SP;
							}
							if (ACTION_TYPE == attack){
								Velocity -= Mm->AxisX()*0.0001f;
							}
							if (ACTION_TYPE == normal&&ACTION_TYPE != attack){
								ANI_TYPE = lan;
							}
							NORMAL_MOVE_TIME = 0;
						}
						//キーが押されていなければアイドリング定数代入
						if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] && ACTION_TYPE != attack){
							if (ACTION_TYPE == normal){
								NORMAL_MOVE_TIME++;
							}
							if (NORMAL_MOVE_TIME == 1){
								AnimationTime = 0;
							}
							if (NORMAL_MOVE_TIME > 1){
								if (ACTION_TYPE == normal){
									ANI_TYPE = idl;
									boost_main1_switch = boost_main1_off;//ブースト一段階ON_OFF
								}
							}

						}
						//アニメーション関数
						if (ANI_TYPE == lan){
							if (ACTION_TYPE == normal){
								Robo_ani_lan();
							}
						}
						if (ANI_TYPE == idl){
							if (ACTION_TYPE == normal){
								Robo_ani_idl();
							}
						}
					});
				}
			}
		}
	//====================================================攻撃アニメーション========================================================
	//ブレードタイプになっている＆終了条件になっていない
	if (weapon_chang == chang_blade){
		//上昇しているときは発動しない
		if (JAMP_TYPE == up_off){
			//ダッシュしていない
			if (ACTION_TYPE != dash){
				//一回目攻撃入力
				if (ATTACK_COUNT == 0 && myship_landing_type == myship_landing_on){
					if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
						ATTACK_ANI_SP = 2.4f;//アニメーションスピード
						ACTION_TYPE = attack;
						blade = blade_on;
						blade_hold = blade_hold_normal;//順手持ち
						ATTACK_ANITIME_RESET = 0;
						ATTACK_COUNT = 1;
						blade_hand_chang = left_hand;
					}
				}
				if (ATTACK_COUNT == 1){
					ATTACK_ANITIME_RESET++;
					if (ATTACK_ANITIME_RESET == 1){
						AnimationTime = 0;
					}
					if (ATTACK_ANITIME_RESET > 1){
						Animation = Model->GetAnimation(L"zan_ren3");
						if (AnimationTime_Copy >= 0 && AnimationTime_Copy <= 49){
							AnimationTime += ATTACK_ANI_SP;
							if (AnimationTime >= 2 && AnimationTime < 3)Blade_motion_se();//剣振りSE
							Velocity += AxisZ()*0.03f;
							if (AnimationTime >= 30){
								AnimationTime = 30;
							}
							AnimationTime_Copy += ATTACK_ANI_SP;
							//2回目の攻撃入力
							if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
								ATTACK_MOUSE_COUNT = 1;
								ATTACK_ANI_SP = 2.6f;//アニメーションスピード
							}
						}
						if (ATTACK_MOUSE_COUNT == 1 && AnimationTime_Copy >= 49){
							AnimationTime_Copy = 49;
							ATTACK_COUNT = 2;
						}
						if (AnimationTime_Copy > 49){
							ATTACK_COUNT = 0;
							ATTACK_ANITIME_RESET = 0;
							AnimationTime = 0;
							AnimationTime_Copy = 0;
							ATTACK_MOUSE_COUNT = 0;
							blade = blade_off;
							ACTION_TYPE = normal;
							Velocity = 0;
						}
					}
				}
				if (ATTACK_COUNT == 2){
					if (AnimationTime_Copy >= 49 && AnimationTime_Copy <= 105){
						if (AnimationTime_Copy >= 49 && AnimationTime_Copy < 50)Blade_motion_se();//剣振りSE
						AnimationTime += ATTACK_ANI_SP;
						if (AnimationTime >= 65){
							AnimationTime = 65;
						}
						AnimationTime_Copy += ATTACK_ANI_SP;
						//3回目の攻撃入力
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							ATTACK_MOUSE_COUNT = 2;
							ATTACK_ANI_SP = 2.9f;//アニメーションスピード
						}
					}
					if (ATTACK_MOUSE_COUNT == 2 && AnimationTime_Copy >= 105){
						AnimationTime_Copy = 105;
						ATTACK_COUNT = 3;
					}
					if (AnimationTime_Copy > 105){
						ATTACK_COUNT = 0;
						ATTACK_ANITIME_RESET = 0;
						AnimationTime = 0;
						AnimationTime_Copy = 0;
						ATTACK_MOUSE_COUNT = 0;
						blade = blade_off;
						ACTION_TYPE = normal;
					}
				}
				if (ATTACK_COUNT == 3){
					if (AnimationTime_Copy >= 105 && AnimationTime_Copy <= 186){
						if (AnimationTime_Copy >= 105 && AnimationTime_Copy < 106)Blade_motion_se();//剣振りSE
						AnimationTime += ATTACK_ANI_SP;
						Velocity += AxisZ()*0.15f;
						if (AnimationTime >= 124){
							AnimationTime = 124;
						}
						AnimationTime_Copy += ATTACK_ANI_SP;
						//4回目の攻撃入力
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							ATTACK_MOUSE_COUNT = 3;
						}
					}
					if (ATTACK_MOUSE_COUNT == 3 && AnimationTime_Copy >= 186){
						AnimationTime_Copy = 186;
						ATTACK_COUNT = 4;
					}
					if (AnimationTime_Copy > 186){
						ATTACK_COUNT = 0;
						ATTACK_ANITIME_RESET = 0;
						AnimationTime = 0;
						AnimationTime_Copy = 0;
						ATTACK_MOUSE_COUNT = 0;
						blade = blade_off;
						ACTION_TYPE = normal;
						Velocity = 0;
					}
				}
				if (ATTACK_COUNT == 4){
					if (AnimationTime_Copy >= 186 && AnimationTime_Copy <= 270){
						if (AnimationTime_Copy >= 186 && AnimationTime_Copy < 187)Blade_motion_se();//剣振りSE
						AnimationTime += ATTACK_ANI_SP;
						Velocity += AxisZ()*0.28f;
						if (AnimationTime >= 184){
							AnimationTime = 184;
						}
						AnimationTime_Copy += ATTACK_ANI_SP;
						//5回目の攻撃入力
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							ATTACK_MOUSE_COUNT = 5;
							ATTACK_ANI_SP = 2.4f;//アニメーションスピード
						}
					}
					if (ATTACK_MOUSE_COUNT == 5 && AnimationTime_Copy >= 270){
						AnimationTime_Copy = 270;
						ATTACK_COUNT = 5;
					}
					if (AnimationTime_Copy > 270){
						ATTACK_COUNT = 0;
						ATTACK_ANITIME_RESET = 0;
						AnimationTime = 0;
						AnimationTime_Copy = 0;
						ATTACK_MOUSE_COUNT = 0;
						blade = blade_off;
						ACTION_TYPE = normal;
						Velocity = 0;
					}
				}
				if (ATTACK_COUNT == 5){
					if (AnimationTime_Copy >= 270 && AnimationTime_Copy <= 300){
						if (AnimationTime_Copy >= 270 && AnimationTime_Copy < 271)Blade_motion_se();//剣振りSE
						AnimationTime += ATTACK_ANI_SP;
						AnimationTime_Copy += ATTACK_ANI_SP;
						if (AnimationTime >= 223){
							AnimationTime = 223;
						}
					}
					if (AnimationTime_Copy > 300){
						AnimationTime_Copy = 300;
						ATTACK_COUNT = 6;
						rota_attack_type = rota_attack_on;
					}
				}
				if (ATTACK_COUNT == 6){
					//回転攻撃
					MyShip_Move_Model3List.Apply([&](CMover*Mm2){
						if (AnimationTime_Copy >= 233 && JUMP_ROTATION_ATTACK_TIME <= 48){
							AnimationTime = 223;
							JUMP_ROTATION_ATTACK_SP = 1.12f;
							JUMP_ROTATION_ATTACK_TIME++;
							if (JUMP_ROTATION_ATTACK_TIME <= 23){
								AxisY_Velocity.Y += JUMP_ROTATION_ATTACK_SP;
								myship_landing_type = myship_landing_off;
								if (JUMP_ROTATION_ATTACK_TIME == 5){
									Rote_VeloZ = Mm2->AxisZ();
								}
								if (JUMP_ROTATION_ATTACK_TIME >= 6){
									Rotation *= CQuaternion(AxisX(), -0.022f);
									Position -= Rote_VeloZ * 0.1f;
								}
							}
						}
						if (JUMP_ROTATION_ATTACK_TIME >= 14 && JUMP_ROTATION_ATTACK_TIME <= 40){
							Rotation *= CQuaternion(AxisX(), -0.022f);
						}
						if (JUMP_ROTATION_ATTACK_TIME >= 14 && JUMP_ROTATION_ATTACK_TIME <= 48){
							Position -= Rote_VeloZ * 0.8f;
						}
						if (JUMP_ROTATION_ATTACK_TIME > 48){
							AnimationTime += ATTACK_ANI_SP - 0.3f;
							if (JUMP_ROTATION_ATTACK_TIME<80){
								Position -= Rote_VeloZ * 0.8f;
							}
						}
						if (AnimationTime > 253){
							AnimationTime = 0;
							AnimationTime_Copy = 0;
							JUMP_ROTATION_ATTACK_TIME = 0;
							Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
							ATTACK_COUNT = 0;
							ATTACK_ANITIME_RESET = 0;
							ATTACK_MOUSE_COUNT = 0;
							blade = blade_off;
							ACTION_TYPE = normal;
							rota_attack_type = rota_attack_off;
						}
					});
				}
			}
			//ダッシュが真の時
			if (ACTION_TYPE == dash){
				//攻撃処理ないの変数初期化
				ATTACK_COUNT = 0;
				ATTACK_ANITIME_RESET = 0;
				AnimationTime_Copy = 0;
				ATTACK_MOUSE_COUNT = 0;
				JUMP_ROTATION_ATTACK_TIME = 0;
			}
		}
	}
	//======================================================ダッシュ移動============================================================
	//ブレードタイプとガンタイプ両方共通
	if (weapon_chang == chang_blade || weapon_chang == chang_gun){
		//ガンショットしていない
		if (ACTION_TYPE != shot_attack){
			//(前ダッシュ)
			//静止状態または通常攻撃しているとき
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//ダッシュ攻撃不可(ダッシュスタートまでいっていない)
				if (DASH_ZANANI_TYPE == 0){
					//ダッシュ入力状態が0
					if (DASH_COUNT == 0){
						//1回目のwを押す
						if (KeyState[0][DIK_W] && !OldKeyState[0][DIK_W] && boost_life >= 50){
							//ダッシュ入力感覚タイマー始動
							DASH_IRREGULAR_COUNT = 1;
						}
						if (DASH_IRREGULAR_COUNT == 1){
							DASH_TIME++;
						}
						if (DASH_TIME >= 1 && DASH_TIME <= 15){
							if (!KeyState[0][DIK_W]){
								DASH_COUNT = 1;
								DASH_TIME = 0;
								DASH_IRREGULAR_COUNT = 0;
							}
							if (KeyState[0][DIK_A] || KeyState[0][DIK_S] || KeyState[0][DIK_D]){
								DASH_COUNT = 0;
								DASH_TIME = 0;
								DASH_IRREGULAR_COUNT = 0;
							}
						}
						if (DASH_TIME > 15){
							if (!KeyState[0][DIK_W]){
								DASH_TIME = 0;
								DASH_IRREGULAR_COUNT = 0;//
							}
							if (KeyState[0][DIK_A] || KeyState[0][DIK_S] || KeyState[0][DIK_D]){
								DASH_COUNT = 0;
								DASH_TIME = 0;
							}
						}
					}

					if (DASH_COUNT == 1){
						DASH_TIME++;
						if (DASH_TIME >= 1 && DASH_TIME <= 15){
							//2回目のwを押す
							if (KeyState[0][DIK_W] && !OldKeyState[0][DIK_W]){
								DASH_COUNT = 2;
								DASH_TIME = 0;
							}
						}
						if (DASH_TIME > 15){
							DASH_TIME = 0;
							DASH_COUNT = 0;
						}
					}
					//ダッシュスタート
					//ダッシュ入力状態2
					if (DASH_COUNT == 2){
						Jet_se();//dash音
						DASH_SP = 4.0f;
						//アクションタイプ(ダッシュ)
						ACTION_TYPE = dash;
						dash_type = dash_w_on;
						if (weapon_chang == chang_blade){
							//ダッシュ攻撃許可
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//アクションタイプ(ダッシュ)処理
			if (ACTION_TYPE == dash&&DASH_COUNT == 2){
				//ダッシュ攻撃に切り替わっていない時のみアニメーション処理
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//ダッシュ攻撃中でも処理する
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME++;
					if (DASH_TIME <= 2){
						Velocity += Mm->AxisZ()*DASH_SP;
						boost_main2_switch = boost_main2_on;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_on;//サブブーストON_OFF
					}
					if (DASH_TIME >= 3 && DASH_TIME <= 36){
						DASH_SP *= 0.9f;
						Velocity += Mm->AxisZ()*DASH_SP;
						if (DASH_TIME == 3){
							AIR_DASHAFTER_MOVE = 1;//空中ダッシュ後移動可能
						}
						//ブーストゲージ消費＆回復
						if (DASH_TIME >= 3 && DASH_TIME <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//ダッシュ攻撃していない
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						//ダッシュ終了
						if (DASH_TIME >= 37){
							boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT = 0;//ダッシュ入力状態初期化
							DASH_TIME = 0;//ダッシュ入力感覚タイマー初期化
							AnimationTime = 0;
							Velocity = 0;//加速度初期化
							DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
							DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
							blade = blade_off;//ブレード消滅
							blade = gun_off;//ガン消滅
							ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
							dash_type = dash_off;
							DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
							boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
							boost_sub_switch = boost_sub_off;
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//ブースト消費OFF
						boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT = 0;//ダッシュ入力状態初期化
						DASH_TIME = 0;//ダッシュ入力感覚タイマー初期化
						AnimationTime = 0;
						Velocity = 0;//加速度初期化
						DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
						DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
						blade = blade_off;//ブレード消滅
						blade = gun_off;//ガン消滅
						ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
						dash_type = dash_off;
						DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
						boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_off;
					}
				});
			}
			//(後ダッシュ)
			//静止状態または通常攻撃しているとき 
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//ダッシュ攻撃不可
				if (DASH_ZANANI_TYPE == 0){
					//ダッシュ入力状態が0
					if (DASH_COUNT2 == 0){
						//1回目のsを押す
						if (KeyState[0][DIK_S] && !OldKeyState[0][DIK_S] && boost_life >= 50){
							//ダッシュ入力感覚タイマー始動
							DASH_IRREGULAR_COUNT2 = 1;
						}
						if (DASH_IRREGULAR_COUNT2 == 1){
							DASH_TIME2++;
						}
						if (DASH_TIME2 >= 1 && DASH_TIME2 <= 15){
							if (!KeyState[0][DIK_S] ){
								DASH_COUNT2 = 1;
								DASH_TIME2 = 0;
								DASH_IRREGULAR_COUNT2 = 0;
							}
							if (KeyState[0][DIK_A] || KeyState[0][DIK_W] || KeyState[0][DIK_D]){
								DASH_COUNT2 = 0;
								DASH_TIME2 = 0;
								DASH_IRREGULAR_COUNT2=0;
							}
						}
						if (DASH_TIME2 > 15){
							if (!KeyState[0][DIK_S] ){
								DASH_TIME2 = 0;
								DASH_IRREGULAR_COUNT2 = 0;
							}
							if (KeyState[0][DIK_A] || KeyState[0][DIK_W] || KeyState[0][DIK_D]){
								DASH_COUNT2 = 0;
								DASH_TIME2 = 0;
							}
						}
					}

					if (DASH_COUNT2 == 1){
						DASH_TIME2++;
						if (DASH_TIME2 >= 1 && DASH_TIME2 <= 15){
							//2回目のsを押す
							if (KeyState[0][DIK_S] && !OldKeyState[0][DIK_S]){
								DASH_COUNT2 = 2;
								DASH_TIME2 = 0;
							}
						}
						if (DASH_TIME2 > 15){
							DASH_TIME2 = 0;
							DASH_COUNT2 = 0;
						}
					}
					//ダッシュスタート
					//ダッシュ入力状態2
					if (DASH_COUNT2 == 2){
						Jet_se();//dash音
						DASH_SP2 = 4.0f;
						//アクションタイプ(ダッシュ)
						ACTION_TYPE = dash;
						dash_type = dash_s_on;
						if (weapon_chang == chang_blade){
							//ダッシュ攻撃許可
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//アクションタイプ(ダッシュ)処理
			if (ACTION_TYPE == dash&&DASH_COUNT2 == 2){
				//ダッシュ攻撃に切り替わっていない時のみアニメーション処理
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//ダッシュ攻撃中でも処理する
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME2++;
					if (DASH_TIME2 <= 2){
						Velocity -= Mm->AxisZ()*DASH_SP2;
						boost_main2_switch = boost_main2_on;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_on;//サブブーストON_OFF
					}
					if (DASH_TIME2 >= 3 && DASH_TIME2 <= 36){
						DASH_SP2 *= 0.9f;
						Velocity -= Mm->AxisZ()*DASH_SP2;
						if (DASH_TIME2 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//ブーストゲージ消費＆回復
						if (DASH_TIME2 >= 3 && DASH_TIME2 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME2 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//ダッシュ攻撃していない
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						//ダッシュ終了
						if (DASH_TIME2 >= 37){
							boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT2 = 0;//ダッシュ入力状態初期化
							DASH_TIME2 = 0;//ダッシュ入力感覚タイマー初期化
							AnimationTime = 0;
							Velocity = 0;//加速度初期化
							DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
							DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
							blade = blade_off;//ブレード消滅
							blade = gun_off;//ガン消滅
							ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
							dash_type = dash_off;
							DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
							boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
							boost_sub_switch = boost_sub_off;//サブブーストON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//ブースト消費OFF
						boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT2 = 0;//ダッシュ入力状態初期化
						DASH_TIME2 = 0;//ダッシュ入力感覚タイマー初期化
						AnimationTime = 0;
						Velocity = 0;//加速度初期化
						DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
						DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
						blade = blade_off;//ブレード消滅
						blade = gun_off;//ガン消滅
						ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
						dash_type = dash_off;
						DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
						boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_off;//サブブーストON_OFF
					}
				});
			}
			//(右ダッシュ)		
			//静止状態または通常攻撃しているとき
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//ダッシュ攻撃不可
				if (DASH_ZANANI_TYPE == 0){
					//ダッシュ入力状態が0
					if (DASH_COUNT3 == 0){
						//1回目のdを押す
						if (KeyState[0][DIK_D] && !OldKeyState[0][DIK_D] && boost_life >= 50){
							//ダッシュ入力感覚タイマー始動
							DASH_IRREGULAR_COUNT3 = 1;
						}
						if (DASH_IRREGULAR_COUNT3 == 1){
							DASH_TIME3++;
						}
						if (DASH_TIME3 >= 1 && DASH_TIME3 <= 15){
							if (!KeyState[0][DIK_D]){
								DASH_COUNT3 = 1;
								DASH_TIME3 = 0;
								DASH_IRREGULAR_COUNT3 = 0;
							}
							if (KeyState[0][DIK_S] || KeyState[0][DIK_W] || KeyState[0][DIK_A]){
								DASH_COUNT3 = 0;
								DASH_TIME3 = 0;
								DASH_IRREGULAR_COUNT3 = 0;
							}
						}
						if (DASH_TIME3 > 15){
							if (!KeyState[0][DIK_D]){
								DASH_TIME3 = 0;
								DASH_IRREGULAR_COUNT3 = 0;
							}
							if (KeyState[0][DIK_S] || KeyState[0][DIK_W] || KeyState[0][DIK_A]){
								DASH_COUNT3 = 0;
								DASH_TIME3 = 0;
							}
						}
					}

					if (DASH_COUNT3 == 1){
						DASH_TIME3++;
						if (DASH_TIME3 >= 1 && DASH_TIME3 <= 15){
							//2回目のdを押す
							if (KeyState[0][DIK_D] && !OldKeyState[0][DIK_D]){
								DASH_COUNT3= 2;
								DASH_TIME3 = 0;
							}
						}
						if (DASH_TIME3 > 15){
							DASH_TIME3 = 0;
							DASH_COUNT3 = 0;
						}
					}
					//ダッシュスタート
					//ダッシュ入力状態2
					if (DASH_COUNT3 == 2){
						Jet_se();//dash音
						DASH_SP3 = 4.0f;
						//アクションタイプ(ダッシュ)
						ACTION_TYPE = dash;
						dash_type = dash_d_on;
						if (weapon_chang == chang_blade){
							//ダッシュ攻撃許可
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//アクションタイプ(ダッシュ)処理
			if (ACTION_TYPE == dash&&DASH_COUNT3 == 2){
				//ダッシュ攻撃に切り替わっていない時のみアニメーション処理
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//ダッシュ攻撃中でも処理する
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME3++;
					if (DASH_TIME3 <= 2){
						boost_sub_switch = boost_sub_on;//サブブーストON_OFF
						boost_main2_switch = boost_main2_on;//ブースト二段階ON_OFF
						Velocity += Mm->AxisX()*DASH_SP3;
					}
					if (DASH_TIME3 >= 3 && DASH_TIME3 <= 36){
						DASH_SP3 *= 0.9f;
						Velocity += Mm->AxisX()*DASH_SP3;
						if (DASH_TIME3 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//ブーストゲージ消費＆回復
						if (DASH_TIME3 >= 3 && DASH_TIME3 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME3 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//ダッシュ攻撃していない
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						//ダッシュ終了
						if (DASH_TIME3 >= 37){
							boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT3 = 0;//ダッシュ入力状態初期化
							DASH_TIME3 = 0;//ダッシュ入力感覚タイマー初期化
							AnimationTime = 0;
							Velocity = 0;//加速度初期化
							DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
							DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
							blade = blade_off;//ブレード消滅
							blade = gun_off;//ガン消滅
							ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
							dash_type = dash_off;
							DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
							boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
							boost_sub_switch = boost_sub_off;//サブブーストON_OFF
						
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//ブースト消費OFF
						boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT3 = 0;//ダッシュ入力状態初期化
						DASH_TIME3 = 0;//ダッシュ入力感覚タイマー初期化
						AnimationTime = 0;
						Velocity = 0;//加速度初期化
						DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
						DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
						blade = blade_off;//ブレード消滅
						blade = gun_off;//ガン消滅
						ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
						dash_type = dash_off;
						DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
						boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_off;//サブブーストON_OFF
					}
				});
			}
			//(左ダッシュ)
			//静止状態または通常攻撃しているとき
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//ダッシュ攻撃不可
				if (DASH_ZANANI_TYPE == 0){
					//ダッシュ入力状態が0
					if (DASH_COUNT4 == 0){
						//1回目のaを押す
						if (KeyState[0][DIK_A] && !OldKeyState[0][DIK_A] && boost_life >= 50){
							//ダッシュ入力感覚タイマー始動
							DASH_IRREGULAR_COUNT4 = 1;
						}
						if (DASH_IRREGULAR_COUNT4 == 1){
							DASH_TIME4++;
						}
						if (DASH_TIME4 >= 1 && DASH_TIME4 <= 15){
							if (!KeyState[0][DIK_A]){
								DASH_COUNT4 = 1;
								DASH_TIME4= 0;
								DASH_IRREGULAR_COUNT4 = 0;
							}
							if (KeyState[0][DIK_D] || KeyState[0][DIK_W] || KeyState[0][DIK_S]){
								DASH_COUNT4 = 0;
								DASH_TIME4 = 0;
								DASH_IRREGULAR_COUNT4 = 0;
							}
						}
						if (DASH_TIME4 > 15){
							if (!KeyState[0][DIK_A]){
								DASH_TIME4 = 0;
								DASH_IRREGULAR_COUNT4 = 0;
							}
							if (KeyState[0][DIK_D] || KeyState[0][DIK_W] || KeyState[0][DIK_S]){
								DASH_COUNT4 = 0;
								DASH_TIME4 = 0;
							}
						}
					}

					if (DASH_COUNT4 == 1){
						DASH_TIME4++;
						if (DASH_TIME4 >= 1 && DASH_TIME4 <= 15){
							//2回目のaを押す
							if (KeyState[0][DIK_A] && !OldKeyState[0][DIK_A]){
								DASH_COUNT4 = 2;
								DASH_TIME4 = 0;
							}
						}
						if (DASH_TIME4 > 15){
							DASH_TIME4 = 0;
							DASH_COUNT4 = 0;
						}
					}
					//ダッシュスタート
					//ダッシュ入力状態2
					if (DASH_COUNT4 == 2){
						DASH_SP4 = 4.0f;
						Jet_se();//dash音
						//アクションタイプ(ダッシュ)
						ACTION_TYPE = dash;
						dash_type = dash_a_on;
						//ブレード装備中のみ処理
						if (weapon_chang == chang_blade){
							//ダッシュ攻撃許可
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//アクションタイプ(ダッシュ)処理
			if (ACTION_TYPE == dash&&DASH_COUNT4 == 2){
				//ダッシュ攻撃に切り替わっていない時のみアニメーション処理
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//ダッシュ攻撃中でも処理する
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME4++;
					if (DASH_TIME4 <= 2){
						boost_sub_switch = boost_sub_on;//サブブーストON_OFF
						Velocity -= Mm->AxisX()*DASH_SP4;
						boost_main2_switch = boost_main2_on;//ブースト二段階ON_OFF
					}
					if (DASH_TIME4 >= 3 && DASH_TIME4 <= 36){
						DASH_SP4 *= 0.9f;
						Velocity -= Mm->AxisX()*DASH_SP4;
						if (DASH_TIME4 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//ブーストゲージ消費＆回復
						if (DASH_TIME4 >= 3 && DASH_TIME4 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME4 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//ダッシュ攻撃していない
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME4 >= 37){
							boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT4 = 0;//ダッシュ入力状態初期化
							DASH_TIME4 = 0;//ダッシュ入力感覚タイマー初期化
							AnimationTime = 0;
							Velocity = 0;//加速度初期化
							DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
							DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
							blade = blade_off;//ブレード消滅
							blade = gun_off;//ガン消滅
							DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
							ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
							boost_sub_switch = boost_sub_off;//サブブーストON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//ブースト消費OFF
						boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT4 = 0;//ダッシュ入力状態初期化
						DASH_TIME4 = 0;//ダッシュ入力感覚タイマー初期化
						AnimationTime = 0;
						Velocity = 0;//加速度初期化
						DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
						DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
						blade = blade_off;//ブレード消滅
						blade = gun_off;//ガン消滅
						DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
						ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_off;//サブブーストON_OFF
					}
				});
			}
			//(左前ダッシュ)
			//静止状態または通常攻撃しているとき
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//ダッシュ攻撃不可
				if (DASH_ZANANI_TYPE == 0){
					//ダッシュ入力状態が0
					if (DASH_COUNT5 == 0){
						//1回目のaを押す
						if (KeyState[0][DIK_A] && KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && boost_life >= 50){
							//ダッシュ入力感覚タイマー始動
							DASH_TIME5++;
						}
						if (DASH_TIME5 >= 1 && DASH_TIME5 <= 15){//20
							if (!KeyState[0][DIK_A] && !KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D]){
								DASH_COUNT5 = 1;
								DASH_TIME5 = 0;
							}
						}
						if (DASH_TIME5 > 15){
							if (!KeyState[0][DIK_A] && !KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D]){
								DASH_TIME5 = 0;
							}
						}
					}
					if (DASH_COUNT5 == 1){
						DASH_TIME5++;
						if (DASH_TIME5 >= 1 && DASH_TIME5 <= 15){
							//2回目のaを押す
							if (KeyState[0][DIK_A] && KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D]){
								DASH_COUNT5 = 2;
								DASH_TIME5 = 0;
							}
						}
						if (DASH_TIME5 > 15){
							DASH_TIME5 = 0;
							DASH_COUNT5 = 0;
						}
					}
					//ダッシュスタート
					//ダッシュ入力状態2
					if (DASH_COUNT5 == 2){
						DASH_SP5 = 2.0f;
						Jet_se();//dash音
						//アクションタイプ(ダッシュ)
						ACTION_TYPE = dash;
						dash_type = dash_aw_on;
						//ブレード装備中のみ処理
						if (weapon_chang == chang_blade){
							//ダッシュ攻撃許可
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//アクションタイプ(ダッシュ)処理
			if (ACTION_TYPE == dash&&DASH_COUNT5 == 2){
				//ダッシュ攻撃に切り替わっていない時のみアニメーション処理
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//ダッシュ攻撃中でも処理する
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME5++;
					if (DASH_TIME5 <= 2){
						boost_main2_switch = boost_main2_on;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_on;//サブブーストON_OFF
						Velocity -= Mm->AxisX()*DASH_SP5;
						Velocity += Mm->AxisZ()*DASH_SP5;
					}
					if (DASH_TIME5 >= 3 && DASH_TIME5 <= 36){
						DASH_SP5 *= 0.9f;
						Velocity -= Mm->AxisX()*DASH_SP5;
						Velocity += Mm->AxisZ()*DASH_SP5;
						if (DASH_TIME5 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//ブーストゲージ消費＆回復
						if (DASH_TIME5 >= 3 && DASH_TIME5 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME5 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//ダッシュ攻撃していない
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME5 >= 37){
							boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT5 = 0;//ダッシュ入力状態初期化
							DASH_TIME5 = 0;//ダッシュ入力感覚タイマー初期化
							AnimationTime = 0;
							Velocity = 0;//加速度初期化
							DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
							DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
							blade = blade_off;//ブレード消滅
							blade = gun_off;//ガン消滅
							DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
							ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
							boost_sub_switch = boost_sub_off;//サブブーストON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//ブースト消費OFF
						boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT5 = 0;//ダッシュ入力状態初期化
						DASH_TIME5 = 0;//ダッシュ入力感覚タイマー初期化
						AnimationTime = 0;
						Velocity = 0;//加速度初期化
						DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
						DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
						blade = blade_off;//ブレード消滅
						blade = gun_off;//ガン消滅
						DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
						ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_off;//サブブーストON_OFF
					}
				});
			}
			//(右前ダッシュ)
			//静止状態または通常攻撃しているとき
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//ダッシュ攻撃不可
				if (DASH_ZANANI_TYPE == 0){
					//ダッシュ入力状態が0
					if (DASH_COUNT6 == 0){
						//1回目のaを押す
						if (KeyState[0][DIK_D] && KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_A] && boost_life >= 50){
							//ダッシュ入力感覚タイマー始動
							DASH_TIME6++;
						}
						if (DASH_TIME6 >= 1 && DASH_TIME6 <= 15){
							if (!KeyState[0][DIK_D] && !KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_A]){
								DASH_COUNT6 = 1;
								DASH_TIME6 = 0;
							}
						}
						if (DASH_TIME6 > 15){
							if (!KeyState[0][DIK_D] && !KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_A]){
								DASH_TIME6 = 0;
							}
						}
					}
					if (DASH_COUNT6 == 1){
						DASH_TIME6++;
						if (DASH_TIME6 >= 1 && DASH_TIME6 <= 15){
							//2回目のaを押す
							if (KeyState[0][DIK_D] && KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_A]){
								DASH_COUNT6 = 2;
								DASH_TIME6 = 0;
							}
						}
						if (DASH_TIME6 > 15){
							DASH_TIME6 = 0;
							DASH_COUNT6 = 0;
						}
					}
					//ダッシュスタート
					//ダッシュ入力状態2
					if (DASH_COUNT6 == 2){
						Jet_se();//dash音
						DASH_SP6 = 2.0f;
						//アクションタイプ(ダッシュ)
						ACTION_TYPE = dash;
						dash_type = dash_dw_on;
						//ブレード装備中のみ処理
						if (weapon_chang == chang_blade){
							//ダッシュ攻撃許可
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//アクションタイプ(ダッシュ)処理
			if (ACTION_TYPE == dash&&DASH_COUNT6 == 2){
				//ダッシュ攻撃に切り替わっていない時のみアニメーション処理
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//ダッシュ攻撃中でも処理する
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME6++;
					if (DASH_TIME6 <= 2){
						boost_main2_switch = boost_main2_on;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_on;//サブブーストON_OFF
						Velocity += Mm->AxisX()*DASH_SP6;
						Velocity += Mm->AxisZ()*DASH_SP6;
					}
					if (DASH_TIME6 >= 3 && DASH_TIME6 <= 36){
						DASH_SP6 *= 0.9f;
						Velocity += Mm->AxisX()*DASH_SP6;
						Velocity += Mm->AxisZ()*DASH_SP6;
						if (DASH_TIME6 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//ブーストゲージ消費＆回復
						if (DASH_TIME6 >= 3 && DASH_TIME6 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME6 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//ダッシュ攻撃していない
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME6 >= 37){
							boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT6 = 0;//ダッシュ入力状態初期化
							DASH_TIME6 = 0;//ダッシュ入力感覚タイマー初期化
							AnimationTime = 0;
							Velocity = 0;//加速度初期化
							DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
							DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
							blade = blade_off;//ブレード消滅
							blade = gun_off;//ガン消滅
							DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
							ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
							boost_sub_switch = boost_sub_off;//サブブーストON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//ブースト消費OFF
						boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT6 = 0;//ダッシュ入力状態初期化
						DASH_TIME6 = 0;//ダッシュ入力感覚タイマー初期化
						AnimationTime = 0;
						Velocity = 0;//加速度初期化
						DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
						DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
						blade = blade_off;//ブレード消滅
						blade = gun_off;//ガン消滅
						DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
						ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_off;//サブブーストON_OFF
					}
				});
			}
			//(左後ダッシュ)
			//静止状態または通常攻撃しているとき
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//ダッシュ攻撃不可
				if (DASH_ZANANI_TYPE == 0){
					//ダッシュ入力状態が0
					if (DASH_COUNT7 == 0){
						//1回目のaを押す
						if (KeyState[0][DIK_A] && KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_D] && boost_life >= 50){
							//ダッシュ入力感覚タイマー始動
							DASH_TIME7++;
						}
						if (DASH_TIME7 >= 1 && DASH_TIME7 <= 15){
							if (!KeyState[0][DIK_A] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_D]){
								DASH_COUNT7 = 1;
								DASH_TIME7 = 0;
							}
						}
						if (DASH_TIME7 > 15){
							if (!KeyState[0][DIK_A] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_D]){
								DASH_TIME7 = 0;
							}
						}
					}
					if (DASH_COUNT7 == 1){
						DASH_TIME7++;
						if (DASH_TIME7 >= 1 && DASH_TIME7 <= 15){
							//2回目のaを押す
							if (KeyState[0][DIK_A] && KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_D]){
								DASH_COUNT7 = 2;
								DASH_TIME7 = 0;
							}
						}
						if (DASH_TIME7 > 15){
							DASH_TIME7 = 0;
							DASH_COUNT7 = 0;
						}
					}
					//ダッシュスタート
					//ダッシュ入力状態2
					if (DASH_COUNT7 == 2){
						Jet_se();//dash音
						DASH_SP7 = 2.0f;
						//アクションタイプ(ダッシュ)
						ACTION_TYPE = dash;
						dash_type = dash_as_on;
						//ブレード装備中のみ処理
						if (weapon_chang == chang_blade){
							//ダッシュ攻撃許可
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//アクションタイプ(ダッシュ)処理
			if (ACTION_TYPE == dash&&DASH_COUNT7 == 2){
				//ダッシュ攻撃に切り替わっていない時のみアニメーション処理
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//ダッシュ攻撃中でも処理する
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME7++;
					if (DASH_TIME7 <= 2){
						boost_main2_switch = boost_main2_on;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_on;//サブブーストON_OFF
						Velocity -= Mm->AxisX()*DASH_SP7;
						Velocity -= Mm->AxisZ()*DASH_SP7;
					}
					if (DASH_TIME7 >= 3 && DASH_TIME7 <= 36){
						DASH_SP7 *= 0.9f;
						Velocity -= Mm->AxisX()*DASH_SP7;
						Velocity -= Mm->AxisZ()*DASH_SP7;
						if (DASH_TIME7 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//ブーストゲージ消費＆回復
						if (DASH_TIME7 >= 3 && DASH_TIME7 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME7 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//ダッシュ攻撃していない
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME7 >= 37){
							boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT7 = 0;//ダッシュ入力状態初期化
							DASH_TIME7 = 0;//ダッシュ入力感覚タイマー初期化
							AnimationTime = 0;
							Velocity = 0;//加速度初期化
							DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
							DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
							blade = blade_off;//ブレード消滅
							blade = gun_off;//ガン消滅
							DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
							ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
							boost_sub_switch = boost_sub_off;//サブブーストON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//ブースト消費OFF
						boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT7 = 0;//ダッシュ入力状態初期化
						DASH_TIME7 = 0;//ダッシュ入力感覚タイマー初期化
						AnimationTime = 0;
						Velocity = 0;//加速度初期化
						DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
						DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
						blade = blade_off;//ブレード消滅
						blade = gun_off;//ガン消滅
						DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
						ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_off;//サブブーストON_OFF
					}
				});
			}
			//(右後ダッシュ)
			//静止状態または通常攻撃しているとき
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//ダッシュ攻撃不可
				if (DASH_ZANANI_TYPE == 0){
					//ダッシュ入力状態が0
					if (DASH_COUNT8 == 0){
						//1回目のaを押す
						if (KeyState[0][DIK_D] && KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_A] && boost_life >= 50){
							//ダッシュ入力感覚タイマー始動
							DASH_TIME8++;
						}
						if (DASH_TIME8 >= 1 && DASH_TIME8 <= 15){
							if (!KeyState[0][DIK_D] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_A]){
								DASH_COUNT8 = 1;
								DASH_TIME8 = 0;
							}
						}
						if (DASH_TIME8 > 15){
							if (!KeyState[0][DIK_D] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_A]){
								DASH_TIME8 = 0;
							}
						}
					}
					if (DASH_COUNT8 == 1){
						DASH_TIME8++;
						if (DASH_TIME8 >= 1 && DASH_TIME8 <= 15){
							//2回目のaを押す
							if (KeyState[0][DIK_D] && KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_A]){
								DASH_COUNT8 = 2;
								DASH_TIME8 = 0;
							}
						}
						if (DASH_TIME8 > 15){
							DASH_TIME8 = 0;
							DASH_COUNT8 = 0;
						}
					}
					//ダッシュスタート
					//ダッシュ入力状態2
					if (DASH_COUNT8 == 2){
						Jet_se();//dash音
						DASH_SP8 = 2.0f;
						//アクションタイプ(ダッシュ)
						ACTION_TYPE = dash;
						dash_type = dash_ds_on;
						//ブレード装備中のみ処理
						if (weapon_chang == chang_blade){
							//ダッシュ攻撃許可
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//アクションタイプ(ダッシュ)処理
			if (ACTION_TYPE == dash&&DASH_COUNT8 == 2){
				//ダッシュ攻撃に切り替わっていない時のみアニメーション処理
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//ダッシュ攻撃中でも処理する
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME8++;
					if (DASH_TIME8 <= 2){
						boost_main2_switch = boost_main2_on;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_on;//サブブーストON_OFF
						Velocity += Mm->AxisX()*DASH_SP8;
						Velocity -= Mm->AxisZ()*DASH_SP8;
					}
					if (DASH_TIME8 >= 3 && DASH_TIME8 <= 36){
						DASH_SP8 *= 0.9f;
						Velocity += Mm->AxisX()*DASH_SP8;
						Velocity -= Mm->AxisZ()*DASH_SP8;
						if (DASH_TIME8 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//ブーストゲージ消費＆回復
						if (DASH_TIME8 >= 3 && DASH_TIME8 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME8 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//ダッシュ攻撃していない
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME8 >= 37){
							boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT8 = 0;//ダッシュ入力状態初期化
							DASH_TIME8 = 0;//ダッシュ入力感覚タイマー初期化
							AnimationTime = 0;
							Velocity = 0;//加速度初期化
							DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
							DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
							blade = blade_off;//ブレード消滅
							blade = gun_off;//ガン消滅
							DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
							ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
							boost_sub_switch = boost_sub_off;//サブブーストON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//ブースト消費OFF
						boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT8 = 0;//ダッシュ入力状態初期化
						DASH_TIME8 = 0;//ダッシュ入力感覚タイマー初期化
						AnimationTime = 0;
						Velocity = 0;//加速度初期化
						DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
						DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
						blade = blade_off;//ブレード消滅
						blade = gun_off;//ガン消滅
						DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
						ACTION_TYPE = normal;//アクションタイプを静止状態に初期化
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
						boost_sub_switch = boost_sub_off;//サブブーストON_OFF
					}
				});
			}
		}
	}
	//===========================================================ダッシュ攻撃=======================================================
	//着地している
	if (myship_landing_type == myship_landing_on){
		//ダッシュ攻撃許可(ダッシュ中)
		if (DASH_ZANANI_TYPE == 1){
			if (myship_landing_type == myship_landing_off){
				DASH_ATTACK_COUNT = dash_attack_off;
				DASH_ATTACK_TIME = 0;
				AnimationTime = 0;
				blade = blade_off;
			}
			//ダッシュ中に左クリックが押された
			if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
				blade = blade_on;//出現
				blade_hold = blade_hold_reverse;//逆手持ち
				DASH_ZAN_CHANGE = dash_zan_on;//ダッシュアニメーションに変更
				Animation = Model->GetAnimation(L"boost_zan");
				DASH_ATTACK_COUNT = dash_attack_on;//ダッシュ攻撃始動
				blade_hand_chang = left_hand;//左手持ち
			}
		}
		//ダッシュ攻撃始動処理
		if (DASH_ATTACK_COUNT == dash_attack_on){
			DASH_ATTACK_TIME++;
			if (DASH_ATTACK_TIME == 1){
				AnimationTime = 0;
			}//2連撃込
			if (DASH_ATTACK_TIME < 38){
				if (DASH_ATTACK_TIME == 1)Blade_motion2_se();//剣振り音
				AnimationTime += 2.2f;
				if (AnimationTime > 80){
					AnimationTime = 80;
				}
			}
			if (DASH_ATTACK_TIME > 38){
				DASH_ATTACK_COUNT = dash_attack_off;
			}
		}
	}
	//空中にいったら
	if (myship_landing_type == myship_landing_off || AIR_BLADE_ATTACK_TYPE == air_blade_attack_on){
		DASH_ATTACK_COUNT = dash_attack_off;
		DASH_ATTACK_TIME = 0;
		DASH_ZANANI_TYPE = 0;
		blade_hold = blade_hold_normal;
		DASH_ZAN_CHANGE = dash_zan_off;
	}
	//=============================================================攻撃方法チェンジ=========================================================
	//ブレード装備中	
	if (weapon_chang == chang_blade){
			if (MouseState[0].Button[2] && !OldMouseState[0].Button[2]){
				WEAPON_CHANGE_COUNT = 1;
				weapon_chang_name = chang_gun;
			}
			if (WEAPON_CHANGE_COUNT==1){
				//移動中
				if (ACTION_TYPE == normal){
					weapon_chang = chang_gun;
					WEAPON_CHANGE_COUNT = 0;
				}
				//通常攻撃中
				if (ACTION_TYPE == attack){
					if (AnimationTime_Copy > 49 && AnimationTime_Copy <= 50){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime_Copy > 105 && AnimationTime_Copy <= 106){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime_Copy > 186 && AnimationTime_Copy <= 187){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime_Copy > 270 && AnimationTime_Copy <= 271){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime_Copy > 300 && AnimationTime_Copy <= 301){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime > 253){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (BLADEWEAPON_CHANGE_NORMAL_TYPE == 1){
						weapon_chang = chang_gun;
						blade = blade_off;//ブレード消滅
						WEAPON_CHANGE_COUNT = 0;
						ATTACK_COUNT = 0;
						ATTACK_ANITIME_RESET = 0;
						AnimationTime_Copy = 0;
						ATTACK_MOUSE_COUNT = 0;
						ACTION_TYPE = normal;
						Velocity = 0;
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 0;
					}
				}
				//ダッシュ移動中
				if (ACTION_TYPE == dash){
					weapon_chang = chang_gun;
					WEAPON_CHANGE_COUNT = 0;
				}
				//ダッシュ攻撃中
				if (DASH_ATTACK_TIME > 38){
					weapon_chang = chang_gun;
					WEAPON_CHANGE_COUNT = 0;
				}
			}
		}
	//ガン装備中
		else if (weapon_chang == chang_gun){
			if (MouseState[0].Button[2] && !OldMouseState[0].Button[2]){
				GUN_WEAPON_CHANGE_COUNT = 1;
				weapon_chang_name = chang_blade;
			}
			if (GUN_WEAPON_CHANGE_COUNT == 1){
				if (GUN_ATTACK_COUNT == 0){
					GUN_WEAPON_CHANGE_NORMAL_TYPE = 1;
				}


				if (GUN_WEAPON_CHANGE_NORMAL_TYPE == 1){
					weapon_chang = chang_blade;
					GUN_ATTACK_COUNT = 0;
					gun = gun_off;
					GUN_ATTACK_TIME = 0;
					ANI_TYPE = idl;
					GUN_WEAPON_CHANGE_NORMAL_TYPE = 0;
					GUN_WEAPON_CHANGE_COUNT = 0;

					AIR_GUNSHOT_COUNT = 0;
					AIR_GUNSHOT_TIME = 0;
					AIR_GUNSHOT_ONOFF = 0;
				}
			}
			
		}
		
	//==============================================================ガン攻撃==================================================================
		//ガン装備中
		if (weapon_chang == chang_gun){
			//上昇中は発動しない(空中にいない)
			if (JAMP_TYPE == up_off&&myship_landing_type == myship_landing_on){
				if (GUN_ATTACK_COUNT == 0 && MouseState[0].Button[0] && !OldMouseState[0].Button[0] && gun_gage_life >= 100){
					gun = gun_on;//ガン出現
					ACTION_TYPE = shot_attack;//アクションタイプをショットに変更
					blade = blade_off;//ブレード消滅
					GUN_ATTACK_TIME = 0;
					//初期化
					DASH_COUNT = 0;//ダッシュ入力状態初期化
					DASH_TIME = 0;//ダッシュ入力感覚タイマー初期化
					DASH_COUNT2 = 0;//ダッシュ入力状態初期化
					DASH_TIME2 = 0;//ダッシュ入力感覚タイマー初期化
					DASH_COUNT3 = 0;//ダッシュ入力状態初期化
					DASH_TIME3 = 0;//ダッシュ入力感覚タイマー初期化
					DASH_COUNT4 = 0;//ダッシュ入力状態初期化
					DASH_TIME4 = 0;//ダッシュ入力感覚タイマー初期化
					DASH_COUNT5 = 0;//ダッシュ入力状態初期化
					DASH_TIME5 = 0;//ダッシュ入力感覚タイマー初期化
					DASH_COUNT6 = 0;//ダッシュ入力状態初期化
					DASH_TIME6 = 0;//ダッシュ入力感覚タイマー初期化
					DASH_COUNT7 = 0;//ダッシュ入力状態初期化
					DASH_TIME7 = 0;//ダッシュ入力感覚タイマー初期化
					DASH_COUNT8 = 0;//ダッシュ入力状態初期化
					DASH_TIME8 = 0;//ダッシュ入力感覚タイマー初期化
					DASH_ZANANI_TYPE = 0;//ダッシュ攻撃許可変数初期化
					DASH_ATTACK_TIME = 0;//ダッシュ攻撃入力感覚タイマー初期化
					DASH_ZAN_CHANGE = dash_zan_off;//ダッシュ攻撃に切り替わっていない時のみアニメーション処理変数初期化
					GUN_ATTACK_COUNT = 1;
					gun_hande_Angle = normal_on;
					boost_main2_switch = boost_main2_off;//ブースト二段階ON_OFF
					dash_type = dash_off;
					boost_sub_switch = boost_sub_off;//サブブースト初期化
					boost_recovery_switch = boost_recovery_on;//ブーストゲージ回復ON
					boost_gage_switch = boost_gage_off;//ブースト消費off
				}
				if (GUN_ATTACK_COUNT == 1){
					GUN_ATTACK_TIME++;
					if (GUN_ATTACK_TIME == 1){
						Animation = Model->GetAnimation(L"shot");
						AnimationTime = 0;
					}
					if (GUN_ATTACK_TIME > 1){
						Animation = Model->GetAnimation(L"shot");
						AnimationTime += 3.2f;
						if (AnimationTime > 30.0){
							AnimationTime = 30;
						}
						//ビーム発射
						if (GUN_ATTACK_TIME == 21){
							Beam_se();//ビーム発射音
							beam_launch = beam_on;//ビーム発射
							gun_gage_consumption = gun_gage_consumption_on;
						}
						if (GUN_ATTACK_TIME > 21){
							beam_launch = beam_off;
							gun_gage_consumption = gun_gage_consumption_off;
						}
						if (GUN_ATTACK_TIME > 33){
							GUN_ATTACK_COUNT = 2;
						}
					}
				}
				if (GUN_ATTACK_COUNT == 2){
					Animation = Model->GetAnimation(L"shot");
					AnimationTime -= 3.2f;
					if (AnimationTime <= 0){
						AnimationTime = 0;
						gun = gun_off;
						GUN_ATTACK_COUNT = 0;
						ACTION_TYPE = normal;
						ANI_TYPE = idl;
						GUN_ATTACK_TIME = 0;
					}
				}
			}
		}
//=================================================================ジャンプ====================================================
		//ブレードタイプとガンタイプ両方共通
		if (weapon_chang == chang_blade || weapon_chang == chang_gun){
			//＜着地中かつ攻撃していない＞
			if (myship_landing_type == myship_landing_on&&ACTION_TYPE != attack&&boost_life >= 1 && GUN_ATTACK_COUNT == 0 && icon0_type == icon0_off){
				if (UP_COUNT == 0){
					UP_TIME = 0;
					UP_SP = 2.2f;
					AxisY_Velocity.Y = 0;
					if (KeyState[0][DIK_SPACE]){
						UP_COUNT = 1;
						myship_landing_type = myship_landing_off;
						JAMP_TYPE = up_on;//ジャンプON
						boost_subup_switch = boost_subup_on;//UPブーストON
						GRAVITY_POWER = 0;
						AnimationTime = 0;

					}
					if (!KeyState[0][DIK_SPACE]){
						JAMP_TYPE = up_off;//ジャンプOFF
						boost_subup_switch = boost_subup_off;//UPブーストOFF
					}
					
				}
			}
			//＜ブーストゲージ0の場合＞
			if (boost_life <= 0){
				JAMP_TYPE = up_off;//ジャンプOFF
				boost_subup_switch = boost_subup_off;//UPブーストOFF
				UP_TIME = 0;
				UP_COUNT = 0;
				GRAVITY_POWER = -1.0;
				air_gage_switch = air_gage_off;
			}
			//＜空中中スペースキーが押されている（上昇している＆ブーストライフ0＆ダッシュしていない＞
			if (myship_landing_type == myship_landing_off&&JAMP_TYPE == up_on&&boost_life >= 1 && icon0_type == icon0_off){//&& dash_type == dash_off
				//----------------------------ジャンプ--------------------
				if (UP_COUNT == 1){//ジャンプON中
					Velocity.Y = 0;
					if (ACTION_TYPE != dash&&!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] && AIR_BLADE_ATTACK_TYPE == 0 && AIR_GUNSHOT_ONOFF == 0){//ダッシュしていない
						Animation = Model->GetAnimation(L"up");
						AnimationTime += 2.5f;
						if (AnimationTime >= 30){
							AnimationTime = 30;
						}
					}
					UP_TIME++;
					//初段上昇
					if (UP_TIME <= 2){
						AxisY_Velocity.Y += UP_SP;
					}
					if (UP_TIME > 3 && UP_TIME <= 3){//初段減速
						UP_SP *= 0.3f;
						AxisY_Velocity.Y += UP_SP;
					}
					if (UP_TIME > 3){
						AxisY_Velocity.Y = 0.0f;
						UP_SP *= 0.88f;
						AxisY_Velocity.Y += UP_SP;
						boost_subup_switch = boost_subup_off;//UPブーストON
					}

					//-------------------------上昇継続-----------------------
					if (UP_TIME > 20){
						if (KeyState[0][DIK_SPACE]){
							air_gage_switch = air_gage_on;
							boost_subup_switch = boost_subup_on;//UPブーストON
							UP_SP = 0.3f;
							AxisY_Velocity.Y += UP_SP;
							if (AxisY_Velocity.Y >= 0.3f){
								AxisY_Velocity.Y = 0.3f;
							}
						}
						//------------上昇中（空中にいる間にマウスボタンを離す）-------------
						if (!KeyState[0][DIK_SPACE]){
							air_gage_switch = air_gage_off;
							boost_subup_switch = boost_subup_off;//UPブーストON
							UP_COUNT = 2;
							UP_TIME = 0;
							GRAVITY_POWER = -1.0;
						}
					}
				}
				if (UP_COUNT == 2){
					if (DASH_COUNT != 3 && DASH_COUNT2 != 3 && DASH_COUNT3 != 3 && DASH_COUNT4 != 3){//ダッシュしてない
						if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] && AIR_BLADE_ATTACK_TYPE == 0 && AIR_GUNSHOT_ONOFF == 0){
							Animation = Model->GetAnimation(L"up");
						}
					}
					//-------------------下降中再上昇---------------------
					if (KeyState[0][DIK_SPACE]){
						AIR_MOVE_CHANGE = 1;
						air_gage_switch = air_gage_on;
						boost_subup_switch = boost_subup_on;//UPブーストON
						if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] && AIR_BLADE_ATTACK_TYPE == 0 && AIR_GUNSHOT_ONOFF == 0){
							Animation = Model->GetAnimation(L"up");
							if (AnimationTime <= 30){
								AnimationTime += 2.5f;
							}
							if (AnimationTime > 30){
								AnimationTime = 30;
							}
						}

						UP_TIME++;
						GRAVITY_POWER = 0.0;
						if (UP_TIME >30){
							UP_SP = 0.3f;
							AxisY_Velocity.Y += UP_SP;
							if (AxisY_Velocity.Y >= 0.3f){
								AxisY_Velocity.Y = 0.3f;
							}
						}
					}
					else if (!KeyState[0][DIK_SPACE] || boost_life <= 0){
						AIR_MOVE_CHANGE = 0;
						air_gage_switch = air_gage_off;
						boost_subup_switch = boost_subup_off;//UPブーストON
						UP_TIME = 0;
						AxisY_Velocity.Y = 0.0f;
						GRAVITY_POWER = -1.0;
					}
				}
			}
			//＜着地していない＆ジャンプしていない＆ダッシュしていない＞
			if (myship_landing_type == myship_landing_off&&UP_COUNT == 0 && dash_type == dash_off){
				if (KeyState[0][DIK_SPACE] && !KeyState[0][DIK_A] && !KeyState[0][DIK_D] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W]&&boost_life>0){
					UP_COUNT = 2;
					JAMP_TYPE = up_on;//ジャンプON
					boost_subup_switch = boost_subup_on;//UPブーストON
					GRAVITY_POWER = -0.1f;
					AnimationTime = 0;
				}
			}
			//空中にいる＆移動していない＆攻撃していない(空中攻撃、通常攻撃)
			if (myship_landing_type == myship_landing_off&&!KeyState[0][DIK_A] && !KeyState[0][DIK_D] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_SPACE]
				       && ACTION_TYPE != attack && GUN_ATTACK_COUNT == 0 && AIR_BLADE_ATTACK == 0 && AIR_GUNSHOT_ONOFF == 0 && AIR_MOVE_CHANGE == 0){
				air_gage_switch = air_gage_off;
				boost_subup_switch = boost_subup_off;
				Animation = Model->GetAnimation(L"up");
				AnimationTime = 30;
			}
		}
		
//=====================================================================空中移動================================================
		//空中にいて攻撃していない。かつダッシュしていない
		if (myship_landing_type == myship_landing_off&&ACTION_TYPE != attack&&ACTION_TYPE != dash){
			AIR_MOVE = 0.4f;
			//通常移動
			MyShip_Move_Model4List.Apply([&](CMover*Mm){
				//前進
				if (KeyState[0][DIK_W]){
					air_gage_switch = air_gage_on;
					boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
					boost_subup_switch = boost_subup_on;//UPサブブーストON
					Velocity += Mm->AxisZ()*AIR_MOVE;
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_AFTER_ANI = 1;
					AIR_RL_MOVEANI = air_rl_moveani_go;//追加2015/5/24
				}
				//後進
				if (KeyState[0][DIK_S]){
					air_gage_switch = air_gage_on;
					boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
					boost_subup_switch = boost_subup_on;//UPサブブーストON
					Velocity -= Mm->AxisZ()*AIR_MOVE;
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_AFTER_ANI = 1;
					AIR_RL_MOVEANI = air_rl_moveani_go;//追加2015/5/24
				}
				//右進
				if (KeyState[0][DIK_D]){
					air_gage_switch = air_gage_on;
					boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
					boost_subup_switch = boost_subup_on;//UPサブブーストON
					Velocity += Mm->AxisX()*AIR_MOVE;
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_AFTER_ANI = 1;
					AIR_RL_MOVEANI = air_rl_moveani_right;//追加2015/5/24
				}
				//左進
				if (KeyState[0][DIK_A]){
					air_gage_switch = air_gage_on;
					boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
					boost_subup_switch = boost_subup_on;//UPサブブーストON
					Velocity -= Mm->AxisX()*AIR_MOVE;
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_AFTER_ANI = 1;
					AIR_RL_MOVEANI = air_rl_moveani_left;//追加2015/5/24
				}
				//キーが押されていなければアイドリング定数代入
				if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A]){
					AIR_DASHAFTER_MOVECOUNT = 0;
					boost_main1_switch = boost_main1_off;//ブースト一段階ON_OFF
					AIR_AFTER_ANI = 0;
					AIR_RL_MOVEANI = air_rl_moveani_go;//追加2015/5/24
				}
				//ブーストゲージ0
				if (boost_life <= 0){
					boost_main1_switch = boost_main1_off;//ブースト一段階ON_OFF
					AIR_DASHAFTER_MOVECOUNT = 0;
					GRAVITY_POWER = -1.0;
				}
			});
			//ブーストライフ0、空中攻撃していない（ブレード&ガン）
			if (boost_life <= 0 && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off&&AIR_GUNSHOT_COUNT == 0){//boost_life <= 0 &&
				if (KeyState[0][DIK_W] || KeyState[0][DIK_S] || KeyState[0][DIK_D] || KeyState[0][DIK_A]){
					Robo_ani_afteamove();
				}
				if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A]){
					Animation = Model->GetAnimation(L"up");
					if (AnimationTime <= 30){
						AnimationTime += 2.5f;
					}
					if (AnimationTime > 30){
						AnimationTime = 30;
					}
				}
			}
		}
		//空中にいてダッシュしているときの重力制御
		if (myship_landing_type == myship_landing_off&&ACTION_TYPE == dash){
			GRAVITY_POWER = -0.1;
		}
		//空中にいてダッシュ後移動しているときの重力＆制御
		if (myship_landing_type == myship_landing_off&&AIR_DASHAFTER_MOVE == 1){
				//前進
				if (KeyState[0][DIK_W]){
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_RL_MOVEANI = air_rl_moveani_go;//追加2015/5/24
				}
				//後進
				if (KeyState[0][DIK_S]){
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_RL_MOVEANI = air_rl_moveani_go;//追加2015/5/24
				}
				//右進
				if (KeyState[0][DIK_D]){
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_RL_MOVEANI = air_rl_moveani_right;//追加2015/5/24
				}
				//左進
				if (KeyState[0][DIK_A]){
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_RL_MOVEANI = air_rl_moveani_left;//追加2015/5/24
				}
		}
		//空中ダッシュ後移動
		if (myship_landing_type == myship_landing_off&&AIR_DASHAFTER_MOVECOUNT == 1){
			AIR_MOVE = 0.5f;
			//通常移動
			MyShip_Move_Model4List.Apply([&](CMover*Mm){
				//前進
				if (KeyState[0][DIK_W]){
					boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
					AIR_AFTER_ANI = 1;
					Velocity += Mm->AxisZ()*AIR_MOVE;
					GRAVITY_POWER = -0.05;
				}
				//後進
				if (KeyState[0][DIK_S]){
					boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
					AIR_AFTER_ANI = 1;
					Velocity -= Mm->AxisZ()*AIR_MOVE;
					GRAVITY_POWER = -0.05;
				}
				//右進
				if (KeyState[0][DIK_D]){
					boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
					AIR_AFTER_ANI = 1;
					Velocity += Mm->AxisX()*AIR_MOVE;
					GRAVITY_POWER = -0.05;
				}
				//左進
				if (KeyState[0][DIK_A]){
					boost_main1_switch = boost_main1_on;//ブースト一段階ON_OFF
					AIR_AFTER_ANI = 1;
					Velocity -= Mm->AxisX()*AIR_MOVE;
					GRAVITY_POWER = -0.05;
				}
				//キーが押されていなければアイドリング定数代入
				if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] ){
					AIR_DASHAFTER_MOVECOUNT = 0;
					GRAVITY_POWER = -0.1;
					AIR_AFTER_ANI = 0;
					boost_main1_switch = boost_main1_off;//ブースト一段階ON_OFF
				}
			});
		}
		//空中攻撃していない
		if (myship_landing_type == myship_landing_off&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off&&AIR_GUNSHOT_COUNT == 0 && ACTION_TYPE != attack){
			if (AIR_AFTER_ANI == 1 || dash_type == dash_a_on || dash_type == dash_d_on || dash_type == dash_w_on || dash_type == dash_s_on || dash_type == dash_aw_on || dash_type == dash_dw_on || dash_type == dash_as_on || dash_type == dash_ds_on){
				//ロックオンOFF
				if (targetselection == targetselection_off)Robo_ani_afteamove();
				//ロックオンON
				if (targetselection == targetselection_on){
					if (AIR_RL_MOVEANI == air_rl_moveani_go)Robo_ani_afteamove();
					if (AIR_RL_MOVEANI == air_rl_moveani_right)Robo_ani_afteamove_r();
					if (AIR_RL_MOVEANI == air_rl_moveani_left)Robo_ani_afteamove_l();
				}
			}
		}
//====================================================================空中攻撃=======================================================
		//ブレード装備中
		if (weapon_chang == chang_blade){
			//空中にいる
			if (myship_landing_type == myship_landing_off&&ACTION_TYPE != attack){
				if (AIR_BLADE_ATTACK == 0){
					if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
						AIR_BLADE_ATTACK = 1;
						AIR_BLADE_ATTACK_TYPE = air_blade_attack_on;
						blade_hand_chang = right_hand;//右手持ち
					}
				}
				//１撃目
				if (AIR_BLADE_ATTACK == 1){
					AIR_BLADE_TIME++;
					if (AIR_BLADE_TIME == 1){
						Blade_motion_se();//剣振りSE
						AnimationTime = 0;
						blade = blade_on;
					}
					if (AIR_BLADE_TIME >= 2 && AIR_BLADE_TIME <= 34){
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							AIR_BLADE_ATTACK_COUNT = 1;
						}
						Animation = Model->GetAnimation(L"aftea_attack");
						AnimationTime += 2.9f;
						if (AnimationTime >= 60){
							AnimationTime = 60;
						}
						//２連撃目へ継続
						if (AIR_BLADE_ATTACK_COUNT == 1 && AIR_BLADE_TIME == 32){
							AIR_BLADE_ATTACK = 2;
							Blade_motion_se();//剣振りSE
							AIR_BLADE_ATTACK_COUNT = 0;
						}
						else if (AIR_BLADE_ATTACK_COUNT == 0 && AIR_BLADE_TIME == 32){
							AIR_BLADE_ATTACK = 0;
							AnimationTime = 0;
							AIR_BLADE_TIME = 0;
							AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
							blade = blade_off;
						}
					}
				}
				//２撃目
				if (AIR_BLADE_ATTACK == 2){
					AIR_BLADE_TIME++;
					if (AIR_BLADE_TIME >= 32 && AIR_BLADE_TIME <= 61){
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							AIR_BLADE_ATTACK_COUNT = 1;
						}
						Animation = Model->GetAnimation(L"aftea_attack");
						AnimationTime += 2.8f;
						if (AnimationTime >= 100){
							AnimationTime = 100;
						}
						//3連撃目へ継続
						if (AIR_BLADE_ATTACK_COUNT == 1 && AIR_BLADE_TIME == 61){
							AIR_BLADE_ATTACK = 3;
							Blade_motion_se();//剣振りSE
							AIR_BLADE_ATTACK_COUNT = 0;
						}
						else if (AIR_BLADE_ATTACK_COUNT == 0 && AIR_BLADE_TIME == 61){
							AIR_BLADE_ATTACK = 0;
							AnimationTime = 0;
							AIR_BLADE_TIME = 0;
							AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
							blade = blade_off;
						}
					}
				}
				//3撃目
				if (AIR_BLADE_ATTACK == 3){
					AIR_BLADE_TIME++;
					if (AIR_BLADE_TIME >= 61 && AIR_BLADE_TIME <= 96){
						Animation = Model->GetAnimation(L"aftea_attack");
						AnimationTime += 3.2f;
						if (AnimationTime >= 145){
							AnimationTime = 145;
						}
						if (AIR_BLADE_TIME == 96){
							AIR_BLADE_ATTACK = 4;
						}
					}
				}
				//初期構え
				if (AIR_BLADE_ATTACK == 4){
					AIR_BLADE_TIME++;
					if (AIR_BLADE_TIME >= 96 && AIR_BLADE_TIME <= 113){
						Animation = Model->GetAnimation(L"aftea_attack");
						AnimationTime += 2.0f;
						if (AnimationTime >= 165){
							AnimationTime = 165;
						}
						if (AIR_BLADE_TIME == 113){
							AIR_BLADE_ATTACK = 0;
							AnimationTime = 0;
							AIR_BLADE_TIME = 0;
							AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
							blade = blade_off;
						}
					}
				}
			}

			//着地時初期化：着地している&通常攻撃していない＆ダッシュ攻撃していない
			if (myship_landing_type == myship_landing_on&&ATTACK_COUNT == 0 && DASH_ATTACK_COUNT == dash_attack_off){
				AIR_BLADE_ATTACK = 0;
				AIR_BLADE_TIME = 0;
				AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
				blade = blade_off;
			}
		}

		//ガン装備中
		if (weapon_chang == chang_gun){
			AIR_BLADE_ATTACK = 0;
			AIR_BLADE_TIME = 0;
			AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
			blade = blade_off;
		}
//====================================================================空中ガン攻撃=======================================================
		//ガン装備中
		if (weapon_chang == chang_gun){
			//空中にいる
			if (myship_landing_type == myship_landing_off){
				if (AIR_GUNSHOT_COUNT == 0 && gun_gage_life >= 100){
					if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
						AIR_GUNSHOT_ONOFF = 1;
						AIR_GUNSHOT_COUNT = 1;
						gun = gun_on;
						gun_hande_Angle = air_on;//ガン角度変更
					}
				}
				if (AIR_GUNSHOT_COUNT == 1){
					Animation = Model->GetAnimation(L"aftea_shot1");
					AIR_GUNSHOT_TIME++;
					if (AIR_GUNSHOT_TIME==1){
						AnimationTime = 0;
					}
					if (AIR_GUNSHOT_TIME>1 && AIR_GUNSHOT_TIME<=23){
						AnimationTime += 2.5f;
						if (AnimationTime >= 30){
							AnimationTime = 30;
						}
					}
					if (AIR_GUNSHOT_TIME == 23){
						beam_launch = beam_on;
						Beam_se();//ビーム発射音
						gun_gage_consumption = gun_gage_consumption_on;
					}
					if (AIR_GUNSHOT_TIME > 23){
						gun_gage_consumption = gun_gage_consumption_off;
						beam_launch = beam_off;
						AnimationTime -= 2.5f;
						if (AnimationTime <= 0){
							AnimationTime = 0;
							AIR_GUNSHOT_COUNT = 0;
							AIR_GUNSHOT_TIME = 0;
							AIR_GUNSHOT_ONOFF = 0;
							gun = gun_off;
							gun_hande_Angle = normal_on;//ガン角度変更
						}
					}
				}
			}
			//着地している＆空中ガン攻撃どの状態でも＆通常ガン攻撃していない
			if (myship_landing_type == myship_landing_on&&AIR_GUNSHOT_COUNT >= 0 && GUN_ATTACK_COUNT == 0){
				AIR_GUNSHOT_COUNT = 0;
				AIR_GUNSHOT_TIME = 0;
				AIR_GUNSHOT_ONOFF = 0;
				gun = gun_off;
				gun_hande_Angle = normal_on;//ガン角度変更
				beam_launch = beam_off;
			}
		}
	}//（ここまでall_combatがON状態になっている前提）
//==================================================================当たり判定================================================================
		float Body_r = 7.0f;//ウォーク用
		float Body_r2 = 7.1f;//ダッシュジャンプ用
		float Body_r3 = 5.0f;//壁用
		float Monitor_r = 3.0f;//モニター用
		CHit Fhit;
		//ステージ床当たり判定
		Stage_01List.Apply([&](CMover*s1){
			//大きな円
			if (Fhit.SphereAndModel(Position, Body_r, s1, s1->Model)){
				myship_landing_type = myship_landing_on;
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
				if (Fhit.SphereAndModel(Position, Body_r, s1, s1->Model)){
					myship_landing_type = myship_landing_on;
					Velocity.Y = 0;
					Color = CColor(1, 1, 1, 1.0f);
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			}
			//当たってない
			if (!Fhit.SphereAndModel(Position, Body_r2, s1, s1->Model) && Position.Y>0){
				myship_landing_type = myship_landing_off;
			}
		});
		//ステージ壁当たり判定
		Stage_02List.Apply([&](CMover*s2){
			//大きな円
			if (Fhit.SphereAndModel(Position, Body_r3, s2, s2->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r3;
			}
		});
		//ステージゲート当たり判定
		Stage_gateList.Apply([&](CMover*s){
			//大きな円
			if (Fhit.SphereAndModel(Position, Body_r3, s, s->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r3;
			}
		});
		//ステージ中央ゲート当たり判定
		Stage_Centergate_LList.Apply([&](CMover*ts){
			//大きな円
			if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
				myship_landing_type = myship_landing_on;
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
				if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
					myship_landing_type = myship_landing_on;
					Velocity.Y = 0;
					Color = CColor(1, 1, 1, 1.0f);
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			}
		});
		Stage_Centergate_RList.Apply([&](CMover*ts){
			//大きな円
			if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
				myship_landing_type = myship_landing_on;
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
				if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
					myship_landing_type = myship_landing_on;
					Velocity.Y = 0;
					Color = CColor(1, 1, 1, 1.0f);
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			}
		});
		Stage_Centergate_LRList.Apply([&](CMover*ts){
			//大きな円
			if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
				myship_landing_type = myship_landing_on;
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
				if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
					myship_landing_type = myship_landing_on;
					Velocity.Y = 0;
					Color = CColor(1, 1, 1, 1.0f);
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			}
		});
		//モニター当たり判定
		MonitorList.Apply([&](CMover*mn){
			//大きな円
			if (Fhit.SphereAndModel(Position, Monitor_r, mn, mn->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Monitor_r;
			}
		});
		//敵当たり判定(メカペン)
		EnemyList.Apply([&](CMover*e){
			CHit Fhit;
			float Body_r = 2.0f;
		
			if (Fhit.SphereAndModel(Position, Body_r, e, e->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//敵当たり判定(パチコマ)Enemy.CppのCEnemy_takyakuクラスに書いてある

		//ゲート3判定（パチコマ起動）
		Stage_gate3List.Apply([&](CMover*s3){
			//大きな円
			if (Fhit.SphereAndModel(Position, Monitor_r, s3, s3->Model)){
				enemy_startup = Enemy_startupmovie_on;
				s3->Life = 0;
			}
		});

		//ゲート4判定（ボスムービー始動）
		Stage_gate4List.Apply([&](CMover*s4){
			//大きな円
			if (Fhit.SphereAndModel(Position, Monitor_r, s4, s4->Model)){
				//ボスムービー開始
				boss_movie_state = boss_movie_on;
				s4->Life = 0;
				//BOSS_BGM
				bgm_state = boss_combat_bgm_on;
			}
		});

		//ボス
		float Body_r4 = 1.3f;
		Enemy_BossList.Apply([&](CMover*eb){
			if (Fhit.SphereAndModel(Position, Body_r4, eb, eb->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r4;
			}
		});
//==================================================================回転補正==================================================================
			//ガンショットしていない
			if (GUN_ATTACK_COUNT != 1){
				if (Velocity.X != 0) {
					MyShip_Move_ModelList.Apply([&](CMover*Mm){
						Velocity.Y = 0;
						Rotation.Interpolate(CQuaternion(Mm->AxisZ() + Mm->AxisX()*0.001f, Velocity), 0.10f);
					});
				}
				if (Velocity.Z != 0) {
					MyShip_Move_ModelList.Apply([&](CMover*Mm){
						Velocity.Y = 0;
						Rotation.Interpolate(CQuaternion(Mm->AxisZ() + Mm->AxisX()*0.001f, Velocity), 0.10f);
					});
				}
			}
//==========================================================ブレード攻撃ダメージ確定Enemy======================================================
		//メカペンギン
		if (weapon_chang == chang_blade){
			//ブレードの当たる範囲にいる敵を検索
			EnemyList.Apply([&](CMover* e) {
				e->BladeHitState = Length(e->Position - Position) < 16.0f ? max(e->BladeHitState, 1) : 0;
			});
			Enemy_takyakuList.Apply([&](CMover* et) {
				et->BladeHitState = Length(et->Position - Position) < 16.0f ? max(et->BladeHitState, 1) : 0;
			});
			Enemy_BossList.Apply([&](CMover* eb) {
				eb->BladeHitState = Length(eb->Position - Position) < 16.0f ? max(eb->BladeHitState, 1) : 0;
			});
		}
//========================================================ガンショット目標&ローテーション========================================================
		//着地中or空中どちらでも処理
		if (myship_landing_type == myship_landing_off || myship_landing_type == myship_landing_on){
			if (weapon_chang == chang_gun){

		//----------------ターゲット選択OFF(オートマーカー)----------------------------------------------------------------------------------------------
				if (targetselection == targetselection_off){
					float el = FLT_MAX;//Enemyレングス
					float etl = FLT_MAX;//Enemy_takyakuレングス
					float ebl = FLT_MAX;//Enemy_takyakuレングス
					//範囲内（メカペン）
					float f = FLT_MAX;
					CMover* n = 0;
					EnemyList.Apply([&](CMover* e) {
						//高さ&限界範囲内の敵判定
						if (e->Position.Y - Position.Y <= 30 && Length(e->Position - Position) <= 200.0f&&Length(e->Position - Position) >= 30.0f)e->State = 1;
						if (e->Position.Y - Position.Y > 30 || Length(e->Position - Position) > 200.0f || Length(e->Position - Position) < 30.0f)e->State = 0;
						if (e->State == 1){
							float g = Length(e->Position - Position);
							if (g < f){
								f = g;
								n = e;
								n->State = 2;
								el = Length(n->Position - Position);
							}
						}
					});

					//範囲内（多脚ロボ）
					float ft = FLT_MAX;
					CMover* nt = 0;
					Enemy_takyakuList.Apply([&](CMover* et) {
						//高さ&限界範囲内の敵判定
						if (et->Position.Y - Position.Y <= 20 && Length(et->Position - Position) <= 200.0f&&Length(et->Position - Position) >= 30.0f)et->State = 1;
						if (et->Position.Y - Position.Y > 20 || Length(et->Position - Position) > 200.0f || Length(et->Position - Position) < 30.0f)et->State = 0;
						if (et->State == 1){
							float gt = Length(et->Position - Position);
							if (gt < ft){
								ft = gt;
								nt = et;
								nt->State = 2;
								etl = Length(nt->Position - Position);
							}
						}
					});


					//最も近い敵判定(メカペンがいるとき)
					EnemyList.Apply([&](CMover* e) {
						if (el<etl){
							n->State = 3;
							if (n->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//追加：AIR_GUNSHOT_COUNT == 1
								CVector p = Position;//最初に座標を保存しておくのがミソ
								Position.Homing(n->Position, 0.0001f);
								Rotation = CQuaternion(AXIS_Z, n->Position - p, -AXIS_Y);
								gunshot_camera_type = gunshot_camera_on;
							}
						}
						else if (el>etl){
							nt->State = 3;
							if (nt->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//追加：AIR_GUNSHOT_COUNT == 1
								CVector p = Position;//最初に座標を保存しておくのがミソ
								Position.Homing(nt->Position, 0.0001f);
								Rotation = CQuaternion(AXIS_Z, nt->Position - p, -AXIS_Y);
								gunshot_camera_type = gunshot_camera_on;
							}
						}
					});
					//最も近い敵判定(多脚ロボがいるとき)
					Enemy_takyakuList.Apply([&](CMover* et) {
						if (el<etl){
							n->State = 3;
							if (n->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//追加：AIR_GUNSHOT_COUNT == 1
								CVector p = Position;//最初に座標を保存しておくのがミソ
								Position.Homing(n->Position, 0.0001f);
								Rotation = CQuaternion(AXIS_Z, n->Position - p, -AXIS_Y);
								gunshot_camera_type = gunshot_camera_on;
							}
						}
						else if (el>etl){
							nt->State = 3;
							if (nt->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//追加：AIR_GUNSHOT_COUNT == 1
								CVector p = Position;//最初に座標を保存しておくのがミソ
								Position.Homing(nt->Position, 0.0001f);
								Rotation = CQuaternion(AXIS_Z, nt->Position - p, -AXIS_Y);
								gunshot_camera_type = gunshot_camera_on;
							}
						}
					});

					//雑魚キャラがいなくBOSSのみ
					if (enemy_count == 0){
						//範囲内（BOSS）
						float fb = FLT_MAX;
						CMover* nb = 0;
						Enemy_BossList.Apply([&](CMover* eb) {
							//高さ&限界範囲内の敵判定
							if (eb->Position.Y - Position.Y <= 30 && Length(eb->Position - Position) <= 200.0f&&Length(eb->Position - Position) >= 30.0f)eb->State = 1;
							if (eb->Position.Y - Position.Y > 30 || Length(eb->Position - Position) > 200.0f || Length(eb->Position - Position) < 30.0f)eb->State = 0;
							if (eb->State == 1){
								float gb = Length(eb->Position - Position);
								if (gb < fb){
									fb = gb;
									nb = eb;
									nb->State = 2;
									ebl = Length(nb->Position - Position);
								}
							}
						});
						Enemy_BossList.Apply([&](CMover* eb) {
							if (nb){
								nb->State = 3;
								if (nb->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//追加：AIR_GUNSHOT_COUNT == 1
									CVector pb = Position;//最初に座標を保存しておくのがミソ
									Position.Homing(nb->Position, 0.0001f);
									Rotation = CQuaternion(AXIS_Z, nb->Position - pb, -AXIS_Y);
									gunshot_camera_type = gunshot_camera_on;
								}
							}
						});
					}
					
					//ショット終了位置初期化
					if (myship_landing_type == myship_landing_on){
						if (GUN_ATTACK_COUNT == 2){
							Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
							gunshot_camera_type = gunshot_camera_off;
						}
					}
					if (myship_landing_type == myship_landing_off){
						if (AIR_GUNSHOT_COUNT == 0){
							Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
							gunshot_camera_type = gunshot_camera_off;
						}
					}
				}
			}
		}
//========================================================ブレード目標&ローテーション========================================================
		//着地中or空中どちらでも処理
		if (myship_landing_type == myship_landing_off || myship_landing_type == myship_landing_on){
			if (weapon_chang == chang_blade || weapon_chang == chang_gun){
				//ターゲット選択OFFからON切り替え
				if (targetselection == targetselection_off){
					if (TARGETSELECTION_COUNT == 0){
						if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
							TARGETSELECTION_COUNT = 1;
						}
					}
					if (TARGETSELECTION_COUNT == 1){
						if (KeyState[0][DIK_F]){
							TARGETSELECTION_TIME++;
							if (TARGETSELECTION_TIME >= TARGETSELECTION_TIMECONSTANT){
								TARGETSELECTION_COUNT = 2;
								TARGETSELECTION_TIME = 0;
							}
						}
					}
					if (TARGETSELECTION_COUNT <= 1 && !KeyState[0][DIK_F] && TARGETSELECTION_TIME < TARGETSELECTION_TIMECONSTANT){
						TARGETSELECTION_TIME = 0;
						TARGETSELECTION_COUNT = 0;
					}
					if (TARGETSELECTION_COUNT == 2){
						TARGETSELECTION_TIME = 0;
						TARGETSELECTION_COUNT = 0;
						targetselection = targetselection_on;
					}
				}
				//ターゲット選択ONからOFF切り替え
				if (targetselection == targetselection_on){
					if (TARGETSELECTION_COUNT == 0){
						if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
							TARGETSELECTION_COUNT = 1;
						}
					}
					if (TARGETSELECTION_COUNT == 1){
						if (KeyState[0][DIK_F]){
							TARGETSELECTION_TIME++;
							if (TARGETSELECTION_TIME >= TARGETSELECTION_TIMECONSTANT){
								TARGETSELECTION_COUNT = 2;
								TARGETSELECTION_TIME = 0;
							}
						}
					}
					if (TARGETSELECTION_COUNT <= 1 && !KeyState[0][DIK_F] && TARGETSELECTION_TIME < TARGETSELECTION_TIMECONSTANT){
						TARGETSELECTION_TIME = 0;
						TARGETSELECTION_COUNT = 0;
					}
					if (TARGETSELECTION_COUNT == 2){
						TARGETSELECTION_TIME = 0;
						TARGETSELECTION_COUNT = 0;
						targetselection = targetselection_off;
					}
				}
				//(ターゲット選択OFF)
				if (targetselection == targetselection_off){
					EnemyList.Apply([&](CMover* e) {
						e->TargetState = 0;
					});
					Enemy_takyakuList.Apply([&](CMover* et) {
						et->TargetState = 0;
					});
					Enemy_BossList.Apply([&](CMover* eb) {
						eb->TargetState = 0;
					});
					EP_COUNT = 0;
				}
				//(ターゲット選択ON)
				if (targetselection == targetselection_on){
					if (EP_COUNT == 0){
						MEKAPEN = NULL;
						PATIKOMA = NULL;
						BOSS = NULL;
						//範囲内敵検索
						EnemyList.Apply([&](CMover* e) {
							if (e->TargetState != 3){
								e->TargetState = Length(e->Position - Position) <= 1000.0f ? 1 : 0;
								MEKAPEN = e;
							}
						});
						Enemy_takyakuList.Apply([&](CMover* et) {
							if (et->TargetState != 3){
								et->TargetState = Length(et->Position - Position) <= 1000.0f ? 1 : 0;
								PATIKOMA = et;
							}
						});
						Enemy_BossList.Apply([&](CMover* eb) {
							if (eb->TargetState != 3){
								eb->TargetState = Length(eb->Position - Position) <= 1000.0f ? 1 : 0;
								BOSS = eb;
							}
						});
					}

					//---------メカペンだけいる-------------
					if (MEKAPEN != NULL&&PATIKOMA == NULL){
						if (EP_COUNT == 0){
							EP_P = NULL;//最初のターゲット決定
							E_LEN = FLT_MAX;
							COLSE_E = NULL;
							EnemyList.Apply([&](CMover* e) {
								//一番近いメカペン検索
								if (e->TargetState == 1){
									E_LEN_S = Length(e->Position - Position);
									if (E_LEN_S < E_LEN){
										E_LEN = E_LEN_S;
										COLSE_E = e;
									}
								}
							});
							if (COLSE_E){
								EP_P = COLSE_E;
								EP_COUNT = 1;
							}
							//標的確定
							if (EP_P){
								EP_P->TargetState = 2;
							}
						}
						if (EP_COUNT == 1){
							if (EP_P){
								if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
									EP_P->TargetState = 3;
									EP_COUNT = 0;
								}
								if (EP_P->Life <= 0){
									EP_COUNT = 0;
								}
							}
						}
					}

					//---------パチコマだけいる-------------
					if (MEKAPEN == NULL&&PATIKOMA != NULL){
						if (EP_COUNT == 0){
							EP_P = NULL;//最初のターゲット決定
							E_LEN = FLT_MAX;
							COLSE_E = NULL;
							Enemy_takyakuList.Apply([&](CMover* et) {
								//一番近いメカペン検索
								if (et->TargetState == 1){
									E_LEN_S = Length(et->Position - Position);
									if (E_LEN_S < E_LEN){
										E_LEN = E_LEN_S;
										COLSE_E = et;
									}
								}
							});
							if (COLSE_E){
								EP_P = COLSE_E;
								EP_COUNT = 1;
							}
							//標的確定
							if (EP_P){
								EP_P->TargetState = 2;
							}
						}
						if (EP_COUNT == 1){
							if (EP_P){
								if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
									EP_P->TargetState = 3;
									EP_COUNT = 0;
								}
								if (EP_P->Life <= 0){
									EP_COUNT = 0;
								}
							}
						}
					}

					if (enemy_count == 0){
						//---------BOSSだけいる-------------
						if (MEKAPEN == NULL&&PATIKOMA == NULL&&BOSS != NULL){
							if (EP_COUNT == 0){
								EP_P = NULL;//最初のターゲット決定
								E_LEN = FLT_MAX;
								COLSE_E = NULL;
								Enemy_BossList.Apply([&](CMover* eb) {
									//一番近いBOSS検索
									if (eb->TargetState == 1){
										E_LEN_S = Length(eb->Position - Position);
										if (E_LEN_S < E_LEN){
											E_LEN = E_LEN_S;
											COLSE_E = eb;
										}
									}
								});
								if (COLSE_E){
									EP_P = COLSE_E;
									EP_COUNT = 1;
								}
								//標的確定
								if (EP_P){
									EP_P->TargetState = 2;
								}
							}
							if (EP_COUNT == 1){
								if (EP_P){
									if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
										EP_P->TargetState = 3;
										EP_COUNT = 0;
									}
									if (EP_P->Life <= 0){
										EP_COUNT = 0;
									}
								}
							}
						}
					}

					//---------メカペン＆パチコマ両方いる-------------
					if (MEKAPEN != NULL&&PATIKOMA != NULL){
						if (EP_COUNT == 0){
							EP_P = NULL;//最初のターゲット決定
							E_LEN = FLT_MAX;
							COLSE_E = NULL;
							EnemyList.Apply([&](CMover* e) {
								//一番近いメカペン検索
								if (e->TargetState == 1){
									E_LEN_S = Length(e->Position - Position);
									if (E_LEN_S < E_LEN){
										E_LEN = E_LEN_S;
										COLSE_E = e;
									}
								}
							});
							EP_P2 = NULL;//最初のターゲット決定
							E_LEN2 = FLT_MAX;
							COLSE_E2 = NULL;
							Enemy_takyakuList.Apply([&](CMover* et) {
								//一番近い多脚検索
								if (et->TargetState == 1){
									E_LEN_S2 = Length(et->Position - Position);
									if (E_LEN_S2 < E_LEN2){
										E_LEN2 = E_LEN_S2;
										COLSE_E2 = et;
									}
								}
							});
							//メカペンとパチコマ近い方を代入
							if (COLSE_E&&COLSE_E2){
								EP_P = Length(COLSE_E->Position - Position) < Length(COLSE_E2->Position - Position) ? COLSE_E : COLSE_E2;
							}
							//標的確定
							if (EP_P){
								EP_P->TargetState = 2;
								EP_COUNT = 1;
							}
						}
						if (EP_COUNT == 1){
							if (EP_P){
								if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
									EP_P->TargetState = 3;
									EP_COUNT = 0;
								}
								if (EP_P->Life <= 0){
									EP_COUNT = 0;
								}
							}
						}
					}

					RANG_E_COUNT = 0;
					EnemyList.Apply([&](CMover* e) {
						if (e->TargetState != 0){
							RANG_E_COUNT = 1;
						}
					});
					Enemy_takyakuList.Apply([&](CMover* et) {
						if (et->TargetState != 0){
							RANG_E_COUNT = 1;
						}
					});
					if (enemy_count == 0){
						Enemy_BossList.Apply([&](CMover* eb) {
							if (eb->TargetState != 0){
								RANG_E_COUNT = 1;
							}
						});
					}
					if (RANG_E_COUNT == 0){
						EP_COUNT = 0;
						targetselection = targetselection_off;
					}
				}


				//標的がメカペンだったら
				EnemyList.Apply([&](CMover* e) {
					//自機回転
					if (weapon_chang == chang_blade){
						if (e->TargetState == 2 && Length(e->Position - Position) <= 20.0f){
							targetmarker_red = 1;
						}
					}
					if (weapon_chang == chang_gun){
						if (e->TargetState == 2 && e->Position.Y - Position.Y <= 30 && e->Position.X - Position.X <= 500 && e->Position.X - Position.X >= -500 && e->Position.Z - Position.Z <= 500 && e->Position.Z - Position.Z >= -500){
							targetmarker_red = 1;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								Velocity.Y = 0;
								CVector PP = Position;
								Rotation = CQuaternion(AXIS_Z, e->Position - PP, -AXIS_Y);
							}
						}
					}
					//攻撃マーカーグリーン
					if (weapon_chang == chang_blade){
						if (e->TargetState == 2 && Length(e->Position - Position) > 20.0f){
							targetmarker_red = 0;
						}
					}
					if (weapon_chang == chang_gun){
						if (e->TargetState == 2 && ((e->Position.Y - Position.Y > 30) || (e->Position.X - Position.X > 500 && e->Position.X - Position.X < -500 && e->Position.Z - Position.Z > 500 && e->Position.Z - Position.Z < -500))){
							targetmarker_red = 0;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								//Velocity.Y = 0;
								//CVector PP = Position;
								//Rotation = CQuaternion(AXIS_Z, e->Position - PP, -AXIS_Y);
							}
						}
					}
					//カメラBOX回転
					if (e->TargetState == 2){
						MyShip_Move_Model2List.Apply([&](CMover* mm2) {//
							Velocity.Y = 0;
							CVector PP3 = Position;
							mm2->Rotation = CQuaternion(AXIS_Z, e->Position - PP3, -AXIS_Y);
							targetenemy_truefalse = targetenemy_truefalse_on;
							selection_camera_reset = selection_camera_reset_on;
						});
					}
				});
				//標的がパチコマだったら
				Enemy_takyakuList.Apply([&](CMover* et) {
					//自機回転
					if (weapon_chang == chang_blade){
						if (et->TargetState == 2 && Length(et->Position - Position) <= 20.0f){
							targetmarker_red = 1;
						}
					}
					if (weapon_chang == chang_gun){
						if (et->TargetState == 2 && et->Position.Y - Position.Y <= 30 && et->Position.X - Position.X <= 500 && et->Position.X - Position.X >= -500 && et->Position.Z - Position.Z <= 500 && et->Position.Z - Position.Z >= -500){
							targetmarker_red = 1;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								Velocity.Y = 0;
								CVector PP = Position;
								Rotation = CQuaternion(AXIS_Z, et->Position - PP, -AXIS_Y);
							}
						}
					}
					//攻撃マーカーグリーン
					//自機回転
					if (weapon_chang == chang_blade){
						if (et->TargetState == 2 && Length(et->Position - Position) > 20.0f){
							targetmarker_red = 0;
						}
					}
					if (weapon_chang == chang_gun){
						if (et->TargetState == 2 && ((et->Position.Y - Position.Y > 30) || (et->Position.X - Position.X > 500 && et->Position.X - Position.X < -500 && et->Position.Z - Position.Z > 500 && et->Position.Z - Position.Z < -500))){
							targetmarker_red = 0;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								//Velocity.Y = 0;
								//CVector PP = Position;
								//Rotation = CQuaternion(AXIS_Z, et->Position - PP, -AXIS_Y);
							}
						}
					}
					//カメラBOX回転
					if (et->TargetState == 2){
						MyShip_Move_Model2List.Apply([&](CMover* mm2) {//
							Velocity.Y = 0;
							CVector PP3 = Position;
							mm2->Rotation = CQuaternion(AXIS_Z, et->Position - PP3, -AXIS_Y);
							targetenemy_truefalse = targetenemy_truefalse_on;
							selection_camera_reset = selection_camera_reset_on;
						});
					}
				});

				//標的がBOSSだったら
				Enemy_BossList.Apply([&](CMover* eb) {
					//自機回転
					if (weapon_chang == chang_blade){
						if (eb->TargetState == 2 && Length(eb->Position - Position) <= 20.0f){
							targetmarker_red = 1;
						}
					}
					if (weapon_chang == chang_gun){
						if (eb->TargetState == 2 && eb->Position.Y - Position.Y <= 30 && eb->Position.X - Position.X <= 500 && eb->Position.X - Position.X >= -500 && eb->Position.Z - Position.Z <= 500 && eb->Position.Z - Position.Z >= -500){
							targetmarker_red = 1;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								Velocity.Y = 0;
								CVector PP = Position;
								Rotation = CQuaternion(AXIS_Z, eb->Position - PP, -AXIS_Y);
							}
						}
					}
					//攻撃マーカーグリーン
					if (weapon_chang == chang_blade){
						if (eb->TargetState == 2 && Length(eb->Position - Position) > 20.0f){
							targetmarker_red = 0;
						}
					}
					if (weapon_chang == chang_gun){
						if (eb->TargetState == 2 && ((eb->Position.Y - Position.Y > 30) || (eb->Position.X - Position.X > 500 && eb->Position.X - Position.X < -500 && eb->Position.Z - Position.Z > 500 && eb->Position.Z - Position.Z < -500))){
							targetmarker_red = 0;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								//Velocity.Y = 0;
								//CVector PP = Position;
								//Rotation = CQuaternion(AXIS_Z, e->Position - PP, -AXIS_Y);
							}
						}
					}
					//カメラBOX回転
					if (eb->TargetState == 2){
						MyShip_Move_Model2List.Apply([&](CMover* mm2) {//
							Velocity.Y = 0;
							CVector PP3 = Position;
							mm2->Rotation = CQuaternion(AXIS_Z, eb->Position - PP3, -AXIS_Y);
							targetenemy_truefalse = targetenemy_truefalse_on;
							selection_camera_reset = selection_camera_reset_on;
						});
					}
				});



				EnemyList.Apply([&](CMover* e) {
					if (e->TargetState != 0){
						RANG_E_COUNT = 1;
					}
					else if (e->TargetState == 0){
						RANG_E_COUNT = 0;
					}
				});
				Enemy_takyakuList.Apply([&](CMover* et) {
					if (et->TargetState != 0){
						RANG_ET_COUNT = 1;
					}
					else if (et->TargetState == 0){
						RANG_E_COUNT = 0;
					}
				});
				if (enemy_count == 0){
					Enemy_BossList.Apply([&](CMover* eb) {
						if (eb->TargetState != 0){
							RANG_ET_COUNT = 1;
						}
						else if (eb->TargetState == 0){
							RANG_E_COUNT = 0;
						}
					});
				}

				ENEMY_All3 = 0;
				EnemyList.Apply([&](CMover* e) {
					if (e->TargetState == 1 || e->TargetState == 2){
						ENEMY_All3 = 1;
					}
				});
				Enemy_takyakuList.Apply([&](CMover* et) {
					if (et->TargetState == 1 || et->TargetState == 2){
						ENEMY_All3 = 1;
					}
				});
				if (enemy_count == 0){
					Enemy_BossList.Apply([&](CMover* eb) {
						if (eb->TargetState == 1 || eb->TargetState == 2){
							ENEMY_All3 = 1;
						}
					});
				}

				if (ENEMY_All3 == 0){
					EnemyList.Apply([&](CMover* e) {
						e->TargetState = 0;
					});
					Enemy_takyakuList.Apply([&](CMover* et) {
						et->TargetState = 0;
					});
					if (enemy_count == 0){
						Enemy_BossList.Apply([&](CMover* eb) {
							eb->TargetState = 0;
						});
					}
				}

				//自機姿勢制御
				if (myship_landing_type == myship_landing_on){
					if (GUN_ATTACK_COUNT == 2 || GUN_ATTACK_COUNT == 0){
						Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
					}
				}
			}
		}

			//防衛機能ムービー中
		if (enemy_startup == Enemy_startupmovie_on || boss_movie_state == boss_movie_on){
				Velocity = 0;
				Robo_ani_idl();
			}

		//プレゼン用システム（瞬間移動）
		if (DELETE_ENEMY_COUNT == 1&&WARP_COUNT == 0){
			if (KeyState[0][DIK_RETURN] && !OldKeyState[0][DIK_RETURN]){
				Position = CVector(2, 317, 1243);
				WARP_COUNT = 1;
			}
		}
		else if (DELETE_ENEMY_COUNT == 1 && WARP_COUNT == 1){
			 if (KeyState[0][DIK_RETURN] && !OldKeyState[0][DIK_RETURN]){
				 Position = CVector(0, 317, 431);
				 WARP_COUNT = 2;
			 }
		 }

		 if (DELETE_ENEMY_COUNT==0&&KeyState[0][DIK_RETURN] && !OldKeyState[0][DIK_RETURN]){
			 Enemy_takyakuList.Apply([&](CMover* et) {
				 et->Life = 0;
			 });
			 EnemyList.Apply([&](CMover* e) {
				 e->Life = 0;
			 });
			 DELETE_ENEMY_COUNT = 1;
			 patikoma_number = 0;
			 mekapen_number = 0;
		 }
}


// ＜自機移動用モデル初期化＞
void CMyShip_Move_Model::Reset() {
	Model = GetModel(L"POSITION_NAME_BOX\\POSITIONNAME_BOX.x");
	Scale = CVector(1, 1, 1)*100;
	Color = CColor(1, 1, 1, 0.0f);
}
// ＜自機移動用モデル移動＞
void CMyShip_Move_Model::Move() {
	MyShipList.Apply([&](CMover*m){
	Position = m->Position + CVector(0, -2.3f, 0)*m->Rotation;
	//Rotation.y = m->Rotation.y;
	//Rotation.z = m->Rotation.z;
	//Rotation.w = m->Rotation.w;
	});
}

// ＜自機移動用モデル2初期化(カメラ同調)＞
void CMyShip_Move_Model2::Reset() {
	Model = GetModel(L"POSITION_NAME_BOX\\POSITIONNAME_BOX.x");
	Scale = CVector(1, 1, 1)*100.0f;
	Color = CColor(1, 0, 1, 0.0f);
}
// ＜自機移動用モデル2移動(カメラ同調)＞
void CMyShip_Move_Model2::Move() {
	MyShipList.Apply([&](CMover*m){
		Position = m->Position + CVector(0, 0, 0);
	});
}

// ＜自機移動用モデル初期化3＞
void CMyShip_Move_Model3::Reset() {
	Model = GetModel(L"POSITION_NAME_BOX\\POSITIONNAME_BOX.x");
	Scale = CVector(1, 1, 1)*100.0f;
	Color = CColor(0, 1, 1, 0.0f);
}
// ＜自機移動用モデル移動3＞
void CMyShip_Move_Model3::Move() {
	MyShipList.Apply([&](CMover*m){
		Position = m->Position + CVector(0, 0, 0);
		Rotation.y = m->Rotation.y;
		Rotation.w = m->Rotation.w;
	});
}

// ＜自機移動用モデル初期化4＞
void CMyShip_Move_Model4::Reset() {
	Model = GetModel(L"POSITION_NAME_BOX\\POSITIONNAME_BOX.x");
	Scale = CVector(1, 1, 1)*100.0f;
	Color = CColor(0, 1, 0, 0.0f);
}
// ＜自機移動用モデル移動4＞
void CMyShip_Move_Model4::Move() {
	if (dash_type == dash_off){
		CameraList.Apply([&](CMover*c){
			Rotation.y = c->Rotation.y;
			Rotation.w = c->Rotation.w;
		});
	}
	MyShipList.Apply([&](CMover*m){
		Position = m->Position + CVector(0, 3, 0);
	});
}

// ＜自機移動用モデル初期化5＞
void CMyShip_Move_Model5::Reset() {
	Model = GetModel(L"BEAM\\sphere.x");
	Scale = CVector(0.7f, 1, 0.4f)*0.1f;
	Color = CColor(1, 1, 1, 0.0f);
}
// ＜自機移動用モデル移動5＞
void CMyShip_Move_Model5::Move() {
	MyShipList.Apply([&](CMover*m){
		Position = m->Position + CVector(0, -2.3f, 0)*m->Rotation;
		Rotation = m->Rotation;
	});
}