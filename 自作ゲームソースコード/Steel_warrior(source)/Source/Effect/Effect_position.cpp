#include "..\Main\Main.h"

//======================================メインブースト（右）==================================================================
// 効果の初期化
void CEffect_position::Reset() {
	Model = GetModel(L"BOOST_3D\\BOOST_RIGHT.x");
	Scale = CVector(1.0f, 1.1f, 1.0f)*100.0f;//0.3,0.75,1.9
	Color = CColor(1, 1, 1, 1.0f);
}

// 効果の移動
void CEffect_position::Move() {
	CModelBone* b = Owner->GetBone(L"R_injection2_Joint");
	Rotation = RotationY(0.0f)*RotationX(0.005f)*RotationZ(0.0f)*b->Rotation;
	Position = b->Position + CVector(-0.32f, -0.87f, 0.945f)*b->Rotation;//-0.32f, -0.87f, 0.95f

	if (boost_main1_switch == boost_main1_on){
		EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 1);
		Color = CColor(1, 1, 1, 0.8f);//0.1
	}
	else if (boost_main1_switch == boost_main1_off){
		EmissiveColor = CColor(1, 1, 1, 1);
		Color = CColor(1, 1, 1, 0.0f);
	}

	if (boost_main2_switch == boost_main2_on){
		New<CEffect>(b->Position + CVector(0.2f, -0.1f, -0.8f)*Rotation, AxisX()*-1.0f + AxisZ()*1.5f);
		New<CEffect>(b->Position + CVector(0.2f, -0.2f, -1.3f)*Rotation, AxisX()*-1.0f + AxisZ()*1.5f);
	}
}

//=======================================メインブースト（左）=================================================================
// 効果の初期化
void CEffect_position2::Reset() {
	Model = GetModel(L"BOOST_3D\\BOOST_LEFT.x");
	Scale = CVector(1.0f, 1.1f, 1.0f)*100.0f;//0.3,0.75,1.9
	Color = CColor(1, 1, 1, 1.0f);
}

// 効果の移動
void CEffect_position2::Move() {
	CModelBone* b = Owner->GetBone(L"L_injection2_Joint");
	Rotation = RotationY(0.0f)*RotationX(0.005f)*RotationZ(0.0f)*b->Rotation;
	Position = b->Position + CVector(0.32f, -0.87f, 0.945f)*b->Rotation;//0.35,0.0,-1.5

	if (boost_main1_switch == 1){
		EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 1);
		Color = CColor(1, 1, 1, 0.8f);
	}
	else if (boost_main1_switch == 0){
		EmissiveColor = CColor(1, 1, 1, 1);
		Color = CColor(1, 1, 1, 0.0f);
	}

	if (boost_main2_switch == 1){
		New<CEffect>(b->Position + CVector(-0.2f, -0.1f, -0.8f)*Rotation, AxisX()*1.0f + AxisZ()*1.5f);
		New<CEffect>(b->Position + CVector(-0.2f, -0.2f, -1.3f)*Rotation, AxisX()*1.0f + AxisZ()*1.5f);
	}

}

//=====================================サブブースト（右）===================================================================

// 効果の初期化
void CEffect_sub_position::Reset() {
	Model = GetModel(L"Default_sample\\cube.x");
	Scale = CVector(0.12f, 0.5f, 0.8f)*0.5f;//0.3,0.75,1.9
	Color = CColor(1, 1, 1, 0.1f);
}

// 効果の移動
void CEffect_sub_position::Move() {
	CModelBone* b = Owner->GetBone(L"R_sabu_injection2_Joint");
	Rotation = RotationY(-0.03f)*RotationX(0.0f)*RotationZ(0.05f)*b->Rotation;
	

	//UP中
	if (boost_subup_switch == boost_subup_on&&boost_sub_switch == boost_sub_off){
		Scale = CVector(0.15f, 0.6f, 0.2f)*0.5f;//0.3,0.75,1.6
		Position = b->Position + CVector(0.13f, 0.05f, -0.72f)*b->Rotation;//-1.4
		EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 1);
		Color = CColor(1, 1, 1, 0.2f);
	}
	//ダッシュしている
	if (boost_sub_switch == boost_sub_on){
		Position = b->Position + CVector(0.11f, 0.05f, -0.8f)*b->Rotation;
		Scale = CVector(0.12f, 0.5f, 0.8f)*0.5f;
		EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 0.5f);
		Color = CColor(1, 1, 1, 0.1f);
		New<CEffect2>(Position + CVector(0.0f, 0.0f, -0.2f)*Rotation, AxisX()*-0.1f + AxisZ()*1.5f);
		New<CEffect2>(Position + CVector(0.0f, 0.0f, -0.5f)*Rotation, AxisX()*-0.1f + AxisZ()*1.5f);
		New<CEffect2>(Position + CVector(0.0f, 0.0f, -0.9f)*Rotation, AxisX()*-0.1f + AxisZ()*1.5f);
	}
	//ブースト消し
	if (boost_subup_switch == boost_subup_off&&boost_sub_switch == boost_sub_off){
		Scale = CVector(0.12f, 0.5f, 1.6f)*0.5f;//0.3,0.75,1.9
		Position = b->Position + CVector(0.23f, 0.05f, -1.4f)*b->Rotation;
		EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 0);
		Color = CColor(1, 1, 1, 0.0f);
	}

}

//=======================================サブブースト（左）===================================================================

// 効果の初期化
void CEffect_sub_position2::Reset() {
	Model = GetModel(L"Default_sample\\cube.x");
	Scale = CVector(0.12f, 0.5f, 0.8f)*0.5f;//0.3,0.75,1.9
	Color = CColor(1, 1, 1, 0.1f);
}

// 効果の移動
void CEffect_sub_position2::Move() {
	CModelBone* b = Owner->GetBone(L"L_sabu_injection2_Joint");
	Rotation = RotationY(-0.03f)*RotationX(0.0f)*RotationZ(0.05f)*b->Rotation;


	//UP中
	if (boost_subup_switch == boost_subup_on&&boost_sub_switch == boost_sub_off){
		Scale = CVector(0.15f, 0.6f, 0.2f)*0.5f;//0.3,0.75,1.6
		Position = b->Position + CVector(-0.13f, 0.05f, -0.72f)*b->Rotation;//-1.4
		EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 1);
		Color = CColor(1, 1, 1, 0.2f);
	}
	//ダッシュしている
	if (boost_sub_switch == boost_sub_on){
		Position = b->Position + CVector(-0.11f, 0.05f, -0.8f)*b->Rotation;
		Scale = CVector(0.12f, 0.5f, 0.8f)*0.5f;
		EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 0.5f);
		Color = CColor(1, 1, 1, 0.1f);
		New<CEffect2>(Position + CVector(0.0f, 0.0f, -0.2f)*Rotation, AxisX()*-0.1f + AxisZ()*1.5f);
		New<CEffect2>(Position + CVector(0.0f, 0.0f, -0.5f)*Rotation, AxisX()*-0.1f + AxisZ()*1.5f);
		New<CEffect2>(Position + CVector(0.0f, 0.0f, -0.9f)*Rotation, AxisX()*-0.1f + AxisZ()*1.5f);
	}
	//ブースト消し
	if (boost_subup_switch == boost_subup_off&&boost_sub_switch == boost_sub_off){
		Scale = CVector(0.12f, 0.5f, 1.6f)*0.5f;//0.3,0.75,1.9
		Position = b->Position + CVector(-0.23f, 0.05f, -1.4f)*b->Rotation;
		EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 0);
		Color = CColor(1, 1, 1, 0.0f);
	}

}
//==============================================斬攻撃エフェクト===============================================================
// 効果の初期化
void CEffect_zan_position::Reset() {
	Texture = GetTexture(L"Default_sample\\Beam.png");
	Scale = CVector(0.02f, 0.1f, 1.0f)*1.0f;
	Color = CColor(1, 1, 1, 1.3f);
	New<CEffect4>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationZ(0.0f));
	New<CEffect3>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationZ(0.0f));
	New<CEffect3>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationZ(-0.15f));
	New<CEffect3>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationZ(0.15f));

}

// 効果の移動
void CEffect_zan_position::Move() {

	NEW_DELETE_COUNT++;
	if (NEW_DELETE_COUNT >= 70){
		Life = 0;
	}
}
//==============================================ショット攻撃エフェクト===============================================================
// 効果の初期化
void CEffect_shothit_position::Reset() {
	Texture = GetTexture(L"Default_sample\\Beam.png");
	Scale = CVector(0.1f, 0.1f, 0.1f)*1.0f;
	Color = CColor(1, 1, 1, 0.0f);
	EFFECT_TIME = 22;
	New<CEffect7>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationX(0.25f));
	New<CEffect7>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationZ(0.05f));
	New<CEffect7>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationZ(-0.05f));
	New<CEffect7>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationZ(-0.25f));
	New<CEffect8>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationZ(0.0f));
}

// 効果の移動
void CEffect_shothit_position::Move() {
	Time++;
		if (Time % EFFECT_TIME == 21){ Life = 0; }
}
//====================================================カミナリ（集約）==================================================================
// 効果の初期化
void CEffect_volt_position::Reset() {
	Texture = GetTexture(L"Default_sample\\Beam.png");
	Scale = CVector(0.1f, 0.1f, 0.1f)*1.0f;
	Color = CColor(1, 1, 1, 0.0f);
	New<CBullet5>(Position + CVector(0.0f, -1.0f, 0.0f), 0, RotationY(0.0f));
	New<CBullet5>(Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationY(0.25f));
	New<CBullet5>(Position + CVector(0.0f, -40.0f, 0.0f), 0, RotationY(0.12f));
	New<CBullet5>(Position + CVector(0.0f, -80.0f, 0.0f), 0, RotationY(-0.12f));
	New<CEffect11>(Position + CVector(0, -107.0f, 0));
	New<CEffect12>(Position + CVector(0, -70, 0));
	New<CEffect12>(Position + CVector(0, -90, 0));
}

// 効果の移動
void CEffect_volt_position::Move() {
		
}
//====================================================カミナリ（生成機）==================================================================
// 効果の初期化
void CEffect_thunder_machinery::Reset() {
	Model = GetModel(L"PARTICLE\\particalee.x");
	Scale = CVector(1.0f, 1.0f, 1.0f)*1.0f;
	Color = CColor(Random(1.0f, 1.0f), Random(1.0f, 1.0f), Random(1.0f, 1.0f), 0.42f);//0.42
	sp = 1.0f;
	New<CEffect15>(Position + CVector(0, 0, 0));//エフェクト15
}

// 効果の移動
void CEffect_thunder_machinery::Move() {
	if (all_combat_type == all_combat_on && clear == clear_off &&(boss_movie_state == boss_movie_on || boss_movie_state == boss_combat_on)){
		EmissiveColor = CColor(Random(1.0f, 1.0f), Random(1.0f, 0.6f), Random(0.4f, 0.6f), COLOR_W);

		if (THUNDER_COUNT == 0){
			THUNDER_TIME = Random(180, 60);
			THUNDER_COUNT = 1;
		}

		if (THUNDER_COUNT == 1){
			Time++;
			if (Time%THUNDER_TIME == 0){
				THUNDER_COUNT = 2;
				New<CEffect14>(Position + CVector(0, -107, 0));
				Time = 0;
			}
		}
		//停止感覚
		if (THUNDER_COUNT == 2){
			THUNDER_TIME2++;
			COLOR_W += 0.005f;
			if (THUNDER_TIME2 >= 110){
				THUNDER_COUNT = 0;
				THUNDER_TIME2 = 0;
			}
		}

		//移動
		if (THUNDER_COUNT < 2){
			COLOR_W = 0;
			MOVE_TIME++;
			if (MOVE_TIME <= 150){
				Position += AxisX()*sp;
			}
			if (MOVE_TIME >= 151 && MOVE_TIME <= 300){
				Position -= AxisX()*sp;
				if (MOVE_TIME == 300){
					MOVE_TIME = 0;
				}
			}
		}
	}
	if (clear != clear_off){
		EmissiveColor = CColor(0,0, 0, 0);
	}
}
//================================================ダメージエフェクトポジション（自機）==================================================================
// 効果の初期化
void CEffect_damage_position::Reset() {
	Model = GetModel(L"PARTICLE\\particalee.x");
	Scale = CVector(1.0f, 1.0f, 1.0f)*1.0f;
	Color = CColor(1, 1, 1, 0.0f);
	POSITION_Y = -0.6;//-0.54
}
// 効果の移動
void CEffect_damage_position::Move() {
	MyShipList.Apply([&](CMover* m){
		Position = m->Position;
	});

	if (COUNT==0){
		MyShipList.Apply([&](CMover* m){
		Time++;
		if (Time == 4){
			New<CEffect20>(m->Position + CVector(0, POSITION_Y, 0));
			New<CEffect17>(m->Position + CVector(0, POSITION_Y, 0));
			New<CEffect16>(m->Position + CVector(0, POSITION_Y, 0));
				COUNT = 1;
				Time = 0;
		}
		});
	}
	if (COUNT == 1){
		MyShipList.Apply([&](CMover* m){
		Time++;
		if (Time==18){
			New<CEffect21>(m->Position + CVector(0, POSITION_Y, 0));
		}
		if (Time==25){
			for (int i = 0; i < 8; i++) New<CEffect18>(m->Position + CVector(0.0f, POSITION_Y, 0.0f), AXIS_Y*RotationX(Random(0, 0.3f))*RotationY(Random(0, 1)));
				
		}
		if (Time == 28){
			New<CEffect19>(m->Position + CVector(0, POSITION_Y, 0));
			Time = 0;
			Life = 0;
			COUNT = 0;
		}
		});
	}
}