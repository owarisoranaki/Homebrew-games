#include "Main.h"

// アイテムの初期化
void CItem::Reset() {
}

void CItem1::Reset() {
	Texture = GetTexture(L"Item.png");

	Scale = CVector(1, 1, 1)*0.1f;
}

void CItem2::Reset() {
	Texture = GetTexture(L"Effect.png");

	Scale = CVector(1, 1, 1)*0.1f;
}

void CItem3::Reset() {
	Texture = GetTexture(L"dokukinoko.png");

	Scale = CVector(1, 1, 1)*0.05f;
}

void CItem4::Reset() {//敵出現ゲート
	Texture = GetTexture(L"Bullet.png");
	Life = 30;
	Scale = CVector(1, 1, 1)*0.1f;
}

void CItem5::Reset() {

}

void CItem6::Reset() {

}

void CItem7::Reset() {

}
void CItem8::Reset() {

}
void CItem9::Reset() {

}
void CItem10::Reset() {

}
void CItem11::Reset() {

}
void CItem12::Reset() {

}
void CItem13::Reset() {

}

// アイテムの移動
void CItem::Move() {
	Position.Y -= 0.006f;//追加
	if (Time % 70 == 10)Texture = GetTexture(L"heart0.png");
	if (Time % 70 == 20)Texture = GetTexture(L"heart1.png");
	if (Time % 70 == 30)Texture = GetTexture(L"heart2.png");
	if (Time % 70 == 40)Texture = GetTexture(L"heart3.png");
	if (Time % 70 == 50)Texture = GetTexture(L"heart4.png");
	Scale = CVector(1, 1, 1)*0.05f;
	Time++;
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}
void CItem1::Move() {
	Position.Y -= 0.006f;//追加
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}
void CItem2::Move() {
}
void CItem3::Move() {
	Position.Y -= 0.006f;//追加
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}
void CItem4::Move() {
	if (Time % 120 == 0)New<CEnemy>(Position);
	Time++;
	//敵ゲート消滅
	WeaponList.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.1f) {
			w->Life = 0;

		}
	});

	//敵ゲート消滅1
	Weapon2List.Apply([&](CMover* w) {
		if (Length(w->Position - Position)<0.18f) {
			w->Life = 0;

		}
	});
	Position.Y -= 0.006f;//追加
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}
void CItem5::Move() {
	if (Time % 70 == 10)Texture = GetTexture(L"wapu0.png");
	if (Time % 70 == 20)Texture = GetTexture(L"wapu01.png");
	if (Time % 70 == 30)Texture = GetTexture(L"wapu02.png");
	if (Time % 70 == 40)Texture = GetTexture(L"wapu03.png");
	if (Time % 70 == 50)Texture = GetTexture(L"wapu04.png");
	Scale = CVector(1, 1, 1)*0.1f;
	Time++;
	Position.Y -= 0.006f;//追加
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}

void CItem6::Move() {
	Texture = GetTexture(L"bom.png");
	Scale = CVector(1, 1, 1)*0.05f;
	Position.Y -= 0.006f;//追加
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	//Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}

void CItem7::Move() {
	Texture = GetTexture(L"Weapon2.png");
	Scale = CVector(1, 1, 1)*0.08f;
	Position.Y -= 0.006f;//追加
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}
void CItem8::Move() {
	if (Time % 70 == 10)Texture = GetTexture(L"wapu0.png");
	if (Time % 70 == 20)Texture = GetTexture(L"wapu01.png");
	if (Time % 70 == 30)Texture = GetTexture(L"wapu02.png");
	if (Time % 70 == 40)Texture = GetTexture(L"wapu03.png");
	if (Time % 70 == 50)Texture = GetTexture(L"wapu04.png");
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(1, 0, 1, 1);
	Time++;
	Position.Y -= 0.006f;//追加
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}
void CItem9::Move() {
	if (Time % 70 == 10)Texture = GetTexture(L"wapu0.png");
	if (Time % 70 == 20)Texture = GetTexture(L"wapu01.png");
	if (Time % 70 == 30)Texture = GetTexture(L"wapu02.png");
	if (Time % 70 == 40)Texture = GetTexture(L"wapu03.png");
	if (Time % 70 == 50)Texture = GetTexture(L"wapu04.png");
	Scale = CVector(1, 1, 1)*0.1f;
	Time++;
	Position.Y -= 0.006f;//追加
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}
void CItem10::Move() {
	Texture = GetTexture(L"momobuki.png");
	Scale = CVector(1, 1, 1)*0.05f;
	Position.Y -= 0.006f;//追加
	//ブロックあたり判定
	CHitRectangle hit;
	Apply(BlockList, hit);
	Apply(Block1List, hit);
	Apply(Block2List, hit);
	Apply(Block3List, hit);
	Apply(Block5List, hit);
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
}
void CItem11::Move() {
	Texture = GetTexture(L"oke_small.png");
	Color = CColor(1, 1, 1, 0.0f);
	Scale = CVector(1, 1, 1)*0.1f;
}
void CItem12::Move() {
	Texture = GetTexture(L"hanten.png");
	Color = CColor(1, 1, 1, 1);
	Scale = CVector(1, 1, 1)*0.1f;
}
void CItem13::Move() {
	Texture = GetTexture(L"hanten1.png");
	Color = CColor(1, 1, 1, 1);
	Scale = CVector(1, 1, 1)*0.1f;
}