class car
{
private:
	int price,model;
public:
	car(int , int);
	car();
	void setprice(int);
	void setmodel(int);
	int getprice();
	int getmodel();
	void increase();
	void update(int);
};
car::car(int newprice, int newmodel)
{	price=newprice;model=newmodel;}
car::car()
{price=0;model=0;}
int car::getmodel(){
    return model;
}
int car:: getprice(){
    return price;
}
void car::setprice(int newprice)
{	price=newprice;}
void car::setmodel(int newmodel)
{	model=newmodel;}
void car:: increase(){
    price=price+price*0.25;
}
void car:: update(int newmodel){
    model=newmodel;
}
int main()
{
    car c1,c2;
    c2.setmodel(2019);
    c2.setprice(10500);
    c2.increase();
    c2.update(2020);
    c1.setprice(c2.getprice());
    c1.setmodel(c2.getmodel());
    cout<<c1.getprice()<<endl;
    cout<<c1.getmodel()<<endl;
    cout<<c2.getprice()<<endl;
    cout<<c2.getmodel()<<endl;
    return 1;
}