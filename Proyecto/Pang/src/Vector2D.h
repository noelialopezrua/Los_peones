#pragma once
class Vector2D
{
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);//si no se inicializa, se inicializaran automaticamente a 0.0
	virtual ~Vector2D();
	float x, y;
	float modulo();
	float argumento();
	Vector2D Unitario();
	Vector2D operator - (Vector2D &v);// eficiencia. El paso por referencia es más rápido que el paso por valor. 
	Vector2D operator + (Vector2D &v);
	float operator *(Vector2D &v);
	Vector2D operator *(float n);

	bool operator = (Vector2D &v);
};