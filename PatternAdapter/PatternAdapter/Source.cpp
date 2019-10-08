#include <iostream>

using namespace std;

class ClassicCar {
public:

	virtual void PressGasPedal() {
		cout << "Press gas pedal!" << endl;
	}
	virtual void PressStopPedal() {
		cout << "Press stop pedal!" << endl;
	}
	virtual void ShiftGearForvard() {
		cout << "Shift gear forvard!" << endl;
	}
	virtual void ShiftGearBack() {
		cout << "Shift the gear back!" << endl;
	}
};
class GameCar {
public:
	virtual void PressRight() {
		cout << "Drive Right!" << endl;
	}
	virtual void PressLeft() {
		cout << "Drive Left!" << endl;
	}
	virtual void PressForvard() {
		cout << "Drive Forvard!" << endl;
	}
	virtual void PressBack() {
		cout << "Drive Back!" << endl;
	}
	virtual void PressB() {
		cout << "Shift the gear back!" << endl;
	}virtual void PressA() {
		cout << "Shift gear forward!" << endl;
	}
	virtual void PressD() {
		cout << "Car stoping!" << endl;
	} 

};
class Adapter : public ClassicCar{
private:
	GameCar & drive;
public:
	Adapter(GameCar & driver) : drive(driver){}
		
	void PressGasPedal() {
		drive.PressForvard();
	}
	void PressStopPedal() {
		drive.PressD();
	}
	void ShiftGearForvard() {
		drive.PressA();
	}
	void ShiftGearBack() {
		drive.PressB();
	}
};
class Driver {
public:
	void Drive(ClassicCar car)
	{
		car.PressGasPedal();
		car.PressStopPedal();
		car.ShiftGearBack();
		car.ShiftGearForvard();
	}
};
void main()
{
	GameCar carr;

	Driver b;
	b.Drive(Adapter(carr));

	system("pause");
}