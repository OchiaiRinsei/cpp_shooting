#pragma once
class TAKO
{
private:
	int Img;
	float Px, Py, Angle;
public:
	void setImage(int img);
	void init();
	void move();
	void draw();
};

