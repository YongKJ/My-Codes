package z2;
public class E2_Constant {
	public static void main(String[] args) {
		final char C = 0xffff;        //最大的字符型常量，十六进制
		final byte B = 0x7f;	      //最大的字节型常量，十六进制
		final short S = 0x7fff;       //最大的短整型常量，十六进制
		final int I16 = 0xabcd;       //十六进制整型常量
		final int I8 = 0567; 	      //八进制整型常量
		final int I10 = 2016;	      //十进制整型常量
		final long L = 123456789L;	  //长整型常量
		final float F = 123456789f;	  //单精度浮点型常量
		final double D1 = 123456789d; //双精度浮点型常量
		final double D2 = 2e13d;      //指数形式的双精度浮点型常量
		System.out.println("最大的字符型常量=" + C);//没有可显示的符号
		System.out.println("最大的字节型常量= " +B);
		System.out.println("最大的短整型常量=" +S);
		System.out.println("十六进制整型常量abcd=" +I16);
		System.out.println("八进制整型常量567= " +I8);
		System.out.println("十进制整型常量2016= " +I10);
		System.out.println("长整型常量123456789=" +L);
		System.out.println("单精度浮点型常量123456789= " +F);
		System.out.println("双精度浮点型常量123456789=" +D1);
		System.out.println("指数形式的双精度浮点型常量2e13=" +D2);
	}
}