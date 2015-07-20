#include "Main.h"

int i;
// ����̏�����
void CWeapon::Reset() {
	wp = 10;
	Scale=CVector(1, 1, 1)*0.09f;
	GetWave(L"se_maoudamashii_system48.wav")->Play(1);
	GetWave(L"se_maoudamashii_system48.wav")->SetVolume(0.07f);
	
}

void CWeapon1::Reset() {
	Texture = GetTexture(L"Block2.png");
	Scale = CVector(1, 1, 1)*0.07f;
}

void CWeapon2::Reset() {
	
	Scale = CVector(1, 1, 1)*0.075f;
	wp = 50;
}

void CWeapon3::Reset() {
	Texture = GetTexture(L"fork1.png");
	Scale = CVector(1, 1, 1)*0.2f;
	wp = 500;
	State = 0;
	State1 = 0;

	CMover *a = this, *b;
	for (int i = 0; i<1; i++) {
		b = New<CBlock21>(Position);
		b->Owner = a;
		a = b;
	}
}

void CWeapon4::Reset() {
	Texture = GetTexture(L"hosikuki.png");
	Scale = CVector(1, 1, 1)*0.2f;
	wp = 1;
	State = 0;
	State1 = 0;
}

void CWeapon5::Reset() {

	Texture = GetTexture(L"konpeitou.png");
	Scale = CVector(1, 1, 1)*0.1f;

}
void CWeapon6::Reset() {

	Texture = GetTexture(L"tama.png");
	Scale = CVector(1, 1, 1)*0.07f;

}
void CWeapon7::Reset() {
	wp = 2;
	Texture = GetTexture(L"momobuki.png");
	Scale = CVector(1, 1, 1)*0.07f;
	GetWave(L"b_040.wav")->Play(1);
	GetWave(L"b_040.wav")->SetVolume(0.07f);

}
void CWeapon8::Reset() {

	Texture = GetTexture(L"tetutoge.png");
	Scale = CVector(1, 1, 1)*0.1f;

}
void CWeapon9::Reset() {

	Texture = GetTexture(L"tetutoge1.png");
	Scale = CVector(1, 1, 1)*0.1f;

}
void CWeapon10::Reset() {
	wp = 60;

	Texture = GetTexture(L"boss_kao1.png");
	Color = CColor(1, 0, 1, 1);
	wp = 100;

	CMover *c = this, *d;
	for (int q = 0; q < 1; q++) {
		d = New<CEnemy7>(Position);
		d->Owner = c;
		c = d;
	}
}
void CWeapon11::Reset(){
	Scale = CVector(1, 1, 1)*0.05f;
	Color = CColor(1, 1, 1, 1)*0.5f;
}
void CWeapon12::Reset(){
	Texture = GetTexture(L"iwa.png");
	Scale = CVector(1, 1, 1)*0.2f;
	Color = CColor(1, 1, 1, 1)*1.0f;
	
}
//-------------------------------------------------------------------------------------------------------------------------

// ����̈ړ�
void CWeapon::Move() {
	//Position += Velocity;
	Texture = GetTexture(L"Weapon2.png");
	Rotation *= RotationZ(0.01f);
	Position += Velocity;

	//�G����&�e����
	EnemyList.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.1f) {
			e->Life -= wp;
			if (e->Life == 0){
				Score += 100;
			}
			if (Length(e->Position - Position) < 0.3f){
				WeaponList.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}
		}});

		/*Enemy2List.Apply([&](CMover* e) {
			if (Length(e->Position - Position) < 0.1f) {
			e->Life -= wp;
			if (e->Life == 0){
			Score += 1000;
			}
			if (Length(e->Position - Position) < 0.1f){
			WeaponList.Apply([&](CMover* w) {
			w->Life = 0;
			});
			}
			}});*/
		//---------------------------------------------------------------------------------------------------------

		//BOSS�炠���蔻��
		Enemy7List.Apply([&](CMover* e) {
			if (Length(e->Position - Position) < 0.4f) {
				e->Life -= wp;
				if (e->Life == 0){
					Score += 1000;
				}
				if (Length(e->Position - Position) < 0.4f){
					WeaponList.Apply([&](CMover* w) {
						w->Life = 0;
					});
				}
			}});
			Enemy2List.Apply([&](CMover* e) {
				if (Length(e->Position - Position) < 0.3f) {
					Life = 0;
				}
			});

//-----------------------------------------------------------------------------------------------------



			Enemy3List.Apply([&](CMover* e) {
				if (Length(e->Position - Position) < 0.1f) {
					e->Life -= wp;
					if (e->Life == 0){
						Score += 100;
					}
					if (Length(e->Position - Position) < 0.1f){
						WeaponList.Apply([&](CMover* w) {
							w->Life = 0;
						});
					}
				}});

				Enemy5List.Apply([&](CMover* e) {
					if (Length(e->Position - Position) < 0.1f) {
						e->Life -= wp;
						if (e->Life == 0){
							Score += 100;
						}
						if (Length(e->Position - Position) < 0.1f){
							WeaponList.Apply([&](CMover* w) {
								w->Life = 0;
							});
						}
					}});
//�u���b�N����
	Block1List.Apply([&](CMover* b) {
		if (Length(b->Position - Position) < 0.1f) {
			b->Life -= wp;
			if (Length(b->Position - Position) < 0.1f){
				WeaponList.Apply([&](CMover* w) {
					w->Life = 0;
					if (b->Life == 0) { New<CEffect4>(b->Position); }
				});}
		}});

		//�����XD����
		Block2List.Apply([&](CMover* b) {
			if (Length(b->Position - Position) < 0.1f) {
				b->Life -= wp;
				if (b->Life == 0){
					BP -= 1;
				}
				if (Length(b->Position - Position) < 0.1f){
					WeaponList.Apply([&](CMover* w) {
						w->Life = 0;
						if (b->Life == 0) { New<CEffect6>(b->Position); }
					});
				}
			}});

			//�����XR����
			Block6List.Apply([&](CMover* b) {
				if (Length(b->Position - Position) < 0.18f) {
					b->Life -= wp;
					//b->Life = 0;
					if (b->Life <= 0){
						BP -= 1;
					}
					if (Length(b->Position - Position) < 0.18f){
						WeaponList.Apply([&](CMover* w) {
							w->Life = 0;
							if (b->Life == 0) { New<CEffect6>(b->Position); }
						});
					}
				}});

				//�����XL����
				Block7List.Apply([&](CMover* b) {
					if (Length(b->Position - Position) < 0.18f) {
						b->Life -= wp;
						//b->Life = 0;
						if (b->Life <= 0){
							BP -= 1;
						}
						if (Length(b->Position - Position) < 0.18f){
							WeaponList.Apply([&](CMover* w) {
								w->Life = 0;
								if (b->Life == 0) { New<CEffect6>(b->Position); }
							});
						}
					}});

//�Q�[�g�A�C�e���Q�b�g
	Item4List.Apply([&](CMover* i) {
		if (Length(i->Position - Position) < 0.2f) {
			i->Life--;}
	});
}

//----------------------------------------------------------------------------------------------------------------------------
//���e
void CWeapon2::Move() {
	Position += Velocity;
	Texture = GetTexture(L"bom.png");
	Rotation *= RotationZ(0.01f);

	MyShipList.Apply([&](CMover* m) {

		if (m->Type == 2){
			Velocity.Y -= 0.03f;
			if (Time % 10 == 0){
				Velocity.Y += 0.15f;
				Velocity.X += 0.02f;
				Time++;
			}
		}

		if (m->Type == 1){
			Velocity.Y -= 0.03f;
			if (Time % 10 == 0){
				Velocity.Y += 0.15f;
				Velocity.X -= 0.02f;
				Time++;
			}
		}
	});

	//�G���j
	EnemyList.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.2f) {
			e->Life -= wp;
			New<CEffect5>(e->Position);
			if (e->Life == 0){
				Score += 100;
			}
			if (Length(e->Position - Position) < 0.2f){
				Weapon2List.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}
		}});

		Enemy7List.Apply([&](CMover* e) {
			if (Length(e->Position - Position) < 0.4f) {
				e->Life -= wp;
				New<CEffect5>(e->Position);
				if (e->Life == 0){
					//Score += 100;
				}
				if (Length(e->Position - Position) < 0.4f){
					Weapon2List.Apply([&](CMover* w) {
						w->Life = 0;
					});
				}
			}});
			Enemy2List.Apply([&](CMover* e) {
				if (Length(e->Position - Position) < 0.4f) {
					//e->Life -= wp;
					New<CEffect5>(e->Position);
					if (e->Life == 0){
						//Score += 100;
					}
					if (Length(e->Position - Position) < 0.4f){
						Weapon2List.Apply([&](CMover* w) {
							w->Life = 0;
						});
					}
				}});

		//Boss���j
		/*Enemy2List.Apply([&](CMover* e) {
			if (Length(e->Position - Position) < 0.3f) {
				e->Life -= wp;
					New<CEffect5>(e->Position);
				if (Length(e->Position - Position) < 0.3f){
					Weapon2List.Apply([&](CMover* w) {
						w->Life = 0;
					});
					if (e->Life == 0){
						Score += 1000;
					}
				}
			}});*/

		//BOSS�炠���蔻��
		Enemy7List.Apply([&](CMover* e) {
			if (Length(e->Position - Position) < 0.1f) {
				e->Life -= wp;
				New<CEffect5>(e->Position);
				if (e->Life == 0){
					Score += 1000;
				}
				if (Length(e->Position - Position) < 0.1f){
					WeaponList.Apply([&](CMover* w) {
						w->Life = 0;
					});
				}
			}});

			Enemy3List.Apply([&](CMover* e) {
				if (Length(e->Position - Position) < 0.1f) {
					e->Life -= wp;
					if (e->Life == 0){
						New<CEffect5>(e->Position);
						Score += 100;
					}
					if (Length(e->Position - Position) < 0.1f){
						Weapon2List.Apply([&](CMover* w) {
							w->Life = 0;
						});
					}
				}});

				Enemy5List.Apply([&](CMover* e) {
					if (Length(e->Position - Position) < 0.1f) {
						e->Life -= wp;
						if (e->Life == 0){
							Score += 100;
						}
						if (Length(e->Position - Position) < 0.1f){
							WeaponList.Apply([&](CMover* w) {
								w->Life = 0;
							});
						}
					}});

		//�u���b�N���e���j�G�t�F�N�g
		BlockList.Apply([&](CMover* b) {
			if (Length(b->Position - Position) < 0.18f) {
				
					New<CEffect5>(b->Position);
			}});
			//�ԃu���b�N���e���j�G�t�F�N�g
			Block3List.Apply([&](CMover* b) {
				if (Length(b->Position - Position) < 0.18f) {

					New<CEffect5>(b->Position);
				}});
				//���u���b�N���e���j�G�t�F�N�g
				Block5List.Apply([&](CMover* b) {
					if (Length(b->Position - Position) < 0.18f) {

						New<CEffect5>(b->Position);
					}});
				//�����XD���e���j�G�t�F�N�g
				Block2List.Apply([&](CMover* b) {
						if (Length(b->Position - Position) < 0.18f) {

							New<CEffect5>(b->Position);
						}});

				//�����XR���e���j�G�t�F�N�g
				Block6List.Apply([&](CMover* b) {
						if (Length(b->Position - Position) < 0.18f) {

							New<CEffect5>(b->Position);
						}});

				//�����XL���e���j�G�t�F�N�g
				Block7List.Apply([&](CMover* b) {
						if (Length(b->Position - Position) < 0.18f) {

							New<CEffect5>(b->Position);
						}});

				//�X�u���b�N���e���j�G�t�F�N�g
				Block1List.Apply([&](CMover* b) {
					if (Length(b->Position - Position) < 0.25f) {

						New<CEffect5>(b->Position);
					}});

				// �u���b�N����
					Block1List.Apply([&](CMover* b) {
					if (Length(b->Position - Position) < 0.25f) {
						b->Life -= wp;
						if (Length(b->Position - Position) < 0.25f){
							Weapon2List.Apply([&](CMover* w) {
								w->Life = 0;
								if (b->Life == 0) { New<CEffect4>(b->Position); }
							});
						}
					}});

					//�G�o���Q�[�g���C�t����
					Item4List.Apply([&](CMover* i) {
						if (Length(i->Position - Position) < 0.2f) {
							i->Life-=wp;
							Life = 0;
							New<CEffect5>(i->Position);
						}
					});

					//�����XD���ŃG�t�F�N�g
					Block2List.Apply([&](CMover* b) {
						if (Length(b->Position - Position) < 0.18f) {
							b->Life -= wp;
							if (b->Life <= 0){
								BP -= 1;
							}
							if (Length(b->Position - Position) < 0.18f){
								Weapon2List.Apply([&](CMover* w) {
									w->Life = 0;
									if (b->Life == 0) { New<CEffect6>(b->Position); }
								});
							}
						}});

						//�����XR���ŃG�t�F�N�g
						Block6List.Apply([&](CMover* b) {
							if (Length(b->Position - Position) < 0.18f) {
								b->Life -= wp;
								if (b->Life <= 0){
									BP -= 1;
								}
								if (Length(b->Position - Position) < 0.18f){
									Weapon2List.Apply([&](CMover* w) {
										w->Life = 0;
										if (b->Life == 0) { New<CEffect6>(b->Position); }
									});
								}
							}});

						//�����XL���ŃG�t�F�N�g
						Block7List.Apply([&](CMover* b) {
							if (Length(b->Position - Position) < 0.18f) {
								b->Life -= wp;
								if (b->Life <= 0){
									BP -= 1;
								}
								if (Length(b->Position - Position) < 0.18f){
									Weapon2List.Apply([&](CMover* w) {
										w->Life = 0;
										if (b->Life == 0) { New<CEffect6>(b->Position); }
									});
								}
							}});

							//���َq�u���b�N1���j�G�t�F�N�g
							Block8List.Apply([&](CMover* b) {
								if (Length(b->Position - Position) < 0.18f) {

									New<CEffect5>(b->Position);
								}});

							//���َq�u���b�N2���j�G�t�F�N�g
							Block9List.Apply([&](CMover* b) {
								if (Length(b->Position - Position) < 0.18f) {

										New<CEffect5>(b->Position);
									}});

							//���َq�u���b�N3���j�G�t�F�N�g
							Block9List.Apply([&](CMover* b) {
									if (Length(b->Position - Position) < 0.18f) {

											New<CEffect5>(b->Position);
										}});

							//���َq�u���b�N4���j�G�t�F�N�g
							Block10List.Apply([&](CMover* b) {
									if (Length(b->Position - Position) < 0.18f) {

												New<CEffect5>(b->Position);
										}});

							//���َq�u���b�N1���j�G�t�F�N�g
							Block11List.Apply([&](CMover* b) {
									if (Length(b->Position - Position) < 0.18f) {

												New<CEffect5>(b->Position);
										}});

							//����1���j�G�t�F�N�g
							Block12List.Apply([&](CMover* b) {
									if (Length(b->Position - Position) < 0.18f) {

										    	New<CEffect5>(b->Position);
										}});

							//����2���j�G�t�F�N�g
							Block13List.Apply([&](CMover* b) {
									if (Length(b->Position - Position) < 0.18f) {

												New<CEffect5>(b->Position);
										}});

							//����3���j�G�t�F�N�g
							Block14List.Apply([&](CMover* b) {
										if (Length(b->Position - Position) < 0.18f) {

												New<CEffect5>(b->Position);
										}});

							//����4���j�G�t�F�N�g
							Block15List.Apply([&](CMover* b) {
										if (Length(b->Position - Position) < 0.18f) {

												New<CEffect5>(b->Position);
										}});

							//���َq�u���b�N1_1���j�G�t�F�N�g
							Block16List.Apply([&](CMover* b) {
										if (Length(b->Position - Position) < 0.18f) {

												New<CEffect5>(b->Position);
										}});

							//���َq�u���b�N2_1���j�G�t�F�N�g
							Block17List.Apply([&](CMover* b) {
										if (Length(b->Position - Position) < 0.18f) {

										       	New<CEffect5>(b->Position);
										}});

							//���َq�u���b�N3_1���j�G�t�F�N�g
						    Block18List.Apply([&](CMover* b) {
										if (Length(b->Position - Position) < 0.18f) {

												New<CEffect5>(b->Position);
										}});

						    //���َq�u���b�N4_1���j�G�t�F�N�g
							Block19List.Apply([&](CMover* b) {
										if (Length(b->Position - Position) < 0.18f) {

												New<CEffect5>(b->Position);
										}});

							//���َq�P�[�L���j�G�t�F�N�g
					     	Block20List.Apply([&](CMover* b) {
										if (Length(b->Position - Position) < 0.25f) {

										     	New<CEffect5>(b->Position);
										}});

										//�L�����f�B�[�P�[�����j�G�t�F�N�g
										Block22List.Apply([&](CMover* b) {
											if (Length(b->Position - Position) < 0.2f) {

												New<CEffect5>(b->Position);
											}});

											/*//�L�����f�B�[�P�[�����j�G�t�F�N�g
											Block23List.Apply([&](CMover* b) {
												if (Length(b->Position - Position) < 0.4f) {

													New<CEffect5>(b->Position);
												}});*/

											//�ԕX���j�G�t�F�N�g
											Block25List.Apply([&](CMover* b) {
												if (Length(b->Position - Position) < 0.18f) {
													New<CEffect5>(b->Position);
												}});

												//�ԕX���j�G�t�F�N�g
												Block26List.Apply([&](CMover* b) {
													if (Length(b->Position - Position) < 0.18f) {
														New<CEffect5>(b->Position);
													}});

													//�ԕX���j�G�t�F�N�g
													Block27List.Apply([&](CMover* b) {
														if (Length(b->Position - Position) < 0.18f) {
															New<CEffect5>(b->Position);
														}});

														//�S�u���b�N���j�G�t�F�N�g
														Block28List.Apply([&](CMover* b) {
															if (Length(b->Position - Position) < 0.18f) {
																New<CEffect5>(b->Position);
															}});
		//�u���b�N�����蔻��
		CHitRectangle hit;
		Apply(BlockList, hit);
		Apply(Block1List, hit);
		Apply(Block2List, hit);
		Apply(Block3List, hit);
		Apply(Block4List, hit);
		Apply(Block5List, hit);
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
		//Apply(Block23List, hit);
}
//-----------------------------------------------------------------------------------------------------
//�t�H�[�N��[
void CWeapon3::Move() {
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.22f) {
			m->Life -= wp;
		}});

		Position.Y -= 0.02f;

		if (State == 0){
			State1++;
			if (State1 <= 180){
				//Position.Y -= 0.04f;
			}}

		if (State == 1){
			State1++;
			if (State1 <= 180){
				Position.Y += 0.03f;
			}}

		if (State == 1 && State1 >= 180){
			State = 0;
			State1 = 0;
		}

	Block8List.Apply([&](CMover* b) {
		if (Length(b->Position - Position)<0.3f) {
			State = 1;
			State1 = 0;
		}});
	Block9List.Apply([&](CMover* b) {
		if (Length(b->Position - Position)<0.3f) {
			State = 1;
			State1 = 0;
		}});
	Block10List.Apply([&](CMover* b) {
		if (Length(b->Position - Position)<0.3f) {
		    State = 1;
			State1 = 0;
		}});
	Block11List.Apply([&](CMover* b) {
		if (Length(b->Position - Position)<0.3f) {
			State = 1;
			State1 = 0;
		}});

	//�u���b�N�����蔻��
	CHitRectangle hit;
	Apply(Block2List, hit);
	Apply(Block6List, hit);
	Apply(Block7List, hit);
	Apply(Block8List, hit);
	Apply(Block9List, hit);
	Apply(Block10List, hit);
	Apply(Block11List, hit);
	Apply(Block22List, hit);
	Apply(Block23List, hit);
}

//------------------------------------------------------------------------------------------------------
//���N�b�L�[
void CWeapon4::Move() {
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.22f) {
			m->Life -= wp;
		}});
		Rotation *= RotationZ(0.01f);

		//�u���b�N�����蔻��
		CHitRectangle hit;
		Apply(Block2List, hit);
		Apply(Block6List, hit);
		Apply(Block7List, hit);
		Apply(Block8List, hit);
		Apply(Block9List, hit);
		Apply(Block10List, hit);
		Apply(Block11List, hit);
		Apply(Block22List, hit);
		Apply(Block23List, hit);
}

void CWeapon5::Move() {
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.1f) {
			m->Life = 0;
		}
	});

	EnemyList.Apply([&](CMover* e) {
		if (Length(e->Position - Position)<0.1f) {
			e->Life = 0;
		}
	});
}
//------------------------------------------------------------------------------------------
void CWeapon6::Move() {

	//Position.X -= 0.03f;
	Position += Velocity;
	Rotation *= RotationZ(0.02f);

	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.1f) {
			m->Life -= 20;
			Life = 0;
			New<CEffect5>(m->Position);
		}
	});

	Block22List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {New<CEffect5>(b->Position);}});
	Block23List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {	New<CEffect5>(b->Position);	}});
	Block2List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { b->Life = 0; BP -= 1; Life = 0;	New<CEffect5>(b->Position); }});

	BlockList.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {Life = 0;New<CEffect5>(b->Position);}});
	Block1List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {Life = 0;	New<CEffect5>(b->Position);	}});
	Block3List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {Life = 0;	New<CEffect5>(b->Position);	}});
	Block5List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {Life = 0;	New<CEffect5>(b->Position);	}});
	Block6List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { b->Life = 0; BP -= 1; Life = 0;	New<CEffect5>(b->Position); }});
	Block7List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { b->Life = 0; BP -= 1; Life = 0;	New<CEffect5>(b->Position); }});
	Block8List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {Life = 0;	New<CEffect5>(b->Position);}});
	Block9List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {Life = 0;	New<CEffect5>(b->Position);}});
    Block10List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {	Life = 0;New<CEffect5>(b->Position);}});
	Block12List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) {	Life = 0;New<CEffect5>(b->Position);}});
    Block13List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
	Block14List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
    Block15List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
	Block16List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
	Block17List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
	Block18List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
    Block19List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
	Block20List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
	Block21List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
    Block25List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
	Block26List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
	Block27List.Apply([&](CMover* b) {if (Length(b->Position - Position) < 0.18f) { Life = 0; New<CEffect5>(b->Position); }});
}
//-----------------------------------------------------------------------------------------------------------------------------------
//���u�[������
void CWeapon7::Move() {

	//�u���b�N����
	Block1List.Apply([&](CMover* b) {
		if (Length(b->Position - Position) < 0.1f) {
			GetWave(L"b_066.wav")->Play(1);
			GetWave(L"b_066.wav")->SetVolume(0.07f);
			b->Life -= wp;
			if (Length(b->Position - Position) < 0.1f){
				WeaponList.Apply([&](CMover* w) {
					//w->Life = 0;
					if (b->Life == 0) { New<CEffect4>(b->Position); }
				});
			}
		}});

		//�����XD����
		Block2List.Apply([&](CMover* b) {
			if (Length(b->Position - Position) < 0.1f) {
				GetWave(L"b_066.wav")->Play(1);
				GetWave(L"b_066.wav")->SetVolume(0.07f);
				b->Life -= wp;
				if (b->Life == 0){
					BP -= 1;
				}
				if (Length(b->Position - Position) < 0.1f){
					Weapon7List.Apply([&](CMover* w) {
						//w->Life = 0;
						if (b->Life <= 0) { New<CEffect6>(b->Position); }
					});
				}
			}});

			//�����XR����
			Block6List.Apply([&](CMover* b) {
				if (Length(b->Position - Position) < 0.18f) {
					GetWave(L"b_066.wav")->Play(1);
					GetWave(L"b_066.wav")->SetVolume(0.07f);
					b->Life -= wp;
					//b->Life = 0;
					if (b->Life <= 0){
						BP -= 1;
					}
					if (Length(b->Position - Position) < 0.18f){
						Weapon3List.Apply([&](CMover* w) {
							w->Life = 0;
							if (b->Life <= 0) { New<CEffect6>(b->Position); }
						});
					}
				}});

				//�����XL����
				Block7List.Apply([&](CMover* b) {
					if (Length(b->Position - Position) < 0.18f) {
						GetWave(L"b_066.wav")->Play(1);
						GetWave(L"b_066.wav")->SetVolume(0.07f);
						b->Life -= wp;
						//b->Life = 0;
						if (b->Life <= 0){
							BP -= 1;
						}
						if (Length(b->Position - Position) < 0.18f){
							WeaponList.Apply([&](CMover* w) {
								w->Life = 0;
								if (b->Life == 0) { New<CEffect6>(b->Position); }
							});
						}
					}});

					//�Q�[�g�A�C�e���Q�b�g
					Item4List.Apply([&](CMover* i) {
						if (Length(i->Position - Position) < 0.2f) {
							i->Life--;
						}
					});

	EnemyList.Apply([&](CMover* e) {
		if (Length(e->Position - Position) < 0.3f) {
			e->Life -= wp;
			GetWave(L"b_066.wav")->Play(1);
			GetWave(L"b_066.wav")->SetVolume(0.07f);
			if (e->Life == 0){
				Score += 100;
			}
			if (Length(e->Position - Position) < 0.3f){
				WeaponList.Apply([&](CMover* w) {
					w->Life = 0;
				});
			}
		}});

		/*Enemy2List.Apply([&](CMover* e) {
			if (Length(e->Position - Position) < 0.1f) {
				e->Life -= wp;
				if (e->Life == 0){
					Score += 1000;
				}
				if (Length(e->Position - Position) < 0.1f){
					WeaponList.Apply([&](CMover* w) {
						w->Life = 0;
					});
				}
			}});*/

		//BOSS�炠���蔻��
		Enemy7List.Apply([&](CMover* e) {
			if (Length(e->Position - Position) < 0.1f) {
				GetWave(L"b_066.wav")->Play(1);
				GetWave(L"b_066.wav")->SetVolume(0.07f);
				e->Life -= wp;
				if (e->Life == 0){
					Score += 1000;
				}
				if (Length(e->Position - Position) < 0.1f){
					WeaponList.Apply([&](CMover* w) {
						w->Life = 0;
					});
				}
			}});
		

			Enemy3List.Apply([&](CMover* e) {
				if (Length(e->Position - Position) < 0.1f) {
					GetWave(L"b_066.wav")->Play(1);
					GetWave(L"b_066.wav")->SetVolume(0.07f);
					e->Life -= wp;
					if (e->Life == 0){
						Score += 100;
					}
					if (Length(e->Position - Position) < 0.1f){
						WeaponList.Apply([&](CMover* w) {
							w->Life = 0;
						});
					}
				}});

				Enemy5List.Apply([&](CMover* e) {
					if (Length(e->Position - Position) < 0.1f) {
						GetWave(L"b_066.wav")->Play(1);
						GetWave(L"b_066.wav")->SetVolume(0.07f);
						e->Life -= wp;
						if (e->Life == 0){
							Score += 100;
						}
						if (Length(e->Position - Position) < 0.1f){
							WeaponList.Apply([&](CMover* w) {
								w->Life = 0;
							});
						}
					}});

	if (Time>30) {
		MyShipList.Apply([&](CMover* m) {
			Rotation.Homing(
				CQuaternion(AXIS_Y, m->Position - Position), 0.04f);
			if (Length(Position - m->Position)<0.2f) Life = 0;
		});
	}
	Position += AxisY()*0.03f;
	Time++;

}
//-------------------------------------------------------------------------------------------------------------------------
void CWeapon8::Move() {
	//�u���b�N�����蔻��
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


	//Scale = CVector(1, 1, 1)*0.1f;
	Scale = CVector(1, 0.31, 1)*0.1f;
	Position = Owner->Position + CVector(0, -0.130f, 0);
	
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.15f) {
			m->Life -= 5000;
		}
	});

	
}

void CWeapon9::Move() {
	//�u���b�N�����蔻��
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


	//Scale = CVector(1, 1, 1)*0.1f;
	Scale = CVector(1, 0.31, 1)*0.1f;
	Position = Owner->Position + CVector(0, 0.130f, 0);

	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position)<0.15f) {
			m->Life -= 5000;
		}
	});

}
void CWeapon10::Move() {
	Scale = CVector(1.2f, 1, 1)*0.27f;
	Position = Owner->Position + CVector(0.04, 0.79f, 0);

	if (Time>30) {
		Enemy2List.Apply([&](CMover* m) {
			Rotation.Homing(
				CQuaternion(AXIS_Y, m->Position - Position), 0.04f);
			if (Length(Position - m->Position)<0.2f) Life = 0;
		});
	}
	Position += AxisY()*0.03f;
	Time++;
}
void CWeapon11::Move() {
	New<CEffect21>(Position);
	Position = Owner->Position + CVector(0, 0.2f, 0)*Rotation;
	Rotation *= RotationZ(0.02f);
	if (Time % 60 == 10)Texture = GetTexture(L"kurima1.png");
	if (Time % 60 == 20)Texture = GetTexture(L"kurima2.png");
	if (Time % 60 == 30)Texture = GetTexture(L"kurima3.png");
	if (Time % 60 == 40)Texture = GetTexture(L"kurima4.png");
	if (Time % 60 == 50)Texture = GetTexture(L"kurima5.png");
	Time++;

	
		New<CEffect22>(Position)->Owner = this;
	
	
}
void CWeapon12::Move() {
	New<CEffect23>(Position);
	Position.Y -= 0.02f;

	//BOSS��ڐG��
	MyShipList.Apply([&](CMover* m) {
		if (Length(m->Position - Position) < 0.2f) {
			m->Life-=10;
			//Score += 100;
		}
	});

	Weapon5List.Apply([&](CMover* m) {
		if (Length(m->Position - Position) < 0.2f) {
			Life = 0;
		}
		});
}