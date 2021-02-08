package z2;
public class E5_Relation_Logic {
	public static void main(String[] args) {
		int x=1;
        boolean b;		
        b=(7>8 && ++x<=9) ? true:false;
        System.out.println("x的值是:"+x+"  b的值是:"+b);
        b=(7<8 || ++x>9) ? true:false;
        System.out.println("x的值是:"+x+"  b的值是:"+b);
        //---------------------------------------------
        b=(7>8 & ++x<=9) ? true:false;
        System.out.println("x的值是:"+x+"  b的值是:"+b);
        b=(7<8 | ++x>9) ? true:false;
        System.out.println("x的值是:"+x+"  b的值是:"+b);
        //----------------------------------------------
        System.out.println("true^false=="+ (true^false));
        System.out.println("false^false=="+ (false^false));
	}
} 