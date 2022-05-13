class MainFrom : public Form{
private:
    Point p1;
    Point p2;
/*
    vector<Line> lineVector;
    vector<Rect> rectVetor;
*/
    //针对所有形状
    vector<Shape*> shapeVector;

public:
    MainForm(){
        //...
    }

protected:
    virtual void OnMouseDown(const MouseEventArgs& e);
    virtual void OnMouseUp(const MouseEventArgs& e);
    virtual void OnPaint(const PaintEventArgs& e);
};

void MainForm::OnMouseDown(const MouseEventArgs& e){
    p1.x=e.X;
    p1.y=e.Y;
    //...
    Form::OnMouseDown(e);
}

void MainForm::OnMouseUp(const MouseEventArgs& e){
    p2.x=e.X;
    p2.y=e.Y;
    //...
    Form::OnMouseDown(e);
}


void MainForm::OnMouseUp(const MouseEventArgs& e){
    p2.x=e.X;
    p2.y=e.Y;
    //...
    if(rdoline.Checked){
        Line line(p1,p2);
        shapeVector.push_back(new Line(p1,p2));
    }else if(rdoRect.Checked){
        int width=abs(p2.x-p1.x);
        int height=abs(p2.y-p1.y);
        Rect rect(p1,width,height);
        shapeVector.push_back(new Rect(p1,width,height));
    }

    //...
    this->Refresh();
    Form::OnMouseUp(e);
}


void MainForm::OnPaint(cosnt PaintEventArgs& e){
    //针对所有形状
    for(int ii=0;ii<shapeVector.size();ii++){
        shapeVector[ii]->Draw(e.Graphics);//多态调用，各负其责
    }
    //...
    Form::OnPaint(e);
}









