#define _演算子のオーバーロード
#ifdef _演算子のオーバーロード
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
    //足す関数
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
    /*Cの加算
    new_pos.x = pos.x + vec.x;
    new_pos.y = pos.y + vec.y;
     
    Cの関数を作って足す方法
    new_pos = pos.plus(vec);

    C++演算子のオーバーロード
    new_pos = pos + vec;*/

    printSize(200);
    print(pos.x);
    print(pos.y);
    while (notQuit) {
    }
}
#endif
#ifdef _初期化と代入
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

    //int x = 10;//これが初期化
    //int x; //これが
    //x = 10;//代入

    //FLOAT2  pos(100, 10);//これが初期化
    //FLOAT2 pos;            //これが
    //pos = FLOAT2(100, 10);//代入

    FLOAT2 pos[2] = {
        FLOAT2(100,10),//代入
        FLOAT2(200,20),
    };

    printSize(200);
    print(pos[1].x);
    print(pos[1].y);
    while (notQuit) {
    }
}
#endif
#ifdef _thisポインタ
#include"libOne.h"
class FLOAT2 {
public:
    float x, y;
    FLOAT2() {
        x = 0;
        y = 0;
    }
    FLOAT2(float x,float y) {
        this->x = x;//thisポインタはアドレスを記憶する
        this->y = y;
    }
};
void gmain() {
    window(1000, 1000, full);

    FLOAT2  pos(100, 10);//ここのposの(実態を用意した時の)アドレスが記憶される

    printSize(200);
    print(pos.x);
    print(pos.y);
    while (notQuit) {
    }
}
#endif
#ifdef _参考
#include"libOne.h"
class FLOAT2 {
public:
    float x, y;
};
void set(FLOAT2& f2) {//&でposの記憶場所が共通になる
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
#ifdef _ファイル分割
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
#ifdef _コンストラクタ・デストラクタ(静的確保)
#include"libOne.h"
class BABY {
public:
    BABY() {//これがコンストラクタ
        textSize(200);
        text("Hello", 700, 300);
    }
    ~BABY() {//デストラクタ
        textSize(200);
        text("GoodBye", 700, 600);
    }
};
void func() {
    BABY baby;
}
//静的確保
void gmain() {
    window(1920, 1080, full);
    func();
    BABY baby;//この瞬間自動的にコンストラクタが呼び出し
              //babyが無くなったらデストラクタ呼び出し
    while (notQuit) {
    }
}
//動的確保
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
#ifdef _メモリの動的確保
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
//1体分確保
/*
void gmain() {
    window(1920, 1080, full);
    hideCursor();//カーソルが見えなくなる関数
    int enemyImg = loadImage("assets\\enemy.png");
    ENEMY* enemy = new ENEMY;
    enemy->setImage(enemyImg);
    enemy->init();
    while (notQuit) {
        clear();
        enemy->move();
        enemy->draw();
    }
    //忘れ注意！！！
    delate enemy;
}
*/
//num体分確保
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
    //忘れ注意！！
    delete[] enemy;
}
#endif
#ifdef _多態性
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
#ifdef _継承
#include"libOne.h"
class CHARACTER {//基底クラス 
//private:
protected://基本privateだが継承先では書き換え可能
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

    virtual void move() {//仮想関数
        Angle += AngSpeed;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }
};
class PLAYER : public CHARACTER {//派生クラス(基底クラス)の全てを継承済
    //中で書き換え可能
public:
    void move() {//とりあえず関数いじるなら基底クラスの関数にvirtual付ける
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
#ifdef _カプセル化
#include"libOne.h"
//外部変数
class CHARACTER { //変数と関数のまとまりはclass
private://privateによりstructの外部で値をいじられなくなる
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

