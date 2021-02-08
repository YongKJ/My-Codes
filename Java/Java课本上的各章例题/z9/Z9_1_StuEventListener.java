package z9;
import java.util.EventListener;
//事件监听器，学生类
public class Z9_1_StuEventListener implements EventListener {
	//事件发生后的回调方法，监听铃声 
	public void ListenBell(Z9_1_RingEvent e){ 		
		if(e.getSound()){
			System.out.println("同学们，上课了!");			
		}else{
			System.out.println("同学们，下课了!");	
		}           
    } 
}