package z9;
import java.util.*;
public class Z9_1_BellEventSource { //铃，事件源	
	private Set<Z9_1_StuEventListener> listener; //监听器容器
	public Z9_1_BellEventSource(){  
        listener = new HashSet<Z9_1_StuEventListener>();         
    }	
	//模拟事件触发器，当成员变量sound的值发生变化时，触发事件。
	public void RingBell(boolean sound) { 		
		Z9_1_RingEvent event = new Z9_1_RingEvent(this, sound);	  
        notifies(event);//通知注册在该事件源上的所有监听器                 
    }
	//给事件源注册监听器  
    public void addStuListener(Z9_1_StuEventListener stu){  
        listener.add(stu);  
    } 
    //当事件发生时,通知注册在该事件源上的所有监听器做出相应的反应（调用回调方法）
	protected void notifies(Z9_1_RingEvent e){  
		Z9_1_StuEventListener stu = null;  
        Iterator<Z9_1_StuEventListener> iterator = listener.iterator();  
        while(iterator.hasNext()){  
            stu = iterator.next();  
            stu.ListenBell(e);  
        }  
    }
}