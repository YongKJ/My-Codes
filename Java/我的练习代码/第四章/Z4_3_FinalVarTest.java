public class Z4_3_FinalVarTest{
	static final int x=0;
	static final stu s1=new stu();
	public static void main(String[] args) {
		//x=1;
		//s1=new stu();
		s1.no=002;
		System.out.println("s1.no="+s1.no);
	}
}
class stu{
	public int no=001;
}