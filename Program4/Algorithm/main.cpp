#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <Windows.h>
#include <memory.h>

using namespace std;

// new - delete => 

template <typename T>
using Uptr = std::unique_ptr<T>;		//	치환 패턴

enum class ItemType {WEAPON, ARMOR, CONSUMABLE};
enum class WeaponType {SWORD, BOW};
enum class ArmorType {HELMET, ARMOR};
enum class consumableType {POTION};

// base 클래스. 
// ~소멸자 base에서 virtual 선언.
class Item
{
public:
	Item(ItemType type, int id, string name) : _type(type), _id(id), _name(name) {} // ctor입력, 탭을 누르면 단축키 자동완성
	virtual ~Item() = default;

	virtual void Use() {}

public:
	ItemType _type;
	int _id;
	string _name;
};

class WeaponItem : public Item
{
public:
	WeaponItem(ItemType type, int id, string name, WeaponType wtype, int damage)
		: Item{ type, id, name }, _wtype(wtype), _damage(damage) 
	{
		type = ItemType::WEAPON;
	}

	void Use() override
	{
		// 아이템 장착(Equip)
		// 무기를 휘둘렀다. 
		cout << "[" << _name <<"] 사용했다." << "공격력 : " << _damage << endl;
	}

public:
	WeaponType _wtype;
	int _damage;
};

class ArmorItem : public Item
{
public:
	ArmorItem(ItemType type, int id, string name, WeaponType wtype, int defence)
		: Item{ id, name }, _atype(atype), _defence(defence) 
	{
		type = ItemType::WEAPON;
	}

	void Use() override
	{
		// 아이템 장착(Equip)
		// 무기를 휘둘렀다. 
		cout << "[" << _name << "] 사용했다." << "공격력 : " << _defence << endl;
	}

public:
	ArmorType _atype;
	int _defence;
};

class ConsumableItem : public Item
{
public:
	consumableItem(ItemType type, int id, string name, WeaponType wtype, int stack)
		: Item{ type, id, name }, _ctype(ctype), _stack(_stack) 
	{}

	void Use() override
	{
		// 아이템 장착(Equip)
		// 무기를 휘둘렀다. 
		cout << "[" << _name << "] 사용했다." << "공격력 : " << _stack << endl;
	}

public:
	ConsumableType _ctype;
	int _stack;
};

int main()
{
	srand(time(0));
#pragma region Item
	unordered_map<int, Uptr<Item>> itemDict;

	vector<Uptr<WeaponItem>> weapons;
	vector<Uptr<ArmorItem>> armors;
	vector<Uptr<ConsumableItem>> consumables;

	weapons.push_back(make_unique<WeaponItem>(1, "검", WeaponType::SWORD, 10));
	weapons.push_back(make_unique<WeaponItem>(2, "활", WeaponType::BOW, 5));

	armors.push_back(make_unique<ArmorItem>(100, "투구", ArmorType::HELMET, 2));
	armors.push_back(make_unique<ArmorItem>(101, "갑옷", ArmorType::ARMOR, 3));

	consumables.push_back(make_unique<ArmorItem>(200, "갑옷", consumableType::POTION, 1));


	for (auto& w : weapons)
		itemDict.insert({ w->_id, std::move(w) });
	for (auto& a : armors)
		itemDict.insert({ a->_id, std::move(a) });
	for (auto& c : consumables)
		itemDict.insert({ c->_id, std::move(c) });

#pragma 

	if (!itemDict.empty())
	{
		int randValue = rand() % itemDict.size();
		auto it = itemDict.begin();

		advance(it, randValue);		//		iterator 반복문 버전.

		Item* itemTemp = it->second.get();

		cout << "아이템 획득: " << itemTemp->_name << endl;

		itemTemp->Use();
	}
}