#include <stdio.h>

struct point{
    int x;
    int y;
};

struct rectangle{
    struct point pt1;
    struct point pt2;
};

struct line{
    struct point pt1;
    struct point pt2;
};


struct point makePoint(int x, int y){
    struct point temp;

    temp.x = x;
    temp.y = y;

    return temp;
}

void printRect(struct rectangle r){
    printf("Rectangle with pt1:[%d, %d] and pt2:[%d, %d]\n", r.pt1.x, r.pt1.y, r.pt2.x, r.pt2.y);
}

struct point addPoint(struct point pt1, struct point pt2){
    return makePoint(pt1.x + pt2.x, pt1.y + pt2.y);
}

int ptInRect(struct point p, struct rectangle r){
    return p.x >= r.pt1.x && p.y <= r.pt2.x && p.y >= r.pt1.y && p.y <= r.pt2.y;
}

int main(int argc, char *argv[]){

    struct point pt1, pt2;
    struct rectangle r;

    pt1 = makePoint(0, 0);
    pt2 = makePoint(5, 10);

    r.pt1 = pt1;
    r.pt2 = pt2;

    printRect(r);

    ptInRect(pt1, r)?printf("pt1 is in the rectangle\n"):printf("pt1 is not in the rectangle\n");

    return 0;
}