#include <iostream>

enum Event { EVENT_ENTITY_FELL };
enum Achievemnet { ACHIEVEMENT_FELL_OFF_BRIDGE };

class Entity 
{
public:
	int isHero() const {};
};

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(const Entity& entity, Event event) = 0;
};

bool heroIsOnBridge_;

class Achievemnets : public Observer
{
public:
	virtual void onNotiy(const Entity& entity, Event event)
	{
		switch (event)
		{
		case EVENT_ENTITY_FELL:
			if (entity.isHero() && heroIsOnBridge_)
			{
				unlock(ACHIEVEMENT_FELL_OFF_BRIDGE);
			}
			break;

			// Handle other events...
			// Update heriIsOnBridge_...
		}
	}

private:
	void unlock(Achievemnet achievement)
	{
		// Unlock if not already unlocked...
	}

	bool heroIsOnBridge_;
};

int main()
{
	
}
