package z9;
public class E1_EventTest {	
	public static void main(String[] args) {
		Z9_1_BellEventSource bell = new Z9_1_BellEventSource();//铃（事件源）     
        bell.addStuListener(new Z9_1_StuEventListener()); //注册监听器（学生）          
        //触发事件  
        bell.RingBell(true);   //true表示上课铃声
        bell.RingBell(false);  //false表示下课铃声
	}
}