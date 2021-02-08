import java.util.*;
public class Z9_1_BellEventSource{
    private Set<Z9_1_StuEventListener> listener;
    public Z9_1_BellEventSource(){
        listener = new HashSet<Z9_1_StuEventListener>();
    }
    public void RingBell(boolean sound){
        Z9_1_RingEvent event = new Z9_1_RingEvent(this,sound);
        notifies(event);
    }
    public void addStuListener(Z9_1_StuEventListener stu){
        listener.add(stu);
    }
    protected void notifies(Z9_1_RingEvent e){
        Z9_1_StuEventListener stu = null;
        Iterator <Z9_1_StuEventListener> iterator = listener.iterator();
        while(iterator.hasNext()){
            stu=iterator.next();
            stu.ListenBell(e);
        }
    }
}
