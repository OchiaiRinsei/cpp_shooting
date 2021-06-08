#define _���Ԑ�
#ifdef _���Ԑ�
#include"libOne.h"
class CHARACTER {
protected:
    int Img = 0;
    float Px = 0, Py = 0, Angle = 0;
    float Vx = 0, Vy = 0, AngSpeed = 0;
public:
    virtual void setImage(int img) {
        Img = img;
    }
    virtual void init() {
        Px = width / 2;
        Py = height / 2;
        Angle = 0;
        Vx = 1;
        Vy = 1;
        AngSpeed = 0.01f;
    }

    virtual void move() {
        Angle += AngSpeed;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }
};
class PLAYER : public CHARACTER {
public:
    void move() {
        Px += Vx;
    }
};
class ENEMY : public CHARACTER{
public:
    void move() {
        Py += Vy;
    }
};

class ENEMY_BULLET : public CHARACTER {
};
void gmain() {
    window(1920, 1080, full);
    int playerImg = loadImage("assets\\player.png");
    int enemyImg = loadImage("assets\\enemy.png");
    int enemyBulletImg = loadImage("assets\\eBullet.png");


    PLAYER player;
    ENEMY enemy;
    ENEMY_BULLET eBullet;

    player.setImage(playerImg);
    enemy.setImage(enemyImg);
    eBullet.setImage(enemyBulletImg);


    const int num = 3;
    CHARACTER* chara[num];
    chara[0] = &player;
    chara[1] = &enemy;
    chara[2] = &eBullet;


    for (int i = 0; i < num; i++) {
        chara[i]->init();
    }
    while (notQuit) {
        for (int i = 0; i < num; i++) {
            chara[i]->move();
        }
        clear();
        for (int i = 0; i < num; i++) {
            chara[i]->draw();
        }
    }
}
#endif
#ifdef _�p��
#include"libOne.h"
class CHARACTER {//���N���X 
//private:
protected://��{private�����p����ł͏��������\
    int Img = 0;
    float Px = 0, Py = 0, Angle = 0;
    float Vx = 0, Vy = 0, AngSpeed = 0;
public:
    virtual void setImage(int img) {
        Img = img;
    }
    virtual void init() {
        Px = width / 2;
        Py = height / 2;
        Angle = 0;
        Vx = 1;
        Vy = 1;
        AngSpeed = 0.01f;
    }

    virtual void move() {//���z�֐�
        Angle += AngSpeed;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }
};
class PLAYER : public CHARACTER {//�h���N���X(���N���X)�̑S�Ă��p����
    //���ŏ��������\
public:
    void move() {//�Ƃ肠�����֐�������Ȃ���N���X�̊֐���virtual�t����
        Px += Vx;
    }
};
void gmain() {
    window(1920, 1080, full);
    int playerImg = loadImage("assets\\player.png");

    PLAYER player;
    //
    CHARACTER* chara = &player;

    chara->setImage(playerImg);
    chara->init();
    while (notQuit) {
        chara->move();
        clear();
        chara->draw();
    }
}
#endif
#ifdef _�J�v�Z����
#include"libOne.h"
//�O���ϐ�
class CHARACTER { //�ϐ��Ɗ֐��̂܂Ƃ܂��class
private://private�ɂ��struct�̊O���Œl���������Ȃ��Ȃ�
    int Img = 0;
    float Px = 0, Py = 0, Angle = 0;
    float Vx = 0, Vy = 0, AngSpeed = 0;
public:
    void setImage(int img) {
        Img = img;
    }
    void init() {
        Px = width / 2;
        Py = height / 2;
        Angle = 0;
        Vx = 1;
        Vy = 1;
        AngSpeed = 0.01f;
    }

    void move() {
        Angle += AngSpeed;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }
};
void gmain() {
    window(1920, 1080, full);
    int playerImg = loadImage("assets\\player.png");

    CHARACTER chara;

    chara.setImage(playerImg);
    chara.init();
    while (notQuit) {
        chara.move();
        clear();
        chara.draw();
    }
}
#endif

