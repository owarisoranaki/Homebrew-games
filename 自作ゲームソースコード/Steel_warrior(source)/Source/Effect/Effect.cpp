#include "..\Main\Main.h"
//======================================メインブーストエフェクト=======================================================================
// 効果の初期化
void CEffect::Reset() {
	Texture = GetTexture(L"DEFAULT_SAMPLEE\\beam.png");
	Scale = CVector(0.7f, 1.4f, 1)*0.3f;
	Color = CColor(1, 1, 1, 1.1f);//0.1
	BOOST_SCALE = 1;
	EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 1);
}

// 効果の移動
void CEffect::Move() {
	EffectList.Apply([&](CMover*e){
		Rotation = e->Rotation;
	});

	Position -= Velocity*0.1f;
	EFFECT_TIME++;

	BOOST_SCALE *= 1.05f;
	Scale *= CVector(1, BOOST_SCALE, 1);


	if (EFFECT_TIME >= 5){
		Life = 0;
	}

	EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 1);
	//ToonInkColor = CColor(1, 1, 1, 1);
	//ToonInkEmissiveColor = CColor(1, 1, 1, 1);
}

//=================================サブメインブーストエフェクト==========================================================================
// 効果の初期化2
void CEffect2::Reset() {
	Texture = GetTexture(L"DEFAULT_SAMPLEE\\beam.png");
	Scale = CVector(0.7f, 1.0f, 1)*0.3f;
	Color = CColor(1, 1, 1, 0.1f);
	EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 1);
}

// 効果の移動2
void CEffect2::Move() {
	Position -= Velocity*0.1f;
	EFFECT_TIME2++;

	//BOOST_SCALE *= 1.03f;
	//Scale *= CVector(1, BOOST_SCALE, 1);

	if (EFFECT_TIME2 >= 3){
		Life = 0;
	}

	EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 1);

}
//====================================ブレードエフェクト(線)====================================================================
// 効果の初期化3
void CEffect3::Reset() {
	Texture = GetTexture(L"DEFAULT_SAMPLE\\Beam.png");
	Scale = CVector(0.02f, 0.1f, 1.0f)*1.0f;
	Color = CColor(1, 1, 1, 0.3f);
	ZAN_EFFECT_SCALEy = 0.02f;
	ZAN_EFFECT_SCALEx = 0.02f;
	//Rotation = RotationZ(-0.1f)*Rotation;
}

// 効果の移動3
void CEffect3::Move() {

	ZAN_EFFECT_TIME++;
	if (ZAN_EFFECT_TIME <= 60){
		ZAN_EFFECT_SCALEy *= 2.0f;
		ZAN_EFFECT_SCALEx += 0.007f;
	}
	if (ZAN_EFFECT_TIME >= 60){
		Life = 0;
	}
	Scale = CVector(ZAN_EFFECT_SCALEx, ZAN_EFFECT_SCALEy, 1.0f)*1.0f;
	EmissiveColor = CColor(Random(0, 0.1f), Random(0.0, 0.3f), Random(1, 1), 1.0f);

}
//====================================ブレードエフェクト2(インパクト)===============================================================================
// 効果の初期化4
void CEffect4::Reset() {
	Scale = CVector(1, 1, 1)*1.1f;
	Texture = GetTexture(L"impact_effect\\impact0002.png");
	EFFECT_TIME = 30;
}

// 効果の移動4
void CEffect4::Move() {

	if (Time % EFFECT_TIME == 0)Texture = GetTexture(L"impact_effect\\impact0001.png");
	if (Time % EFFECT_TIME == 1)Texture = GetTexture(L"impact_effect\\impact0002.png");
	if (Time % EFFECT_TIME == 2)Texture = GetTexture(L"impact_effect\\impact0003.png");
	if (Time % EFFECT_TIME == 3)Texture = GetTexture(L"impact_effect\\impact0004.png");
	if (Time % EFFECT_TIME == 4)Texture = GetTexture(L"impact_effect\\impact0005.png");
	if (Time % EFFECT_TIME == 5)Texture = GetTexture(L"impact_effect\\impact0006.png");
	if (Time % EFFECT_TIME == 6)Texture = GetTexture(L"impact_effect\\impact0007.png");
	if (Time % EFFECT_TIME == 7)Texture = GetTexture(L"impact_effect\\impact0008.png");
	if (Time % EFFECT_TIME == 8)Texture = GetTexture(L"impact_effect\\impact0009.png");
	if (Time % EFFECT_TIME == 9)Texture = GetTexture(L"impact_effect\\impact0010.png");
	if (Time % EFFECT_TIME == 10)Texture = GetTexture(L"impact_effect\\impact0011.png");
	if (Time % EFFECT_TIME == 11)Texture = GetTexture(L"impact_effect\\impact0012.png");
	if (Time % EFFECT_TIME == 12)Texture = GetTexture(L"impact_effect\\impact0013.png");
	if (Time % EFFECT_TIME == 13)Texture = GetTexture(L"impact_effect\\impact0014.png");
	if (Time % EFFECT_TIME == 14)Texture = GetTexture(L"impact_effect\\impact0015.png");
	if (Time % EFFECT_TIME == 15)Texture = GetTexture(L"impact_effect\\impact0016.png");
	if (Time % EFFECT_TIME == 16)Texture = GetTexture(L"impact_effect\\impact0017.png");
	if (Time % EFFECT_TIME == 17)Texture = GetTexture(L"impact_effect\\impact0018.png");
	if (Time % EFFECT_TIME == 18)Texture = GetTexture(L"impact_effect\\impact0019.png");
	if (Time % EFFECT_TIME == 19)Texture = GetTexture(L"impact_effect\\impact0020.png");
	if (Time % EFFECT_TIME == 20)Texture = GetTexture(L"impact_effect\\impact0021.png");
	if (Time % EFFECT_TIME == 21)Texture = GetTexture(L"impact_effect\\impact0022.png");
	if (Time % EFFECT_TIME == 22)Texture = GetTexture(L"impact_effect\\impact0023.png");
	if (Time % EFFECT_TIME == 23)Texture = GetTexture(L"impact_effect\\impact0024.png");
	if (Time % EFFECT_TIME == 24)Texture = GetTexture(L"impact_effect\\impact0025.png");
	if (Time % EFFECT_TIME == 25)Texture = GetTexture(L"impact_effect\\impact0026.png");
	if (Time % EFFECT_TIME == 26)Texture = GetTexture(L"impact_effect\\impact0027.png");
	if (Time % EFFECT_TIME == 27){ Life = 0; }
	Scale = CVector(1, 1, 1)*15.0f;
	Color = CColor(1, 1, 1, 0.9f);
	Time++;
	EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 1);
}
//=========================================爆弾爆発（敵）======================================================================================
// 効果の初期化5
void CEffect5::Reset() {
	Scale = CVector(1, 1, 1)*0.7f;
	Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0001.png");
	EFFECT_TIME = 16;
	Scale = CVector(1, 1, 1)*0.5f;
}

// 効果の移動5
void CEffect5::Move() {

	if (Time % EFFECT_TIME == 0)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0001.png");
	if (Time % EFFECT_TIME == 1)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0002.png");
	if (Time % EFFECT_TIME == 2)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0003.png");
	if (Time % EFFECT_TIME == 3)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0004.png");
	if (Time % EFFECT_TIME == 4)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0005.png");
	if (Time % EFFECT_TIME == 5)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0006.png");
	if (Time % EFFECT_TIME == 6)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0007.png");
	if (Time % EFFECT_TIME == 7)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0008.png");
	if (Time % EFFECT_TIME == 8)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0009.png");
	if (Time % EFFECT_TIME == 9)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0010.png");
	if (Time % EFFECT_TIME == 10)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0011.png");
	if (Time % EFFECT_TIME == 11)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0012.png");
	if (Time % EFFECT_TIME == 12)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0013.png");
	if (Time % EFFECT_TIME == 13)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0014.png");
	if (Time % EFFECT_TIME == 14)Texture = GetTexture(L"BOOM_EFFECT\\bakuhatu0015.png");
	if (Time % EFFECT_TIME == 15){ Life = 0; }
	Scale = CVector(1, 1, 1)*40.0f;//4.0
	Color = CColor(1, 1, 1, 1.0f);
	Time++;
	EmissiveColor = CColor(Random(0, 0.3f), Random(0.6, 0.6f), Random(1, 1), 10);
}
//====================================ダメージ(爆発ポリゴン組み合わせ：敵)===============================================================================

// 効果の初期化6
void CEffect6::Reset() {
	Model = GetModel(L"DEFAULT_SAMPLE\\sphere.x");
	Scale = CVector(1, 1, 1)*6.0f;
	Color = CColor(1, 0, 0, 0.7f);
}

// 効果の移動6
void CEffect6::Move() {
	EFFECT_TIME++;
	Scale *= 1.1f;

	//自機当たり判定
	float Body_r2 = 5.0f;
	CHit Fhit;

	if (EFFECT_TIME >= 30){
		Score += 10;
		Life = 0;
	}
	EmissiveColor = CColor(Random(0, 0.3f), Random(0.3, 0.6f), Random(1, 1), 0.7f);
}
//====================================ショット当たり（リングエフェクト）===============================================================================
// 効果の初期化7
void CEffect7::Reset() {
	Model = GetModel(L"RING\\ring.x");
	Scale = CVector(1, 30, 1)*0.1f;
	Color = CColor(1, 1, 1, 0.1f);
	EFFECT_TIME = 22;
}

// 効果の移動7
void CEffect7::Move() {
		Time++;
		if (Time < 7){
			Scale += 0.15f;
		}
	EmissiveColor = CColor(Random(1, 1), Random(0.1, 0.2f), Random(0.2f, 0.2f), 1.5f);
	if (Time % EFFECT_TIME == 21){ Life = 0; }
}
//====================================ショット当たり（2Dエフェクト）===============================================================================
// 効果の初期化8
void CEffect8::Reset() {
	Scale = CVector(1, 1, 1)*0.7f;
	Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect0.png");
	EFFECT_TIME = 22;
	Scale = CVector(1, 1, 1)*0.5f;
}

// 効果の移動8
void CEffect8::Move() {
	if (Time % EFFECT_TIME == 0)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect0.png");
	if (Time % EFFECT_TIME == 1)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect1.png");
	if (Time % EFFECT_TIME == 2)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect2.png");
	if (Time % EFFECT_TIME == 3)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect3.png");
	if (Time % EFFECT_TIME == 4)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect4.png");
	if (Time % EFFECT_TIME == 5)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect5.png");
	if (Time % EFFECT_TIME == 6)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect6.png");
	if (Time % EFFECT_TIME == 7)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect7.png");
	if (Time % EFFECT_TIME == 8)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect8.png");
	if (Time % EFFECT_TIME == 9)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect9.png");
	if (Time % EFFECT_TIME == 10)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect10.png");
	if (Time % EFFECT_TIME == 11)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect11.png");
	if (Time % EFFECT_TIME == 12)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect12.png");
	if (Time % EFFECT_TIME == 13)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect13.png");
	if (Time % EFFECT_TIME == 14)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect14.png");
	if (Time % EFFECT_TIME == 15)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect15.png");
	if (Time % EFFECT_TIME == 16)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect16.png");
	if (Time % EFFECT_TIME == 17)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect17.png");
	if (Time % EFFECT_TIME == 18)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect18.png");
	if (Time % EFFECT_TIME == 19)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect19.png");
	if (Time % EFFECT_TIME == 20)Texture = GetTexture(L"BEAM_SHOT_EFFECT\\shot_effect20.png");
	if (Time % EFFECT_TIME == 21){ Life = 0; }
	Scale = CVector(1, 1, 1)*12.0f;//4.0
	Color = CColor(1, 1, 1, 1.0f);
	Time++;
	EmissiveColor = CColor(Random(1, 1), Random(0.1, 0.2f), Random(0.2f, 0.2f), 12);
}
//====================================ショットtターゲット当たり（リングエフェクト）===============================================================================
// 効果の初期化9
void CEffect9::Reset() {
	Model = GetModel(L"RING\\ring.x");
	Scale = CVector(1, 30, 1)*0.1f;//0.1
	Color = CColor(1, 1, 1, 0.1f);
	EFFECT_TIME = 22;
}

// 効果の移動9
void CEffect9::Move() {
		Time++;
		if (Time < 15){
			Scale += 0.05f;
			EmissiveColor = CColor(Random(0.1f, 0.1f), Random(0.1, 0.2f), Random(0.6f, 0.6f), 1.0f);
		}
		if (Time>=20){
			EmissiveColor = CColor(Random(1, 1), Random(0.1, 0.2f), Random(0.6f, 0.6f), 1.0f);
		}
		
		//消滅
		Bullet2List.Apply([&](CMover* B2) {
			if (Length(B2->Position-Position) <= 1.0f){
				Life = 0;
			}
		});
		Bullet3List.Apply([&](CMover* B3) {
			if (Length(B3->Position - Position) <= 1.0f){
				Life = 0;
			}
		});
		Bullet4List.Apply([&](CMover* B4) {
			if (Length(B4->Position - Position) <= 1.0f){
				Life = 0;
			}
		});
		Bullet6List.Apply([&](CMover* B6) {
			if (Length(B6->Position - Position) <= 1.0f){
				Life = 0;
			}
		});
}
//===========================================リトルボム（小爆発エフェクト）===============================================================================
// 効果の初期化10
void CEffect10::Reset() {
	Scale = CVector(1, 1, 1)*0.7f;
	Texture = GetTexture(L"effect\\bakuhatu0001.png");
	EFFECT_TIME = 16;
	Scale = CVector(1, 1, 1)*0.5f;
}

// 効果の移動10
void CEffect10::Move() {
	if (Time % EFFECT_TIME == 0)Texture = GetTexture(L"effect\\bakuhatu0001.png");
	if (Time % EFFECT_TIME == 1)Texture = GetTexture(L"effect\\bakuhatu0002.png");
	if (Time % EFFECT_TIME == 2)Texture = GetTexture(L"effect\\bakuhatu0003.png");
	if (Time % EFFECT_TIME == 3)Texture = GetTexture(L"effect\\bakuhatu0004.png");
	if (Time % EFFECT_TIME == 4)Texture = GetTexture(L"effect\\bakuhatu0005.png");
	if (Time % EFFECT_TIME == 5)Texture = GetTexture(L"effect\\bakuhatu0006.png");
	if (Time % EFFECT_TIME == 6)Texture = GetTexture(L"effect\\bakuhatu0007.png");
	if (Time % EFFECT_TIME == 7)Texture = GetTexture(L"effect\\bakuhatu0008.png");
	if (Time % EFFECT_TIME == 8)Texture = GetTexture(L"effect\\bakuhatu0009.png");
	if (Time % EFFECT_TIME == 9)Texture = GetTexture(L"effect\\bakuhatu0010.png");
	if (Time % EFFECT_TIME == 10)Texture = GetTexture(L"effect\\bakuhatu0011.png");
	if (Time % EFFECT_TIME == 11)Texture = GetTexture(L"effect\\bakuhatu0012.png");
	if (Time % EFFECT_TIME == 12)Texture = GetTexture(L"effect\\bakuhatu0013.png");
	if (Time % EFFECT_TIME == 13)Texture = GetTexture(L"effect\\bakuhatu0014.png");
	if (Time % EFFECT_TIME == 14)Texture = GetTexture(L"effect\\bakuhatu0015.png");
	if (Time % EFFECT_TIME == 15){ Life = 0; }
	Scale = CVector(1, 1, 1)*5.0f;//4.0
	Color = CColor(1, 1, 1, 1.0f);
	Time++;
	EmissiveColor = CColor(Random(1, 1.0f), Random(0.2, 0.1f), Random(0.6f, 0.6f), 3);

}
//===========================================カミナリエフェクト(球)============================================================================================
// 効果の初期化11
void CEffect11::Reset() {
	Model = GetModel(L"DEFAULT_SAMPLE\\sphere.x");
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(1, 1, 1, 1.0f);
}

// 効果の移動11
void CEffect11::Move() {
	Color = CColor(Random(1, 1), Random(0.9f, 0.7f), Random(1, 0.5f), 1.0f);
	EmissiveColor = CColor(Random(1, 1.0f), Random(0.6, 0.3f), Random(0.2f, 0.1f), Random(1, 0));
		Time++;
		Scale += 1.6f;
		if (Time>8){
			for (int i = 0; i<40; i++) New<CEffect13>(Position + CVector(0.0f, -1.2f, 0.0f), AXIS_Y*RotationX(Random(0, 0.3f))*RotationY(Random(0, 1)));
			Life = 0;
	}
}
//===========================================カミナリエフェクト2（線）============================================================================================
// 効果の初期化12
void CEffect12::Reset() {
	Model = GetModel(L"VOLT\\volt2.x");
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(1, 1, 1, 1.0f);
}

// 効果の移動12
void CEffect12::Move() {
	Color = CColor(Random(1, 1), Random(0.9f, 0.7f), Random(1, 0.5f), 1.0f);
	EmissiveColor = CColor(Random(1, 1.0f), Random(0.6, 0.3f), Random(0.2f, 0.1f), Random(0.7f, 0));
		Time++;
		Scale.X += 0.06f;
		Scale.Y += 1.6f;
		Scale.Z += 0.06f;
		if (Time>5){
			Life = 0;
		}
}
//===========================================カミナリエフェクト3（粒子）============================================================================================
// 効果の初期化13
void CEffect13::Reset() {
	Model = GetModel(L"PARTICLE\\particalee.x");
	//Scale = CVector(1, 1, 1)*0.1f;
	Scale = Random(0.1f, 0.2f)*2;
	Color = CColor(1, 1, 1, 1.0f);
}

// 効果の移動13
void CEffect13::Move() {
	//色
	Color = CColor(Random(1, 1), Random(0.9f, 0.7f), Random(1, 0.5f), 1.0f);
	EmissiveColor = CColor(Random(1, 1.0f), Random(0.6, 0.3f), Random(0.2f, 0.1f), Random(0.7f, 0));
	//MOVE
	Position += Velocity;
	Velocity.Y -= 0.025f;
	if (Position.Y<0) Position.Y = 0, Velocity.Y *= -0.9f;
	Scale *= 0.9f;
	if (Scale.X<0.01f) Life = 0;
}
//===========================================カミナリエフェクト4（場所）============================================================================================
// 効果の初期化14
void CEffect14::Reset() {
	Model = GetModel(L"VOLT\\volt2.x");
	Scale = CVector(1, 0.02f, 1)*SCALE;//1.2
	Color = CColor(1, 1, 1, 0.0f);
}

// 効果の移動14
void CEffect14::Move() {
	//色
	Color = CColor(Random(1, 1), Random(0.9f, 0.7f), Random(0.7f, 0.5f), W*0.15f);
	EmissiveColor = CColor(Random(1.0f, 1.0f), Random(0.7f, 0.5f), Random(0.2f, 0.1f), Random(0.001f + W,0.04f));
		W += 0.0025f;
		SCALE += 0.013f;
		Scale = CVector(1, 0.02f, 1)*SCALE;
		Time++;
		if (Time==90){
			//自機がいるときだけ
			if (myship_death == myship_death_off){
				Volt();//雷音
			}
			Life = 0;
			New<CEffect_volt_position>(Position+CVector(0, 105, 0));
		}
}
//===========================================カミナリエフェクト5（生成機核）============================================================================================
// 効果の初期化15
void CEffect15::Reset() {
	Model = GetModel(L"PARTICLE\\particalee.x");
	Scale = CVector(1, 1, 1)*0.52f;
	Color = CColor(1, 1, 1, 1.0f);
	W = 0.07f;
}

// 効果の移動15
void CEffect15::Move() {
		//色
		EmissiveColor = CColor(Random(1.0f, 1.0f), Random(1.0f, 0.6f), Random(0.4f, 0.6f), W);
	
	Effect_thunder_machineryList.Apply([&](CMover* E){
		Position = E->Position;
	});
}
//===========================================ダメージエフェクト（自機ダメージ：棘）============================================================================================
// 効果の初期化16
void CEffect16::Reset() {
	//Model = GetModel(L"DAMAGE\\damage.x");
	Texture = GetTexture(L"DAMAGE\\damage2\\damage0000.png");
	Scale = CVector(1, 1, 1)*1.0f;
	Color = CColor(1, 1, 1, 0.2f);
	EFFECT_TIME = 30;
	POSITION_Y = -0.6;//-0.54f
}

// 効果の移動16
void CEffect16::Move() {
	if (Time % EFFECT_TIME == 0)Texture = GetTexture(L"DAMAGE\\damage2\\damage0000.png");
	if (Time % EFFECT_TIME == 1)Texture = GetTexture(L"DAMAGE\\damage2\\damage0001.png");
	if (Time % EFFECT_TIME == 2)Texture = GetTexture(L"DAMAGE\\damage2\\damage0002.png");
	if (Time % EFFECT_TIME == 3)Texture = GetTexture(L"DAMAGE\\damage2\\damage0003.png");
	if (Time % EFFECT_TIME == 4)Texture = GetTexture(L"DAMAGE\\damage2\\damage0004.png");
	if (Time % EFFECT_TIME == 5)Texture = GetTexture(L"DAMAGE\\damage2\\damage0005.png");
	if (Time % EFFECT_TIME == 6)Texture = GetTexture(L"DAMAGE\\damage2\\damage0006.png");
	if (Time % EFFECT_TIME == 7)Texture = GetTexture(L"DAMAGE\\damage2\\damage0007.png");
	if (Time % EFFECT_TIME == 8)Texture = GetTexture(L"DAMAGE\\damage2\\damage0008.png");
	if (Time % EFFECT_TIME == 9)Texture = GetTexture(L"DAMAGE\\damage2\\damage0009.png");
	if (Time % EFFECT_TIME == 10)Texture = GetTexture(L"DAMAGE\\damage2\\damage0010.png");
	if (Time % EFFECT_TIME == 11)Texture = GetTexture(L"DAMAGE\\damage2\\damage0011.png");
	if (Time % EFFECT_TIME == 12)Texture = GetTexture(L"DAMAGE\\damage2\\damage0012.png");
	if (Time % EFFECT_TIME == 13)Texture = GetTexture(L"DAMAGE\\damage2\\damage0013.png");
	if (Time % EFFECT_TIME == 14)Texture = GetTexture(L"DAMAGE\\damage2\\damage0014.png");
	if (Time % EFFECT_TIME == 15)Texture = GetTexture(L"DAMAGE\\damage2\\damage0015.png");
	if (Time % EFFECT_TIME == 16)Texture = GetTexture(L"DAMAGE\\damage2\\damage0016.png");
	if (Time % EFFECT_TIME == 17)Texture = GetTexture(L"DAMAGE\\damage2\\damage0017.png");
	if (Time % EFFECT_TIME == 18)Texture = GetTexture(L"DAMAGE\\damage2\\damage0018.png");
	if (Time % EFFECT_TIME == 19)Texture = GetTexture(L"DAMAGE\\damage2\\damage0019.png");
	if (Time % EFFECT_TIME == 20)Texture = GetTexture(L"DAMAGE\\damage2\\damage0020.png");
	if (Time % EFFECT_TIME == 21)Texture = GetTexture(L"DAMAGE\\damage2\\damage0021.png");
	if (Time % EFFECT_TIME == 22)Texture = GetTexture(L"DAMAGE\\damage2\\damage0022.png");
	if (Time % EFFECT_TIME == 23)Texture = GetTexture(L"DAMAGE\\damage2\\damage0023.png");
	if (Time % EFFECT_TIME == 24)Texture = GetTexture(L"DAMAGE\\damage2\\damage0024.png");
	if (Time % EFFECT_TIME == 25)Texture = GetTexture(L"DAMAGE\\damage2\\damage0025.png");
	if (Time % EFFECT_TIME == 26)Texture = GetTexture(L"DAMAGE\\damage2\\damage0026.png");
	if (Time % EFFECT_TIME == 27)Texture = GetTexture(L"DAMAGE\\damage2\\damage0027.png");
	if (Time % EFFECT_TIME == 28)Texture = GetTexture(L"DAMAGE\\damage2\\damage0028.png");
	if (Time % EFFECT_TIME == 29){ Life = 0; }
	Scale = CVector(1, 1, 1)*6.5f;//8
	Color = CColor(1, 1, 1, 0.2f);
	Time++;
	//色
	EmissiveColor = CColor(Random(1.0f, 1.0f), Random(0.3f, 0.7f), Random(0.1f, 0.1f), 0.15f);
	MyShipList.Apply([&](CMover* m){
		Position = m->Position + CVector(0, POSITION_Y, 0);
	});
}
//===========================================ダメージエフェクト2（自機ダメージ2:球）============================================================================================
// 効果の初期化17
void CEffect17::Reset() {
	Scale = CVector(1, 1, 1)*0.7f;
	Texture = GetTexture(L"effect\\bakuhatu0001.png");
	EFFECT_TIME = 30;
	Scale = CVector(1, 1, 1)*1.0f;
	POSITION_Y = -0.6;//-0.54f
}

// 効果の移動17
void CEffect17::Move() {
		if (Time % EFFECT_TIME == 0)Texture = GetTexture(L"DAMAGE\\damage000000.png");
		if (Time % EFFECT_TIME == 1)Texture = GetTexture(L"DAMAGE\\damage000001.png");
		if (Time % EFFECT_TIME == 2)Texture = GetTexture(L"DAMAGE\\damage000002.png");
		if (Time % EFFECT_TIME == 3)Texture = GetTexture(L"DAMAGE\\damage000003.png");
		if (Time % EFFECT_TIME == 4)Texture = GetTexture(L"DAMAGE\\damage000004.png");
		if (Time % EFFECT_TIME == 5)Texture = GetTexture(L"DAMAGE\\damage000005.png");
		if (Time % EFFECT_TIME == 6)Texture = GetTexture(L"DAMAGE\\damage000006.png");
		if (Time % EFFECT_TIME == 7)Texture = GetTexture(L"DAMAGE\\damage000007.png");
		if (Time % EFFECT_TIME == 8)Texture = GetTexture(L"DAMAGE\\damage000008.png");
		if (Time % EFFECT_TIME == 9)Texture = GetTexture(L"DAMAGE\\damage000009.png");
		if (Time % EFFECT_TIME == 10)Texture = GetTexture(L"DAMAGE\\damage000010.png");
		if (Time % EFFECT_TIME == 11)Texture = GetTexture(L"DAMAGE\\damage000011.png");
		if (Time % EFFECT_TIME == 12)Texture = GetTexture(L"DAMAGE\\damage000012.png");
		if (Time % EFFECT_TIME == 13)Texture = GetTexture(L"DAMAGE\\damage000013.png");
		if (Time % EFFECT_TIME == 14)Texture = GetTexture(L"DAMAGE\\damage000014.png");
		if (Time % EFFECT_TIME == 15)Texture = GetTexture(L"DAMAGE\\damage000015.png");
		if (Time % EFFECT_TIME == 16)Texture = GetTexture(L"DAMAGE\\damage000016.png");
		if (Time % EFFECT_TIME == 17)Texture = GetTexture(L"DAMAGE\\damage000017.png");
		if (Time % EFFECT_TIME == 18)Texture = GetTexture(L"DAMAGE\\damage000018.png");
		if (Time % EFFECT_TIME == 19)Texture = GetTexture(L"DAMAGE\\damage000019.png");
		if (Time % EFFECT_TIME == 20)Texture = GetTexture(L"DAMAGE\\damage000020.png");
		if (Time % EFFECT_TIME == 21)Texture = GetTexture(L"DAMAGE\\damage000021.png");
		if (Time % EFFECT_TIME == 22)Texture = GetTexture(L"DAMAGE\\damage000022.png");
		if (Time % EFFECT_TIME == 23)Texture = GetTexture(L"DAMAGE\\damage000023.png");
		if (Time % EFFECT_TIME == 24)Texture = GetTexture(L"DAMAGE\\damage000024.png");
		if (Time % EFFECT_TIME == 25)Texture = GetTexture(L"DAMAGE\\damage000025.png");
		if (Time % EFFECT_TIME == 26)Texture = GetTexture(L"DAMAGE\\damage000026.png");
		if (Time % EFFECT_TIME == 27)Texture = GetTexture(L"DAMAGE\\damage000027.png");
		if (Time % EFFECT_TIME == 28)Texture = GetTexture(L"DAMAGE\\damage000028.png");
		if (Time % EFFECT_TIME == 29){ Life = 0; }
		Scale = CVector(1, 1, 1)*3.5f;//3
		Color = CColor(1, 1, 1, 1.0f);
		Time++;
		//色
		EmissiveColor = CColor(Random(1.0f, 1.0f), Random(0.2f, 0.2f), Random(0.1f, 0.1f), 0.8f);
		MyShipList.Apply([&](CMover* m){
			Position = m->Position + CVector(0, POSITION_Y, 0);
		});
}
//===========================================ダメージエフェクト3（自機ダメージ3：粒子）============================================================================================
// 効果の初期化18
void CEffect18::Reset() {
	Model = GetModel(L"PARTICLE\\particalee.x");
	//Scale = CVector(1, 1, 1)*0.1f;
	Scale = Random(0.1f, 0.2f) * 1;
	Color = CColor(1, 1, 1, 1.0f);
}

// 効果の移動18
void CEffect18::Move() {
	//色
	Color = CColor(Random(1, 1), Random(0.9f, 0.7f), Random(1, 0.5f), 1.0f);
	EmissiveColor = CColor(Random(1, 1.0f), Random(0.3, 0.3f), Random(0.2f, 0.1f), Random(0.8f, 0.3f));
	//MOVE
	Position += Velocity;
	Velocity.Y -= 0.07f;//0.06f(ダメージ過度)
	if (Position.Y<0) Position.Y = 0, Velocity.Y *= -0.86f;
	Scale *= 0.82f;//0.72(ダメージ過度)
	if (Scale.X<0.01f) Life = 0;
}
//===========================================ダメージエフェクト4（自機ダメージ4：炎）============================================================================================
// 効果の初期化19
void CEffect19::Reset() {
	Scale = CVector(1, 1, 1)*0.7f;
	Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom0.png");
	EFFECT_TIME = 11;
	Scale = CVector(1, 1, 1)*1.0f;
	POSITION_Y = -0.6;//-0.54f
}

// 効果の移動19
void CEffect19::Move() {
	if (Time % EFFECT_TIME == 0)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom0.png");
	if (Time % EFFECT_TIME == 1)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom1.png");
	if (Time % EFFECT_TIME == 2)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom2.png");
	if (Time % EFFECT_TIME == 3)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom3.png");
	if (Time % EFFECT_TIME == 4)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom4.png");
	if (Time % EFFECT_TIME == 5)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom5.png");
	if (Time % EFFECT_TIME == 6)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom6.png");
	if (Time % EFFECT_TIME == 7)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom7.png");
	if (Time % EFFECT_TIME == 8)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom8.png");
	if (Time % EFFECT_TIME == 9)Texture = GetTexture(L"DAMAGE_BOOM_EFFECT\\damage_boom9.png");
	if (Time % EFFECT_TIME == 10){ Life = 0; }
	Scale = CVector(1, 1, 1)*4.5f;//4.5
	Color = CColor(1, 1, 1, 0.7f);
	Time++;
	//色
	EmissiveColor = CColor(Random(1.0f, 1.0f), Random(0.3f, 0.2f), Random(0.9f, 0.1f), 0.7f);
	MyShipList.Apply([&](CMover* m){
		Position = m->Position + CVector(0, POSITION_Y, 0);
	});
}
//===========================================ダメージエフェクト5（自機ダメージ5：棘球）============================================================================================
// 効果の初期化20
void CEffect20::Reset() {
	//Scale = CVector(1, 1, 1)*0.7f;
	//Model = GetModel(L"DEFAULT_SAMPLE\\sphere.x");
	Model = GetModel(L"DAMAGE\\damage3\\damage3.x");
	Scale = CVector(1, 0.02f, 1)*0.01f;
	Color = CColor(1, 1, 1, 0.01f);
	POSITION_Y = -0.6;//-0.54f
}

// 効果の移動20
void CEffect20::Move() {
	Time++;
	Scale.X += 0.022f;//0.1
	Scale.Y += 0.015f;//0.1
	Scale.Z += 0.022f;//0.1
	if (Time>30){
		Life = 0;
	}
	//色
	EmissiveColor = CColor(Random(1.0f, 5.0f), Random(0.5f, 0.3f), Random(0.2f, 0.1f), 0.4f);
	MyShipList.Apply([&](CMover* m){
		Position = m->Position + CVector(0, POSITION_Y, 0);
	});
}
//===========================================ダメージエフェクト6（自機ダメージ6：球）============================================================================================
// 効果の初期化21
void CEffect21::Reset() {
	Model = GetModel(L"DEFAULT_SAMPLE\\sphere.x");
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(1, 1, 1, 0.01f);
	POSITION_Y = -0.6;//-0.54f
}

// 効果の移動21
void CEffect21::Move() {
	Time++;
	Scale += 0.29f;//0.28
	if (Time > 12){
		Life = 0;
	}
	//色
	EmissiveColor = CColor(Random(1.0f, 5.0f), Random(0.5f, 0.3f), Random(0.2f, 0.1f), 0.3f);
	MyShipList.Apply([&](CMover* m){
		Position = m->Position + CVector(0, POSITION_Y, 0);
	});
}
//===================================================ロックオンマーカー============================================================================================================
// 効果の初期化22
void CEffect22::Reset() {
	Texture = GetTexture(L"LOCK\\LOCK.png");
	Scale = CVector(1.0f, 1.0f, 1.0f)*5.0f;//5
	Life = 2;
	Color = CColor(1, 0, 0, 0.0f);//0.1
}

// 効果の移動22
void CEffect22::Move() {
	if (targetselection == targetselection_off){
		LIGHTNESS = 0;
		LIGHTNESS_2 = 1;
	}
	if (targetselection == targetselection_on){
		LIGHTNESS = 1;
		LIGHTNESS_2 = 0;
	}

	if (weapon_chang == chang_gun){
		if (targetselection == targetselection_off){
			Texture = GetTexture(L"LOCK\\LOCK.png");
			Scale = CVector(1.0f, 1.0f, 1.0f)*3.2f;//5
			if (Owner->State == 0)Color = CColor(1, 1, 1, 0.0f);//0.1  OwnerはBlock
			else if (Owner->State == 1 || Owner->State == 2)Color = CColor(1, 1, 1, 0.0f);
			else if (Owner->State == 3)Color = CColor(1, 0, 0, LIGHTNESS_2);
		}
		if (targetselection == targetselection_on){
			Texture = GetTexture(L"LOCK\\LOCK02.png");
			if (Owner->TargetState == 0){
				Color = CColor(1, 1, 1, 0.0f);
			}
			if (Owner->TargetState == 1){
				Color = CColor(1, 1, 1, LIGHTNESS);
				Scale = CVector(1.0f, 1.0f, 1.0f)*2.5f;
			}
			if (Owner->TargetState == 2 && targetmarker_red ==0){
				Color = CColor(0, 1, 0, LIGHTNESS);
				Scale = CVector(1.0f, 1.0f, 1.0f)*2.5f;
			}
			if (Owner->TargetState == 2 && targetmarker_red == 1){
				Color = CColor(1, 0, 0, LIGHTNESS);
				Scale = CVector(1.0f, 1.0f, 1.0f)*3.8f;
			}
			if (Owner->TargetState == 3){
				Color = CColor(1, 0, 0, 0.0f);
			}
		}
	}
	else if (weapon_chang == chang_blade){
		if (targetselection == targetselection_off){
			Texture = GetTexture(L"LOCK\\LOCK02.png");
			Scale = CVector(1.0f, 1.0f, 1.0f)*3.2f;//5
			if (Owner->State >= 0)Color = CColor(1, 1, 1, 0.0f);//0.1  OwnerはBlock
		}
		if (targetselection == targetselection_on){
			Texture = GetTexture(L"LOCK\\LOCK02.png");
			Scale = CVector(1.0f, 1.0f, 1.0f)*2.5f;
			if (Owner->TargetState == 0){
				Color = CColor(1, 1, 1, 0.0f);
			}
			if (Owner->TargetState == 1){
				Color = CColor(1, 1, 1, LIGHTNESS);
				Scale = CVector(1.0f, 1.0f, 1.0f)*3.2f;
			}
			if (Owner->TargetState == 2 && targetmarker_red == 0){
				Color = CColor(0, 1, 0, LIGHTNESS);
				Scale = CVector(1.0f, 1.0f, 1.0f)*3.8f;
			}
			if (Owner->TargetState == 2 && targetmarker_red == 1){
				Color = CColor(1, 0, 0, LIGHTNESS);
				Scale = CVector(1.0f, 1.0f, 1.0f)*5.0f;
			}
			if (Owner->TargetState == 3){
				Color = CColor(1, 0, 0, 0.0f);
			}
		}
	}

	Position = Owner->Position+CVector(0,0,10)*Owner->Rotation;

	if (Owner->Life<=0){
		Life = 0;
	}
}
//===========================================モニタースイッチマーカー============================================================================================
// モニターONOFFアイコン初期化
void CIcon0::Reset() {
	Texture = GetTexture(L"MONITOR\\ICON.png");
	Scale = CVector(3.8f, 1.0f, 1.0f)*1.0f;//5
	SCALE = 0.7f;
	SCALE2 = 0.02f;
}

// モニターONOFFアイコン移動
void CIcon0::Move() {
	MyShipList.Apply([&](CMover* m){
		MonitorList.Apply([&](CMover* mn){
			Stage_Centergate_LRList.Apply([&](CMover*st){
				Position = m->Position + CVector(0, 4.5f, 0)*Camera->Rotation;
				if (icon0_type != icon0_movie_on&&st->Type==0){
					icon0_type = Length(m->Position - mn->Position) < 10 ? icon0_on : icon0_off;
				}
			});
		});
	});

	if (icon0_type == icon0_on){
		SCALE_TIME++;
		if (SCALE_TIME % 8 == 0){
			if (SCALE > 1.1f)SCALE_COUNT = 1;
			if (SCALE <= 0.7f)SCALE_COUNT = 0;
		}
		if (SCALE_COUNT == 0)SCALE += SCALE2;
		if (SCALE_COUNT == 1)SCALE -= SCALE2;

		Scale = CVector(3.8f, 1.0f, 1.0f)*SCALE;
		Color = CColor(1, 1, 1, 1.0f);
		if (KeyState[0][DIK_SPACE] && !OldKeyState[0][DIK_SPACE]){
			icon0_type = icon0_movie_on;
		}
	}
	if (icon0_type == icon0_off || icon0_type == icon0_movie_on){
		Color = CColor(1, 1, 1, 0.0f);
		SCALE = 0.7f;
	}
}