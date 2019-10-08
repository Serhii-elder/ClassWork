#include<iostream>
#include<string>

using namespace std;

class Processor {
protected:
	string name;
public:
	Processor(string name) {
		this->name = name;
	}
	virtual void ShowInfo() const {
		cout << "Processor: "<<name<<endl;
	}
};
class AMD : public Processor{
public:
	AMD() : Processor("Ryzen 3600"){}

	virtual void ShowInfo() const {
		cout << "Processor AMD: " << name << endl;
	}
};
class Intel : public Processor {
public:
	Intel() : Processor("i3 540") {}

	virtual void ShowInfo() const {
		cout << "Processor Intel: " << name << endl;
	}
};
class HDD {
protected:
	string name;
public:
	HDD(string name) {
		this->name = name;
	}
	virtual void ShowInfo() const {
		cout << "Memory: " << name << endl;
	}
};
class Hitachi : public HDD {
public:
	Hitachi() : HDD("Hitachi 5000") {}

	virtual void ShowInfo() const {
		cout << "HDD Hitachi: " << name << endl;
	}
};
class Panasonic : public HDD {
public:
	Panasonic() : HDD("Panasonic 4600") {}

	virtual void ShowInfo() const {
		cout << "HDD Panasonic: " << name << endl;
	}
};
class Memory {
protected:
	string name;
public:
	Memory(string name) {
		this->name = name;
	}
	virtual void ShowInfo() const {
		cout << "Memory: " << name << endl;
	}
};
class Tanbash : public Memory {
public:
	Tanbash() : Memory("Tanbash 2600") {}

	virtual void ShowInfo() const {
		cout << "Memory Tanbash: " << name << endl;
	}
};
class GoodRAM : public Memory {
public:
	GoodRAM() : Memory("GoodRAM 2400") {}

	virtual void ShowInfo() const {
		cout << "Memory GoodRAM: " << name << endl;
	}
};

class IPCFactory{
public:
	virtual Processor* GetProc() = 0;
	virtual HDD * GetHdd() = 0;
	virtual Memory * GetMemory() = 0;
};
class GamePCFactory : public IPCFactory{
public:
	Processor* GetProc() {
		return new AMD();
	}
	Memory * GetMemory() {
		return new Tanbash();
	}
	HDD * GetHdd() {
		return new Hitachi();
	}
};
class OfficePCFactory : public IPCFactory {
public:
	Processor* GetProc() {
		return new Intel();
	}
	Memory* GetMemory() {
		return new GoodRAM();
	}
	HDD* GetHdd() {
		return new Panasonic();
	}
};
void main()
{
	IPCFactory* factory = new OfficePCFactory();

	Processor * proc = factory->GetProc();
	HDD* hdd = factory->GetHdd();
	Memory* memory = factory->GetMemory();

	proc->ShowInfo();
	hdd->ShowInfo();
	memory->ShowInfo();

	system("pause");
}