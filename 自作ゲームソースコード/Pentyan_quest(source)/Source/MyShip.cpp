#include "Main.h"


// 自機の初期化
void CMyShip::Reset() {
	Texture=GetTexture(L"pen-l.png");
	Scale=CVector(1, 1, 1)*0.1f;
	Life = 1000;
}

// 自機の移動
void CMyShip::Move() {
	
	Velocity.X = 0;
	//Velocity.Y -= 0.004f;
	Position += Velocity;

	//ブロックあたり判定
	//CHitCircleAndRotatedRectangle hit(0.1f);
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
	Apply(Block6List, hit);
	Apply(Block7List, hit);
	Apply(Block8List, hit);
	Apply(Block9List, hit);
	Apply(Block10List, hit);
	Apply(Block11List, hit);
	Apply(Block12List, hit);
	Apply(Block13List, hit);
	Apply(Block14List, hit);
	Apply(Block15List, hit);
	Apply(Block16List, hit);
	Apply(Block17List, hit);
	Apply(Block18List, hit);
	Apply(Block19List, hit);
	Apply(Block20List, hit);
	Apply(Block21List, hit);
	Apply(Block22List, hit);
	Apply(Block23List, hit);
	Apply(Block24List, hit);
	Apply(Block25List, hit);
	Apply(Block26List, hit);
	Apply(Block27List, hit);
	Apply(Block28List, hit);
	Apply(Block29List, hit);
	Apply(Block30List, hit);
	Apply(Block31List, hit);
	//Apply(Enemy8List, hit);
	//Apply(Enemy7List, hit);
	Apply(Enemy10List, hit);
	

	//New<CEffect>(Position);//自機にスポット
	//New<CBullet>(Position.XYF(1));//画面暗闇

	//止まっている時アニメーション

	if (pause == 1){
		if (Time % 10 == 0)Texture = GetTexture(L"pen-r1.png");
		if (Time % 20 == 1)Texture = GetTexture(L"pen-r1.png");
		if (Time % 20 == 2)Texture = GetTexture(L"pen-r1.png");
		if (Time % 20 == 3)Texture = GetTexture(L"pen-r2.png");
		if (Time % 20 == 4)Texture = GetTexture(L"pen-r2.png");
		if (Time % 20 == 5)Texture = GetTexture(L"pen-r2.png");
		Time++;
	}

	if (pause == 2){
		if (Time % 10 == 0)Texture = GetTexture(L"pen-l1.png");
		if (Time % 20 == 1)Texture = GetTexture(L"pen-l1.png");
		if (Time % 20 == 2)Texture = GetTexture(L"pen-l1.png");
		if (Time % 20 == 3)Texture = GetTexture(L"pen-l2.png");
		if (Time % 20 == 4)Texture = GetTexture(L"pen-l2.png");
		if (Time % 20 == 5)Texture = GetTexture(L"pen-l2.png");
		Time++;
	}

	//キーごとのアニメーション変更
	//左キー
	if (KeyState[0][DIK_A]) {
		//Velocity.X = -0.02f;
		//Position += KeyState[0].Direction()*0.015f;
		Scale = CVector(1, 1, 1)*0.1f;
		Type = 1;
		pause = 1;
	}
	//右キー
	if (KeyState[0][DIK_D]) {
		//Velocity.X += 0.022f;
		//Position += KeyState[0].Direction()*0.015f;
		//Position += PadState[0].X;
		Scale = CVector(1, 1, 1)*0.1f;
		Type = 2;
		pause = 2;
	}
	//ジャンプ
	/*if (KeyState[0][DIK_UP] && !KeyState[0][DIK_LEFT] && hit.Down) Velocity.Y += 0.022f;
	if (KeyState[0][DIK_UP] && !KeyState[0][DIK_RIGHT] && hit.Down) Velocity.Y += 0.022f;
	if (KeyState[0][DIK_UP] && hit.Down && KeyState[0][DIK_RIGHT]) Velocity.Y = 0.032f;//右移動ジャンプ
	if (KeyState[0][DIK_UP] && hit.Down && KeyState[0][DIK_LEFT]) Velocity.Y = 0.032f;//左移動ジャンプ*/
	//右腹滑り
	if (RW==0&&KeyState[0][DIK_S] && KeyState[0][DIK_D]) {
		Texture = GetTexture(L"pen-l6.png");
		Position += KeyState[0].Direction()*0.02f;
		if (KeyState[0][DIK_W]) Position.Y -= 0.1f;
		Scale = CVector(0.8, 0.6, 1)*0.1f;

		New<CEffect18>(Position);
	}
	//左腹滑り
	if (RW == 0 && KeyState[0][DIK_S] && KeyState[0][DIK_A]) {
		Texture = GetTexture(L"pen-r6.png");
		Position += KeyState[0].Direction()*0.02f;
		if (KeyState[0][DIK_W]) Position.Y -= 0.1f;
		Scale = CVector(0.8, 0.6, 1)*0.1f;

		New<CEffect19>(Position);
	}
	//大きくなる調整
	if (RW == 0 && KeyState[0][DIK_S] && !KeyState[0][DIK_A] && !KeyState[0][DIK_D]) {
		Scale = CVector(1, 1, 1)*0.1f;
	}

	//ショット
	if (syot == 0 && RW==0){
		if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]) {
			if (Type == 1 && !KeyState[0][DIK_S]){
				New<CWeapon>(Position, CVector(-0.05f, 0, 0));
				//New<CWeapon>(Position, CVector(0, 0, 0));
				Texture = GetTexture(L"pen-r3.png");
			}
			if (Type == 2 && !KeyState[0][DIK_S]){
				New<CWeapon>(Position, CVector(0.05f, 0, 0));
				Texture = GetTexture(L"pen-l3.png");
			}
		}
	}
	//爆弾

	if (syot == 1 && RW==0){
		if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]) {
			if (Type == 1 && !KeyState[0][DIK_S]){
				New<CWeapon2>(Position, CVector(-0.03f, 0.00, 0));
				Texture = GetTexture(L"pen-r3.png");
				bom++;

			}
			if (Type == 2 && !KeyState[0][DIK_S]){
				New<CWeapon2>(Position, CVector(0.03f, 0.00f, 0));
				Texture = GetTexture(L"pen-l3.png");
				bom++;
			}
		}

	}

	//桃ブーメラン
	if (syot == 2 && RW==0){
		if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]) {
			if (Type == 1 && !KeyState[0][DIK_S]){
				New<CWeapon7>(Position, 2, RotationZ(0.160f));
				Texture = GetTexture(L"pen-r3.png");
			}
			if (Type == 2 && !KeyState[0][DIK_S]){
				New<CWeapon7>(Position, 0, RotationZ(-0.160f));
				Texture = GetTexture(L"pen-l3.png");
			}
		}

	}

	//ショット中の手の表示
	if (Type == 1 && !KeyState[0][DIK_S] && MouseState[0].Button[0] && !OldMouseState[0].Button[0] && !KeyState[0][DIK_W]){
		Texture = GetTexture(L"pen-r3.png");
	}
	if (Type == 2 && !KeyState[0][DIK_S] && MouseState[0].Button[0] && !OldMouseState[0].Button[0] && !KeyState[0][DIK_W]){
		Texture = GetTexture(L"pen-l3.png");
	}
	//爆弾設置中の手の表示
	if (Type == 1 && !KeyState[0][DIK_S] && KeyState[0][DIK_R] && !KeyState[0][DIK_A] && !KeyState[0][DIK_W]){
		Texture = GetTexture(L"pen-r3.png");
	}
	if (Type == 2 && !KeyState[0][DIK_S] && KeyState[0][DIK_R] && !KeyState[0][DIK_D] && !KeyState[0][DIK_W]){
		Texture = GetTexture(L"pen-l3.png");
	}



	//ブロックタイプ選択
	if (MouseState[0].Button[2] && !OldMouseState[0].Button[2] && BT<3) { BT += 1; }
	if (BT==3) {BT = 0;}

	//ブロックセット
	if (BP < 0)BP = 0;
	//ブロックDOWN
	if (RW==0 && BT == 0){
		if (MouseState[0].Button[1] && !OldMouseState[0].Button[1] && BP < 5) {
			if (Type == 1 && !MouseState[0].Button[2] && BP < 5){
				New<CBlock2>(Position + CVector(-0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-r4.png");
				BP++;
			}
			if (Type == 2 && !MouseState[0].Button[2] && BP < 5){
				New<CBlock2>(Position + CVector(0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-l4.png");
				BP++;
			}
		}
	}
	//ブロックRIGHT
	if (RW == 0 && BT == 1){
		if (MouseState[0].Button[1] && !OldMouseState[0].Button[1] && BP < 5) {
			if (Type == 1 && !MouseState[0].Button[2] && BP < 7){
				New<CBlock6>(Position + CVector(-0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-r4.png");
				BP++;
			}
			if (Type == 2 && !MouseState[0].Button[2] && BP < 5){
				New<CBlock6>(Position + CVector(0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-l4.png");
				BP++;
			}
		}
	}
	//ブロックLEFT
	if (RW == 0 && BT == 2){
		if (MouseState[0].Button[1] && !OldMouseState[0].Button[1] && BP < 5) {
			if (Type == 1 && !MouseState[0].Button[2]&& BP < 7){
				New<CBlock7>(Position + CVector(-0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-r4.png");
				BP++;
			}
			if (Type == 2 && !MouseState[0].Button[2] && BP < 5){
				New<CBlock7>(Position + CVector(0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-l4.png");
				BP++;
			}
		}
	}

	//ブロックブレイク
		//ブレイクDOWN
	if (BP>0){
		if (KeyState[0][DIK_SPACE] && BP > 0 && Type == 2){
			Texture = GetTexture(L"pen-l5.png");
			Time++;
			Block2List.Apply([&](CMover* b) {
				b->Life = 0;
				//BP = 0;
				if (b->Life == 0) { New<CEffect3>(b->Position); }
			});
		}
		if (KeyState[0][DIK_SPACE] && BP > 0 && Type == 1){
			Texture = GetTexture(L"pen-r5.png");
			Time++;
			Block2List.Apply([&](CMover* b) {
				b->Life = 0;
				//BP = 0;
				if (b->Life == 0) { New<CEffect3>(b->Position); }
			});
		}

		//ブレイクRIGHT
		if (KeyState[0][DIK_SPACE] && BP > 0 && Type == 2){
			Texture = GetTexture(L"pen-l5.png");
			Time++;
			Block6List.Apply([&](CMover* r) {
				r->Life = 0;
				//BP = 0;
				if (r->Life == 0) { New<CEffect3>(r->Position); }
			});
		}
		if (KeyState[0][DIK_SPACE] && BP > 0 && Type == 1){
			Texture = GetTexture(L"pen-r5.png");
			Time++;
			Block6List.Apply([&](CMover* r) {
				r->Life = 0;
				//BP = 0;
				if (r->Life == 0) { New<CEffect3>(r->Position); }
			});
		}
		//ブレイクLEFT
		if (KeyState[0][DIK_SPACE] && BP > 0 && Type == 2){
			Texture = GetTexture(L"pen-l5.png");
			Time++;
			Block7List.Apply([&](CMover* l) {
				l->Life = 0;
				//BP = 0;
				if (l->Life == 0) { New<CEffect3>(l->Position); }
			});
		}
		if (KeyState[0][DIK_SPACE] && BP > 0 && Type == 1){
			Texture = GetTexture(L"pen-r5.png");
			Time++;
			Block7List.Apply([&](CMover* l) {
				l->Life = 0;
				//BP = 0;
				if (l->Life == 0) { New<CEffect3>(l->Position); }
			});
		}
		if (KeyState[0][DIK_SPACE]){
			BP = 0;
		}
	}
	
	//敵と接触時
	EnemyList.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.1f) {
			//e->Life = 0;
			//Life--;
			//Score += 100;
		}
	});
	//BOSS接触時
	Enemy2List.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.1f) {
			Life-=0.01f;
			//Score += 100;
		}
	});

	//タイ焼き
	Enemy3List.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.1f) {
			Life-=0.001f;
		}
	});

	//爆弾野郎
	Enemy5List.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.1f) {
			Life -= 100;
			e->Life = 0;
			New<CEffect7>(e->Position);
		}
	});

	//敵あたり判定
	Apply(Enemy2List, hit);

	//アイテム取得
	//ハート
	ItemList.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			//ハートゲット
			GetWave(L"b_090.wav")->Play(1);
			GetWave(L"b_090.wav")->SetVolume(0.07f);
			i->Life = 0;
			Life += 800;
			Score += 80;
		}
	});

	//ステージカメラ移動(寿司)
	Item11List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			CS = 1;
			//i->Life = 0;
		}
	});

	//ステージカメラ反転（緑上i）
	Item12List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			TT = 1;
			//BRR == 1;
			//i->Life = 0;
		}
	});

	//ステージカメラ反転（青上o）
	Item13List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			TT = 0;
			//BRR = 0;
			//i->Life = 0;
		}
	});

	//氷弾アイテム
	Item7List.Apply([&](CMover* h) {
		if (Length(h->Position - Position) < 0.1f) {
			//weaponゲット
			GetWave(L"se_maoudamashii_onepoint26.wav")->Play(1);
			GetWave(L"se_maoudamashii_onepoint26.wav")->SetVolume(0.07f);
			syot = 0;
			SI = 0;
			h->Life = 0;
		}
	});

	//爆弾アイテム
	Item6List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			//weaponゲット
			GetWave(L"se_maoudamashii_onepoint26.wav")->Play(1);
			GetWave(L"se_maoudamashii_onepoint26.wav")->SetVolume(0.07f);
			syot = 1;
			SI = 1;
			i->Life = 0;
		}
	});

	//桃ブーメランアイテム
	Item10List.Apply([&](CMover* h) {
		if (Length(h->Position - Position) < 0.1f) {
			//weaponゲット
			GetWave(L"se_maoudamashii_onepoint26.wav")->Play(1);
			GetWave(L"se_maoudamashii_onepoint26.wav")->SetVolume(0.07f);
			syot = 2;
			SI = 2;
			h->Life = 0;
		}
	});

	//暗闇スイッチ
	Item1List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			i->Life = 0;
			kura = 1;
		}

	});
	//ダメージアイテム(キノコ)
	Item3List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			//キノコゲット
			GetWave(L"se_maoudamashii_onepoint13.wav")->Play(1);
			GetWave(L"se_maoudamashii_onepoint13.wav")->SetVolume(0.07f);
			i->Life = 0;
			Life -= 100;
			Score += 200;
		}
	});

	if (kura == 1){
		New<CEffect>(Position);//自機にスポット
		New<CBullet>(Position.XYF(1));//画面暗闇
	}

	//明るくスイッチ
	Item2List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			i->Life = 0;
			kura = 0;
		}

	});

//ステージ移動
	//1～2
	Item5List.Apply([&](CMover* i) {
		if (Length(Position - i->Position)<0.05f) {
			//ゲートタッチ
			GetWave(L"b_046.wav")->Play(1);
			GetWave(L"b_046.wav")->SetVolume(0.08f);
			StageList.Apply([&](CMover* s) {
				CP = 1;
				if (s->Type == 1) {
					s->Type =2;
					s->Reset();
					BP = 0;
				}
			});
		}
	});
	//2～3
	Item8List.Apply([&](CMover* i) {
		SI = 0;
		if (Length(Position - i->Position)<0.05f) {
			//ゲートタッチ
			GetWave(L"b_046.wav")->Play(1);
			GetWave(L"b_046.wav")->SetVolume(0.08f);
			StageList.Apply([&](CMover* s) {
				CS = 3;
				if (s->Type == 2) {
					s->Type = 3;
					s->Reset();
					BP = 0;
				}
			});
		}
	});
	//3～4
	Item9List.Apply([&](CMover* i) {
		if (Length(Position - i->Position)<0.05f) {
			//ゲートタッチ
			GetWave(L"b_046.wav")->Play(1);
			GetWave(L"b_046.wav")->SetVolume(0.08f);
			StageList.Apply([&](CMover* s) {
				CP = 0;
				if (s->Type == 2) {
					s->Type = 3;
					s->Reset();
				}
			});
		}
	});


	//ライフと無敵時間
	//敵
	if (State == 0) {
		EnemyList.Apply([&](CMover* e) {
			if (Length(Position - e->Position) < 0.1f) {
				//Life--;
				State = 1;
				MutekiTime = 0;
				Color.A = 0.3f;
			}
		});
		Enemy8List.Apply([&](CMover* e) {
			if (Length(Position - e->Position) < 0.45f) {
				//Life--;
				State = 1;
				MutekiTime = 0;
				Color.A = 0.3f;
			}
		});
		Weapon12List.Apply([&](CMover* e) {
			if (Length(Position - e->Position) < 0.2f) {
				//Life--;
				State = 1;
				MutekiTime = 0;
				Color.A = 0.3f;
			}
		});
	}
	//タイ焼き
	if (State == 0) {
		Enemy3List.Apply([&](CMover* e) {
			if (Length(Position - e->Position) < 0.1f) {
				Life--;
				State = 1;
				MutekiTime = 0;
				Color.A = 0.3f;
			}
		});
	}
	//爆弾野郎
	if(State == 0) {
		Enemy5List.Apply([&](CMover* e) {
			if (Length(Position - e->Position) < 0.1f) {
				Life--;
				State = 1;
				MutekiTime = 0;
				Color.A = 0.3f;
			}
		});
	}
	//フォーク
	if (State == 0) {
		Weapon3List.Apply([&](CMover* w) {
			if (Length(Position - w->Position) < 0.2f) {
				//Life--;
				State = 1;
				MutekiTime = 0;
				Color.A = 0.3f;
			}
		});
	}
	//星クッキー
	if (State == 0) {
		Weapon4List.Apply([&](CMover* w) {
			if (Length(Position - w->Position) < 0.3f) {
				Life++;
				State = 1;
				MutekiTime = 0;
				Color.A = 0.3f;
			}
		});
	}

	if (State == 1) {
		MutekiTime++;
		if (MutekiTime == 100) {
			Color.A = 1;
			State = 0;
		}
	}

	//リセット時BP0
	if (KeyState[0][DIK_C]){
		Texture = GetTexture(L"pen-l3.png");
		BP = 0;
	}
	
	//召喚ブロック右・左自動移動あたり判定
	Block6List.Apply([&](CMover* b) {
		if (Length(Position - b->Position)<0.25f) {
			Position += b->Velocity;
		}
	});

	Block7List.Apply([&](CMover* b) {
		if (Length(Position - b->Position)<0.26f) {
			Position += b->Velocity;
		}
	});

//---------------------------------------------------------------------------------------
//エンターキーを押すと反転
	if (KeyState[0][DIK_A]) Velocity.X = -0.02f;
	if (KeyState[0][DIK_D]) Velocity.X = 0.02f;
	if (state1 == 1) Velocity.X *= -1;

	if (state1 == 0) Velocity.Y -= 0.002f;
	if (state1 == 1) Velocity.Y += 0.002f;
	Position += Velocity;

	//自キャラジャンプ
	if (state1 == 0 && hit.Down && KeyState[0][DIK_W]) {
		Velocity.Y = 0.02f;
		//JUMP
		GetWave(L"jump_2.wav")->Play(1);
		GetWave(L"jump_2.wav")->SetVolume(0.07f);
		
	}
	if (state1 == 1 && hit.Up && KeyState[0][DIK_W]) {
		Velocity.Y = -0.02f;
		//JUMP
		GetWave(L"jump_2.wav")->Play(1);
		GetWave(L"jump_2.wav")->SetVolume(0.07f);
	}

	//-----------------------------------------------------------------------------
		//反転
		/*if (RW==0 && KeyState[0][DIK_RETURN] && !OldKeyState[0][DIK_RETURN]) {
			state1 = 1-state1;
			RW = 1;
		}*/

		if (RW == 0 && TT==1) {
			state1 = 1 - state1;
			RW = 1;
		}
		//正常化
		/*if (RW == 1 && KeyState[0][DIK_W] && !OldKeyState[0][DIK_W]){
			state1 = 1 - state1; 
			RW = 0;
		}*/
		if (RW == 1 && TT == 0) {
			state1 = 1 - state1;
			RW = 0;
		}
	
		
		if (RW == 1){
			Rotation = RotationZ(0.5f*state1);
			Camera->Rotation.Interpolate(Rotation, 0.1f);
		}
		if (RW == 0){
			Rotation = RotationZ(0.5f*state1);
			Camera->Rotation.Interpolate(Rotation, 0.1f);
		}

	//---------------------------------------------------------------------------------
	if (RW == 1){
		//ショット
		if (syot == 0 && RW==1){
			if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]) {
				if (Type == 1 && !KeyState[0][DIK_S]){
					New<CWeapon>(Position, CVector(0.05f, 0, 0));
					Texture = GetTexture(L"pen-r3.png");
				}
				if (Type == 2 && !KeyState[0][DIK_S]){
					New<CWeapon>(Position, CVector(-0.05f, 0, 0));
					Texture = GetTexture(L"pen-l3.png");
				}
			}
		}
		//爆弾

		if (syot == 1 && RW==1){
			if (MouseState[0].Button[1] && !OldMouseState[0].Button[1]) {
				if (Type == 1 && !KeyState[0][DIK_S]){
					New<CWeapon2>(Position, CVector(0.03f, 0.00, 0));
					Texture = GetTexture(L"pen-r3.png");
					bom++;

				}
				if (Type == 2 && !KeyState[0][DIK_S]){
					New<CWeapon2>(Position, CVector(-0.03f, 0.00f, 0));
					Texture = GetTexture(L"pen-l3.png");
					bom++;
				}
			}

		}

		//桃ブーメラン
		if (syot == 2 && RW==1){
			if (MouseState[0].Button[1] && !OldMouseState[0].Button[1]) {
				if (Type == 1 && !KeyState[0][DIK_S]){
					New<CWeapon7>(Position, 2, RotationZ(-0.160f));
					Texture = GetTexture(L"pen-r3.png");
				}
				if (Type == 2 && !KeyState[0][DIK_S]){
					New<CWeapon7>(Position, 0, RotationZ(0.160f));
					Texture = GetTexture(L"pen-l3.png");
				}
			}

		}
	}

	//	Camera->Rotation=Rotation;

	//右腹滑り
	if (RW == 1 && KeyState[0][DIK_S] && KeyState[0][DIK_D]) {
		Texture = GetTexture(L"pen-l6.png");
		Position -= KeyState[0].Direction()*0.02f;
		if (KeyState[0][DIK_W]) Position.Y -= 0.1f;
		Scale = CVector(0.8, 0.6, 1)*0.1f;
	}
	//左腹滑り
	if (RW == 1 && KeyState[0][DIK_S] && KeyState[0][DIK_A]) {
		Texture = GetTexture(L"pen-r6.png");
		Position -= KeyState[0].Direction()*0.02f;
		if (KeyState[0][DIK_W]) Position.Y -= 0.1f;
		Scale = CVector(0.8, 0.6, 1)*0.1f;
	}
	//大きくなる調整
	if (RW == 1 && KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A]) {
		Scale = CVector(1, 1, 1)*0.1f;
	}

	//ブロックDOWN
	if (RW == 1 && BT == 0){
		if (MouseState[0].Button[1] && !OldMouseState[0].Button[1] && BP < 5) {
			if (Type == 1 && !MouseState[0].Button[2] && BP < 5){
				New<CBlock2>(Position + CVector(0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-r4.png");
				BP++;
			}
			if (Type == 2 && !MouseState[0].Button[2] && BP < 5){
				New<CBlock2>(Position + CVector(-0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-l4.png");
				BP++;
			}
		}
	}
	//ブロックRIGHT
	if (RW == 1 && BT == 1){
		if (MouseState[0].Button[1] && !OldMouseState[0].Button[1] && BP < 5) {
			if (Type == 1 && !MouseState[0].Button[2] && BP < 7){
				New<CBlock6>(Position + CVector(0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-r4.png");
				BP++;
			}
			if (Type == 2 && !MouseState[0].Button[2] && BP < 5){
				New<CBlock6>(Position + CVector(-0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-l4.png");
				BP++;
			}
		}
	}
	//ブロックLEFT
	if (RW == 1 && BT == 2){
		if (MouseState[0].Button[1] && !OldMouseState[0].Button[1] && BP < 5) {
			if (Type == 1 && !MouseState[0].Button[2] && BP < 7){
				New<CBlock7>(Position + CVector(0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-r4.png");
				BP++;
			}
			if (Type == 2 && !MouseState[0].Button[2] && BP < 5){
				New<CBlock7>(Position + CVector(-0.2f, 0.01f, 0));
				Texture = GetTexture(L"pen-l4.png");
				BP++;
			}
		}
	}



	/*if (KeyState[0][DIK_X] && !OldKeyState[0][DIK_X]&&kurima<3){
		New<CBullet1>(Position+ CVector(0.2f, 0, 0));
		kurima++;
	}*/
	if (KeyState[0][DIK_SPACE] && !OldKeyState[0][DIK_SPACE]){
		kurima = 0;
		Bullet1List.Apply([&](CMover* b) {
			b->Life = 0;
		});
		Weapon11List.Apply([&](CMover* b) {
			b->Life = 0;
		});
		Effect21List.Apply([&](CMover* b) {
			b->Life = 0;
		});
	}


	








}


