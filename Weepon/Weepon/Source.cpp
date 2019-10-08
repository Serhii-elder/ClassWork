#include<iostream>
#include<string>

using namespace std;

class Weapon {
private:
	float caliber;
	int damage;
	double distanc;

	virtual Bullet* CreateBullet() = 0;
public:
	Weapon(float caliber, int damage, double distanc) {
		this->caliber = caliber;
		this->damage = damage;
		this->distanc = distanc;
	}
	Bullet* Shot(){
		Bullet *m = CreateBullet();

		m->StartMove();
		m->Set(7.6,5.1,600);
	}
};

class Bullet {
private:
	float caliber;
	float weight;
	double speed;
public:
	Bullet(float caliber, float weight, double speed) {
		this->caliber = caliber;
		this->weight = weight;
		this->speed = speed;
	}
	virtual void StartMove() {
		cout << "I am Bullet , I started!" << endl;
	};
	virtual void Hit() = 0;

	void Set(float caliber, float weight, double speed) {
		this->caliber = caliber;
		this->weight = weight;
		this->speed = speed;
	}
};

class Automat : public Weapon {
	
private:
	Automat() : Weapon(7.6, 600, 2.1){}

};

class Shotgun : public Weapon {
	
private:
	Shotgun() : Weapon(5.5, 400, 1.8) {}

};

class AutomaticBulet : public Bullet{

public:
	AutomaticBulet():Bullet(5.5, 400, 1.8){}

	virtual void Hit() {
		cout << "i am automat bullet HIIIIT" << endl;
	}
	virtual void StartMove() {
		cout << "I am Bullet of automat , I started!" << endl;
	}
};

class ShotganBullet : public Bullet{

public:
	ShotganBullet():Bullet(4.5, 300, 1.2){}

	virtual void Hit() {
		cout << "i am shotgan bullet HIIIIT" << endl;
	}
	virtual void StartMove() {
		cout << "I am Bullet of shotgan , I started!" << endl;
	}
};

