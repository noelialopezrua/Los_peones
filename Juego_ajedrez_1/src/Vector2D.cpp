#include "Vector2D.h"
#include "freeglut.h"
#include <math.h>

Vector2D::Vector2D(float xv, float zv) {
	x = xv;
	z = zv;
}
Vector2D::~Vector2D() {}

Vector2D Vector2D::operator+(Vector2D op)
{
	Vector2D resultado;
	resultado.x = x + op.x;
	resultado.z = z + op.z;
	return Vector2D();
}

float Vector2D::modulo()
{
	return (float)sqrt(x * x + z * z);
}

float Vector2D::argumento()
{
	return (float)atan2(z, x);
}

Vector2D Vector2D::unitario()
{
	Vector2D retorno(x, z);
	float mod = modulo();
	if (mod > 0.0001)
	{
		retorno.x /= mod;
		retorno.z /= mod;
	}
	return retorno;
}



float Vector2D::operator*(Vector2D v)
{
	return (float)x * v.x + z * v.z;
}

Vector2D Vector2D::operator*(float n)
{
	x = x * n;
	z = z * n;
	return Vector2D();
}

Vector2D Vector2D::operator - (Vector2D v)
{
	Vector2D res;
	res.x = x - v.x;
	res.z = z - v.z;
	return res;
}
