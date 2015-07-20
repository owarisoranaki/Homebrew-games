#include "..\Main\Main.h"

// ステージの初期化
void CStage::Reset() {
	NewLight<CLight>(CMover::AMBIENT, CColor(0.35f, 0.35f, 0.35f, 1.0f));//0.35f, 0.35f, 0.35f, 1（一律全体背景）
	NewLight<CLight>(CMover::DIRECTIONAL, CColor(0.3f, 0.4f, 0.7f, 1), CVector(-1, 1, -1));//0.7,0.3,0.3,1
	NewLight<CLight>(CMover::DIRECTIONAL, CColor(0.4f, 0.3f, 0.4f, 1), CVector(1, -1, 1));//0.4f, 0.3f, 0.4f, 1
	NewLight<CLight>(CMover::SHADOW, CColor(0.3f, 0.3f, 0.3f, 1), CVector(0, 0, 0));//0.2f, 0.2f, 0.2f, 1
	NewLight<CLight>(CMover::POINT, CColor(0.3f, 0.3f, 0.3f, 1), CVector(0, 0, 0));//0.2f, 0.2f, 0.2f, 1
	
	//3D
	New<CStage_01>(CVector(0, -5.0f, 0));//-8
	New<CStage_02>(CVector(0, -5.0f, 0));//-8
	New<CStage_Centergate_L>(CVector(0.0f, -9.0f, 327.9f));
	New<CStage_Centergate_R>(CVector(0.0f, -9.0f, 327.9f));
	New<CStage_Centergate_LR>(CVector(0.0f, -5.0f, 327.9f));//-327.9f, -5.0f, 327.9f
	New<CMonitor>(CVector(2.0f, 318.5f, 1278.0f));//1288
	New<CMyShip>(CVector(0, 450, -290));//0,450,-290///-4.35f,4, 430
	New<CMyShip_Move_Model>();
	New<CMyShip_Move_Model2>();
	New<CMyShip_Move_Model3>();
	New<CMyShip_Move_Model4>();
	New<CMyShip_Move_Model5>();
	
	//テスト
	//New<CItem4>(CVector(0, 400, -280));
	//New<CEnemy_Boss>(CVector(0, 500, -270));//0,450,-290///-4.35f,4, 430

	//ゲート
	New<CStage_gate>(CVector(0, 350.0f,675));
	New<CStage_gate2>();
	New<CStage_gate3>(CVector(0, 400.0f, -15));
	New<CStage_gate4>(CVector(-4, 2.0f, 440));

	//2D
		New<COP_RHINE0>(CVector(0, 0, 0));
		New<COP_RHINE1>(CVector(0, 0, 0));
		New<COP_LIFEGAGE>(CVector(0, 0, 0));
		New<COP_LIFEGAGE2>(CVector(0, 0, 0));
		New<COP_BOOSTGAGE>(CVector(0, 0, 0));
		New<COP_BOOSTGAGE2>(CVector(0, 0, 0));
		New<COP_LIFEGAGE_FRAME>(CVector(0, 0, 0));
		New<COP_TIME>(CVector(0, 0, 0));
		New<COP_MESSAGE_FRAME>(CVector(0, 0, 0));
		New<COP_TARGET_FRAME>(CVector(0, 0, 0));
		New<COP_MOVIE_FRAME>(CVector(0, 0.7f, 0));
		New<COP_MOVIE_FRAME>(CVector(0, -0.7f, 0));
		New<COP_Screen>(CVector(0, 0, 10));
		New<COP_Screen_Write>(CVector(0, -0.35f, 0));
		New<COP_GUN_GAGE>();
		New<COP_GUN_FRAME>(CVector(0, 0, 0));
		New<COP_GUN_FRAME2>(CVector(0, 0, 0));
		New<CIcon0>();
		New<Cfade_black>(CVector(0, 0, 10));
		New<CEND>(CVector(0, 0, 10));
		New<CPush_c>(CVector(0, -0.4f, 0));
		New<CHELP0>(CVector(0, 0, 10));

	//敵生成＆変数初期化
		//敵数初期化＆合計数
		mekapen_number = 16; patikoma_number = 10;
		enemy_count = mekapen_number + patikoma_number;
		//敵生成
		for (int i = 0; i < mekapen_number; i++){
			New<CEnemy>(CVector(Random(200, -200), Random(340, 340), Random(530, 196)));
			//New<CEnemy>(CVector(Random(30, -30), 440, Random(-300,-290)));
		}
		for (int i = 0; i < patikoma_number; i++){
			New<CEnemy_takyaku>(CVector(Random(-280, 280), Random(320, 320), Random(530, 120)),0,0,i);
			//New<CEnemy_takyaku>(CVector(Random(30, -30), 390, Random(-300, -290)));
		}
		for (int i = 0; i < 38; i++){//38
			New<CEffect_thunder_machinery>(CVector(Random(-107.0f,107.0f), 102.5f, Random(800.0f,600.0f)), 0, RotationY(Random(0.0f,1.0f)));
		}
	//色明度
		RGB = 1.0f;
		AW_MINPLU = -0.02f;
}

// ステージの移動
void CStage::Move() {
	
	//ライト光調整
	if (camera_combat_state_type == camera_combat_state_on){
		LightList.Apply([&](CMover* l){
				if (l->Type == AMBIENT) {
					if (l->Color == CColor(0.35f, 0.35f, 0.35f, 1.0f)){
						l->Color = CColor(0.6f, 0.6f, 0.6f, 1.0);
						l->AMBIENTState = 1;
						RGB = 0.6f;
					}
				}
				if (l->Type == DIRECTIONAL){
					if (l->Color == CColor(0.3f, 0.4f, 0.7f, 1.0f))l->State = 1;
					if (l->Color == CColor(0.4f, 0.3f, 0.4f, 1.0f))l->State = 2;
				}
				/*if (l->Type == POINT){
					MyShipList.Apply([&](CMover* e){
					l->Color = CColor(20.3f, 0.4f, 0.7f, 20.0f);
					l->Position = e->Position + (CVector(0, 4, 0));
					});
					}*/
		});
	}
	LightList.Apply([&](CMover* l){
		if (enemy_count != 0){
			//最終的にはRGB=4が良い
			if (MovieState == 1 && DEFENS_LIGHT_TIME < 870){
				DEFENS_LIGHT_TIME++;
				STAGE_COLOR++;
				if (STAGE_COLOR % 7 == 0)RGB += AW_MINPLU;
				if (RGB <= 0.2f)AW_MINPLU = 0.02f;
				if (RGB >= 0.6f)AW_MINPLU = -0.02f;
				if (l->Type == AMBIENT) {
					if (l->AMBIENTState == 1)l->Color = CColor(RGB + 0.3f, RGB, RGB, 0.5f);
				}
				if (l->Type == DIRECTIONAL){
					if (l->State == 1)l->Color = CColor(0.6f*RGB + 0.4f, 0.3f, 0.3f, 1);
					if (l->State == 2)l->Color = CColor(0.4f, 0.2f, 0.1f, 1);
				}
			}
		}
		if (enemy_count == 0){
			BGM_TIME++;
			if (BGM_TIME==1){
				bgm_state = defence_combatrelease_on;//BGM
			}
			if (BGM_TIME >= 30){
				//こちら側でStateを変えてStage_gate.cppでゲートを消す処理をしている（赤ゲート）
				Stage_gateList.Apply([&](CMover* st){
					st->State = 2;
				});
				Stage_gate2List.Apply([&](CMover* st2){
					st2->State = 2;
				});
			}
			if (BGM_TIME >= 310){
				if (BGM_TIME == 350){
					message_switch = message_on;//メッセージON
				}
				if (l->Type == AMBIENT) {
					l->Color = CColor(0.45f, 0.45f, 0.45f, 1.0f);
				}
				if (l->Type == DIRECTIONAL){
					if (l->State == 1)l->Color = CColor(0.3f, 0.4f, 0.7f, 1.0f);
					if (l->State == 2)l->Color = CColor(0.4f, 0.3f, 0.4f, 1.0f);
				}
			}
		}
	});

	//ゲームオーバー時ライト
	LightList.Apply([&](CMover* l){
		if (clear == clear_bad_on){
			BAD_END_RIGHTTIME++;
			if (BAD_END_RIGHTTIME == 1){
					bgm_state = mission_failure_bgm_on;//ミッション失敗BGM
			}
			if (BAD_END_RIGHTTIME>1){
				BAD_END_RIGHTTIME = 2;
			}
			if (L_R>=0){
				L_R -= 0.002f;
			}
			if (l->Type == AMBIENT) {
				l->Color = CColor(L_R, L_R, L_R, L_R);//初期全て共通0.45fのため同一変数
			}
			if (L_R <= 0.0f){
				L_R = 0;
			}
		}
	});
	if (boss_movie_state == boss_movie_on){
		Time++;
		if (Time == 1){
			New<CEnemy_Boss>(CVector(+120.35f, 100.0f, 740.0f));
		}
	}


	//現在の敵の数
	enemy_count = mekapen_number + patikoma_number;
	EnemyList.Apply([&](CMover* e){
		if (e->Life <= 0){
			Score += 200;
			mekapen_number--;
		}
	});
	Enemy_takyakuList.Apply([&](CMover* et){
		if (et->Life <= 0){
			Score += 400;
			patikoma_number--;
		}
	});
	//ボス消滅
	Enemy_BossList.Apply([&](CMover* et){
		//残り時間あり
		if (timeleft == timeleft_yes){
			if (et->Life <= 0){
				Enemy_Boss_modelList.Apply([&](CMover* eb){
					eb->AttackState = 0;
					eb->Life = 0;
					GetWave(L"ENEMY_ATACK\\littleshot.wav")->SetVolume(0.0f);
				});
				Score += 400;
				clear = clear_good_on;
				bgm_state = clearend_bgm_on;
			}
		}
	});

	//自機消滅
	MyShipList.Apply([&](CMover* m){
		if (m->Life<=0){
			myship_death = myship_death_on;
			MYSHIP_DEATH_COUNT = 1;
			New<CEffect5>(m->Position);
			New<CEffect6>(m->Position);
			GetWave(L"ENEMY_ATACK\\big_bomb.wav")->Play(1);
			GetWave(L"ENEMY_ATACK\\big_bomb.wav")->SetVolume(0.4f);
			Effect_positionList.Apply([&](CMover* e){
				e->Life = 0;
			});
			Effect_position2List.Apply([&](CMover* e2){
				e2->Life = 0;
			});
			Effect_sub_positionList.Apply([&](CMover* es){
				es->Life = 0;
			});
			Effect_sub_position2List.Apply([&](CMover* es2){
				es2->Life = 0;
			});
			WeaponList.Apply([&](CMover* w){
				w->Life = 0;
			});
			Weapon_GunList.Apply([&](CMover* g){
				g->Life = 0;
			});
			clear = clear_bad_on;
		}
	});

	if (myship_death == myship_death_on&&clear == clear_bad_on){
		//音消去(SOUND_VOLUME1=0.4f, SOUND_VOLUME2=0.3f, SOUND_VOLUME3=0.2f, SOUND_VOLUME4=0.15f, SOUND_VOLUME5=0.1f)
		GetWave(L"ENEMY_ATACK\\big_bomb.wav")->SetVolume(SOUND_VOLUME1);
		GetWave(L"ENEMY_ATACK\\e_beam.wav")->SetVolume(SOUND_VOLUME2);
		GetWave(L"ACTION\\beam_hit.wav")->SetVolume(SOUND_VOLUME2);
		GetWave(L"BGM\\defencerelease_bgm.wav")->SetVolume(SOUND_VOLUME2);
		GetWave(L"BGM\\defence_combat.wav")->SetVolume(SOUND_VOLUME2);
		GetWave(L"BGM\\normal_bgm.wav")->SetVolume(SOUND_VOLUME3);
		GetWave(L"BOSSBGM\\boss_bgm1.wav")->SetVolume(SOUND_VOLUME3);
		GetWave(L"system\\alarm.wav")->SetVolume(SOUND_VOLUME3);
		GetWave(L"ENEMY_ATACK\\littleshot.wav")->SetVolume(SOUND_VOLUME3);
		GetWave(L"ENEMY_ATACK\\volt.wav")->SetVolume(SOUND_VOLUME4);
		GetWave(L"ENEMY_ATACK\\volt.wav")->SetVolume(SOUND_VOLUME4);
		GetWave(L"ENEMY_ATACK\\little_bomb.wav")->SetVolume(SOUND_VOLUME5);

		SOUND_VOLUME1-= 0.005f;
		SOUND_VOLUME2-= 0.005f;
		SOUND_VOLUME3-= 0.005f;
		SOUND_VOLUME4-= 0.005f;
		SOUND_VOLUME5-= 0.005f;
		if (SOUND_VOLUME1 <= 0)SOUND_VOLUME1 = 0;
		if (SOUND_VOLUME2 <= 0)SOUND_VOLUME2 = 0;
		if (SOUND_VOLUME3 <= 0)SOUND_VOLUME3 = 0;
		if (SOUND_VOLUME4 <= 0)SOUND_VOLUME4 = 0;
		if (SOUND_VOLUME5 <= 0)SOUND_VOLUME5 = 0;
		if (SOUND_VOLUME1 == 0 && SOUND_VOLUME2 == 0 && SOUND_VOLUME3 == 0 && SOUND_VOLUME4 == 0 && SOUND_VOLUME5 == 0){

		}
	}
}
//==================================================================================================================
//ステージ_01の初期化（床）
void CStage_01::Reset() {
	Model = GetModel(L"STAGE\\STAGE0001_yuka.x");//機体モデル4STAGE\\stage0_3_1.x
	Scale = CVector(1, 1, 1)*5.5f;//サイズ0.4
	Color = CColor(1, 1, 1, 1.0f);
	Texture = GetTexture(L"STAGE\\stage0_3_2.png");
	TextureScale = CVector(5.3f, 5.3f, 5.3f);
	Rotation = RotationY(-0.25f);
}
// ステージ_01の移動
void CStage_01::Move() {

}
//==================================================================================================================
//ステージ_02の初期化（壁）
void CStage_02::Reset() {
	Model = GetModel(L"STAGE\\STAGE0002_kabe.x");//機体モデル4STAGE\\stage0_3_2.x
	Scale = CVector(1, 1, 1)*5.5f;//サイズ0.4
	Color = CColor(1, 1, 1, 1.0f);
	Texture = GetTexture(L"STAGE\\stage0_3_3.png");
	TextureScale = CVector(6.0f, 6.0f,6.0f);
	Rotation = RotationY(-0.25);
}
// ステージ_02の移動
void CStage_02::Move() {
}
//==================================================================================================================
//ステージ_ゲートの初期化
void CStage_gate::Reset() {
	Model = GetModel(L"DEFAULT_SAMPLE\\cube.x");//機体モデル
	Scale = CVector(129, 53, 0.01f)*1.0f;//サイズ
	Color = CColor(1, 0, 0, 0.0f);
}
// ステージ_ゲートの移動
void CStage_gate::Move() {
	//EmissiveColor = CColor(Random(0.3f, 0.3f), Random(0.1f, 0.0f), Random(0.0f, 0.0f), Random(0.2f,0.12f));
	//Camera.cppでState変更
	if (State == 1){
		if (w <= 0.05f){
			w += 0.0003f;
		}
		Color = CColor(1, 0, 0, w);
		EmissiveColor = CColor(Random(3.0f, 0.0f), Random(0.1f, 0.2f), Random(0.2f, 0.0f), w);
	}
	if (State == 2){
		w -= 0.0003f;
		if (w<=0){
			Life = 0;
		}
		Color = CColor(1, 0, 0, w);
		EmissiveColor = CColor(Random(3.0f, 0.0f), Random(0.1f, 0.2f), Random(0.2f, 0.0f), w);
	}
}
//==================================================================================================================
//ステージ_ゲート2の初期化
void CStage_gate2::Reset() {
	Model = GetModel(L"DEFAULT_SAMPLE\\cube.x");//機体モデル
	Scale = CVector(129, 2.0f, 0.01f)*1.0f;//サイズ
	Color = CColor(1, 0, 0,0);
	Y = 305;
	w = 0;
}
// ステージ_ゲートの移動
void CStage_gate2::Move() {
	//Camera.cppでState変更
	if (State == 1){
		if (w<=0.08f){
			w += 0.0002f;
		}
		Color = CColor(1, 0, 0, w);
		EmissiveColor = CColor(Random(3.0f, 0.0f), Random(0.1f, 0.2f), Random(0.2f, 0.0f),w);
		Position = CVector(0, Y, 671);
		if (Y <= 375){
			Y += 1.0f;
		}
		if (Y > 375){
			Y = 305;
		}
	}
	if (State == 2){
		w -= 0.0004f;
		if (w <= 0){
			Life = 0;
		}
		Color = CColor(1, 0, 0, w);
		EmissiveColor = CColor(Random(3.0f, 0.0f), Random(0.1f, 0.2f), Random(0.2f, 0.0f), w);
	}
}
//==================================================================================================================
//ステージ_ゲート3の初期化
void CStage_gate3::Reset() {
	Model = GetModel(L"DEFAULT_SAMPLE\\cube.x");//機体モデル
	Scale = CVector(129, 53, 0.01f)*1.0f;//サイズ
	Color = CColor(1, 0, 0, 0.0f);
}
// ステージ_ゲート3の移動
void CStage_gate3::Move() {
	EmissiveColor = CColor(Random(0.0f, 0.3f), Random(0.1f, 0.0f), Random(6.0f, 0.4f), Random(0.2f, 0.12f));
}
//==================================================================================================================
//ステージ_ゲート4の初期化(ボス部屋)
void CStage_gate4::Reset() {
	Model = GetModel(L"DEFAULT_SAMPLE\\cube.x");//機体モデル
	Scale = CVector(129, 53, 0.01f)*1.0f;//サイズ
	Color = CColor(1, 0, 0, 0.0f);
}
// ステージ_ゲート4の移動
void CStage_gate4::Move() {
	//EmissiveColor = CColor(Random(0.0f, 0.3f), Random(0.1f, 0.0f), Random(6.0f, 0.4f), Random(0.2f, 0.12f));
}
//==================================================================================================================
//センターゲート左の初期化
void CStage_Centergate_L::Reset() {
	//Model = GetModel(L"STAGE\\CENTEAR_LR_0000.x");
	Model = GetModel(L"STAGE\\CCENTOR_L_0001.x");
	Color = CColor(1, 1, 1, 0.0f);
	Scale = CVector(1, 1, 1)*5.5f;//サイズ0.4
	Rotation = CQuaternion(AXIS_Y, 0.5f);
}
// センターゲート左の移動
void CStage_Centergate_L::Move() {
	//EmissiveColor = CColor(Random(0.3f, 0.3f), Random(0.1f, 0.0f), Random(0.0f, 0.0f), 0.2f);
	Stage_Centergate_LRList.Apply([&](CMover*st){
		if (st->Type == 1){
			TIME++;
			if (TIME == 1){
				Color = CColor(1, 1, 1, 1.0f);
			}
			if (TIME == 1){
				GetWave(L"system\\center_gate_open.wav")->Play(1);
				GetWave(L"system\\center_gate_open.wav")->SetVolume(0.4f);
			}
			if (TIME <= 350){
				Position.X += 0.3f;
				if (TIME == 325){
					GetWave(L"system\\center_gate_open.wav")->SetVolume(0.0f);
					GetWave(L"system\\center_gate_open2.wav")->Play(1);
					GetWave(L"system\\center_gate_open2.wav")->SetVolume(0.4f);
				}
			}
			if (TIME == 355){
				message_switch = message_on;// 中央ゲート解放メッセージON
				TIME = 356;
			}
		}
	});
	
}
//==================================================================================================================
//センターゲート右の初期化
void CStage_Centergate_R::Reset() {
	Model = GetModel(L"STAGE\\CCENTOR_R_0001.x");
	Scale = CVector(1, 1, 1)*5.5f;//サイズ0.4
	Color = CColor(1, 1, 1, 0.0f);
	Rotation = CQuaternion(AXIS_Y, 0.5f);
}
// センターゲート右の移動
void CStage_Centergate_R::Move() {
	//EmissiveColor = CColor(Random(0.3f, 0.3f), Random(0.1f, 0.0f), Random(0.0f, 0.0f), 0.2f);
	Stage_Centergate_LRList.Apply([&](CMover*st){
		if (st->Type==1){
			TIME++;
			if (TIME == 1){
				Color = CColor(1, 1, 1, 1.0f);
			}
			if (TIME <= 350){
				Position.X -= 0.3f;
			}
			if (TIME==351){
				icon0_type = icon0_off;
				MyShipList.Apply([&](CMover*m){
					Camera->Position = m->Position + CVector(0, 4, -52)*Camera->Rotation;
					Camera->Rotation = m->Rotation;
				});
			}
		}
	});
}
//==================================================================================================================
//センターゲート左右の初期化
void CStage_Centergate_LR::Reset() {
	Model = GetModel(L"STAGE\\CCENTOR_LR_0001.x");//CENTEAR_LR_0000.x
	Color = CColor(1, 1, 1, 1.0f);
	Scale = CVector(1, 1, 1)*5.5f;//サイズ0.4
}
// センターゲート左右の移動
void CStage_Centergate_LR::Move() {
	//EmissiveColor = CColor(Random(0.3f, 0.3f), Random(0.1f, 0.0f), Random(0.0f, 0.0f), 0.2f);
	
	if (centergate_movietype == centergate_movie_on){
		ROTA_TIME++;
		if (ROTA_TIME==1){
			GetWave(L"system\\center_gate_rota.wav")->Play(1);
			GetWave(L"system\\center_gate_rota.wav")->SetVolume(0.8f);
		}
		if (ROTA_TIME<=125){
			Rotation *= CQuaternion(AXIS_Y, 0.004f);
		}
		if (ROTA_TIME > 125 && ROTA_TIME < 164){
			Position.Y -= 0.1f;
		}
		if (ROTA_TIME == 165){
			Color = CColor(1, 1, 1, 1.0f);
		}
		if (ROTA_TIME == 166){
			Type = 1;
			Position = -1000;
		}
	}
	
}
//==================================================================================================================
//モニターの初期化
void CMonitor::Reset() {
	Model = GetModel(L"MONITOR\\MONITOR.x");
	Color = CColor(1, 1, 1, 1.0f);
	Scale = CVector(1, 1, 1)*0.16f;//サイズ0.4
}
//モニターの移動
void CMonitor::Move() {
	EmissiveColor = CColor(Random(0.3f, 0.3f), Random(0.3f, 0.3f), Random(0.3f, 0.3f), 0.4f);
}