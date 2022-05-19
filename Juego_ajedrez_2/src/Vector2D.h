#pragma once
class Vector2D {

public:
	Vector2D(float xv = 0.0f, float zv = 0.0f);
	virtual ~Vector2D();

	float x;
	float z;
	

	Vector2D operator + (Vector2D op);
	float modulo();
	float argumento();
	Vector2D unitario();
	Vector2D operator - (Vector2D v);
	float operator * (Vector2D);
	Vector2D operator * (float);
};