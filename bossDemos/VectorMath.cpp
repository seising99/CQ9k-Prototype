#include "VectorMath.h"

const sf::Vector2f VectorMath::Normalize(const sf::Vector2f &_vector)
{
	float vLength = sqrt(abs(_vector.x * _vector.x) + abs(_vector.y * _vector.y));
	return sf::Vector2f((_vector.x / vLength), (_vector.y / vLength));
}

const float VectorMath::Length(const sf::Vector2f& _vector)
{
	return sqrt(abs(_vector.x * _vector.x) + abs(_vector.y * _vector.y));
}
