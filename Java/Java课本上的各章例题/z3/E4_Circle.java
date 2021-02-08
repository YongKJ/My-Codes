package z3;
public class E4_Circle {	
	public static void main(String[] args) {
		Circle c1 = new Circle(); 
	    Circle c2 = new Circle(2,3,5); 
	    System.out.println("圆1: "+c1);
	    System.out.println("圆2: "+c2);
	}
}
class Circle
{
	int x,y,r;      //圆心和半径	
	public Circle() //无参构造方法
	{
		x=0;
		y=0;
    	r=1;
	}
    Circle(int X,int Y,int R) //有参构造方法
	{
	    x=X;
	    y=Y;
        r=R;
	}
    public String toString() {
    	String t;
    	t="它的圆心坐标是("+x+","+y+")，半径是"+r;    	    
        return t;
    }     
}