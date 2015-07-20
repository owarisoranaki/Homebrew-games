#include "Main.h"


// ���@�̏�����
void CMyShip::Reset() {
	Texture=GetTexture(L"pen-l.png");
	Scale=CVector(1, 1, 1)*0.1f;
	Life = 1000;
}

// ���@�̈ړ�
void CMyShip::Move() {
	
	Velocity.X = 0;
	//Velocity.Y -= 0.004f;
	Position += Velocity;

	//�u���b�N�����蔻��
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
	

	//New<CEffect>(Position);//���@�ɃX�|�b�g
	//New<CBullet>(Position.XYF(1));//��ʈÈ�

	//�~�܂��Ă��鎞�A�j���[�V����

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

	//�L�[���Ƃ̃A�j���[�V�����ύX
	//���L�[
	if (KeyState[0][DIK_A]) {
		//Velocity.X = -0.02f;
		//Position += KeyState[0].Direction()*0.015f;
		Scale = CVector(1, 1, 1)*0.1f;
		Type = 1;
		pause = 1;
	}
	//�E�L�[
	if (KeyState[0][DIK_D]) {
		//Velocity.X += 0.022f;
		//Position += KeyState[0].Direction()*0.015f;
		//Position += PadState[0].X;
		Scale = CVector(1, 1, 1)*0.1f;
		Type = 2;
		pause = 2;
	}
	//�W�����v
	/*if (KeyState[0][DIK_UP] && !KeyState[0][DIK_LEFT] && hit.Down) Velocity.Y += 0.022f;
	if (KeyState[0][DIK_UP] && !KeyState[0][DIK_RIGHT] && hit.Down) Velocity.Y += 0.022f;
	if (KeyState[0][DIK_UP] && hit.Down && KeyState[0][DIK_RIGHT]) Velocity.Y = 0.032f;//�E�ړ��W�����v
	if (KeyState[0][DIK_UP] && hit.Down && KeyState[0][DIK_LEFT]) Velocity.Y = 0.032f;//���ړ��W�����v*/
	//�E������
	if (RW==0&&KeyState[0][DIK_S] && KeyState[0][DIK_D]) {
		Texture = GetTexture(L"pen-l6.png");
		Position += KeyState[0].Direction()*0.02f;
		if (KeyState[0][DIK_W]) Position.Y -= 0.1f;
		Scale = CVector(0.8, 0.6, 1)*0.1f;

		New<CEffect18>(Position);
	}
	//��������
	if (RW == 0 && KeyState[0][DIK_S] && KeyState[0][DIK_A]) {
		Texture = GetTexture(L"pen-r6.png");
		Position += KeyState[0].Direction()*0.02f;
		if (KeyState[0][DIK_W]) Position.Y -= 0.1f;
		Scale = CVector(0.8, 0.6, 1)*0.1f;

		New<CEffect19>(Position);
	}
	//�傫���Ȃ钲��
	if (RW == 0 && KeyState[0][DIK_S] && !KeyState[0][DIK_A] && !KeyState[0][DIK_D]) {
		Scale = CVector(1, 1, 1)*0.1f;
	}

	//�V���b�g
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
	//���e

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

	//���u�[������
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

	//�V���b�g���̎�̕\��
	if (Type == 1 && !KeyState[0][DIK_S] && MouseState[0].Button[0] && !OldMouseState[0].Button[0] && !KeyState[0][DIK_W]){
		Texture = GetTexture(L"pen-r3.png");
	}
	if (Type == 2 && !KeyState[0][DIK_S] && MouseState[0].Button[0] && !OldMouseState[0].Button[0] && !KeyState[0][DIK_W]){
		Texture = GetTexture(L"pen-l3.png");
	}
	//���e�ݒu���̎�̕\��
	if (Type == 1 && !KeyState[0][DIK_S] && KeyState[0][DIK_R] && !KeyState[0][DIK_A] && !KeyState[0][DIK_W]){
		Texture = GetTexture(L"pen-r3.png");
	}
	if (Type == 2 && !KeyState[0][DIK_S] && KeyState[0][DIK_R] && !KeyState[0][DIK_D] && !KeyState[0][DIK_W]){
		Texture = GetTexture(L"pen-l3.png");
	}



	//�u���b�N�^�C�v�I��
	if (MouseState[0].Button[2] && !OldMouseState[0].Button[2] && BT<3) { BT += 1; }
	if (BT==3) {BT = 0;}

	//�u���b�N�Z�b�g
	if (BP < 0)BP = 0;
	//�u���b�NDOWN
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
	//�u���b�NRIGHT
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
	//�u���b�NLEFT
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

	//�u���b�N�u���C�N
		//�u���C�NDOWN
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

		//�u���C�NRIGHT
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
		//�u���C�NLEFT
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
	
	//�G�ƐڐG��
	EnemyList.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.1f) {
			//e->Life = 0;
			//Life--;
			//Score += 100;
		}
	});
	//BOSS�ڐG��
	Enemy2List.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.1f) {
			Life-=0.01f;
			//Score += 100;
		}
	});

	//�^�C�Ă�
	Enemy3List.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.1f) {
			Life-=0.001f;
		}
	});

	//���e��Y
	Enemy5List.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.1f) {
			Life -= 100;
			e->Life = 0;
			New<CEffect7>(e->Position);
		}
	});

	//�G�����蔻��
	Apply(Enemy2List, hit);

	//�A�C�e���擾
	//�n�[�g
	ItemList.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			//�n�[�g�Q�b�g
			GetWave(L"b_090.wav")->Play(1);
			GetWave(L"b_090.wav")->SetVolume(0.07f);
			i->Life = 0;
			Life += 800;
			Score += 80;
		}
	});

	//�X�e�[�W�J�����ړ�(���i)
	Item11List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			CS = 1;
			//i->Life = 0;
		}
	});

	//�X�e�[�W�J�������]�i�Ώ�i�j
	Item12List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			TT = 1;
			//BRR == 1;
			//i->Life = 0;
		}
	});

	//�X�e�[�W�J�������]�i��o�j
	Item13List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			TT = 0;
			//BRR = 0;
			//i->Life = 0;
		}
	});

	//�X�e�A�C�e��
	Item7List.Apply([&](CMover* h) {
		if (Length(h->Position - Position) < 0.1f) {
			//weapon�Q�b�g
			GetWave(L"se_maoudamashii_onepoint26.wav")->Play(1);
			GetWave(L"se_maoudamashii_onepoint26.wav")->SetVolume(0.07f);
			syot = 0;
			SI = 0;
			h->Life = 0;
		}
	});

	//���e�A�C�e��
	Item6List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			//weapon�Q�b�g
			GetWave(L"se_maoudamashii_onepoint26.wav")->Play(1);
			GetWave(L"se_maoudamashii_onepoint26.wav")->SetVolume(0.07f);
			syot = 1;
			SI = 1;
			i->Life = 0;
		}
	});

	//���u�[�������A�C�e��
	Item10List.Apply([&](CMover* h) {
		if (Length(h->Position - Position) < 0.1f) {
			//weapon�Q�b�g
			GetWave(L"se_maoudamashii_onepoint26.wav")->Play(1);
			GetWave(L"se_maoudamashii_onepoint26.wav")->SetVolume(0.07f);
			syot = 2;
			SI = 2;
			h->Life = 0;
		}
	});

	//�ÈŃX�C�b�`
	Item1List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			i->Life = 0;
			kura = 1;
		}

	});
	//�_���[�W�A�C�e��(�L�m�R)
	Item3List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			//�L�m�R�Q�b�g
			GetWave(L"se_maoudamashii_onepoint13.wav")->Play(1);
			GetWave(L"se_maoudamashii_onepoint13.wav")->SetVolume(0.07f);
			i->Life = 0;
			Life -= 100;
			Score += 200;
		}
	});

	if (kura == 1){
		New<CEffect>(Position);//���@�ɃX�|�b�g
		New<CBullet>(Position.XYF(1));//��ʈÈ�
	}

	//���邭�X�C�b�`
	Item2List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.1f) {
			i->Life = 0;
			kura = 0;
		}

	});

//�X�e�[�W�ړ�
	//1�`2
	Item5List.Apply([&](CMover* i) {
		if (Length(Position - i->Position)<0.05f) {
			//�Q�[�g�^�b�`
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
	//2�`3
	Item8List.Apply([&](CMover* i) {
		SI = 0;
		if (Length(Position - i->Position)<0.05f) {
			//�Q�[�g�^�b�`
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
	//3�`4
	Item9List.Apply([&](CMover* i) {
		if (Length(Position - i->Position)<0.05f) {
			//�Q�[�g�^�b�`
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


	//���C�t�Ɩ��G����
	//�G
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
	//�^�C�Ă�
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
	//���e��Y
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
	//�t�H�[�N
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
	//���N�b�L�[
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

	//���Z�b�g��BP0
	if (KeyState[0][DIK_C]){
		Texture = GetTexture(L"pen-l3.png");
		BP = 0;
	}
	
	//�����u���b�N�E�E�������ړ������蔻��
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
//�G���^�[�L�[�������Ɣ��]
	if (KeyState[0][DIK_A]) Velocity.X = -0.02f;
	if (KeyState[0][DIK_D]) Velocity.X = 0.02f;
	if (state1 == 1) Velocity.X *= -1;

	if (state1 == 0) Velocity.Y -= 0.002f;
	if (state1 == 1) Velocity.Y += 0.002f;
	Position += Velocity;

	//���L�����W�����v
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
		//���]
		/*if (RW==0 && KeyState[0][DIK_RETURN] && !OldKeyState[0][DIK_RETURN]) {
			state1 = 1-state1;
			RW = 1;
		}*/

		if (RW == 0 && TT==1) {
			state1 = 1 - state1;
			RW = 1;
		}
		//���퉻
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
		//�V���b�g
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
		//���e

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

		//���u�[������
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

	//�E������
	if (RW == 1 && KeyState[0][DIK_S] && KeyState[0][DIK_D]) {
		Texture = GetTexture(L"pen-l6.png");
		Position -= KeyState[0].Direction()*0.02f;
		if (KeyState[0][DIK_W]) Position.Y -= 0.1f;
		Scale = CVector(0.8, 0.6, 1)*0.1f;
	}
	//��������
	if (RW == 1 && KeyState[0][DIK_S] && KeyState[0][DIK_A]) {
		Texture = GetTexture(L"pen-r6.png");
		Position -= KeyState[0].Direction()*0.02f;
		if (KeyState[0][DIK_W]) Position.Y -= 0.1f;
		Scale = CVector(0.8, 0.6, 1)*0.1f;
	}
	//�傫���Ȃ钲��
	if (RW == 1 && KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A]) {
		Scale = CVector(1, 1, 1)*0.1f;
	}

	//�u���b�NDOWN
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
	//�u���b�NRIGHT
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
	//�u���b�NLEFT
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


