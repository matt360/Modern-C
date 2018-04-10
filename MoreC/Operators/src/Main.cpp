// Operators
/*
Operators are just functions.
*/

//CODE

#include <iostream>

struct Vector2
{
	float x, y;

	Vector2(float x, float y)
		: x(x), y(y) {}


	Vector2 Add(const Vector2& other) const // const since it's not going to modify the contents of the vector - it will create a new class
	{
		return Vector2(x + other.x, y + other.y);
	}

	// operator overloading - the way we define this is just like any other function
	// we write the return type, instead of the function name we write the word 'operator' and the sign we want to overload,
	// we open up the parantheses and pass the parameter
	Vector2	operator+(const Vector2& other) const
	{
        return Add(other);
	}

	Vector2 Multiply(const Vector2& other) const // const - since we're not going to modify the contents of the class
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2	operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}
	
	bool operator!=(const Vector2& other) const
	{
		return !(*this == other);
		//return !operator==(other); // the same as above
	}
	/*
	Vector2 Add(const Vector2& other) const // const - since we're not going to modify the contents of the class
	{
		//return *this + other;
		return operator+(other);
	}

	Vector2	operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Multiply(const Vector2& other) const // const since it's not going to modify the contents of the vector - it will create a new class
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2	operator*(const Vector2& other) const
	{
		return Multiply(other);
	}
	*/
};

// cout overloading
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position.Add(speed.Multiply(powerup));
	Vector2 result2 = position + speed * powerup;

	std::cout << result2 << std::endl;

	if (result1 == result2)
	{

	}

	std::cin.get();
}