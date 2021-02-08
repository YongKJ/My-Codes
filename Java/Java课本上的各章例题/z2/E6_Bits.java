package z2;
public class E6_Bits {
	static int a=0xb6;
	static int b=0x65;
	public static void main(String[] args) {
		System.out.println("a & b="+Integer.toHexString(a&b));
		System.out.println("a | b="+Integer.toHexString(a|b));
		System.out.println("a ^ b="+Integer.toHexString(a^b));
		System.out.println(" ~a ="+Integer.toHexString(~a));
        System.out.println("a<<2="+Integer.toHexString(a<<2));
        System.out.println("a>>2="+Integer.toHexString(a>>2));
        System.out.println("a>>>2="+Integer.toHexString(a>>>2));
	}
}