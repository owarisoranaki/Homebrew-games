#include "Main.h"

// �G�̏�����
void CEnemy::Reset() {
	Scale=CVector(1, 1, 1)*0.1f;
	ETP = 0;
	Life = 50;
	Ept = 1;
	Ept2 = 0;
}

//BOSS��
void CEnemy2::Reset() {
	ETP2 = 0;
	Ept2 = 1;
	Life = 200;

	if (Type == 0) {
		New<CEnemy8>(1)->Owner = this;
	}
	

	//������
	Velocity = CVector(1, 1, 0)*0.008f;
	CMover *a = this, *b;
	for (int q = 0; q<1; q++) {
		b = New<CEnemy6>(Position);
		b->Owner = a;
		a = b;

	}
/*	//��
	if (ATP == 0){
		Velocity = CVector(1, 1, 0)*0.008f;
		CMover *e = this, *f;
		for (int q = 0; q < 1; q++) {
			b = New<CEnemy8>(Position);
			b->Owner = a;
			a = b;
		}
	}

	//��i�U���j
	if (ATP == 1){
		Velocity = CVector(1, 1, 0)*0.008f;
		CMover *a = this, *b;
		for (int q = 0; q < 1; q++) {
			b = New<CWeapon10>(Position);
			b->Owner = a;
			a = b;

			//	if (Time % 300 == 0){ ATP = 0; }
		}
	}*/
	
}

void CEnemy3::Reset() {
	ETP2 = 0;
	Ept3 = 1;
	Scale = CVector(1, 0.7f, 1)*0.1f;
	Life = 50;
	HomePosition = Position;
}

void CEnemy5::Reset() {
	Life = 20;
	Velocity = CVector(1, 1, 0)*0.008f;
	
}
//BOSS������
void CEnemy6::Reset() {
	Texture = GetTexture(L"Boss_asi.png");
	Color = CColor(1, 1, 1, 0.0f);
	//Scale = CVector(1, 1, 1)*0.1f;
}
//BOSS�画��
void CEnemy7::Reset() {
	Life = 10;//200
	Texture = GetTexture(L"Boss_kao.png");
	Color = CColor(1, 1, 1, 0.0f);
	//Scale = CVector(1, 1, 1)*0.1f;
}
//BOSS��
void CEnemy8::Reset() {

	wp = 20;
	Velocity = CVector(1, 1, 0)*0.008f;
		CMover *c = this, *d;
		for (int q = 0; q < 1; q++) {
			d = New<CEnemy7>(Position);
			d->Owner = c;
			c = d;
		}

		CMover *e = this, *f;
		for (int q = 0; q < 1; q++) {
			f = New<CEnemy10>(Position);
			f->Owner = e;
			e = f;
		}

	Color = CColor(1, 1, 1, 1.0f);
	//Scale = CVector(1, 1, 1)*0.1f;
	Scale = CVector(1.07f, 1, 1)*0.30f;
}
//BOSS�画��(���ʁE��ʁj
void CEnemy9::Reset() {
	
	Texture = GetTexture(L"kaohit_L.png");
	Color = CColor(1, 1, 1, 0.8f);
	//Scale = CVector(1, 1, 1)*0.1f;

}
//BOSS�画��
void CEnemy10::Reset() {

	Texture = GetTexture(L"Boss_kao.png");
	Color = CColor(1, 0, 1, 0.0f);
	//Scale = CVector(1, 1, 1)*0.1f;

}

//----------------------------------------------------------------------------------------------------------

// �G�̈ړ�
void CEnemy::Move() {
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
	Apply(Block22List, hit);
	Apply(Block23List, hit);
	Apply(Block28List, hit);
	Apply(Block29List, hit);
	//Apply(EnemyList, hit);

	
	Velocity.Y -= 0.002f;
	Position += Velocity;
	
Block3List.Apply([&](CMover* b) {//�ԃu���b�N�ڐG
	if (Length(Position - b->Position) < 0.21f) {
		Color.A = 1;
		Ept = 1;
	}
});

Block5List.Apply([&](CMover* b) {//���u���b�N�ڐG
	if (Length(Position - b->Position) < 0.21f) {
		Color.A = 1;
		Ept = 2;
	}
});

	if (Ept == 1){//������
		if (Time % 30 == 10)Texture = GetTexture(L"kuma_r.png");
		if (Time % 30 == 20)Texture = GetTexture(L"kuma_r1.png");
		if (Time % 30 == 25)Texture = GetTexture(L"kuma_r2.png");
		Time++;
		
	}

	if (Ept == 2){//�E����
		if (Time % 30 == 10)Texture = GetTexture(L"kuma_l.png");
		if (Time % 30 == 20)Texture = GetTexture(L"kuma_l1.png");
		if (Time % 30 == 25)Texture = GetTexture(L"kuma_l2.png");
		Time++;	
	}

	MyShipList.Apply([&](CMover* m) {
		float f = Length(Position - m->Position);//���@�ƓG�Ƃ̋����v�Z

		if (f < 0.2 && Ept == 1 && hit.Down){//���ߋ����s��
			Velocity.Y += 0.03f;
			Velocity.X -= 0.012f;
			Position += Velocity;
		}
		if (f < 1.5 &&f > 0.2 && Ept == 1){//���������s��
			if (Time % 40 == 5)New<CWeapon6>(Position, CVector(-0.05f, 0, 0));
			Time++;
			if (hit.Down)Position.X += -0.005f;
		}
		
		if (f < 0.2 && Ept == 2 && hit.Down){//�E�ߋ����s��
			Velocity.Y += 0.03f;
			Velocity.X += 0.012f;
			Position += Velocity;
		}
		if (f < 1.5 &&f > 0.2 && Ept == 2){//�E�������s��
			if (Time % 40 == 5)New<CWeapon6>(Position, CVector(0.05f, 0, 0));
			Time++;
			if (hit.Down)Position.X += 0.005f;
		}
	});
	
}

//=====================================================BOSS��================================================================================================
void CEnemy2::Move() {

	Scale = CVector(1.1f, 1, 1)*0.35f;
	Velocity.Y -= 0.005f;

	//������
		if (Bst == 0){
			//if (Time % 140 == 0)New<CWeapon6>(Position, CVector(-0.15f, 0.3f, 0));
			//if (Time % 140 == 0)New<CWeapon6>(Position, CVector(-0.15f, 0.0f, 0));
			//Time++;

			Position.X -= 0.007f;
			Position += Velocity;
			if (Time % 300 == 0){
				//�ړ���JUMP�i�K�b�R���j
				GetWave(L"se_maoudamashii_se_sound09.wav")->Play(1);
				GetWave(L"se_maoudamashii_se_sound09.wav")->SetVolume(0.07f);
				Velocity.Y += 0.07f; Position += Velocity;
			}
			if (Time % 125 == 20)Texture = GetTexture(L"boss_karada1.png");
			if (Time % 125 == 40)Texture = GetTexture(L"boss_karada2.png");
			if (Time % 125 == 60)Texture = GetTexture(L"boss_karada3.png");
			if (Time % 125 == 80)Texture = GetTexture(L"boss_karada4.png");
			if (Time % 125 == 100)Texture = GetTexture(L"boss_karada5.png");
			if (Time % 125 == 120)Texture = GetTexture(L"boss_karada6.png");
			Time++;
		}
	//�E����
		if (Bst == 1){
			//if (Time % 140 == 0)New<CWeapon6>(Position, CVector(0.15f, 0.3f, 0));
			//if (Time % 140 == 0)New<CWeapon6>(Position, CVector(0.15f, 0.0f, 0));
			//Time++;

			Position.X += 0.007f;
			Position += Velocity;

			if (Time % 300 == 0){
				//�ړ���JUMP�i�K�b�R���j
				GetWave(L"se_maoudamashii_se_sound09.wav")->Play(1);
				GetWave(L"se_maoudamashii_se_sound09.wav")->SetVolume(0.07f);
				Velocity.Y += 0.07f; Position += Velocity;
			}
			if (Time % 120 == 20)Texture = GetTexture(L"boss_karada1R.png");
			if (Time % 120 == 40)Texture = GetTexture(L"boss_karada2R.png");
			if (Time % 120 == 60)Texture = GetTexture(L"boss_karada3R.png");
			if (Time % 120 == 80)Texture = GetTexture(L"boss_karada4R.png");
			if (Time % 120 == 100)Texture = GetTexture(L"boss_karada5R.png");
			if (Time % 120 == 120)Texture = GetTexture(L"boss_karada6R.png");
			Time++;

		}
	

	/*if(ATP==0){
		if (Time % 180 == 0){
			Enemy8List.Apply([&](CMover* b) {
				b->Color = CColor(1, 1, 1, 1.0f);
				//b->Life = 0;
			});
		}
		ATP = 1;
	}

	if (ATP == 1){
		if (Time % 240 == 0){
			Enemy8List.Apply([&](CMover* b) {
				b->Color = CColor(1, 1, 1, 1.0f);
			});
		}
		ATP = 0;
	}*/

	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
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
	Apply(Block28List, hit);
	Apply(Block29List, hit);
	//Apply(Block30List, hit);
	


	Block30List.Apply([&](CMover* b) {//�u���b�N�ڐG
		if (Length(Position - b->Position) <0.6f) {
			Color.A = 0.9f;
			Bst = 1;
			BSST = 1;
		}
	});

	Block31List.Apply([&](CMover* b) {//�u���b�N�ڐG
		if (Length(Position - b->Position) < 0.6f) {
			Color.A = 0.9f;
			Bst = 0;
			BSST = 0;
		}
	});
	
}

//-----------------------------------------------------------------------------------------
void CEnemy3::Move() {//�^�C�Ă�

	if (TEXTURE_CHANGE == 1){//�E����
			if (Time % 25 == 10)Texture = GetTexture(L"taiyaki.png");
			if (Time % 25 == 20)Texture = GetTexture(L"taiyaki1.png");
			Time++;
		}
	if (TEXTURE_CHANGE==0){//������
			if (Time % 25 == 10)Texture = GetTexture(L"taiyaki2.png");
			if (Time % 25 == 20)Texture = GetTexture(L"taiyaki3.png");
			Time++;
		}

		MyShipList.Apply([&](CMover* m) {
				X = m->Position.X - Position.X;
				X_COPY = X;
		});
		if (COUNT == 0){
			//�`�F���W�摜
			if (X<0){
				TEXTURE_CHANGE = 0;
			}
			if (X>0){
				TEXTURE_CHANGE = 1;
			}
			if (X_COPY < 0){
				X_COPY *= -1;
			}
		}

		
		if (COUNT == 0){
			MyShipList.Apply([&](CMover* m) {
				Position.Homing(m->Position, 0.003f);
				LEN_COPY = Length(Position - m->Position);

				if (LEN_COPY < 0)LEN_COPY *= -1;

				if (LEN_COPY<=0.1f){
					if (TEXTURE_CHANGE == 0){
						TEXTURE_CHANGE = 1;
					}
					else if (TEXTURE_CHANGE == 1){
						TEXTURE_CHANGE = 0;
					}
					COUNT = 1;
				}
			});
		}
		if (COUNT == 1){
			Position.Homing(HomePosition, 0.003f);
			if (Length(Position - HomePosition) < 0.1f){
				COUNT = 0;
			}
		}
		
		

		/*if (State == 0 && Ept3==1) {
			Position.X -= 0.007f;
			MyShipList.Apply([&](CMover* m) {
				float f = Length(Position - m->Position);
				if (f<0.1f || f>0.7f) State = 1;
				Position += Normalize(m->Position - Position)*0.01f;
			});
		}
		if (State == 1 && Ept3==1) {
			Position += Normalize(HomePosition - Position)*0.01f;
			if (Length(HomePosition - Position)<0.01f) {
				Position = HomePosition;
				State = 0;
			}
		}*/

		CHitRectangle hit;
		Apply(BlockList, hit);
		Apply(Block1List, hit);
		Apply(Block2List, hit);
		Apply(Block3List, hit);
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
		/*Apply(Block20List, hit);
		Apply(Block22List, hit);
		Apply(Block23List, hit);*/
}

void CEnemy5::Move() {

	if (Time % 45 == 10)Texture = GetTexture(L"bakudan1.png");
	if (Time % 45 == 20)Texture = GetTexture(L"bakudan2.png");
	Time++;
	Scale = CVector(1, 1, 1)*0.08f;
	Rotation *= RotationZ(0.02f);
	Position += Velocity;
	CVector v = Velocity;
	CHitRectangle hit; (0.3f, 0.3f, 0.3f, 0.3f);

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
	Apply(Block22List, hit);
	Apply(Block23List, hit);
	Apply(Block28List, hit);
	Apply(Block29List, hit);
	if (hit.Up || hit.Down) Velocity.Y = -v.Y;
	if (hit.Left || hit.Right) Velocity.X = -v.X;
}
//BOSS������
void CEnemy6::Move() {
	Scale = CVector(2.2f, 0.31, 1)*0.1f;
	Position = Owner->Position + CVector(0.02f, -0.32f, 0);

	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.131f) {
			m->Life = 0;
		}
	});
}
//BOSS��̂����蔻��
void CEnemy7::Move() {
	Scale = CVector(1.1f,1, 1)*0.22f;
	Position = Owner->Position + CVector(0.01, 0.06f, 0);

	if (Life <= 100){
		BOSSHP = 1;
	}
}
//BOSS��
void CEnemy8::Move() {
	Position += Velocity;
	//Texture = GetTexture(L"boss_kao1.png");
	//if (Time % 300 == 0)

	//������
	if (BSST == 0){
		/*if (kao == 0){
			Scale = CVector(1.2f, 1, 1)*0.27f;
			Position = Owner->Position + CVector(0.04, 0.89f, 0);
		}*/

		/*if (Time % 120 == 0){
			Position.X -= 0.6f;
			Position += Velocity;
		}*/

		if (Time % 120 == 20)Texture = GetTexture(L"boss_kao1.png");
		if (Time % 120 == 40)Texture = GetTexture(L"boss_kao2.png");
		if (Time % 120 == 60)Texture = GetTexture(L"boss_kao3.png");
		if (Time % 120 == 80)Texture = GetTexture(L"boss_kao4.png");
		if (Time % 120 == 100)Texture = GetTexture(L"boss_kao5.png");
		if (Time % 120 == 120)Texture = GetTexture(L"boss_kao6.png");
		Time++;
	}
	//�E����
	if (BSST == 1){
		//Scale = CVector(1.2f, 1, 1)*0.27f;
		//Position = Owner->Position + CVector(-0.04, 0.89f, 0);

		if (Time % 120 == 20)Texture = GetTexture(L"boss_kao1R.png");
		if (Time % 120 == 40)Texture = GetTexture(L"boss_kao2R.png");
		if (Time % 120 == 60)Texture = GetTexture(L"boss_kao3R.png");
		if (Time % 120 == 80)Texture = GetTexture(L"boss_kao4R.png");
		if (Time % 120 == 100)Texture = GetTexture(L"boss_kao5R.png");
		if (Time % 120 == 120)Texture = GetTexture(L"boss_kao6R.png");
		Time++;
	}

	if (Type == 1) {
		//����΂��ϐ�
		if (atama == 0){
			if (Time % 420 == 0){ 
				Color = CColor(1, 0, 0, 1);
				if (Time % 60 == 0)atama = 1;
				Time++;
			}
		}

		if (State == 0) {
			Position = Owner->Position + CVector(0, 0.59f, 0);
			if (atama==1){
					KM = 0, State = 1;
					atama = 0;
			}
		}
		if (State == 1) {//���ł���
			MyShipList.Apply([&](CMover* m) {
					Position += Normalize(m->Position - Position)*0.04f;
					KM++; BOSSC = 1;
					if (KM == 60) State = 2;
					New<CEffect20>(Position);
					//���ł������̉��i�V���r�r�r�r�[���j
					GetWave(L"se_maoudamashii_battle02.wav")->Play(1);
					GetWave(L"se_maoudamashii_battle02.wav")->SetVolume(0.02f);
			});
		}
		if (State == 2) {//�߂��Ă���X�s�[�h
			CVector target = Owner->Position + CVector(0, 0.59f, 0);
			Position += Normalize(target - Position)*0.05f;
			if (Length(target - Position)<0.02f) State = 0;
			BOSSC = 0;
			New<CEffect20>(Position);
			Color = CColor(1, 1, 1, 1);
		}
	}

	//BOSS��ڐG���_���[�W
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.44f) {
			m->Life -= wp;
		}
	});
	//�U�����蓧����
	if (MutekiTime1 == 0) {
		WeaponList.Apply([&](CMover* e) {
			if (Length(Position - e->Position) < 0.5f) {
				//Life--;
				MutekiTime1 = 1;
				MutekiTime = 1;
				Color.A = 0.7f;
			}
		});
		if (MutekiTime1 == 1)MutekiTime1 = 0;
	}
	

	if (MutekiTime1 == 0) {
		Weapon2List.Apply([&](CMover* e) {
			if (Length(Position - e->Position) < 0.4f) {
				//Life--;
				MutekiTime1 = 1;
				MutekiTime = 1;
				Color.A = 0.7f;
			}
		});
		if (MutekiTime1 == 1)MutekiTime1 = 0;
	}

	if (MutekiTime1 == 0) {
		Weapon7List.Apply([&](CMover* e) {
			if (Length(Position - e->Position) < 0.4f) {
				//Life--;
				MutekiTime1 = 1;
				MutekiTime = 1;
				Color.A = 0.7f;
			}
		});
		if (MutekiTime1 == 1)MutekiTime1 = 0;
	}

	CHitRectangle hit;
	Apply(Block14List, hit);
	Apply(Block15List, hit);
	Apply(Block2List, hit);
	Apply(Block6List, hit);
	Apply(Block7List, hit);
}

void CEnemy9::Move() {

}
void CEnemy10::Move() {
	Scale = CVector(1.2f, 1, 1)*0.22f;
	Position = Owner->Position + CVector(0.01, 0.06f, 0);
}