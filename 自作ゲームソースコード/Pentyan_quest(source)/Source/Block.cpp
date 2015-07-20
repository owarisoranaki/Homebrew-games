#include "Main.h"


// ブロックの初期化
void CBlock::Reset() {
	Texture=GetTexture(L"Block0.png");
	Scale=CVector(1, 1, 1)*0.1f;
}

void CBlock1::Reset() {
	Life = 100;//10回で壊れる
	Scale = CVector(1, 1, 1)*0.15f;
}

void CBlock2::Reset() {
	//氷召喚
	GetWave(L"se_maoudamashii_element_ice02.wav")->Play(1);
	GetWave(L"se_maoudamashii_element_ice02.wav")->SetVolume(0.07f);

	//Texture = GetTexture(L"Block_D.png");
	Scale = CVector(1, 1, 1)*0.1f;

	Life = 20;//2回以下で壊れる

}

void CBlock3::Reset() {

	Texture = GetTexture(L"Block_kasi2.png");
	Scale = CVector(1, 1, 1)*0.1f;

}

void CBlock4::Reset() {

	Texture = GetTexture(L"toge1.png");
	Scale = CVector(1, 1, 1)*0.1f;

}

void CBlock5::Reset() {

	Texture = GetTexture(L"Block_kasi1.png");
	Scale = CVector(1, 1, 1)*0.1f;

}

void CBlock6::Reset() {
	Texture = GetTexture(L"Block_R.png");
	Scale = CVector(1, 1, 1)*0.1f;

	Life = 20;//2回以下で壊れる

}
void CBlock7::Reset() {
	Texture = GetTexture(L"Block_L.png");
	Scale = CVector(1, 1, 1)*0.1f;

	Life = 20;//2回以下で壊れる

}
void CBlock8::Reset() {
	Texture = GetTexture(L"Block_kasi1.png");
	Scale = CVector(1, 1, 1)*0.1f;
}

void CBlock9::Reset() {
	Texture = GetTexture(L"Block_kasi2.png");
	Scale = CVector(1, 1, 1)*0.1f;
}

void CBlock10::Reset() {
	Texture = GetTexture(L"Block_kasi3.png");
	Scale = CVector(1, 1, 1)*0.1f;
}

void CBlock11::Reset() {
	Texture = GetTexture(L"Block_kasi4.png");
	Scale = CVector(1, 1, 1)*0.1f;
}

void CBlock12::Reset() {
	Texture = GetTexture(L"Block_sui1.png");
	Scale = CVector(1, 1, 1)*0.1f;
}

void CBlock13::Reset() {
	Texture = GetTexture(L"Block_sui2.png");
	Scale = CVector(1, 1, 1)*0.1f;
}
void CBlock14::Reset() {
	if (CS != 3 || CS != 4){
		Texture = GetTexture(L"Block_sui3.png");
		Color = CColor(1, 1, 1, 1);
	}

	if (CS == 3 || CS == 4){
		Texture = GetTexture(L"Block_sui3.png");
		Color = CColor(1, 0, 0, 1);
	}
	Scale = CVector(1, 1, 1)*0.1f;
}
void CBlock15::Reset() {
	if (CS != 3 || CS != 4){
		Texture = GetTexture(L"Block_sui4.png");
		Color = CColor(1, 1, 1, 1);
	}

	if (CS == 3 || CS == 4){
		Texture = GetTexture(L"Block_sui4.png");
		Color = CColor(1, 0, 0, 1);
	}
	Scale = CVector(1, 1, 1)*0.1f;
}

void CBlock16::Reset() {
	Texture = GetTexture(L"Block_kasi1_1.png");
	Scale = CVector(1, 1, 1)*0.1f;
}

void CBlock17::Reset() {
	Texture = GetTexture(L"Block_kasi2_1.png");
	Scale = CVector(1, 1, 1)*0.1f;
}
void CBlock18::Reset() {
	Texture = GetTexture(L"Block_kasi3_1.png");
	Scale = CVector(1, 1, 1)*0.1f;
}
void CBlock19::Reset() {
	Texture = GetTexture(L"Block_kasi4_1.png");
	Scale = CVector(1, 1, 1)*0.1f;
}
void CBlock20::Reset() {
	Texture = GetTexture(L"ke-ki.png");
	Scale = CVector(1, 1, 1)*0.18f;
}
void CBlock21::Reset() {
	Texture = GetTexture(L"fork0.png");
}
void CBlock22::Reset() {
	Texture = GetTexture(L"Block_akasiro.png");
	Scale = CVector(0.7f, 2.0f, 1)*0.1f;
}
void CBlock23::Reset() {
	Texture = GetTexture(L"Block_akasiro1.png");
	Scale = CVector(3, 0.6f, 1)*0.1f;
}
void CBlock24::Reset() {
	Texture = GetTexture(L"taihou.png");
	Scale = CVector(1, 1, 1)*0.1f;
}
void CBlock25::Reset() {
	Texture = GetTexture(L"Block_R1.png");
	Scale = CVector(1, 1, 1)*0.1f;
}
void CBlock26::Reset() {
	Texture = GetTexture(L"Block_L1.png");
	Scale = CVector(1, 1, 1)*0.1f;
}
void CBlock27::Reset() {
	Texture = GetTexture(L"Block_D1.png");
	Scale = CVector(1, 1, 1)*0.1f;
}
void CBlock28::Reset() {
	Texture = GetTexture(L"Block_tetu.png");
	Scale = CVector(1, 1, 1)*0.1f;

	CMover *a = this, *b;
	for (int q = 0; q<1; q++) {
		b = New<CWeapon8>(Position);
		b->Owner = a;
		a = b;
	}
}
void CBlock29::Reset() {
	Texture = GetTexture(L"Block_tetu.png");
	Scale = CVector(1, 1, 1)*0.1f;

	CMover *a = this, *b;
	for (int q = 0; q<1; q++) {
		b = New<CWeapon9>(Position);
		b->Owner = a;
		a = b;
	}
	CMover *c = this, *d;
	for (int q = 0; q < 1; q++) {
		d = New<CWeapon8>(Position);
		d->Owner = c;
		c = d;
	}
}
void CBlock30::Reset() {

	Texture = GetTexture(L"Block_sui3.png");
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(1, 0, 1, 1);
}
void CBlock31::Reset() {

	Texture = GetTexture(L"Block_sui3.png");
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(0, 1, 1, 1);
}

//---------------------------------------------------------------------------------------------------------------
// ブロックの移動
void CBlock::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;}});

			Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
//消滅氷フィールドブロック
void CBlock1::Move() {
	if (Life <= 100 && Life >= 60){
		Texture = GetTexture(L"Block3.png");
	}
	if (Life <= 40 && Life >= 10){
		Texture = GetTexture(L"Block3-1.png");
	}

	Weapon2List.Apply([&](CMover* w) {
		if (Length(w->Position - Position) < 0.18f){
			Weapon2List.Apply([&](CMover* w) {
				w->Life = 0;
			});
		}});
}

void CBlock2::Move() {
	//Position.X += 0.003f;
	if (RW == 0){
		Texture = GetTexture(L"Block_D.png");
		Position.Y -= 0.006f;
	}
	
	if (RW == 1){
		Texture = GetTexture(L"Block_DU.png");
		Position.Y += 0.006f;
		//Rotation = RotationZ(0.5f);
	}

	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.05f) {
			//m->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.15f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});

			Enemy8List.Apply([&](CMover* e) {
				if (Length(e->Position - Position) < 0.44f){
						Life -= 8;
						if (Life <= 0){
							New<CEffect3>(Position);
							BP--;
						}
				}});

				Weapon12List.Apply([&](CMover* e) {
					if (Length(e->Position - Position) < 0.44f){
						Life = 0;
						if (Life <= 0){
							New<CEffect3>(Position);
							BP--;
						}
					}});

	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block4List, hit);
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
	Apply(Block22List, hit);
	Apply(Block23List, hit);
	Apply(Block25List, hit);
	Apply(Block26List, hit);
	Apply(Block28List, hit);
	Apply(Block29List, hit);
	//Apply(Block27List, hit);
	Apply(Weapon5List, hit);
	Apply(EnemyList, hit);
	Apply(Enemy8List, hit);
}

void CBlock3::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

	Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});

}

void CBlock4::Move() {
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.1f) {
			m->Life = 0;}
	});

	EnemyList.Apply([&](CMover* e) {
		if (Length(e->Position - Position)<0.1f) {
			e->Life = 0;
		}
	});
}

void CBlock5::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}

void CBlock6::Move() {
	Position.X += 0.004f;
	//Position.Y -= 0.006f;
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<1) {
			Velocity.X = 0.004f;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.15f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});

		//ブロックあたり判定
		CHitRectangle hit;
		Apply(BlockList, hit);
		Apply(Block1List, hit);
		Apply(Block2List, hit);
		Apply(Block3List, hit);
		Apply(Block4List, hit);
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
		Apply(Block22List, hit);
		Apply(Block23List, hit);
		//Apply(Block25List, hit);
		Apply(Block26List, hit);
		Apply(Block27List, hit);
		//Apply(Block28List, hit);
		//Apply(Block29List, hit);
		Apply(Weapon5List, hit);
		Apply(EnemyList, hit);
		Apply(Enemy8List, hit);
}

void CBlock7::Move() {
	Position.X -= 0.004f;
	//Position.Y -= 0.006f;
	//Velocity.X = 0.002f;
	//Position -= Velocity;
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<1) {
			Velocity.X = -0.004f;
			//m->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.15f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});

		//ブロックあたり判定
		CHitRectangle hit;
		Apply(BlockList, hit);
		Apply(Block1List, hit);
		Apply(Block2List, hit);
		Apply(Block3List, hit);
		Apply(Block4List, hit);
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
		Apply(Block22List, hit);
		Apply(Block23List, hit);
		Apply(Block25List, hit);
		//Apply(Block26List, hit);
		Apply(Block27List, hit);
		//Apply(Block28List, hit);
		//Apply(Block29List, hit);
		Apply(Weapon5List, hit);
		Apply(EnemyList, hit);
		Apply(Enemy8List, hit);
}
void CBlock8::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

	Weapon2List.Apply([&](CMover* w) {
		if (Length(w->Position - Position) < 0.18f){
			Weapon2List.Apply([&](CMover* w) {
				w->Life = 0;
			});
		}});
}

void CBlock9::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}

void CBlock10::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}

void CBlock11::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock12::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock13::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock14::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock15::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock16::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock17::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock18::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock19::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock20::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.25f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
}
void CBlock21::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});
		
		Scale = CVector(1, 6, 1)*0.1f;
		Position = Owner->Position + CVector(0, 0.8f, 0);

}
void CBlock22::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.19f) {
			//w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});

		Weapon6List.Apply([&](CMover* w) {
				if (Length(w->Position - Position) < 0.18f){
					Weapon6List.Apply([&](CMover* w) {
						w->Life = 0;
					});
				}});
}
void CBlock23::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.19f) {
			//w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.1f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});
			Weapon6List.Apply([&](CMover* w) {
				if (Length(w->Position - Position) < 0.18f){
					Weapon6List.Apply([&](CMover* w) {
						w->Life = 0;
					});
				}});
}
void CBlock24::Move() {
	//Position.X += 0.003f;
	Position.Y -= 0.006f;
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<2.0f) {
			//m->Life = 0;
			if (Time % 140 == 0)New<CWeapon6>(Position, CVector(-0.05f, 0, 0));
			Time++;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});

			/*if (Time % 140 == 0)New<CWeapon6>(Position, CVector(-0.05f, 0, 0));
			Time++;*/

			//ブロックあたり判定
			CHitRectangle hit;
			Apply(BlockList, hit);
			Apply(Block1List, hit);
			Apply(Block2List, hit);
			Apply(Block3List, hit);
			Apply(Block4List, hit);
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
			Apply(Block22List, hit);
			Apply(Block23List, hit);
			Apply(Block24List, hit);
			Apply(Block25List, hit);
			Apply(Block26List, hit);
			Apply(Block27List, hit);
			Apply(Block29List, hit);
			Apply(EnemyList, hit);
}
void CBlock25::Move() {
	Position.X += 0.004f;
	
		Block6List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.20f){
				Life = 0;
				if (Life == 0) { New<CEffect15>(Position); }

		Block6List.Apply([&](CMover* w) {
					w->Life = 0;
					BP -= 1;
					if (w->Life == 0) { New<CEffect6>(w->Position); }
				});
			}});

			WeaponList.Apply([&](CMover* w) {
				if (Length(w->Position - Position) < 0.18f){
					w->Life = 0;
				}});

				Weapon2List.Apply([&](CMover* w) {
					if (Length(w->Position - Position) < 0.18f){
						w->Life = 0;
					}});

			//ブロックあたり判定
			CHitRectangle hit;
			Apply(BlockList, hit);
			Apply(Block1List, hit);
			Apply(Block2List, hit);
			Apply(Block3List, hit);
			Apply(Block4List, hit);
			Apply(Block5List, hit);
			//Apply(Block6List, hit);
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
			Apply(Block22List, hit);
			Apply(Block23List, hit);
			Apply(Block25List, hit);
			Apply(Block26List, hit);
			Apply(Block27List, hit);
			Apply(Block29List, hit);
			Apply(EnemyList, hit);
}
void CBlock26::Move() {
	Position.X -= 0.004f;

	Block7List.Apply([&](CMover* w) {
		if (Length(w->Position - Position) < 0.20f){
			Life = 0;

			if (Life == 0) { New<CEffect15>(Position); }

			Block7List.Apply([&](CMover* w) {
				w->Life = 0;
				BP -= 1;
				if (w->Life == 0) { New<CEffect6>(w->Position); }
			});
		}});

		WeaponList.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				w->Life = 0;
			}});

			Weapon2List.Apply([&](CMover* w) {
				if (Length(w->Position - Position) < 0.18f){
					w->Life = 0;
				}});

		//ブロックあたり判定
		CHitRectangle hit;
		Apply(BlockList, hit);
		Apply(Block1List, hit);
		Apply(Block2List, hit);
		Apply(Block3List, hit);
		Apply(Block4List, hit);
		Apply(Block5List, hit);
		Apply(Block6List, hit);
		//Apply(Block7List, hit);
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
		Apply(Block22List, hit);
		Apply(Block23List, hit);
		Apply(Block25List, hit);
		Apply(Block26List, hit);
		Apply(Block27List, hit);
		Apply(Block29List, hit);
		Apply(EnemyList, hit);
}

void CBlock27::Move() {
	Position.Y -= 0.006f;

	Block2List.Apply([&](CMover* w) {
		if (Length(w->Position - Position) < 0.20f){
			Life = 0;

			if (Life == 0) { New<CEffect15>(Position); }

			Block2List.Apply([&](CMover* w) {
				w->Life = 0;
				BP -= 1;
				if (w->Life == 0) { New<CEffect6>(w->Position); }
			});
		}});

		WeaponList.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				w->Life = 0;
			}});

			Weapon2List.Apply([&](CMover* w) {
				if (Length(w->Position - Position) < 0.18f){
					w->Life = 0;
				}});

				//ブロックあたり判定
				CHitRectangle hit;
				Apply(BlockList, hit);
				Apply(Block1List, hit);
				//Apply(Block2List, hit);
				Apply(Block3List, hit);
				Apply(Block4List, hit);
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
				Apply(Block22List, hit);
				Apply(Block23List, hit);
				Apply(Block25List, hit);
				Apply(Block26List, hit);
				Apply(Block27List, hit);
				Apply(Block29List, hit);
				Apply(EnemyList, hit);
}

void CBlock28::Move() {
	if (RW == 0)Position.Y -= 0.006f;
	if (RW == 1)Position.Y += 0.006f;

	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position) < 0.18f){
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				w->Life = 0;
			}});

			//ブロックあたり判定
			CHitRectangle hit;
			Apply(BlockList, hit);
			Apply(Block1List, hit);
			Apply(Block2List, hit);
			Apply(Block3List, hit);
			Apply(Block4List, hit);
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
			Apply(Block22List, hit);
			Apply(Block23List, hit);
			Apply(Block25List, hit);
			Apply(Block26List, hit);
			Apply(Block27List, hit);
			Apply(Block28List, hit);
			Apply(Block29List, hit);
			Apply(EnemyList, hit);
			Apply(Weapon5List, hit);

			Block6List.Apply([&](CMover* w) {
				if (Length(w->Position - Position) < 0.13f || Length(w->Position - Position) < 0.01f){
					w->Life = 0;
					BP -= 1;
					if (w->Life == 0) { New<CEffect6>(w->Position); }
				}});
				Block7List.Apply([&](CMover* w) {
					if (Length(w->Position - Position) < 0.13f || Length(w->Position - Position) < 0.01f){
						w->Life = 0;
						BP -= 1;
						if (w->Life == 0) { New<CEffect6>(w->Position); }
					}});
}

void CBlock29::Move() {
	if (RW == 0)Position.Y -= 0.006f;
	if (RW == 1)Position.Y += 0.006f;

	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position) < 0.13f || Length(w->Position - Position) < 0.01f){
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.13f || Length(w->Position - Position) < 0.01f){
				w->Life = 0;
			}});

			//ブロックあたり判定
			CHitRectangle hit;
			Apply(BlockList, hit);
			Apply(Block1List, hit);
			Apply(Block2List, hit);
			Apply(Block3List, hit);
			Apply(Block4List, hit);
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
			Apply(Block22List, hit);
			Apply(Block23List, hit);
			Apply(Block25List, hit);
			Apply(Block26List, hit);
			Apply(Block27List, hit);
			Apply(Block28List, hit);
			Apply(Block29List, hit);
			Apply(EnemyList, hit);
			Apply(Weapon5List, hit);

			Block6List.Apply([&](CMover* w) {
				if (Length(w->Position - Position) < 0.13f){
					w->Life = 0;
					BP -= 1;
					if (w->Life == 0) { New<CEffect6>(w->Position); }
				}});
				Block7List.Apply([&](CMover* w) {
					if (Length(w->Position - Position) < 0.13f){
						w->Life = 0;
						BP -= 1;
						if (w->Life == 0) { New<CEffect6>(w->Position); }
					}});
}
void CBlock30::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});

}
void CBlock31::Move() {
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;
		}});

		Weapon2List.Apply([&](CMover* w) {
			if (Length(w->Position - Position) < 0.18f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}});

}