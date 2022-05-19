#include "Vector2D.h"
#include "freeglut.h"
#include <math.h>

Vector2D::Vector2D(float xv, float yv) {
	x = xv;
	y = yv;
}
Vector2D::~Vector2D() {}

Vector2D Vector2D::operator+(Vector2D op)
{
	Vector2D resultado;
	resultado.x = x + op.x;
	resultado.y = y + op.y;
	return Vector2D();
}

float Vector2D::modulo()
{
	return (float)sqrt(x * x + y * y);
}

float Vector2D::argumento()
{
	return (float)atan2(y, x);
}

Vector2D Vector2D::unitario()
{
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.0001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}



float Vector2D::operator*(Vector2D v)
{
	return (float)x * v.x + y * v.y;
}

Vector2D Vector2D::operator*(float n)
{
	x = x * n;
	y = y * n;
	return Vector2D();
}

Vector2D Vector2D::operator - (Vector2D v)
{
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}
