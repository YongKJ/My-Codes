package z3;
public class E10_StaticExp {
	int x=2; 	    //实例变量
    static int y=3; //类变量
    int add(int x,int y)	//实例方法
    {
    	this.x=x;
        this.y=y; 
        return(this.x+this.y);
    }
    static int sub(int xx,int y) 	//类方法
    {
    	//x=xx; 	    //不能使用非static变量x，即静态方法只能访问静态变量
        //this.y=y; 	//不能使用this或super
        return (xx-y); 
    }
	public static void main(String[] args) {
		Z3_10_StaticExp s=new Z3_10_StaticExp();
		System.out.println("add: "+s.add(1,2));
		System.out.println("sub: "+Z3_10_StaticExp.sub(1,2));
	}
}