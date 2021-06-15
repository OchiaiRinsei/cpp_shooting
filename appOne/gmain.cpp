#define _���Z�q�̃I�[�o�[���[�h
#ifdef _���Z�q�̃I�[�o�[���[�h
#include"libOne.h"
class FLOAT2 {
public:
    float x = 0, y = 0;
    FLOAT2() {
    }
    FLOAT2(float x, float y) {
        this->x = x;
        this->y = y;
    }
    //�����֐�
    /*
    FLOAT2 plus(FLOAT2& f2) {
        return FLOAT2(x + f2.x, y + f2.y);
    */
    FLOAT2 operator+(FLOAT2& f2) {
        return FLOAT2(x + f2.x, y + f2.y);
    }
    FLOAT2 operator-(FLOAT2& f2) {
        return FLOAT2(x - f2.x, y - f2.y);
    }
    FLOAT2 operator*(float f) {
        return FLOAT2(x * f, y * f);
    }
    void operator+=(const FLOAT2& f2) {
        x += f2.x;
        y += f2.y;
    }
    void nomalize() {
        float mag = sqrt(x * x + y * y);
        x /= mag;
        y /= mag;
    }
};
void gmain() {
    window(1000, 1000, full);

    FLOAT2  pos(100, 10);
    FLOAT2  vec(200, 20);
    vec.nomalize();
    pos += vec*5.0f;
    /*C�̉��Z
    new_pos.x = pos.x + vec.x;
    new_pos.y = pos.y + vec.y;
     
    C�̊֐�������đ������@
    new_pos = pos.plus(vec);

    C++���Z�q�̃I�[�o�[���[�h
    new_pos = pos + vec;*/

    printSize(200);
    print(pos.x);
    print(pos.y);
    while (notQuit) {
    }
}
#endif
#ifdef _�������Ƒ��
#include"libOne.h"
class FLOAT2 {
public:
    float x=0, y=0;
    FLOAT2(){
    }
    FLOAT2(float x, float y) {
        this->x = x;
        this->y = y;
    }
};
void gmain() {
    window(1000, 1000, full);

    //int x = 10;//���ꂪ������
    //int x; //���ꂪ
    //x = 10;//���

    //FLOAT2  pos(100, 10);//���ꂪ������
    //FLOAT2 pos;            //���ꂪ
    //pos = FLOAT2(100, 10);//���

    FLOAT2 pos[2] = {
        FLOAT2(100,10),//���
        FLOAT2(200,20),
    };

    printSize(200);
    print(pos[1].x);
    print(pos[1].y);
    while (notQuit) {
    }
}
#endif
#ifdef _this�|�C���^
#include"libOne.h"
class FLOAT2 {
public:
    float x, y;
    FLOAT2() {
        x = 0;
        y = 0;
    }
    FLOAT2(float x,float y) {
        this->x = x;//this�|�C���^�̓A�h���X���L������
        this->y = y;
    }
};
void gmain() {
    window(1000, 1000, full);

    FLOAT2  pos(100, 10);//������pos��(���Ԃ�p�ӂ�������)�A�h���X���L�������

    printSize(200);
    print(pos.x);
    print(pos.y);
    while (notQuit) {
    }
}
#endif
#ifdef _�Q�l
#include"libOne.h"
class FLOAT2 {
public:
    float x, y;
};
void set(FLOAT2& f2) {//&��pos�̋L���ꏊ�����ʂɂȂ�
    f2.x = 100;
    f2.y = 10;
}
void gmain() {
    window(1000, 1000, full);
    FLOAT2  pos;
    set(pos);
    printSize(200);
    print(pos.x);
    print(pos.y);
    while (notQuit) {
    }
}
#endif
#ifdef _�t�@�C������
#include"libOne.h"
#include"TAKO.h"
void gmain() {
    window(1920, 1080, full);
    int takoImg = loadImage("assets\\enemy.png");
    int num = 30;
    TAKO* takos = new TAKO[num];
    for (int i = 0; i < num; i++) {
        takos[i].setImage(takoImg);
        takos[i].init();
    }
    while (notQuit) {
        for (int i = 0; i < num; i++) {
            takos[i].move();
            takos[i].draw();
        }
    }
    delete[] takos;
}
#endif
#ifdef _�R���X�g���N�^�E�f�X�g���N�^(�ÓI�m��)
#include"libOne.h"
class BABY {
public:
    BABY() {//���ꂪ�R���X�g���N�^
        textSize(200);
        text("Hello", 700, 300);
    }
    ~BABY() {//�f�X�g���N�^
        textSize(200);
        text("GoodBye", 700, 600);
    }
};
void func() {
    BABY baby;
}
//�ÓI�m��
void gmain() {
    window(1920, 1080, full);
    func();
    BABY baby;//���̏u�Ԏ����I�ɃR���X�g���N�^���Ăяo��
              //baby�������Ȃ�����f�X�g���N�^�Ăяo��
    while (notQuit) {
    }
}
//���I�m��
/*
void gmain() {
    window(1920, 1080, full);
    BABY* baby = new BABY;
    delete baby;
    while (notQuit) {
    }
}
*/
#endif
#ifdef _�������̓��I�m��
#include"libOne.h"
class ENEMY {
private:
    int Img = 0;
    float Px = 0, Py = 0, Vx = 0;
public:
    virtual void setImage(int img) {
        Img = img;
    }
    void init() {
        Px = random() % (int)width;
        Py = random() % (int)height;
        Vx = random() % 5 + 1.0f;
        int e = random();
        if (e % 2 == 0) {
            Vx = -Vx;
        }
    }
    void move() {
        Px += Vx;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py);
    }
};
//1�̕��m��
/*
void gmain() {
    window(1920, 1080, full);
    hideCursor();//�J�[�\���������Ȃ��Ȃ�֐�
    int enemyImg = loadImage("assets\\enemy.png");
    ENEMY* enemy = new ENEMY;
    enemy->setImage(enemyImg);
    enemy->init();
    while (notQuit) {
        clear();
        enemy->move();
        enemy->draw();
    }
    //�Y�꒍�ӁI�I�I
    delate enemy;
}
*/
//num�̕��m��
void gmain() {
    window(1920, 1080, full);
    hideCursor();
    int enemyImg = loadImage("assets\\enemy.png");
    int num = 50;
    ENEMY* enemy = new ENEMY[num];
    for (int i = 0; i < num; i++) {
        enemy[i].setImage(enemyImg);
        enemy[i].init();
    }
    while (notQuit) {
        clear();
        for (int i = 0; i < num; i++) {
            enemy[i].move();
        }
        for (int i = 0; i < num; i++) {
            enemy[i].draw();
        }
    }
    //�Y�꒍�ӁI�I
    delete[] enemy;
}
#endif
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
    //float px() { return Px; }

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
    void init(){
        Px = width / 2;
        Py = height / 2-300;
        Vx = 100;
        Vy = height / 2 - 400;
    }
    void move() {
        if (Px >= width / 2 + 300 || Px < width / 2 - 300) { Vx = -Vx; }
        Px += Vx;
    }
};

class ENEMY : public CHARACTER{
public:
    void init() {
        Px = width / 2;
        Py = height / 2 + 300;
        Vx = 2;
    }
    void move() {
        if (Px >= width / 2 + 300 || Px < width / 2 - 300) { Vx = -Vx; }
        Px += Vx;
    }
};

class ENEMY_BULLET : public CHARACTER {
    void init() {
        // Px = px;
        Px = width / 2;
        Py = height / 2 + 300;
        Vx = 2;
        Vy = -2;
    }
    void move() {
        if (isPress(KEY_SPACE)) {
            for (int i = 0; i < 1; i++) {
                Py += Vy;
            }
            if (Py < 0) {
                Py = height / 2+300;
            }
        }
    }
};
class PLAYER_BULLET : public CHARACTER {

};
void gmain() {
    window(1920, 1080, full);
    int playerImg = loadImage("assets\\player.png");
    int playerBulletImg = loadImage("assets\\pBullet.png");
    int enemyImg = loadImage("assets\\enemy.png");
    int enemyBulletImg = loadImage("assets\\eBullet.png");


    PLAYER player;
    ENEMY enemy;
    ENEMY_BULLET eBullet;
    PLAYER_BULLET pBullet;

    player.setImage(playerImg);
    pBullet.setImage(playerBulletImg);
    enemy.setImage(enemyImg);
    eBullet.setImage(enemyBulletImg);


    const int num = 4;
    CHARACTER* chara[num];
    chara[0] = &player;
    chara[1] = &enemy;
    chara[2] = &eBullet;
    chara[3] = &pBullet;


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

