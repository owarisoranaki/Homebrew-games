// 武器（ブレード）
class CWeapon : public CMyMover {
public:
	int ENEMY_COLOR_TIME = 0;
	int ENEMY_BLADE_HIT = 0;
	int ENEMY_BLADE_HIT2 = 0;
	int ENEMY_BLADE_HIT3 = 0;
	int ENEMY_GUNSHOT_HIT = 0;
	int ENEMY2_BLADE_HIT = 0;
	int ENEMY3_BLADE_HIT = 0;
	int ENEMY_TIME = 0;
	int ENEMY_TIME2 = 0;
	int ENEMY_TIME3 = 0;

	void Blade_hit_se(){
		GetWave(L"ACTION\\blade.wav")->Play(1);
		GetWave(L"ACTION\\blade.wav")->SetVolume(0.5f);
	}
	void* operator new(size_t n) { return WeaponList.New(n); }
	void operator delete(void* p) { WeaponList.Delete(p); }
	CWeapon() : CMyMover(WeaponList) {}
	void Reset();
	void Move();
};

// 武器（ガン）
class CWeapon_Gun : public CMyMover {
public:
	void* operator new(size_t n){ return Weapon_GunList.New(n); }
	void operator delete(void* p) { Weapon_GunList.Delete(p); }
	CWeapon_Gun() : CMyMover(Weapon_GunList) {}
	void Reset();
	void Move();
};

