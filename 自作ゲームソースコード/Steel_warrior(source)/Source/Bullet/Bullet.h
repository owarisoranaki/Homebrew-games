// 弾(Myship)
class CBullet : public CMyMover {
public:
	int ENEMY_HIT_COUNT = 0;
	float SCALE_X =0;
	float SCALE_Y = 0;
	float SCALE_Z = 0;
	float BEAM_MOVE = 0;
	float CW = 1;
	int BEAM_COUNT = 0;
	int BEAM_TIME = 0;
	float COLOR_W = 1;
	void Beam_hit_se(){
		GetWave(L"ACTION\\beam_hit.wav")->Play(1);
		GetWave(L"ACTION\\beam_hit.wav")->SetVolume(0.3f);
	}
	void* operator new(size_t n) { return BulletList.New(n); }
	void operator delete(void* p) { BulletList.Delete(p); }
	CBullet() : CMyMover(BulletList) {}
	void Reset();
	void Move();
};
// 弾(左)(Enemy)
class CBullet2 : public CMyMover {
public:
	CVector MYSHIP_POSITION_COPY = 0;
	int MOVE_COUNT = 0;

	void Little_bomb_impact(){
		GetWave(L"ENEMY_ATACK\\little_bomb.wav")->Play(1);
		GetWave(L"ENEMY_ATACK\\little_bomb.wav")->SetVolume(0.1f);
	}
	void* operator new(size_t n){ return Bullet2List.New(n); }
	void operator delete(void* p) { Bullet2List.Delete(p); }
	CBullet2() : CMyMover(Bullet2List) {}
	void Reset();
	void Move();
};
// 弾(右)(Enemy)
class CBullet3 : public CMyMover {
public:
	CVector MYSHIP_POSITION_COPY = 0;
	int MOVE_COUNT = 0;
	void Little_bomb_impact(){
		GetWave(L"ENEMY_ATACK\\little_bomb.wav")->Play(1);
		GetWave(L"ENEMY_ATACK\\little_bomb.wav")->SetVolume(0.1f);
	}
	void* operator new(size_t n){ return Bullet3List.New(n); }
	void operator delete(void* p) { Bullet3List.Delete(p); }
	CBullet3() : CMyMover(Bullet3List) {}
	void Reset();
	void Move();
};
// 弾(上)(Enemy)
class CBullet4 : public CMyMover {
public:
	CVector MYSHIP_POSITION_COPY = 0;
	int MOVE_COUNT = 0;
	void Little_bomb_impact(){
		GetWave(L"ENEMY_ATACK\\little_bomb.wav")->Play(1);
		GetWave(L"ENEMY_ATACK\\little_bomb.wav")->SetVolume(0.12f);
	}
	void* operator new(size_t n){ return Bullet4List.New(n); }
	void operator delete(void* p) { Bullet4List.Delete(p); }
	CBullet4() : CMyMover(Bullet4List) {}
	void Reset();
	void Move();
};
// カミナリ
class CBullet5 : public CMyMover {
public:
	void* operator new(size_t n){ return Bullet5List.New(n); }
	void operator delete(void* p) { Bullet5List.Delete(p); }
	CBullet5() : CMyMover(Bullet5List) {}
	void Reset();
	void Move();
};
// 弾(下)(Enemy)
class CBullet6 : public CMyMover {
public:
	CVector MYSHIP_POSITION_COPY = 0;
	int MOVE_COUNT = 0;
	void Little_bomb_impact(){
		GetWave(L"ENEMY_ATACK\\little_bomb.wav")->Play(1);
		GetWave(L"ENEMY_ATACK\\little_bomb.wav")->SetVolume(0.11f);
	}
	void* operator new(size_t n){ return Bullet6List.New(n); }
	void operator delete(void* p) { Bullet6List.Delete(p); }
	CBullet6() : CMyMover(Bullet6List) {}
	void Reset();
	void Move();
};
// パチコマビーム
class CBullet7 : public CMyMover {
public:
	float S_X = 0;
	float S_Y = 0;
	float S_Z = 0;
	void* operator new(size_t n){ return Bullet7List.New(n); }
	void operator delete(void* p) { Bullet7List.Delete(p); }
	CBullet7() : CMyMover(Bullet7List) {}
	void Reset();
	void Move();
};
// パチコマビーム(球)
class CBullet8 : public CMyMover {
public:
	int TIME_COUNT = 0;
	int S_COUNT = 0;
	float S_X = 0;
	float S_Y = 0;
	float S_Z = 0;
	void* operator new(size_t n){ return Bullet8List.New(n); }
	void operator delete(void* p) { Bullet8List.Delete(p); }
	CBullet8() : CMyMover(Bullet8List) {}
	void Reset();
	void Move();
};
// BOSS_gun弾
class CBullet9 : public CMyMover {
public:
	int HOMING_TIME=0;
	void* operator new(size_t n){ return Bullet9List.New(n); }
	void operator delete(void* p) { Bullet9List.Delete(p); }
	CBullet9() : CMyMover(Bullet9List) {}
	void Reset();
	void Move();
};