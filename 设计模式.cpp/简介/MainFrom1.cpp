class MainFrom : public Form{
private:
    Point p1;
    Point p2;

    vector<Line> lineVector;
    vector<Rect> rectVetor;

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
        lineVector.push_back(line);
    }else if(rdoRect.Checked){
        int width=abs(p2.x-p1.x);
        int height=abs(p2.y-p1.y);
        Rect rect(p1,width,height);
        rectVector.push_back(rect);
    }

    //...
    this->Refresh();
    Form::OnMouseUp(e);
}


void MainForm::OnPaint(cosnt PaintEventArgs& e){
    //针对直线
    for(int ii=0;ii<lineVector.size();ii++){
        e.Graphics.DrawLine(Pens.Red,lineVector[ii].start.x,lineVector[ii].start.y,lineVector[ii].end.x,lineVector[ii].end.y);
    }

    for(int ii=0;ii<rectVector.size();ii++){
        e.Graphics.DrawRectangle(Pens.Red,rectVector[ii].leftUp,rectVector[ii].width,rectVector[ii].height);
    }

    //...
    Form::OnPaint(e);
}


