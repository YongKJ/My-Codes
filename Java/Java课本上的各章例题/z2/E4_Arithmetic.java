package z2;
public class E4_Arithmetic {
	public static void main(String[] args) {
		int i=1;
    	//一元运算符中的自加和自减运算
    	System.out.println("i++="+(i++)+"\t"+"++i="+(++i));
    	System.out.println("i--="+(i--)+"\t"+"--i="+(--i));
        //-------------------------------------------------
    	int x=7/3;	 //两个整数相除，结果是整数
    	double y=7.0/3.0;//两个浮点数相除，结果是浮点数
    	System.out.println("7/3="+x+"\t"+"7.0/3.0="+y);
        //-------------------------------------------------
    	int m=7%3;	 //两个整数相除取余数，余数为整数	
    	double n=7.5%3.2;//两个浮点数相除取余数，余数为浮点数
    	System.out.println("7%3="+m+"\t"+"7.5%3.2="+n);
	}
}