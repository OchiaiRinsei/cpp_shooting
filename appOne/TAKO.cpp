#include "TAKO.h"
#include "libone.h"

void TAKO::setImage(int img) {//TAKO::��class TAKO�̊֐��Ƃ��Ĉ�����
	Img = img;
}
void TAKO::init() {
	Px = random() % (int)width;
	Py = random() % (int)height;
	Angle = 0;
}
void TAKO::move() {
	Angle += 0.01f;
}
void TAKO::draw() {
	image(Img, Px, Py, Angle);
}