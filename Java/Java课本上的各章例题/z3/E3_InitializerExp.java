package z3;
public class E3_InitializerExp {
	//实例变量初始化器
    String s1 = "000";
    static String s2 = "NNN";    
    //构造函数
    public Z3_3_InitializerExp() {        
        s1 = "111";
        s2 = "AAA";
        System.out.println("构造函数被调用后，s1="+s1+",s2="+s2);
    } 
    //静态初始化器
    static {
        System.out.println("静态变量s2的初始值："+s2);
        s2 = "BBB";
        System.out.println("静态初始化器被调用后，静态变量s2="+s2);
    } 
    //实例初始化器
    {
        System.out.println("实例变量s1的初始值："+s1);
        s1 = "222";
        System.out.println("实例初始化器被调用后，实例变量s1="+s1);
    }
	public static void main(String[] args) {
		new Z3_3_InitializerExp();
		System.out.println("-------------------------");
        new Z3_3_InitializerExp();
	}
}