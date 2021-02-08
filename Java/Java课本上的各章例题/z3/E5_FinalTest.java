package z3;
public class E5_FinalTest {
	private final int A = 100; 
	public  static final int B = 200; 
    private final int C; //final空白,必须在初始化对象的时候赋初值    
    public Z3_5_FinalTest(int x) { 
        C = x; 
    } 
	public static void main(String[] args) {
		Z3_5_FinalTest  t1 = new Z3_5_FinalTest (1); 
        //t1.A=101;    //出错,final变量的值一旦给定就无法改变 
		System.out.println("t1.A="+t1.A); 
		System.out.println("t1.B="+t1.B); 
		System.out.println("t1.C="+t1.C); //final空白变量C依据对象的不同而不同 
        Z3_5_FinalTest  t2 = new Z3_5_FinalTest (2); 
        System.out.println("t2.A="+t2.A);        
        System.out.println("t2.B="+t2.B); 
        System.out.println("t2.C="+t2.C); //final空白变量C依据对象的不同而不同 
        //System.out.println("Z3_5_FinalTest.A="+Z3_5_FinalTest.A); //出错       
        System.out.println("Z3_5_FinalTest.B="+Z3_5_FinalTest.B);            
	}
}