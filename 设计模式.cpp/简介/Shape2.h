class Shape{
public:
    virtual void Draw(const Graphics& g)=0;
    virtual ~Shape(){}
};

class Point{
public:
    int x;
    int y;
};

class Line :public Shape{
public:
    Point start;
    Point end;

    Line(const Point& start,const Point& end){
        this->start=start;
        this->end=end;
    }
    virtual void Draw(const Graphics& g){
        g.DrawLine(Pens.Red,start.x,start.y,end.x,end.y);
    }
};

class Rect:public Shape{
public:
    Point leftUp;
    int width;
    int height;

    Rect(const Point& leftUp,int width,int height){
        this->leftUp=leftUp;
        this->width=width;
        this->height=height;
    }

    virtual void ...
};