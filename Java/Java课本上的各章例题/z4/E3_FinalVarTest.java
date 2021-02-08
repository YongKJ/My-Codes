package z4;
public class E3_FinalVarTest {
	static final int x=0;
	static final stu s1 = new stu();
	public static void main(String[] args) {
		//x=1;   //出错了
        //s1 = new stu(); //出错了
        s1.no=002;    //可以    
        System.out.println("s1.no="+s1.no); 
	}
}
class stu {
	public int no = 001;
}